/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef icomp_TMultiAttributeMember_included
#define icomp_TMultiAttributeMember_included


#include "icomp/IComponentContext.h"


namespace icomp
{


/**
	Pointer to component attribute.
	\internal
	Don't use direct this class, use macros \c I_ATTR and \c I_ASSIGN_MULTI_* instead.
*/
template <typename Attribute>
class TMultiAttributeMember
{
public:
	typedef Attribute AttributeType;
	typedef void InterfaceType;

	TMultiAttributeMember();

	bool Init(	const IComponent* ownerPtr,
				const IRealAttributeStaticInfo& staticInfo,
				const IComponent** definitionComponentPtr = NULL);

	/**
		Check if this attribute is valid.
	*/
	bool IsValid() const;

	/**
		Get number of attributes.
	*/
	int GetCount() const;

	/**
		Access to object pointed by internal pointer.
	*/
	const typename Attribute::ValueType& operator[](int index) const;

private:
	const Attribute* m_attributePtr;
};


// public methods

template <typename Attribute>
TMultiAttributeMember<Attribute>::TMultiAttributeMember()
:	m_attributePtr(NULL)
{
}


template <typename Attribute>
bool TMultiAttributeMember<Attribute>::Init(
			const IComponent* ownerPtr,
			const IRealAttributeStaticInfo& staticInfo,
			const IComponent** definitionComponentPtr)
{
	I_ASSERT(ownerPtr != NULL);

	const std::string& attributeId = staticInfo.GetAttributeId();
	const IComponentContext* componentContextPtr = ownerPtr->GetComponentContext();
	if (componentContextPtr != NULL){
		int definitionLevel = -1;
		const iser::IObject* attributePtr = componentContextPtr->GetAttribute(attributeId, &definitionLevel);
		m_attributePtr = dynamic_cast<const Attribute*>(attributePtr);

		if (m_attributePtr != NULL){
			I_ASSERT(definitionLevel >= 0);

			if (definitionComponentPtr != NULL){
				while (definitionLevel > 0){
					ownerPtr = ownerPtr->GetParentComponent();
					I_ASSERT(ownerPtr != NULL);

					--definitionLevel;
				}

				*definitionComponentPtr = ownerPtr;
			}

			return true;
		}
	}
	else{
		m_attributePtr = NULL;
	}

	return false;
}


template <typename Attribute>
bool TMultiAttributeMember<Attribute>::IsValid() const
{
	return (m_attributePtr != NULL);
}


template <typename Attribute>
int TMultiAttributeMember<Attribute>::GetCount() const
{
	if (m_attributePtr != NULL){
		return m_attributePtr->GetValuesCount();
	}
	else{
		return 0;
	}
}


template <typename Attribute>
const typename Attribute::ValueType& TMultiAttributeMember<Attribute>::operator[](int index) const
{
	I_ASSERT(index >= 0);
	I_ASSERT(index < GetCount());
	I_ASSERT(m_attributePtr != NULL);	// operator* was called for invalid object, or no IsValid() check was called.
	I_ASSERT(m_attributePtr->GetValuesCount() == GetCount());

	return m_attributePtr->GetValueAt(index);
}


}//namespace icomp


#endif // !icomp_TMultiAttributeMember_included


