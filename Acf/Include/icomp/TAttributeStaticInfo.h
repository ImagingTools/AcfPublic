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


#ifndef icomp_TAttributeStaticInfo_included
#define icomp_TAttributeStaticInfo_included


#include "istd/CClassInfo.h"

#include "icomp/IRealAttributeStaticInfo.h"
#include "icomp/CBaseComponentStaticInfo.h"


namespace icomp
{


template <class Attribute>
class TAttributeStaticInfo: virtual public IRealAttributeStaticInfo
{
public:
	TAttributeStaticInfo(
				icomp::CBaseComponentStaticInfo& staticInfo,
				const std::string& id,
				const std::string& description,
				const Attribute* defaultValuePtr,
				int flags,
				const istd::CClassInfo& relatedInterfaceInfo);

	// reimplemented (icomp::IRealAttributeStaticInfo)
	virtual const std::string& GetAttributeId() const;

	// reimplemented (icomp::IAttributeStaticInfo)
	virtual const std::string& GetAttributeDescription() const;
	virtual const iser::IObject* GetAttributeDefaultValue() const;
	virtual const std::string& GetAttributeTypeName() const;
	virtual IComponentStaticInfo::Ids GetRelatedMetaIds(int metaGroupId, int flags, int flagsMask) const;
	virtual int GetAttributeFlags() const;

private:
	std::string m_id;
	std::string m_description;
	const Attribute* m_defaultValuePtr;
	int m_attributeFlags;
	istd::CClassInfo m_relatedInterfaceType;
};


// public methods

template <class Attribute>
TAttributeStaticInfo<Attribute>::TAttributeStaticInfo(
			icomp::CBaseComponentStaticInfo& staticInfo,
			const std::string& id,
			const std::string& description,
			const Attribute* defaultValuePtr,
			int flags,
			const istd::CClassInfo& relatedInterfaceInfo)
:	m_id(id),
	m_description(description),
	m_defaultValuePtr(defaultValuePtr),
	m_attributeFlags(flags),
	m_relatedInterfaceType(relatedInterfaceInfo)
{
	staticInfo.RegisterAttributeInfo(id, this);
}


// reimplemented (icomp::IRealAttributeStaticInfo)

template <class Attribute>
const std::string& TAttributeStaticInfo<Attribute>::GetAttributeId() const
{
	return m_id;
}


// reimplemented (icomp::IAttributeStaticInfo)

template <class Attribute>
const std::string& TAttributeStaticInfo<Attribute>::GetAttributeDescription() const
{
	return m_description;
}


template <class Attribute>
const iser::IObject* TAttributeStaticInfo<Attribute>::GetAttributeDefaultValue() const
{
	return m_defaultValuePtr;
}


template <class Attribute>
const std::string& TAttributeStaticInfo<Attribute>::GetAttributeTypeName() const
{
	return Attribute::GetTypeName();
}


template <class Attribute>
IComponentStaticInfo::Ids TAttributeStaticInfo<Attribute>::GetRelatedMetaIds(int metaGroupId, int flags, int flagsMask) const
{
	IComponentStaticInfo::Ids retVal;

	if (metaGroupId == IComponentStaticInfo::MGI_INTERFACES){
		if (((m_attributeFlags & flagsMask) == flags) && !m_relatedInterfaceType.IsVoid()){
			retVal.insert(m_relatedInterfaceType.GetName());
		}
	}

	return retVal;
}


template <class Attribute>
int TAttributeStaticInfo<Attribute>::GetAttributeFlags() const
{
	return m_attributeFlags;
}


}//namespace icomp


#endif // !icomp_TAttributeStaticInfo_included


