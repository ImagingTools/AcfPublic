/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iqtipr/CCircleFinderParamsGuiComp.h>


// ACF includes
#include <istd/CChangeNotifier.h>


namespace iqtipr
{


// protected methods

// reimplemented (iqtgui::TGuiObserverWrap)

void CCircleFinderParamsGuiComp::UpdateModel() const
{
	Q_ASSERT(IsGuiCreated());

	iipr::ICircleFinderParams* objectPtr = GetObservedObject();
	Q_ASSERT(objectPtr != NULL);

	objectPtr->SetOutlierEliminationEnabled(EnableOutliersElimination->isChecked());

	double distanceDisplayFactor = 1;

	const imath::IUnitInfo* unitInfoPtr = objectPtr->GetDistanceUnitInfo();
	if (unitInfoPtr != NULL){
		distanceDisplayFactor = unitInfoPtr->GetDisplayMultiplicationFactor();
	}

	objectPtr->SetMinOutlierDistance(MinOutliersDistance->value() / distanceDisplayFactor);
	objectPtr->SetCaliperMode(CaliperMode->currentIndex());

	if (MaxRaysCount->text() == MaxRaysCount->specialValueText()){
		objectPtr->SetRaysCount(-1);
	}
	else{
		objectPtr->SetRaysCount(MaxRaysCount->value());
	}
}


void CCircleFinderParamsGuiComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	Q_ASSERT(IsGuiCreated());

	bool isUnitVisible = false;

	iipr::ICircleFinderParams* objectPtr = GetObservedObject();
	if (objectPtr != NULL){
		bool useOutlier = objectPtr->IsOutlierEliminationEnabled();

		EnableOutliersElimination->setChecked(useOutlier);

		MinOutliersDistance->setVisible(useOutlier);
		MinOutliersDistanceLabel->setVisible(useOutlier);
		CaliperMode->setCurrentIndex(objectPtr->GetCaliperMode());

		double distanceDisplayFactor = 1;
		QString unitName;

		const imath::IUnitInfo* unitInfoPtr = objectPtr->GetDistanceUnitInfo();
		if (unitInfoPtr != NULL){
			unitName = unitInfoPtr->GetUnitName();
			distanceDisplayFactor = unitInfoPtr->GetDisplayMultiplicationFactor();
		}

		MinOutliersDistance->setValue(objectPtr->GetMinOutlierDistance() * distanceDisplayFactor);

		UnitLabel->setText(unitName);
		isUnitVisible = !unitName.isEmpty() && useOutlier;

		if (objectPtr->GetRaysCount() < 0){
			MaxRaysCount->setValue(MaxRaysCount->minimum());
		}
		else{
			MaxRaysCount->setValue(objectPtr->GetRaysCount());
		}
	}

	UnitLabel->setVisible(isUnitVisible);
}


// protected slots

void CCircleFinderParamsGuiComp::on_EnableOutliersElimination_toggled(bool /*value*/)
{
	DoUpdateModel();

	UpdateGui(istd::IChangeable::GetAllChanges());
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


