/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iqt2d/CCircleParamsGuiComp.h>


namespace iqt2d
{


// protected methods

void CCircleParamsGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	MoveToCenterButton->setVisible(m_centerScreenPointProviderCompPtr.IsValid());
}

// protected slots

void CCircleParamsGuiComp::OnParamsChanged(double /*value*/)
{
	DoUpdateModel();
}


void CCircleParamsGuiComp::OnActionTriggered(QAction* actionPtr)
{
	BaseClass::OnActionTriggered(actionPtr);
}

void CCircleParamsGuiComp::on_MoveToCenterButton_clicked(bool)
{
	i2d::CCircle* objectPtr = GetObservedObject();
	if (objectPtr != NULL && m_centerScreenPointProviderCompPtr.IsValid()) {
		i2d::CCircle screenCircle;
		screenCircle.CopyFrom(*objectPtr, istd::IChangeable::CompatibilityMode::CM_CONVERT);
		const i2d::CPosition2d* centerPtr = dynamic_cast<const i2d::CPosition2d*>(m_centerScreenPointProviderCompPtr->GetObject2d());
		if (centerPtr != NULL) {
			screenCircle.MoveCenterTo(centerPtr->GetCenter());
		}

		const i2d::ICalibration2d* calibrationPtr = objectPtr->GetCalibration();
		if (calibrationPtr != NULL) {
			i2d::CCircle centerCircle;
			screenCircle.GetInvTransformed(*calibrationPtr, centerCircle);
			objectPtr->SetPosition(centerCircle.GetPosition());
			objectPtr->SetRadius(centerCircle.GetRadius());
		}
		else {
			objectPtr->SetPosition(screenCircle.GetPosition());
			objectPtr->SetRadius(screenCircle.GetRadius());
		}
	}
}

} // namespace iqt2d


