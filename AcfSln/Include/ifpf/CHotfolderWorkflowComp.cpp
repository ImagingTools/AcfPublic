/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "ifpf/CHotfolderWorkflowComp.h"


// Qt includes
#include <QtCore/QStringList>
#include <QtCore/QMutexLocker>

// ACF includes
#include "istd/TChangeNotifier.h"
#include "istd/CStaticServicesProvider.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"
#include "iproc/IProcessor.h"


namespace ifpf
{


// public methods

CHotfolderWorkflowComp::CHotfolderWorkflowComp()
{
}


// reimplemented (ifpf::IHotfolderInfoManager)

ifpf::IHotfolderProcessingInfo* CHotfolderWorkflowComp::GetProcessingInfo(const QString& /*hotfolderName*/) const
{
	return NULL;
}


// reimplemented (ifpf::IHotfolderWorkflow)

ifpf::IHotfolderWorkflowItem* CHotfolderWorkflowComp::AddHotfolder(const QString& hotfolderName, const QString& hotfolderId)
{
	HotfolderItem* newHotfolderInfoPtr = CreateHotfolder(hotfolderName, hotfolderId);
	if (newHotfolderInfoPtr != NULL){
		istd::CChangeNotifier changePtr(this, CF_HOTFOLDER_ADDED);

		m_hotfolders.PushBack(newHotfolderInfoPtr);

		return newHotfolderInfoPtr->elementPtr.GetPtr();
	}

	return NULL;
}


bool CHotfolderWorkflowComp::RemoveHotfolder(const QString& /*hotfolderName*/)
{
	return true;
}


QStringList CHotfolderWorkflowComp::GetHotfolderIds() const
{
	QStringList hotfolderIds;

	if (m_hotoflderFactoryIdsAttrPtr.IsValid()){
		for (int index = 0; index < m_hotoflderFactoryIdsAttrPtr.GetCount(); index++){
			hotfolderIds.push_back(m_hotoflderFactoryIdsAttrPtr[index]);
		}
	}

	return hotfolderIds;
}


QStringList CHotfolderWorkflowComp::GetHotfolderList() const
{
	QStringList hotfolderList;

	for (int index = 0; index < m_hotfolders.GetCount(); index++){
		hotfolderList.push_back(m_hotfolders.GetAt(index)->elementPtr->GetName());
	}

	return hotfolderList;
}


ifpf::IHotfolderWorkflowItem* CHotfolderWorkflowComp::GetHotfolder(const QString& hotfolderName) const
{
	for (int index = 0; index < m_hotfolders.GetCount(); index++){
		HotfolderItem* infoPtr = m_hotfolders.GetAt(index);
		I_ASSERT(infoPtr != NULL);
		I_ASSERT(infoPtr->elementPtr != NULL);

		if (infoPtr->elementPtr->GetName() == hotfolderName){
			return infoPtr->elementPtr.GetPtr();
		}
	}

	return NULL;
}


// reimplemented (iser::ISerializable)

bool CHotfolderWorkflowComp::Serialize(iser::IArchive& /*archive*/)
{
	bool retVal = true;

	return retVal;
}


// protected methods
	
CHotfolderWorkflowComp::HotfolderItem* CHotfolderWorkflowComp::CreateHotfolder(const QString& hotfolderName, const QString& hotfolderId) const
{
	if (!m_hotoflderFactoriesCompPtr.IsValid()){
		return NULL;
	}

	if (!m_hotoflderFactoryIdsAttrPtr.IsValid()){
		return NULL;
	}

	istd::TDelPtr<HotfolderItem> newHotfolderItemPtr(new HotfolderItem());

	for (int factoryIndex = 0; factoryIndex < m_hotoflderFactoryIdsAttrPtr.GetCount(); factoryIndex++){
		if (hotfolderId == m_hotoflderFactoryIdsAttrPtr[factoryIndex]){
			if (factoryIndex < m_hotoflderFactoriesCompPtr.GetCount()){
				iprm::IParamsSet* hotfolderParamsPtr = m_hotoflderFactoriesCompPtr.CreateInstance(factoryIndex);
				if (hotfolderParamsPtr != NULL){
					newHotfolderItemPtr->hotfolderParamsPtr.SetPtr(hotfolderParamsPtr);

					newHotfolderItemPtr->elementPtr.SetPtr(CreateWorkflowItem(hotfolderId));

					newHotfolderItemPtr->elementPtr->SetName(hotfolderName);

					return newHotfolderItemPtr.PopPtr();
				}
			}
		}
	}

	return NULL;
}


ifpf::IHotfolderWorkflowItem* CHotfolderWorkflowComp::CreateWorkflowItem(const QString& hotfolderId) const
{
	ifpf::CHotfolderWorkflowItem* itemPtr = new ifpf::CHotfolderWorkflowItem();

	itemPtr->Initialize(hotfolderId, this);

	return itemPtr;
}


} // namespace ifpf


