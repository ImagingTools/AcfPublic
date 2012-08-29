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


#include "iqtprm/CComboParamsManagerGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "istd/CChangeDelegator.h"

#include "iprm/IParamsSet.h"


namespace iqtprm
{


// public methods

CComboParamsManagerGuiComp::CComboParamsManagerGuiComp()
:	m_lastConnectedModelPtr(NULL)
{
}


// protected methods

void CComboParamsManagerGuiComp::UpdateParamsView(int selectedIndex)
{
	imod::IModel* modelPtr = NULL;

	iprm::IParamsManager* objectPtr = GetObjectPtr();
	if (objectPtr != NULL && (selectedIndex >= 0)){
		I_ASSERT(selectedIndex < objectPtr->GetParamsSetsCount());

		if (m_paramsObserverCompPtr.IsValid()){
			modelPtr = dynamic_cast<imod::IModel*>(objectPtr->GetParamsSet(selectedIndex));
		}
	}

	if (modelPtr != m_lastConnectedModelPtr){
		EnsureParamsGuiDetached();

		bool paramsFrameVisible = false;

		if (modelPtr != NULL){
			I_ASSERT(!modelPtr->IsAttached(m_paramsObserverCompPtr.GetPtr()));
				
			if (modelPtr->AttachObserver(m_paramsObserverCompPtr.GetPtr())){
				m_lastConnectedModelPtr = modelPtr;

				paramsFrameVisible = true;
			}
		}

		ParamsFrame->setVisible(paramsFrameVisible);
	}

	if (selectedIndex == -1){
		ParamsFrame->setVisible(false);
	}
}


void CComboParamsManagerGuiComp::EnsureParamsGuiDetached()
{
	if (m_paramsObserverCompPtr.IsValid() && (m_lastConnectedModelPtr != NULL)){
		if (m_paramsObserverCompPtr->IsModelAttached(m_lastConnectedModelPtr)){
			m_lastConnectedModelPtr->DetachObserver(m_paramsObserverCompPtr.GetPtr());
		}
	}

	m_lastConnectedModelPtr = NULL;
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CComboParamsManagerGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	// Attach selector to the model
	imod::IModel* modelPtr = GetModelPtr();
	if (modelPtr != NULL && m_selectionObserverCompPtr.IsValid()){
		modelPtr->AttachObserver(m_selectionObserverCompPtr.GetPtr());
	}
}


void CComboParamsManagerGuiComp::OnGuiModelDetached()
{
	EnsureParamsGuiDetached();

	// Detach selector from the model
	imod::IModel* modelPtr = GetModelPtr();
	if (modelPtr != NULL && m_selectionObserverCompPtr.IsValid() && modelPtr->IsAttached(m_selectionObserverCompPtr.GetPtr())){
		modelPtr->DetachObserver(m_selectionObserverCompPtr.GetPtr());
	}
	
	BaseClass::OnGuiModelDetached();
}


void CComboParamsManagerGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	int selectedIndex = -1;

	iprm::IParamsManager* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		selectedIndex = objectPtr->GetSelectedOptionIndex();
	}

	UpdateParamsView(selectedIndex);
}


// reimplemented (iqtgui::CComponentBase)

void CComboParamsManagerGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	if (m_paramsGuiCompPtr.IsValid()){
		m_paramsGuiCompPtr->CreateGui(ParamsFrame);
	}

	if (m_selectionGuiCompPtr.IsValid()){
		m_selectionGuiCompPtr->CreateGui(SelectorFrame);
	}

	ParamsFrame->setVisible(false);
}


void CComboParamsManagerGuiComp::OnGuiDestroyed()
{
	if (m_paramsGuiCompPtr.IsValid()){
		m_paramsGuiCompPtr->DestroyGui();
	}

	if (m_selectionGuiCompPtr.IsValid()){
		m_selectionGuiCompPtr->DestroyGui();
	}

	BaseClass::OnGuiDestroyed();
}


} // namespace iqtprm


