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


#include "iipr/CEdgeDistancesSupplierComp.h"



namespace iipr
{


// reimplemented (imeas::INumericValueProvider)

int CEdgeDistancesSupplierComp::GetValuesCount() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->GetValuesCount();
	}

	return 0;
}


const imeas::INumericValue& CEdgeDistancesSupplierComp::GetNumericValue(int index) const
{
	I_ASSERT(index == 0);

	const ProductType* productPtr = GetWorkProduct();
	I_ASSERT(productPtr != NULL);

	return productPtr->GetNumericValue(index);
}


// protected methods

// reimplemented (iproc::TSupplierCompWrap)

int CEdgeDistancesSupplierComp::ProduceObject(ProductType& result) const
{
	result.ResetFeatures();

	if (		m_bitmapProviderCompPtr.IsValid() &&
				m_processorCompPtr.IsValid()){
		const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
		if (bitmapPtr != NULL){
			iprm::IParamsSet* paramsSetPtr = GetModelParametersSet();

			int processorState = m_processorCompPtr->DoProcessing(
							paramsSetPtr,
							bitmapPtr,
							&result);

			if (processorState != iproc::IProcessor::TS_OK){
				return WS_ERROR;
			}

			if (result.GetValuesCount() < 1){
				return WS_ERROR;
			}

			return WS_OK;
		}
	}

	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CEdgeDistancesSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr());
	}
}


} // namespace iipr


