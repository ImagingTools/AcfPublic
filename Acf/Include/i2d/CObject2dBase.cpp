/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/CObject2dBase.h"


namespace i2d
{


CObject2dBase::CObject2dBase()
:	m_calibrationPtr(NULL)
{
}


CObject2dBase::CObject2dBase(const CObject2dBase& object2d)
:	m_calibrationPtr(object2d.m_calibrationPtr)
{
}


void CObject2dBase::SetCalibration(const ICalibration2d* calibrationPtr)
{
	m_calibrationPtr = calibrationPtr;
}


// reimplemented (i2d::ICalibrationProvider)

const ICalibration2d* CObject2dBase::GetCalibration() const
{
	return m_calibrationPtr;
}


// reimplemented (i2d::IObject2d)

bool CObject2dBase::Transform(
			const ITransformation2d& /*transformation*/,
			ITransformation2d::ExactnessMode /*mode*/,
			double* /*errorFactorPtr*/)
{
	return false;
}


bool CObject2dBase::InvTransform(
			const ITransformation2d& /*transformation*/,
			ITransformation2d::ExactnessMode /*mode*/,
			double* /*errorFactorPtr*/)
{
	return false;
}


bool CObject2dBase::GetTransformed(
			const ITransformation2d& /*transformation*/,
			IObject2d& /*result*/,
			ITransformation2d::ExactnessMode /*mode*/,
			double* /*errorFactorPtr*/) const
{
	return false;
}


bool CObject2dBase::GetInvTransformed(
			const ITransformation2d& /*transformation*/,
			IObject2d& /*result*/,
			ITransformation2d::ExactnessMode /*mode*/,
			double* /*errorFactorPtr*/) const
{
	return false;
}


// reimplemented (istd::IChangeable)

bool CObject2dBase::CopyFrom(const istd::IChangeable& object, CompatibilityMode mode)
{
	bool retVal = true;

	const CObject2dBase* object2dPtr = dynamic_cast<const CObject2dBase*>(&object);
	if (object2dPtr != NULL){
		switch (mode){
		case CM_STRICT:
			if (m_calibrationPtr != object2dPtr->m_calibrationPtr){
				return false;
			}
			break;

		case CM_WITH_REFS:
			m_calibrationPtr = object2dPtr->m_calibrationPtr;
			break;

		case CM_CONVERT:
			if (object2dPtr->m_calibrationPtr != NULL){
				retVal = Transform(*object2dPtr->m_calibrationPtr) && retVal;
			}

			if (m_calibrationPtr != NULL){
				retVal = InvTransform(*m_calibrationPtr) && retVal;
			}

			break;

		default:
			break;
		}
	}

	return retVal;
}


} // namespace i2d


