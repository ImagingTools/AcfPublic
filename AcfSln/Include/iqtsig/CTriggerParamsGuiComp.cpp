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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtsig/CTriggerParamsGuiComp.h"


#include "istd/TChangeNotifier.h"

#include "isig/ITriggerConstraints.h"


namespace iqtsig
{


// reimplemented (imod::IModelEditor)

void CTriggerParamsGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	isig::ITriggerParams* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	int triggerMode = -1;

	if (NoTriggerRB->isChecked()){
		triggerMode = isig::ITriggerParams::TM_NONE;
	}
	else if (ContinuousRB->isChecked()){
		triggerMode = isig::ITriggerParams::TM_CONTINUOUS;
	}
	else if (RisingEdgeRB->isChecked()){
		triggerMode = isig::ITriggerParams::TM_RISING_EDGE;
	}
	else if (FallingEdgeRB->isChecked()){
		triggerMode = isig::ITriggerParams::TM_FALLING_EDGE;
	}
	else if (PositiveLevelRB->isChecked()){
		triggerMode = isig::ITriggerParams::TM_POSITIVE_LEVEL;
	}
	else if (NegativeLevelRB->isChecked()){
		triggerMode = isig::ITriggerParams::TM_NEGATIVE_LEVEL;
	}
	else if (SoftwareTriggerRB->isChecked()){
		triggerMode = isig::ITriggerParams::TM_SOFTWARE;
	}

	if ((triggerMode >= 0) && (triggerMode != objectPtr->GetTriggerMode())){
		istd::CChangeNotifier notifier(objectPtr);

		objectPtr->SetTriggerMode(triggerMode);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CTriggerParamsGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	I_ASSERT(IsGuiCreated());
	const isig::ITriggerParams* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	const isig::ITriggerConstraints* constraintsPtr = objectPtr->GetTriggerConstraints();
	if (constraintsPtr != NULL){
		NoTriggerRB->setVisible(constraintsPtr->IsTriggerModeSupported(isig::ITriggerParams::TM_NONE));
		ContinuousRB->setVisible(constraintsPtr->IsTriggerModeSupported(isig::ITriggerParams::TM_CONTINUOUS));
		RisingEdgeRB->setVisible(constraintsPtr->IsTriggerModeSupported(isig::ITriggerParams::TM_RISING_EDGE));
		FallingEdgeRB->setVisible(constraintsPtr->IsTriggerModeSupported(isig::ITriggerParams::TM_FALLING_EDGE));
		PositiveLevelRB->setVisible(constraintsPtr->IsTriggerModeSupported(isig::ITriggerParams::TM_POSITIVE_LEVEL));
		NegativeLevelRB->setVisible(constraintsPtr->IsTriggerModeSupported(isig::ITriggerParams::TM_NEGATIVE_LEVEL));
		SoftwareTriggerRB->setVisible(constraintsPtr->IsTriggerModeSupported(isig::ITriggerParams::TM_SOFTWARE));
	}
	else{
		NoTriggerRB->setVisible(true);
		ContinuousRB->setVisible(true);
		RisingEdgeRB->setVisible(true);
		FallingEdgeRB->setVisible(true);
		PositiveLevelRB->setVisible(true);
		NegativeLevelRB->setVisible(true);
		SoftwareTriggerRB->setVisible(true);
	}
}


void CTriggerParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	const isig::ITriggerParams* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		int triggerMode = objectPtr->GetTriggerMode();

		NoTriggerRB->setChecked(triggerMode == isig::ITriggerParams::TM_NONE);
		ContinuousRB->setChecked(triggerMode == isig::ITriggerParams::TM_CONTINUOUS);
		RisingEdgeRB->setChecked(triggerMode == isig::ITriggerParams::TM_RISING_EDGE);
		FallingEdgeRB->setChecked(triggerMode == isig::ITriggerParams::TM_FALLING_EDGE);
		PositiveLevelRB->setChecked(triggerMode == isig::ITriggerParams::TM_POSITIVE_LEVEL);
		NegativeLevelRB->setChecked(triggerMode == isig::ITriggerParams::TM_NEGATIVE_LEVEL);
		SoftwareTriggerRB->setChecked(triggerMode == isig::ITriggerParams::TM_SOFTWARE);
	}
}


// protected slots

void CTriggerParamsGuiComp::on_NoTriggerRB_toggled(bool /*state*/)
{
	DoUpdateModel();
}


void CTriggerParamsGuiComp::on_ContinuousRB_toggled(bool /*state*/)
{
	DoUpdateModel();
}


void CTriggerParamsGuiComp::on_RisingEdgeRB_toggled(bool /*state*/)
{
	DoUpdateModel();
}


void CTriggerParamsGuiComp::on_FallingEdgeRB_toggled(bool /*state*/)
{
	DoUpdateModel();
}


void CTriggerParamsGuiComp::on_PositiveLevelRB_toggled(bool /*state*/)
{
	DoUpdateModel();
}


void CTriggerParamsGuiComp::on_NegativeLevelRB_toggled(bool /*state*/)
{
	DoUpdateModel();
}


void CTriggerParamsGuiComp::on_SoftwareTriggerRB_toggled(bool /*state*/)
{
	DoUpdateModel();
}


} // namespace iqtsig


