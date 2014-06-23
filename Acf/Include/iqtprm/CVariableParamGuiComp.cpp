/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqtprm/CVariableParamGuiComp.h"


// ACF includes
#include "istd/CChangeNotifier.h"

#include "imod/IModel.h"
#include "imod/IObserver.h"

#include "iqt/CSignalBlocker.h"

#include "iview/IShapeView.h"

#include "iqt2d/IViewProvider.h"


namespace iqtprm
{


CVariableParamGuiComp::CVariableParamGuiComp()
:	m_lastParamModelPtr(NULL),
	m_currentTypeIndex(-1)
{
}


// reimplemented (imod::IObserver)

bool CVariableParamGuiComp::OnModelDetached(imod::IModel* modelPtr)
{
	if (BaseClass::OnModelDetached(modelPtr)){
		DetachCurrentType();

		return true;
	}

	return false;
}


// reimplemented (iqt2d::IViewExtender)

void CVariableParamGuiComp::AddItemsToScene(iqt2d::IViewProvider* providerPtr, int flags)
{
	Q_ASSERT(providerPtr != NULL);

	m_connectedSceneFlags[providerPtr] = flags;

	if ((m_currentTypeIndex >= 0) && (m_currentTypeIndex < m_extendersCompPtr.GetCount())){
		iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[m_currentTypeIndex];
		if (extenderPtr != NULL){
			extenderPtr->AddItemsToScene(providerPtr, flags);
		}
	}
}


void CVariableParamGuiComp::RemoveItemsFromScene(iqt2d::IViewProvider* providerPtr)
{
	Q_ASSERT(providerPtr != NULL);

	if ((m_currentTypeIndex >= 0) && (m_currentTypeIndex < m_extendersCompPtr.GetCount())){
		iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[m_currentTypeIndex];
		if (extenderPtr != NULL){
			extenderPtr->RemoveItemsFromScene(providerPtr);
		}
	}

	m_connectedSceneFlags.remove(providerPtr);
}


// protected methods

void CVariableParamGuiComp::AttachCurrentType()
{
	if (m_currentTypeIndex >= 0){
		iprm::IVariableParam* variableParamPtr = GetObjectPtr();
		if (variableParamPtr != NULL){
			imod::IModel* paramModelPtr = dynamic_cast<imod::IModel*>(variableParamPtr->GetParameter());
			if ((paramModelPtr != NULL) && (m_currentTypeIndex < m_observersCompPtr.GetCount())){
				imod::IObserver* observerPtr = m_observersCompPtr[m_currentTypeIndex];
				if ((observerPtr != NULL) && paramModelPtr->AttachObserver(observerPtr)){
					m_lastParamModelPtr = paramModelPtr;
				}
			}
		}

		if (m_currentTypeIndex < m_guisCompPtr.GetCount()){
			iqtgui::IGuiObject* guiPtr = m_guisCompPtr[m_currentTypeIndex];
			if (guiPtr != NULL){
				guiPtr->CreateGui(ParamFrame);
			}
		}

		if (m_currentTypeIndex < m_extendersCompPtr.GetCount()){
			iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[m_currentTypeIndex];
			if (extenderPtr != NULL){
				for (		ConnectedSceneFlags::const_iterator sceneIter = m_connectedSceneFlags.begin();
							sceneIter != m_connectedSceneFlags.end();
							++sceneIter){
					iqt2d::IViewProvider* providerPtr = sceneIter.key();
					Q_ASSERT(providerPtr != NULL);

					extenderPtr->AddItemsToScene(providerPtr, sceneIter.value());
					iview::IShapeView* viewPtr = providerPtr->GetView();
					if (viewPtr != NULL){
						viewPtr->Update();
					}
				}
			}
		}
	}
}


void CVariableParamGuiComp::DetachCurrentType()
{
	if (m_currentTypeIndex >= 0){
		if ((m_currentTypeIndex >= 0) && (m_currentTypeIndex < m_extendersCompPtr.GetCount())){
			iqt2d::IViewExtender* extenderPtr = m_extendersCompPtr[m_currentTypeIndex];
			if (extenderPtr != NULL){
				for (		ConnectedSceneFlags::const_iterator sceneIter = m_connectedSceneFlags.begin();
							sceneIter != m_connectedSceneFlags.end();
							++sceneIter){
					iqt2d::IViewProvider* providerPtr = sceneIter.key();
					Q_ASSERT(providerPtr != NULL);

					extenderPtr->RemoveItemsFromScene(providerPtr);
					iview::IShapeView* viewPtr = providerPtr->GetView();
					if (viewPtr != NULL){
						viewPtr->Update();
					}
				}
			}
		}

		if (IsGuiCreated()){
			if (m_currentTypeIndex < m_guisCompPtr.GetCount()){
				iqtgui::IGuiObject* guiPtr = m_guisCompPtr[m_currentTypeIndex];
				if ((guiPtr != NULL) && guiPtr->IsGuiCreated()){
					guiPtr->DestroyGui();
				}
			}
		}

		if ((m_lastParamModelPtr != NULL) && (m_currentTypeIndex < m_observersCompPtr.GetCount())){
			imod::IObserver* observerPtr = m_observersCompPtr[m_currentTypeIndex];
			if ((observerPtr != NULL) && observerPtr->IsModelAttached(m_lastParamModelPtr)){
				m_lastParamModelPtr->DetachObserver(observerPtr);
			}
		}

		m_currentTypeIndex = -1;
		m_lastParamModelPtr = NULL;
	}
}


// reimplemented (iqtgui::TGuiObserverWrap)

void CVariableParamGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& changeSet)
{
	Q_ASSERT(IsGuiCreated());

	Q_ASSERT(m_currentTypeIndex < m_typeIdsAttrPtr.GetCount());

	iprm::IVariableParam* variableParamPtr = GetObjectPtr();
	if (variableParamPtr == NULL){
		return;
	}

	QByteArray currentId;
	if (m_currentTypeIndex >= 0){
		currentId = m_typeIdsAttrPtr[m_currentTypeIndex].toLocal8Bit();
	}

	QByteArray typeId = variableParamPtr->GetParameterTypeId();
	if (typeId != currentId){
		DetachCurrentType();

		int typeIdsCount = m_typeIdsAttrPtr.GetCount();
		for (int i = 0; i < typeIdsCount; ++i){
			if (typeId == m_typeIdsAttrPtr[i].toLocal8Bit()){
				m_currentTypeIndex = i;

				AttachCurrentType();

				break;
			}
		}
	}

	TypeSelectorCB->setCurrentIndex(m_currentTypeIndex);

	if (		(m_lastParamModelPtr != NULL) &&
				(m_currentTypeIndex >= 0) &&
				(m_currentTypeIndex < m_editorsCompPtr.GetCount())){
		imod::IModelEditor* editorPtr = m_editorsCompPtr[m_currentTypeIndex];
		if (editorPtr != NULL){
			editorPtr->UpdateEditor(changeSet);
		}
	}

	if (IsGuiCreated()){
		TypeSelectorCB->setVisible(m_currentTypeIndex < 0);
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CVariableParamGuiComp::OnGuiCreated()
{
	iqt::CSignalBlocker block(TypeSelectorCB);

	TypeSelectorCB->clear();

	int typeIdsCount = m_typeIdsAttrPtr.GetCount();
	for (int i = 0; i < typeIdsCount; ++i){
		QString typeName = (i < m_typeNamesAttrPtr.GetCount())? m_typeNamesAttrPtr[i]: m_typeIdsAttrPtr[i];
		TypeSelectorCB->addItem(typeName);
	}

	TypeSelectorCB->setCurrentIndex(m_currentTypeIndex);

	BaseClass::OnGuiCreated();
}


void CVariableParamGuiComp::OnGuiDestroyed()
{
	int elementsCount = m_guisCompPtr.GetCount();
	for (int i = 0; i < elementsCount; ++i){
		iqtgui::IGuiObject* guiPtr = m_guisCompPtr[i];

		if ((guiPtr != NULL) && guiPtr->IsGuiCreated()){
			guiPtr->DestroyGui();
		}
	}

	BaseClass::OnGuiDestroyed();
}


// protected slots

void CVariableParamGuiComp::on_TypeSelectorCB_currentIndexChanged(int index)
{
	if (index == m_currentTypeIndex){
		return;
	}

	iprm::IVariableParam* variableParamPtr = GetObjectPtr();
	if (variableParamPtr == NULL){
		return;
	}

	istd::CChangeNotifier notifier(variableParamPtr);

	if ((index >= 0) && (index < m_typeIdsAttrPtr.GetCount())){
		variableParamPtr->AssignTypeId(m_typeIdsAttrPtr[index].toLocal8Bit());
	}
}


} // namespace iqtprm


