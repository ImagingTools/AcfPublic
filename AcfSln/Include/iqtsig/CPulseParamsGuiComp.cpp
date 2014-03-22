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


#include "iqtsig/CPulseParamsGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

// ACF-Solutions includes
#include "isig/IPulseConstraints.h"


namespace iqtsig
{


// reimplemented (imod::IModelEditor)

void CPulseParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	isig::IPulseParams* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	if (DelayTimeSB->isVisible() && (DelayTimeSB->value() / 1000.0 != objectPtr->GetDelayTime())){
		objectPtr->SetDelayTime(DelayTimeSB->value() / 1000.0);
	}
	if (PulseTimeSB->isVisible() && (PulseTimeSB->value() / 1000.0 != objectPtr->GetPulseDuration())){
		objectPtr->SetPulseDuration(PulseTimeSB->value() / 1000.0);
	}
	if (RelaxingTimeSB->isVisible() && (RelaxingTimeSB->value() / 1000.0 != objectPtr->GetRelaxingTime())){
		objectPtr->SetRelaxingTime(RelaxingTimeSB->value() / 1000.0);
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CPulseParamsGuiComp::OnGuiModelAttached()
{
	BaseClass::OnGuiModelAttached();

	Q_ASSERT(IsGuiCreated());
	const isig::IPulseParams* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	istd::CRange delayTimeRange(0, 0.1);
	istd::CRange pulseTimeRange(0, 0.1);
	istd::CRange relaxingTimeRange(0, 0.1);

	int supportedFlags = isig::IPulseConstraints::PSF_PULSE_DURATION;

	const isig::IPulseConstraints* constraintsPtr = objectPtr->GetPulseConstraints();
	if (constraintsPtr != NULL){
		supportedFlags = constraintsPtr->GetPulseSupportedFlags();
		delayTimeRange = constraintsPtr->GetDelayTimeRange();
		pulseTimeRange = constraintsPtr->GetPulseDurationRange();
		relaxingTimeRange = constraintsPtr->GetRelaxingTimeRange();
	}

	bool hasDelayTime = (supportedFlags && isig::IPulseConstraints::PSF_DELAY_TIME);
	DelayTimeLabel->setVisible(hasDelayTime);
	DelayTimeSB->setVisible(hasDelayTime);
	DelayTimeUnitLabel->setVisible(hasDelayTime);
	if (hasDelayTime){
		DelayTimeSB->setMinimum(delayTimeRange.GetMinValue() * 1000);
		DelayTimeSB->setMaximum(delayTimeRange.GetMaxValue() * 1000);
	}

	bool hasPulseTime = (supportedFlags && isig::IPulseConstraints::PSF_PULSE_DURATION);
	PulseTimeLabel->setVisible(hasPulseTime);
	PulseTimeSB->setVisible(hasPulseTime);
	PulseTimeUnitLabel->setVisible(hasPulseTime);
	if (hasPulseTime){
		PulseTimeSB->setMinimum(pulseTimeRange.GetMinValue() * 1000);
		PulseTimeSB->setMaximum(pulseTimeRange.GetMaxValue() * 1000);
	}

	bool hasRelaxingTime = (supportedFlags && isig::IPulseConstraints::PSF_RELAXING_TIME);
	RelaxingTimeLabel->setVisible(hasRelaxingTime);
	RelaxingTimeSB->setVisible(hasRelaxingTime);
	RelaxingTimeUnitLabel->setVisible(hasRelaxingTime);
	if (hasRelaxingTime){
		RelaxingTimeSB->setMinimum(relaxingTimeRange.GetMinValue() * 1000);
		RelaxingTimeSB->setMaximum(relaxingTimeRange.GetMaxValue() * 1000);
	}
}


void CPulseParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	Q_ASSERT(IsGuiCreated());

	const isig::IPulseParams* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		DelayTimeSB->setValue(objectPtr->GetDelayTime() * 1000);
		PulseTimeSB->setValue(objectPtr->GetPulseDuration() * 1000);
		RelaxingTimeSB->setValue(objectPtr->GetRelaxingTime() * 1000);
	}
}


// protected slots

void CPulseParamsGuiComp::on_DelayTimeSB_valueChanged(double /*value*/)
{
	DoUpdateModel();
}


void CPulseParamsGuiComp::on_PulseTimeSB_valueChanged(double /*value*/)
{
	DoUpdateModel();
}


void CPulseParamsGuiComp::on_RelaxingTimeSB_valueChanged(double /*value*/)
{
	DoUpdateModel();
}


} // namespace iqtsig


