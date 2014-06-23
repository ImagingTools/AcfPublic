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


// ACF includes
#include "icomp/CCompositeComponentStaticInfo.h"

	
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


const icomp::IComponentStaticInfo* CElementSelectionInfoManagerBase::GetComponentMetaInfo(const icomp::CComponentAddress& address) const
{
	AddressToInfoMap::ConstIterator foundInfoIter = m_adressToMetaInfoMap.constFind(address);
	if (foundInfoIter != m_adressToMetaInfoMap.constEnd()){
		return foundInfoIter.value().GetPtr();
	}

	return NULL;
}


const iser::IObject* CElementSelectionInfoManagerBase::GetAttributeObject(
			const QByteArray& attributeId,
			const icomp::IRegistry::ElementInfo& elementInfo) const
{
	const icomp::IComponentStaticInfo* componentInfoPtr = GetComponentMetaInfo(elementInfo.address);
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
	const icomp::IComponentStaticInfo* componentInfoPtr = GetComponentMetaInfo(elementInfo.address);
	if (componentInfoPtr == NULL){
		return NULL;
	}

	return componentInfoPtr->GetAttributeInfo(attributeId);
}


// protected methods

void CElementSelectionInfoManagerBase::UpdateAddressToMetaInfoMap()
{
	m_adressToMetaInfoMap.clear();

	const icomp::IComponentEnvironmentManager* metaInfoManagerPtr = GetMetaInfoManagerPtr();
	if (metaInfoManagerPtr == NULL){
		return;
	}

	const IElementSelectionInfo* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	const icomp::IRegistry* registryPtr = objectPtr->GetSelectedRegistry();
	if (registryPtr == NULL){
		return;
	}

	IElementSelectionInfo::Elements selectedElements = objectPtr->GetSelectedElements();
	for (		IElementSelectionInfo::Elements::const_iterator iter = selectedElements.begin();
				iter != selectedElements.end();
				++iter){
		const icomp::IRegistry::ElementInfo* selectedInfoPtr = iter.value();
		Q_ASSERT(selectedInfoPtr != NULL);

		const icomp::IRegistryElement* elementPtr = selectedInfoPtr->elementPtr.GetPtr();
		if (elementPtr != NULL){
			const icomp::CComponentAddress& componentAddress = selectedInfoPtr->address;

			istd::TOptDelPtr<const icomp::IComponentStaticInfo>& infoPtr = m_adressToMetaInfoMap[componentAddress];
			if (!componentAddress.GetPackageId().isEmpty()){
				const icomp::IComponentStaticInfo* staticInfoPtr = metaInfoManagerPtr->GetComponentMetaInfo(componentAddress);
				if (staticInfoPtr != NULL){
					infoPtr.SetPtr(staticInfoPtr, false);
				}
			}
			else{
				icomp::IRegistry* embeddedRegistryPtr = registryPtr->GetEmbeddedRegistry(componentAddress.GetComponentId());
				if (embeddedRegistryPtr != NULL){
					infoPtr.SetPtr(new icomp::CCompositeComponentStaticInfo(*embeddedRegistryPtr, *metaInfoManagerPtr), true);
				}
			}
		}
	}
}


// reimplemented (imod::CSingleModelObserverBase)

void CElementSelectionInfoManagerBase::OnUpdate(const istd::IChangeable::ChangeSet& changeSet)
{
	UpdateAddressToMetaInfoMap();

	BaseClass::OnUpdate(changeSet);
}


} // namespace icmpstr


