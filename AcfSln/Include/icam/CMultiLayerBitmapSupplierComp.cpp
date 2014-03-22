/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "icam/CMultiLayerBitmapSupplierComp.h"


// ACF includes
#include "imod/TModelWrap.h"
#include "iprm/TParamsPtr.h"


namespace icam
{


// reimplemented (iimg::IMultiBitmapProvider)

int CMultiLayerBitmapSupplierComp::GetBitmapsCount() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->GetPtr()->GetBitmapsCount();
	}

	return 0;
}


const iimg::IBitmap* CMultiLayerBitmapSupplierComp::GetBitmap(int bitmapIndex) const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->GetPtr()->GetBitmap(bitmapIndex);
	}

	return NULL;
}


const iprm::IOptionsList* CMultiLayerBitmapSupplierComp::GetBitmapListInfo() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->GetPtr()->GetBitmapListInfo();
	}

	return NULL;
}


// protected methods

// reimplemented (iproc::TSupplierCompWrap)

bool CMultiLayerBitmapSupplierComp::InitializeWork()
{
	if (m_bitmapAcquisitionCompPtr.IsValid()){
		m_bitmapAcquisitionCompPtr->InitProcessor(GetModelParametersSet());

		return true;
	}

	return false;
}


int CMultiLayerBitmapSupplierComp::ProduceObject(ProductType& result) const
{
	if (!m_bitmapCompFact.IsValid()){
		return WS_CRITICAL;
	}

	result.Reset();

	if (!result.IsValid()){
		result.SetPtr(m_bitmapCompFact.CreateInstance());
		if (!result.IsValid()){
			return WS_CRITICAL;
		}
	}

	if (result.IsValid() && m_bitmapAcquisitionCompPtr.IsValid()){
		Timer performanceTimer(this, "Image acquisition");

		int status = m_bitmapAcquisitionCompPtr->DoProcessing(GetModelParametersSet(), NULL, result.GetPtr());
		switch (status){
			case iproc::IProcessor::TS_OK:
				return WS_OK;

			case iproc::IProcessor::TS_CANCELED:
				return WS_CANCELED;

			default:
				return WS_ERROR;
		}
	}

	return WS_CRITICAL;
}


} // namespace icam

