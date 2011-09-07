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


#ifndef icomp_TAttribute_included
#define icomp_TAttribute_included


#include "istd/CClassInfo.h"

#include "iser/IArchive.h"
#include "iser/IObject.h"
#include "iser/CArchiveTag.h"
#include "iser/TCopySerializedWrap.h"

#include "icomp/IAttributeStaticInfo.h"


namespace icomp
{


/**
	Template implementation of single component attribute.
	\internal
	Don't use direct this class, use macros \c I_ATTR and \c I_ASSIGN instead.
*/
template <typename Value>
class TAttribute: virtual public iser::TCopySerializedWrap<iser::IObject>
{
public:
	typedef Value ValueType;

	enum DefaultAttributeFlags
	{
		DAF_OBLIGATORY = IAttributeStaticInfo::AF_OBLIGATORY | IAttributeStaticInfo::AF_NULLABLE,
		DAF_OPTIONAL = IAttributeStaticInfo::AF_NULLABLE
	};

	TAttribute();
	TAttribute(const TAttribute& attribute);

	explicit TAttribute(const Value& value);

	virtual const Value& GetValue() const;
	virtual void SetValue(const Value& value);

	// reimplemented (iser::IObject)
	virtual const std::string& GetFactoryId() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// static methods
	static const std::string& GetTypeName();

protected:
	Value m_value;

private:
	static const std::string s_typeName;
};


// public methods

template <typename Value>
TAttribute<Value>::TAttribute()
{
}


template <typename Value>
TAttribute<Value>::TAttribute(const Value& value)
:	m_value(value)
{
}


template <typename Value>
TAttribute<Value>::TAttribute(const TAttribute& attribute)
:	m_value(attribute.GetValue())
{
}


template <typename Value>
const Value& TAttribute<Value>::GetValue() const
{
	return m_value;
}


template <typename Value>
void TAttribute<Value>::SetValue(const Value& value)
{
	m_value = value;
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

	static iser::CArchiveTag valueTag("Value", "Value of attribute");
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


} // namespace icomp


#endif // !icomp_TAttribute_included


