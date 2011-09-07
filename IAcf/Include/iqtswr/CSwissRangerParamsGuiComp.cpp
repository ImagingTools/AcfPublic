/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iqtswr/CSwissRangerParamsGuiComp.h"


#include "istd/TChangeNotifier.h"

#include "iqt/CSignalBlocker.h"


namespace iqtswr
{


// reimplemented (imod::IModelEditor)

void CSwissRangerParamsGuiComp::UpdateModel() const
{
	I_ASSERT(IsGuiCreated());

	iswr::ISwissRangerParams* objectPtr = GetObjectPtr();
	I_ASSERT(objectPtr != NULL);

	istd::TChangeNotifier<iswr::ISwissRangerParams> changePtr(objectPtr);

	objectPtr->SetAmplitudeThreshold(AmplitudeThresholdSpin->value() / 100.0);
	objectPtr->SetModulationFrequencyMode(ModulationFrequencyModeCombo->currentIndex());
	objectPtr->SetMedianFilterEnabled(MedianFilterCheck->isChecked());
	objectPtr->SetAdaptiveFilterEnabled(AdaptiveFilterCheck->isChecked());
}


// reimplemented (iqtgui::TGuiObserverWrap)

void CSwissRangerParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	I_ASSERT(IsGuiCreated());

	iswr::ISwissRangerParams* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		iqt::CSignalBlocker block(GetWidget(), true);
		AmplitudeThresholdSpin->setValue(objectPtr->GetAmplitudeThreshold() * 100);
		ModulationFrequencyModeCombo->setCurrentIndex(objectPtr->GetModulationFrequencyMode());
		MedianFilterCheck->setChecked(objectPtr->IsMedianFilterEnabled());
		AdaptiveFilterCheck->setChecked(objectPtr->IsAdaptiveFilterEnabled());
	}
}



// reimplemented (iqtgui::CComponentBase)

void CSwissRangerParamsGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	connect(ModulationFrequencyModeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(OnModelChanged()));
	connect(AmplitudeThresholdSpin, SIGNAL(valueChanged(double)), this, SLOT(OnModelChanged()));
	connect(MedianFilterCheck, SIGNAL(stateChanged(int)), this, SLOT(OnModelChanged()));
}


// protected slots

void CSwissRangerParamsGuiComp::OnModelChanged()
{
	if (!IsUpdateBlocked()){
		UpdateBlocker blockUpdate(this);

		UpdateModel();
	}
}


} // namespace iqtswr


