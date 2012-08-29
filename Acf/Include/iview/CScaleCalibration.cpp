/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iview/CScaleCalibration.h"


namespace iview
{


CScaleCalibration::CScaleCalibration()
	:m_viewCenter(0, 0),
	m_scaleFactor(1.0)
{
}


void CScaleCalibration::Reset()
{
	istd::CChangeNotifier changeNotifier(this);

	m_viewCenter.Reset();

	m_scaleFactor = 1.0;
}


i2d::CAffine2d CScaleCalibration::GetLogToViewTransform() const
{
	i2d::CAffine2d result;

	GetLogToViewTransform(result);

	return result;
}


void CScaleCalibration::GetLogToViewTransform(i2d::CAffine2d& result) const
{
	result.Reset(m_viewCenter, 0, m_scaleFactor);
}


// reimplemented (i2d::ITransformation2d)

int CScaleCalibration::GetTransformationFlags() const
{
	return TF_FORWARD | TF_INVERTED | TF_INJECTIVE | TF_SURJECTIVE | TF_AFFINE | TF_CONTINUES;
}


bool CScaleCalibration::GetDistance(
			const i2d::CVector2d& origPos1,
			const i2d::CVector2d& origPos2,
			double& result,
			ExactnessMode /*mode*/) const
{
	if (qAbs(m_scaleFactor) > I_EPSILON){
		result = origPos1.GetDistance(origPos2) / m_scaleFactor;

		return true;
	}

	return false;
}


bool CScaleCalibration::GetPositionAt(const i2d::CVector2d& viewPosition, i2d::CVector2d& result, ExactnessMode /*mode*/) const
{
	if (qAbs(m_scaleFactor) > I_EPSILON){
		result = (viewPosition - m_viewCenter) / m_scaleFactor;

		return true;
	}

	return false;
}


bool CScaleCalibration::GetInvPositionAt(const i2d::CVector2d& logPosition, i2d::CVector2d& result, ExactnessMode /*mode*/) const
{
	result = logPosition * m_scaleFactor + m_viewCenter;

	return true;
}


bool CScaleCalibration::GetLocalTransform(const i2d::CVector2d& /*logPosition*/, i2d::CAffine2d& result, ExactnessMode /*mode*/) const
{
	result.Reset(i2d::CVector2d(0, 0), 0.0, m_scaleFactor);

	return true;
}


bool CScaleCalibration::GetLocalInvTransform(const i2d::CVector2d& /*viewPosition*/, i2d::CAffine2d& result, ExactnessMode /*mode*/) const
{
	if (qAbs(m_scaleFactor) > I_EPSILON){
		result.Reset(i2d::CVector2d(0, 0), 0, 1.0 / m_scaleFactor);

		return true;
	}

	return false;
}


const i2d::ITransformation2d* CScaleCalibration::CreateCombinedTransformation(const ITransformation2d& transform) const
{
	const CScaleCalibration* scaleTransformPtr = dynamic_cast<const CScaleCalibration*>(&transform);
	if (scaleTransformPtr != NULL){
		CScaleCalibration* combinedPtr = new CScaleCalibration();

		combinedPtr->SetScaleFactor(GetScaleFactor() * scaleTransformPtr->GetScaleFactor());

		return combinedPtr;
	}

	return NULL;
}


// reimplemented (imath::TISurjectFunction)

bool CScaleCalibration::GetInvValueAt(const i2d::CVector2d& argument, i2d::CVector2d& result) const
{
	return GetInvPositionAt(argument, result);
}


i2d::CVector2d CScaleCalibration::GetInvValueAt(const i2d::CVector2d& argument) const
{
	i2d::CVector2d retVal;
	
	GetInvValueAt(argument, retVal);

	return retVal;
}


// reimplemented (imath::TIMathFunction)

bool CScaleCalibration::GetValueAt(const i2d::CVector2d& argument, i2d::CVector2d& result) const
{
	return GetPositionAt(argument, result);
}


i2d::CVector2d CScaleCalibration::GetValueAt(const i2d::CVector2d& argument) const
{
	i2d::CVector2d retVal;
	
	GetValueAt(argument, retVal);

	return retVal;
}


// reimplemented (iser::ISerializable)

bool CScaleCalibration::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier changePtr(archive.IsStoring() ? NULL : this);

	bool retVal = m_viewCenter.Serialize(archive);
	retVal = retVal && archive.Process(m_scaleFactor);

	return retVal;
}


} // namespace iview


