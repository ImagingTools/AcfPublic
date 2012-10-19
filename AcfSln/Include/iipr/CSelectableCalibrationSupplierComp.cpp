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


#include "iipr/CSelectableCalibrationSupplierComp.h"


// ACF includes
#include "i2d/ITransformation2d.h"


namespace iipr
{


// public methods

// reimplemented (i2d::ICalibrationProvider)

const i2d::ITransformation2d* CSelectableCalibrationSupplierComp::GetCalibration() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->GetPtr();
	}

	return NULL;
}


// protected methods

// reimplemented (iproc::TSupplierCompWrap)

int CSelectableCalibrationSupplierComp::ProduceObject(ProductType& result) const
{
	if (!m_calibrationCompFact.IsValid()){
		return WS_CRITICAL;
	}


	if (!result.IsValid()){
		result.SetPtr(m_calibrationCompFact.CreateInstance());
		if (!result.IsValid()){
			return WS_CRITICAL;
		}
	}

	if (m_multiCalibrationProviderCompPtr.IsValid() && m_calibrationSelectionCompPtr.IsValid()){
		int selectedIndex = m_calibrationSelectionCompPtr->GetSelectedOptionIndex();
		if (selectedIndex < 0){
			SendVerboseMessage("Calibration selection index invalid");

			return WS_ERROR;
		}

		int calibrationsCount = m_multiCalibrationProviderCompPtr->GetCalibrationsCount();
		if (selectedIndex >= calibrationsCount){
			return WS_ERROR;		
		}

		const i2d::ITransformation2d* outputCalibrationPtr = m_multiCalibrationProviderCompPtr->GetCalibration(selectedIndex);
		if (outputCalibrationPtr != NULL){
			if (result->CopyFrom(*outputCalibrationPtr)){
				return WS_OK;
			}
		}
		else{
			return WS_ERROR;
		}
	}

	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CSelectableCalibrationSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_calibrationSelectionModelCompPtr.IsValid()){
		RegisterSupplierInput(m_calibrationSelectionModelCompPtr.GetPtr());
	}

	if (m_multiCalibrationProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_multiCalibrationProviderModelCompPtr.GetPtr());
	}
}


void CSelectableCalibrationSupplierComp::OnComponentDestroyed()
{
	if (m_calibrationSelectionModelCompPtr.IsValid()){
		UnregisterSupplierInput(m_calibrationSelectionModelCompPtr.GetPtr());
	}

	if (m_multiCalibrationProviderModelCompPtr.IsValid()){
		UnregisterSupplierInput(m_multiCalibrationProviderModelCompPtr.GetPtr());
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace iipr

