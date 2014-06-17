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


#include "iqtprm/CEnableableParamGuiComp.h"


namespace iqtprm
{


// public methods

// reimplemented (imod::IModelEditor)

void CEnableableParamGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	iprm::IEnableableParam* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	UpdateBlocker updateBlocker(const_cast<CEnableableParamGuiComp*>(this));

	bool isEnabled = EnableableCheck->isChecked();
	if (isEnabled != objectPtr->IsEnabled()){
		istd::CChangeNotifier notifier(objectPtr);

		objectPtr->SetEnabled(isEnabled);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CEnableableParamGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	iprm::IEnableableParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		
		EnableableCheck->setChecked(objectPtr->IsEnabled());	
		EnableableCheck->setEnabled(objectPtr->IsEnablingAllowed());
	}
}


void CEnableableParamGuiComp::UpdateGui(int /*updateFlags*/)
{
	Q_ASSERT(IsGuiCreated());

	iprm::IEnableableParam* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		
		EnableableCheck->setChecked(objectPtr->IsEnabled());
		EnableableCheck->setEnabled(objectPtr->IsEnablingAllowed());		
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CEnableableParamGuiComp::OnGuiCreated()
{
	if (m_enableableLabelAttrPtr.IsValid()){
		EnableableCheck->setText(*m_enableableLabelAttrPtr);
	}

	BaseClass::OnGuiCreated();
}

void CEnableableParamGuiComp::OnGuiRetranslate()
{
	if (m_enableableLabelAttrPtr.IsValid()){
		EnableableCheck->setText(*m_enableableLabelAttrPtr);
	}
}

// protected slots

void CEnableableParamGuiComp::on_EnableableCheck_stateChanged(int /*state*/)
{
	DoUpdateModel();
}

} // namespace iqtprm


