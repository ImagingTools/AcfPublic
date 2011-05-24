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


#include "iqt2d/CSelectableSceneExtenderComp.h"


// ACF includes
#include "imod/IModel.h"
#include "imod/IObserver.h"


namespace iqt2d
{


// reimplemented (imod::IObserver)

bool CSelectableSceneExtenderComp::OnDetached(imod::IModel* modelPtr)
{
	DetachCurrent();

	return BaseClass2::OnDetached(modelPtr);
}


// reimplemented (iqt2d::ISceneExtender)

void CSelectableSceneExtenderComp::AddItemsToScene(iqt2d::ISceneProvider* providerPtr, int flags)
{
	I_ASSERT(providerPtr != NULL);

	m_connectedSceneFlags[providerPtr] = flags;

	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	int currentIndex = objectPtr->GetSelectedOptionIndex();

	if ((currentIndex >= 0) && (currentIndex < m_extendersCompPtr.GetCount())){
		iqt2d::ISceneExtender* extenderPtr = m_extendersCompPtr[currentIndex];
		if (extenderPtr != NULL){
			extenderPtr->AddItemsToScene(providerPtr, flags);
		}
	}
}


void CSelectableSceneExtenderComp::RemoveItemsFromScene(iqt2d::ISceneProvider* providerPtr)
{
	I_ASSERT(providerPtr != NULL);

	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	int currentIndex = objectPtr->GetSelectedOptionIndex();

	if ((currentIndex >= 0) && (currentIndex < m_extendersCompPtr.GetCount())){
		iqt2d::ISceneExtender* extenderPtr = m_extendersCompPtr[currentIndex];
		if (extenderPtr != NULL){
			extenderPtr->RemoveItemsFromScene(providerPtr);
		}
	}

	m_connectedSceneFlags.erase(providerPtr);
}


// protected methods

void CSelectableSceneExtenderComp::AttachCurrent()
{
	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	int currentIndex = objectPtr->GetSelectedOptionIndex();

	if (currentIndex >= 0 && currentIndex < m_extendersCompPtr.GetCount()){
		iqt2d::ISceneExtender* extenderPtr = m_extendersCompPtr[currentIndex];
		if (extenderPtr != NULL){
			for (		ConnectedSceneFlags::const_iterator sceneIter = m_connectedSceneFlags.begin();
						sceneIter != m_connectedSceneFlags.end();
						++sceneIter){
				iqt2d::ISceneProvider* providerPtr = sceneIter->first;
				I_ASSERT(providerPtr != NULL);

				extenderPtr->AddItemsToScene(providerPtr, sceneIter->second);
			}
		}
	}
}


void CSelectableSceneExtenderComp::DetachCurrent()
{
	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	int currentIndex = objectPtr->GetSelectedOptionIndex();

	if (currentIndex >= 0 && currentIndex < m_extendersCompPtr.GetCount()){
		iqt2d::ISceneExtender* extenderPtr = m_extendersCompPtr[currentIndex];
		if (extenderPtr != NULL){
			for (		ConnectedSceneFlags::const_iterator sceneIter = m_connectedSceneFlags.begin();
						sceneIter != m_connectedSceneFlags.end();
						++sceneIter){
				iqt2d::ISceneProvider* providerPtr = sceneIter->first;
				I_ASSERT(providerPtr != NULL);

				extenderPtr->RemoveItemsFromScene(providerPtr);
			}
		}
	}
}


// reimplemented (imod::CSingleModelObserverBase)

void CSelectableSceneExtenderComp::BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	if ((updateFlags & iprm::ISelectionParam::CF_SELECTION_CHANGED) != 0){
		DetachCurrent();
	}

	BaseClass2::BeforeUpdate(modelPtr, updateFlags, updateParamsPtr);
}


void CSelectableSceneExtenderComp::AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	if ((updateFlags & iprm::ISelectionParam::CF_SELECTION_CHANGED) != 0){
		AttachCurrent();
	}

	BaseClass2::AfterUpdate(modelPtr, updateFlags, updateParamsPtr);
}


} // namespace iqt2d


