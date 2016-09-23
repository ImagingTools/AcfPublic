/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <iqtcam/CScaleCalibrationEditorComp.h>


// STL includes
#include <iostream>

// Qt includes
#include<QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMessageBox>
#else
#include <QtGui/QMessageBox>
#endif

// ACF includes
#include <imath/CVarVector.h>
#include <iinsp/ISupplier.h>


namespace iqtcam
{


void CScaleCalibrationEditorComp::UpdateModel() const
{
	imeas::INumericValue* model = dynamic_cast<imeas::INumericValue*>(GetObservedModel());
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
	BaseClass::OnGuiCreated();

	connect(ScaleXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(OnValueChanged(double)));
	connect(ScaleYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(OnValueChanged(double)));

	if (!m_circleProviderCompPtr.IsValid()){
		CalibrationGroupBox->setVisible(false);
	}

	if (NominalRadiusSpinBox->value() == 0){
		CalibrateButton->setDisabled(true);
	}
}


void CScaleCalibrationEditorComp::UpdateGui(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	imeas::INumericValue* model = dynamic_cast<imeas::INumericValue*>(GetObservedModel());
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
	if (!m_circleProviderCompPtr.IsValid()){
		return;
	}

	double nominalRadius = NominalRadiusSpinBox->value();
	if (nominalRadius == 0){
		return; // avoid division by zero
	}

	if (m_calibrationDialogCompPtr.IsValid()){
		int retVal = m_calibrationDialogCompPtr->ExecuteDialog(this);
		if (retVal == QDialog::Rejected){
			return;
		}
	}

	iinsp::ISupplier* supplierPtr = dynamic_cast<iinsp::ISupplier*>(m_circleProviderCompPtr.GetPtr());
	if (supplierPtr != NULL){
		supplierPtr->InvalidateSupplier();
		supplierPtr->EnsureWorkInitialized();
		supplierPtr->EnsureWorkFinished();

		if (supplierPtr->GetWorkStatus() != iinsp::ISupplier::WS_OK){
			return;
		}
	}

	for (int i = 0; i < m_circleProviderCompPtr->GetValuesCount(); i++){
		const imeas::INumericValue& value = m_circleProviderCompPtr->GetNumericValue(i);
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
	CalibrateButton->setDisabled(d == 0 || !m_circleProviderCompPtr.IsValid());
}

} // namespace iqtcam

