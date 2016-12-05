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


#include <icam/CSnapBitmapSupplierCompBase.h>

// ACF includes
#include <imod/TModelWrap.h>
#include <imath/CGeneralUnitInfo.h>
#include <i2d/CAffineCalibration2d.h>
#include <iprm/TParamsPtr.h>


// ACF-Solutions includes
#include <icam/CCalibratedCameraComp.h>


namespace icam
{


// public methods

// reimplemented (iimg::IBitmapProvider)

const iimg::IBitmap* CSnapBitmapSupplierCompBase::GetBitmap() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->second.GetPtr();
	}

	return NULL;
}


// reimplemented (i2d::ICalibrationProvider)

const i2d::ICalibration2d* CSnapBitmapSupplierCompBase::GetCalibration() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->first.GetPtr();
	}

	return NULL;
}


// protected methods

// reimplemented (iinsp::TSupplierCompWrap)

bool CSnapBitmapSupplierCompBase::InitializeWork()
{
	if (m_bitmapAcquisitionCompPtr.IsValid()){
		m_bitmapAcquisitionCompPtr->InitProcessor(GetModelParametersSet());

		return true;
	}

	return false;
}


int CSnapBitmapSupplierCompBase::ProduceObject(ProductType& result) const
{
	result.first.Reset();

	if (!m_bitmapAcquisitionCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component architecture, 'BitmapAcquisition' component reference is not set");

		return WS_CRITICAL;
	}

	if (!result.second.IsValid()){
		result.second.SetPtr(CreateBitmap());
		if (!result.second.IsValid()){
			SendErrorMessage(0, "Bitmap instance could not be created");

			return WS_ERROR;
		}
	}

	Timer performanceTimer(this, "Image acquisition");

	int status = m_bitmapAcquisitionCompPtr->DoProcessing(GetModelParametersSet(), NULL, result.second.GetPtr());
	switch (status){
		case iproc::IProcessor::TS_OK:
			{
				istd::CIndex2d bitmapSize = result.second->GetImageSize();
				i2d::CVector2d center(bitmapSize.GetX() * 0.5, bitmapSize.GetY() * 0.5);

				iprm::TParamsPtr<i2d::ICalibration2d> calibrationPtr(GetModelParametersSet(), m_calibrationIdAttrPtr, m_defaultCalibrationCompPtr, false);
				if (calibrationPtr.IsValid()){
					result.first.SetCastedOrRemove(calibrationPtr->CloneMe());
				}
				else{
					result.first.Reset();
				}
			}
			return WS_OK;

		case iproc::IProcessor::TS_CANCELED:
			return WS_CANCELED;

		default:
			return WS_ERROR;
	}

	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CSnapBitmapSupplierCompBase::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	// initialize components
	m_bitmapAcquisitionCompPtr.EnsureInitialized();
	m_defaultCalibrationCompPtr.EnsureInitialized();
}


} // namespace icam


