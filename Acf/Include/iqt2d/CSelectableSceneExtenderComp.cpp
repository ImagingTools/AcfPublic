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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt2d/CSelectableSceneExtenderComp.h"


// ACF includes
#include "imod/IModel.h"
#include "imod/IObserver.h"


namespace iqt2d
{


CSelectableSceneExtenderComp::CSelectableSceneExtenderComp()
	:m_currentSelectedIndex(-1)	
{
}


// reimplemented (imod::IObserver)

bool CSelectableSceneExtenderComp::OnAttached(imod::IModel* modelPtr)
{
	if (BaseClass2::OnAttached(modelPtr)){
		AttachCurrent();

		return true;
	}

	return false;
}


bool CSelectableSceneExtenderComp::OnDetached(imod::IModel* modelPtr)
{
	DetachCurrent();

	return BaseClass2::OnDetached(modelPtr);
}


// reimplemented (iqt2d::IViewExtender)

void CSelectableSceneExtenderComp::AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags)
{
	I_ASSERT(providerPtr != NULL);

	m_connectedSceneFlags[providerPtr] = flags;

	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	int currentIndex = objectPtr->GetSelectedOptionIndex();

	if ((currentIndex >= 0) && (currentIndex < m_extendersCompPtr.GetCount())){
		iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[currentIndex];
		if (extenderPtr != NULL){
			extenderPtr->AddItemsToScene(providerPtr, flags);
		}
	}
}


void CSelectableSceneExtenderComp::RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr)
{
	I_ASSERT(providerPtr != NULL);

	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	int currentIndex = objectPtr->GetSelectedOptionIndex();

	if ((currentIndex >= 0) && (currentIndex < m_extendersCompPtr.GetCount())){
		iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[currentIndex];
		if (extenderPtr != NULL){
			extenderPtr->RemoveItemsFromScene(providerPtr);
		}
	}

	m_connectedSceneFlags.remove(providerPtr);
}


// protected methods

void CSelectableSceneExtenderComp::AttachCurrent()
{
	iprm::ISelectionParam* objectPtr = GetObjectPtr();
	if (objectPtr == NULL){
		return;
	}

	DetachCurrent();

	int currentIndex = objectPtr->GetSelectedOptionIndex();
	m_currentSelectedIndex = currentIndex;

	if (currentIndex >= 0 && currentIndex < m_extendersCompPtr.GetCount()){
		iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[currentIndex];
		if (extenderPtr != NULL){
			for (		ConnectedSceneFlags::const_iterator sceneIter = m_connectedSceneFlags.begin();
						sceneIter != m_connectedSceneFlags.end();
						++sceneIter){
				iqt2d::IViewProvider* providerPtr = sceneIter.key();
				I_ASSERT(providerPtr != NULL);

				extenderPtr->AddItemsToScene(providerPtr, sceneIter.value());
			}
		}
	}
}


void CSelectableSceneExtenderComp::DetachCurrent()
{
	if (m_currentSelectedIndex >= 0 && m_currentSelectedIndex < m_extendersCompPtr.GetCount()){
		iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[m_currentSelectedIndex];
		if (extenderPtr != NULL){
			for (		ConnectedSceneFlags::const_iterator sceneIter = m_connectedSceneFlags.begin();
						sceneIter != m_connectedSceneFlags.end();
						++sceneIter){
				iqt2d::IViewProvider* providerPtr = sceneIter.key();
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


