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


#include <iipr/CEdgeDistancesSupplierComp.h>


// ACF includes
#include <ilog/CMessage.h>


namespace iipr
{


// reimplemented (iipr::IFeaturesProvider)

int CEdgeDistancesSupplierComp::GetFeaturesCount() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->GetFeaturesCount();
	}

	return 0;
}


const imeas::INumericValue& CEdgeDistancesSupplierComp::GetFeature(int index) const
{
	Q_ASSERT(index == 0);

	const ProductType* productPtr = GetWorkProduct();
	Q_ASSERT(productPtr != NULL);

	return productPtr->GetFeature(index);
}


// protected methods

// reimplemented (iinsp::TSupplierCompWrap)

iinsp::ISupplier::WorkStatus CEdgeDistancesSupplierComp::ProduceObject(ProductType& result) const
{
	result.ResetFeatures();

	if (		m_bitmapProviderCompPtr.IsValid() &&
				m_processorCompPtr.IsValid()){
		const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
		if (bitmapPtr == NULL){
			AddMessage(new ilog::CMessage(ilog::CMessage::IC_ERROR, 0, QObject::tr("No input image"), "EdgeDistances"));

			return WS_FAILED;
		}

		iprm::IParamsSet* paramsSetPtr = GetModelParametersSet();

		Timer performanceTimer(this, "Distance calculation");

		int processorState = m_processorCompPtr->DoProcessing(
						paramsSetPtr,
						bitmapPtr,
						&result);

		if (processorState != iproc::IProcessor::TS_OK){
			return WS_FAILED;
		}

		if (result.GetFeaturesCount() < 1){
			return WS_FAILED;
		}

		return WS_OK;
	}

	return WS_FAILED;
}


// reimplemented (icomp::CComponentBase)

void CEdgeDistancesSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr(), m_bitmapSupplierCompPtr.GetPtr());
	}
}


} // namespace iipr


