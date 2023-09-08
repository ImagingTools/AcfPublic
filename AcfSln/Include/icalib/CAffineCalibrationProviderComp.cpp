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


#include <icalib/CAffineCalibrationProviderComp.h>


namespace icalib
{


// public methods

// reimplemented (i2d::ICalibrationProvider)

const i2d::ICalibration2d* CAffineCalibrationProviderComp::GetCalibration() const
{
	return &m_affineCalibration;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CAffineCalibrationProviderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_rotationAngleCompPtr.IsValid() && m_rotationAngleModelCompPtr.IsValid()){
		BaseClass2::RegisterModel(m_rotationAngleModelCompPtr.GetPtr(), MI_ROTATION);
	}

	if (m_scaleCompPtr.IsValid() && m_scaleModelCompPtr.IsValid()){
		BaseClass2::RegisterModel(m_scaleModelCompPtr.GetPtr(), MI_SCALE);
	}

	if (m_translationCompPtr.IsValid() && m_translationModelCompPtr.IsValid()){
		BaseClass2::RegisterModel(m_translationModelCompPtr.GetPtr(), MI_TRANSLATION);
	}
}


void CAffineCalibrationProviderComp::OnComponentDestroyed()
{
	BaseClass2::UnregisterAllModels();

	BaseClass::OnComponentDestroyed();
}


// reimplemented (imod::CMultiModelDispatcherBase)

void CAffineCalibrationProviderComp::OnModelChanged(int modelId, const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	switch (modelId)
	{
	case MI_ROTATION:
	case MI_SCALE:
		UpdateMatrix();
		break;
	case MI_TRANSLATION:
		UpdateTranslation();
		break;
	default:
		break;
	}
}


// private methods

void CAffineCalibrationProviderComp::UpdateMatrix()
{
	istd::CChangeNotifier notifier(this);

	double angle = 0.0;
	if (m_rotationAngleCompPtr.IsValid()){
		imath::CVarVector values = m_rotationAngleCompPtr->GetValues();
		if (values.GetElementsCount() > 0){
			angle = qDegreesToRadians(values[0]);
		}
	}

	i2d::CVector2d scale(1.0, 1.0);

	if (m_scaleCompPtr.IsValid()){
		imath::CVarVector values = m_scaleCompPtr->GetValues();
		if (values.GetElementsCount() > 0){
			scale.SetX(values[0]);
		}

		if (values.GetElementsCount() > 1){
			scale.SetY(values[1]);
		}
	}

	i2d::CMatrix2d deform;
	deform.Reset(angle, scale);

	m_affineCalibration.GetTransformationRef().SetDeformMatrix(deform);
}


void CAffineCalibrationProviderComp::UpdateTranslation()
{
	istd::CChangeNotifier notifier(this);

	i2d::CVector2d traslation;

	if (m_translationCompPtr.IsValid()){
		imath::CVarVector values = m_translationCompPtr->GetValues();
		if (values.GetElementsCount() > 0){
			traslation.SetX(values[0]);
		}

		if (values.GetElementsCount() > 1){
			traslation.SetY(values[1]);
		}
	}

	m_affineCalibration.GetTransformationRef().SetTranslation(traslation);
}


} // namespace icalib


