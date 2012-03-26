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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CDelegatedBitmapSupplierComp.h"


namespace iipr
{


// reimplemented (iipr::IBitmapProvider)

const iimg::IBitmap* CDelegatedBitmapSupplierComp::GetBitmap() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->second;
	}

	return NULL;
}

	
// reimplemented (i2d::ICalibrationProvider)

const i2d::ITransformation2d* CDelegatedBitmapSupplierComp::GetCalibration() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->first;
	}
	else{
		return NULL;
	}
}


//protected methods

// reimplemented (iproc::TSupplierCompWrap)

int CDelegatedBitmapSupplierComp::ProduceObject(ProductType& result) const
{
	if (m_inputBitmapProviderCompPtr.IsValid()){
		result.first = NULL;
		result.second = m_inputBitmapProviderCompPtr->GetBitmap();

		if (m_calibrationProviderCompPtr.IsValid()){
			result.first = m_calibrationProviderCompPtr->GetCalibration();
		}

		if (result.second != NULL){
			return ISupplier::WS_OK;
		}
		else{
			return ISupplier::WS_ERROR;
		}
	}

	if (m_bitmapCompPtr.IsValid()){
		result.first = m_calibrationCompPtr.GetPtr();
		result.second = m_bitmapCompPtr.GetPtr();

		return ISupplier::WS_OK;
	}

	return ISupplier::WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CDelegatedBitmapSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_inputBitmapProviderCompPtr.IsValid()){
		if (m_inputBitmapProviderModelCompPtr.IsValid()){
			RegisterSupplierInput(m_inputBitmapProviderModelCompPtr.GetPtr());
		}
	}
	else{
		if (m_bitmapModelCompPtr.IsValid()){
			RegisterSupplierInput(m_bitmapModelCompPtr.GetPtr());
		}
		if (m_calibrationModelCompPtr.IsValid()){
			RegisterSupplierInput(m_calibrationModelCompPtr.GetPtr());
		}
	}
}


} // namespace iipr


