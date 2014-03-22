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


#include "iqtipr/CCircleFinderParamsGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqtipr
{


// reimplemented (imod::IModelEditor)

void CCircleFinderParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	iipr::ICircleFinderParams* objectPtr = GetObjectPtr();
	Q_ASSERT(objectPtr != NULL);

	objectPtr->SetOutlierEliminationEnabled(EnableOutliersElimination->isChecked());
	objectPtr->SetMinOutlierDistance(MinOutliersDistance->value());
	objectPtr->SetCaliperMode(CaliperMode->currentIndex());

	if (MaxRaysCount->text() == MaxRaysCount->specialValueText()){
		objectPtr->SetRaysCount(-1);
	}
	else{
		objectPtr->SetRaysCount(MaxRaysCount->value());
	}
}


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CCircleFinderParamsGuiComp::UpdateGui(int /*updateFlags*/)
{
	Q_ASSERT(IsGuiCreated());

	iipr::ICircleFinderParams* objectPtr = GetObjectPtr();
	if (objectPtr != NULL){
		EnableOutliersElimination->setChecked(objectPtr->IsOutlierEliminationEnabled());

		MinOutliersDistance->setVisible(objectPtr->IsOutlierEliminationEnabled());
		MinOutliersDistanceLabel->setVisible(objectPtr->IsOutlierEliminationEnabled());
		CaliperMode->setCurrentIndex(objectPtr->GetCaliperMode());

		MinOutliersDistance->setValue(objectPtr->GetMinOutlierDistance());

		if (objectPtr->GetRaysCount() < 0){
			MaxRaysCount->setValue(MaxRaysCount->minimum());
		}
		else{
			MaxRaysCount->setValue(objectPtr->GetRaysCount());
		}
	}
}


// protected slots

void CCircleFinderParamsGuiComp::on_EnableOutliersElimination_toggled(bool /*value*/)
{
	DoUpdateModel();
}


void CCircleFinderParamsGuiComp::on_MinOutliersDistance_valueChanged(double /*value*/)
{
	DoUpdateModel();
}


void CCircleFinderParamsGuiComp::on_MaxRaysCount_valueChanged(int /*value*/)
{
	DoUpdateModel();
}


void CCircleFinderParamsGuiComp::on_CaliperMode_currentIndexChanged(int /*index*/)
{
	DoUpdateModel();
}


} // namespace iqtipr


