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


#include "CScaleCalibrationEditorComp.h"
#include <iostream>
#include <imath/CVarVector.h>
#include <QtGui/qmessagebox.h>


namespace iqtcam
{


void CScaleCalibrationEditorComp::UpdateModel() const
{
	BaseClass::UpdateModel();

	imeas::INumericValue* model = dynamic_cast<imeas::INumericValue*>(GetModelPtr());
	if (model == NULL){
		return;
	}

	imath::CVarVector vec;
	vec.SetElementsCount(2, 0);
	vec.SetElement(0, ScaleXSpinBox->value());
	vec.SetElement(1, ScaleYSpinBox->value());

	model->SetValues(vec);
}


void CScaleCalibrationEditorComp::OnGuiCreated()
{
	connect(ScaleXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(OnValueChanged(double)));
	connect(ScaleYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(OnValueChanged(double)));

	if (!m_circleProviderPtr.IsValid()){
		CalibrationGroupBox->setVisible(false);
	}

	if (NominalRadiusSpinBox->value() == 0){
		CalibrateButton->setDisabled(true);
	}
}


void CScaleCalibrationEditorComp::UpdateGui(int)
{
	imeas::INumericValue* model = dynamic_cast<imeas::INumericValue*>(GetModelPtr());
	if (model == NULL){
		return;
	}

	imath::CVarVector vec = model->GetValues();
	if (vec.GetElementsCount() >= 2){
		ScaleYSpinBox->setValue(vec[1]);
	}
	if (vec.GetElementsCount() >= 1){
		ScaleXSpinBox->setValue(vec[0]);
	}
}


void CScaleCalibrationEditorComp::OnValueChanged(double)
{
	DoUpdateModel();
}


void CScaleCalibrationEditorComp::on_CalibrateButton_clicked()
{
	if (!m_circleProviderPtr.IsValid()){
		return;
	}

	double nominalRadius = NominalRadiusSpinBox->value();
	if (nominalRadius == 0){
		return; // avoid division by zero
	}

	for (int i = 0; i < m_circleProviderPtr->GetValuesCount(); i++){
		const imeas::INumericValue& value = m_circleProviderPtr->GetNumericValue(i);
		if (!value.IsValueTypeSupported(imeas::INumericValue::VTI_RADIUS)){
			continue;
		}

		imath::CVarVector vec = value.GetValues();
		if (vec.GetElementsCount() > 0){
			double scaleX = vec[2] / nominalRadius;
			double scaleY = scaleX;
			if (vec.GetElementsCount() > 3){
				scaleX = vec[3] / nominalRadius;
			}

			ScaleXSpinBox->setValue(scaleX);
			ScaleYSpinBox->setValue(scaleY);

			DoUpdateModel();

			break;
		}
	}
}


void CScaleCalibrationEditorComp::on_NominalRadiusSpinBox_valueChanged(double d)
{
	CalibrateButton->setDisabled(d == 0 || !m_circleProviderPtr.IsValid());
}

} // namespace iqtcam

