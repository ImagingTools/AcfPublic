/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
**
**	This file may be used under the terms of the GNU Lesser
**	General Public License version 2.1 as published by the Free Software
**	Foundation and appearing in the file LicenseLGPL.txt included in the
**	packaging of this file.  Please review the following information to
**	ensure the GNU Lesser General Public License version 2.1 requirements
**	will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iattr_TAttribute_included
#define iattr_TAttribute_included


#include "istd/TChangeNotifier.h"
#include "istd/CClassInfo.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"
#include "iser/TCopySerializedWrap.h"

#include "iattr/CAttributeBase.h"


namespace iattr
{


/**
	Template implementation of an atomic attribute.
*/
template <typename Value>
class TAttribute: public iattr::CAttributeBase
{
public:
	typedef Value ValueType;
	typedef TAttribute<Value> AttributeType;
	typedef iattr::CAttributeBase BaseClass;

	TAttribute();

	TAttribute(
				iattr::IAttributesManager* attributeOwnerPtr,
				const std::string& attributeName,
				const std::string& attributeDescription,
				int attributeFlags,
				int changeFlags = 0,
				const ValueType& defaultValue = ValueType());

	const Value& GetValue() const;
	void SetValue(const Value& value);
	void ResetValue();

	// reimplemented (iser::IAttribute)
	virtual const iser::IObject* GetDefaultAttributePtr() const;

	// reimplemented (iser::IObject)
	virtual const std::string& GetFactoryId() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// static methods
	static const std::string& GetTypeName();

protected:
	Value m_value;

	mutable istd::TDelPtr<AttributeType> m_defaultAttributeValuePtr;

private:
	static const std::string s_typeName;
};


// public methods

template <typename Value>
TAttribute<Value>::TAttribute()
	:BaseClass()
{
}


template <typename Value>
TAttribute<Value>::TAttribute(
				iattr::IAttributesManager* attributeOwnerPtr,
				const std::string& attributeName,
				const std::string& attributeDescription,
				int attributeFlags,
				int changeFlags,
				const ValueType& defaultValue)
	:BaseClass(attributeOwnerPtr, attributeName, attributeDescription, attributeFlags, changeFlags),
	m_value(defaultValue)
{
	if (!m_defaultAttributeValuePtr.IsValid()){
		m_defaultAttributeValuePtr.SetPtr(new AttributeType());

		m_defaultAttributeValuePtr->SetValue(defaultValue);
	}
}


template <typename Value>
const Value& TAttribute<Value>::GetValue() const
{
	return m_value;
}


template <typename Value>
void TAttribute<Value>::SetValue(const Value& value)
{
	if (m_value != value){
		istd::CChangeNotifier changePtr(m_attributeOwnerPtr, m_changeFlags);

		m_value = value;
	}
}


template <typename Value>
void  TAttribute<Value>::ResetValue()
{
	if (m_defaultAttributeValuePtr.IsValid()){
		SetValue(m_defaultAttributeValuePtr->GetValue());
	}
}


// reimplemented (iser::IAttribute)

template <typename Value>
const iser::IObject* TAttribute<Value>::GetDefaultAttributePtr() const
{
	return m_defaultAttributeValuePtr.GetPtr();
}


// reimplemented (iser::IObject)

template <typename Value>
const std::string& TAttribute<Value>::GetFactoryId() const
{
	return s_typeName;
}


// reimplemented (ISerializable)

template <typename Value>
bool TAttribute<Value>::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag valueTag("Value", "Attribute value");
	retVal = retVal && archive.BeginTag(valueTag);

	retVal = retVal && archive.Process(m_value);

	retVal = retVal && archive.EndTag(valueTag);

	return retVal;
}


// static methods

template <typename Value>
const std::string& TAttribute<Value>::GetTypeName()
{
	return s_typeName;
}


// private static attributes

template <typename Value>
const std::string TAttribute<Value>::s_typeName(istd::CClassInfo::GetName<TAttribute<Value> >());


// typedefs

typedef TAttribute<double> CDoubleAttribute;
typedef TAttribute<bool> CBoolAttribute;
typedef TAttribute<int> CIntAttribute;
typedef TAttribute<istd::CString> CStringAttribute;


} // namespace iattr


#endif // !iattr_TAttribute_included


