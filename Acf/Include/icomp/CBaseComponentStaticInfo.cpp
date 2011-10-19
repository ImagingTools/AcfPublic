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


#include "icomp/CBaseComponentStaticInfo.h"


#include "istd/istd.h"


namespace icomp
{


CBaseComponentStaticInfo::CBaseComponentStaticInfo(const IRealComponentStaticInfo* baseComponentPtr)
:	m_baseComponentPtr(baseComponentPtr)
{
}


void CBaseComponentStaticInfo::RegisterInterfaceExtractor(const std::string& interfaceName, InterfaceExtractorPtr extractorPtr)
{
	m_interfaceExtractors[interfaceName] = extractorPtr;
}


void CBaseComponentStaticInfo::RegisterAttributeInfo(const std::string& attributeId, const IAttributeStaticInfo* attributeInfoPtr)
{
	m_attributeInfos[attributeId] = attributeInfoPtr;
}


void CBaseComponentStaticInfo::RegisterSubcomponentInfo(const std::string& embeddedId, const IComponentStaticInfo* componentInfoPtr)
{
	m_subcomponentInfos[embeddedId] = componentInfoPtr;
}


//	reimplemented (icomp::IRealComponentStaticInfo)

IComponent* CBaseComponentStaticInfo::CreateComponent() const
{
	I_CRITICAL();	// trying to create abstract base component. Check if I_BEGIN_COMPONENT in constructed component wasn't forgotten

	return NULL;
}


void* CBaseComponentStaticInfo::GetComponentInterface(const istd::CClassInfo& interfaceType, IComponent& component) const
{
	InterfaceExtractors::const_iterator foundIter = m_interfaceExtractors.find(interfaceType.GetName());
	if (foundIter != m_interfaceExtractors.end()){
		InterfaceExtractorPtr extractorPtr = foundIter->second;

		return extractorPtr(component);
	}

	if (interfaceType.IsConst()){
		istd::CClassInfo nonConstType = interfaceType.GetConstCasted(false);

		InterfaceExtractors::const_iterator foundIter = m_interfaceExtractors.find(nonConstType.GetName());
		if (foundIter != m_interfaceExtractors.end()){
			InterfaceExtractorPtr extractorPtr = foundIter->second;

			return extractorPtr(component);
		}
	}

	if (m_baseComponentPtr != NULL){
		return m_baseComponentPtr->GetComponentInterface(interfaceType, component);
	}

	return NULL;
}


//	reimplemented (icomp::IComponentStaticInfo)

const IAttributeStaticInfo* CBaseComponentStaticInfo::GetAttributeInfo(const std::string& attributeId) const
{
	AttributeInfos::const_iterator fondIter = m_attributeInfos.find(attributeId);
	if (fondIter != m_attributeInfos.end()){
		return fondIter->second;
	}
	else if (m_baseComponentPtr != NULL){
		return m_baseComponentPtr->GetAttributeInfo(attributeId);
	}
	else{
		return NULL;
	}
}


const IComponentStaticInfo* CBaseComponentStaticInfo::GetSubcomponentInfo(const std::string& subcomponentId) const
{
	SubcomponentInfos::const_iterator fondIter = m_subcomponentInfos.find(subcomponentId);
	if (fondIter != m_subcomponentInfos.end()){
		return fondIter->second;
	}
	else if (m_baseComponentPtr != NULL){
		return m_baseComponentPtr->GetSubcomponentInfo(subcomponentId);
	}
	else{
		return NULL;
	}
}


IComponentStaticInfo::Ids CBaseComponentStaticInfo::GetMetaIds(int metaGroupId) const
{
	Ids retVal;

	if (m_baseComponentPtr != NULL){
		retVal = m_baseComponentPtr->GetMetaIds(metaGroupId);
	}

	if (metaGroupId == MGI_INTERFACES){
		for (		InterfaceExtractors::const_iterator iter = m_interfaceExtractors.begin();
					iter != m_interfaceExtractors.end();
					++iter){
			retVal.insert(iter->first);
		}
	}
	else if (metaGroupId == MGI_ATTRIBUTES){
		for (		AttributeInfos::const_iterator iter = m_attributeInfos.begin();
					iter != m_attributeInfos.end();
					++iter){
			retVal.insert(iter->first);
		}
	}
	else if (metaGroupId == MGI_SUBCOMPONENTS){
		for (		SubcomponentInfos::const_iterator iter = m_subcomponentInfos.begin();
					iter != m_subcomponentInfos.end();
					++iter){
			retVal.insert(iter->first);
		}
	}

	return retVal;
}


}//namespace icomp


