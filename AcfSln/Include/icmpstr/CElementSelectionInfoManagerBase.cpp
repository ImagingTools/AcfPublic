/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "icmpstr/CElementSelectionInfoManagerBase.h"


	
namespace icmpstr
{


// public methods

CElementSelectionInfoManagerBase::CElementSelectionInfoManagerBase()
{
}


icomp::IRegistry* CElementSelectionInfoManagerBase::GetRegistry() const
{
	const IElementSelectionInfo* selectionInfoPtr = GetObjectPtr();
	if (selectionInfoPtr == NULL){
		return NULL;
	}

	return selectionInfoPtr->GetSelectedRegistry();
}


QStringList CElementSelectionInfoManagerBase::GetExportAliases(const QByteArray& attributeName) const
{
	const IElementSelectionInfo* selectionInfoPtr = GetObjectPtr();
	if (selectionInfoPtr == NULL){
		return QStringList();
	}

	QStringList exportedAliases;

	const icomp::IRegistry* registryPtr = selectionInfoPtr->GetSelectedRegistry();
	if (registryPtr != NULL){
		const icomp::IRegistry::ExportedElementsMap& exportedMap = registryPtr->GetExportedElementsMap();
		for (		icomp::IRegistry::ExportedElementsMap::const_iterator iter = exportedMap.begin();
					iter != exportedMap.end();
					++iter){
			if (iter.value() == attributeName){
				exportedAliases.append(iter.key());
			}
		}
	}

	return exportedAliases;
}


const iser::IObject* CElementSelectionInfoManagerBase::GetAttributeObject(
			const QByteArray& attributeId,
			const icomp::IRegistry::ElementInfo& elementInfo) const
{
	const icomp::IMetaInfoManager* metaInfoManagerPtr = GetMetaInfoManagerPtr();
	if (metaInfoManagerPtr == NULL){
		return NULL;
	}

	const icomp::IComponentStaticInfo* componentInfoPtr = metaInfoManagerPtr->GetComponentMetaInfo(elementInfo.address);
	if (componentInfoPtr == NULL){
		return NULL;
	}

	const icomp::IAttributeStaticInfo* staticInfoPtr = componentInfoPtr->GetAttributeInfo(attributeId);

	const iser::IObject* attributePtr = NULL;
	const icomp::IRegistryElement::AttributeInfo* attributeInfoPtr = elementInfo.elementPtr->GetAttributeInfo(attributeId);
	if ((attributeInfoPtr != NULL) && attributeInfoPtr->attributePtr.IsValid()){
		attributePtr = attributeInfoPtr->attributePtr.GetPtr();
	}
	else if (staticInfoPtr != NULL){
		attributePtr = staticInfoPtr->GetAttributeDefaultValue();
	}

	return attributePtr;
}


const icomp::IAttributeStaticInfo* CElementSelectionInfoManagerBase::GetAttributeStaticInfo(
			const QByteArray& attributeId,
			const icomp::IRegistry::ElementInfo& elementInfo) const
{
	const icomp::IMetaInfoManager* metaInfoManagerPtr = GetMetaInfoManagerPtr();
	if (metaInfoManagerPtr == NULL){
		return NULL;
	}

	const icomp::IComponentStaticInfo* componentInfoPtr = metaInfoManagerPtr->GetComponentMetaInfo(elementInfo.address);
	if (componentInfoPtr == NULL){
		return NULL;
	}

	return componentInfoPtr->GetAttributeInfo(attributeId);
}


} // namespace icmpstr


