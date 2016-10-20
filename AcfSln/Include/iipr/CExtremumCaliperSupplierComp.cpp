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


#include <iipr/CExtremumCaliperSupplierComp.h>


// ACF-Solutions includes
#include <imeas/CSimpleNumericValue.h>


namespace iipr
{


// public methods

// reimplemented (iipr::IFeaturesProvider)

int CExtremumCaliperSupplierComp::GetFeaturesCount() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL)
	{
		return productPtr->GetFeaturesCount();
	}

	return 0;
}


const imeas::INumericValue& CExtremumCaliperSupplierComp::GetFeature(int index) const
{
	static imeas::CSimpleNumericValue emptyValue;

	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL)
	{
		return productPtr->GetFeature(index);
	}

	return emptyValue;
}


// protected methods

// reimplemented (iinsp::TSupplierCompWrap)

int CExtremumCaliperSupplierComp::ProduceObject(ProductType& result) const
{
	if (		m_sequenceProviderCompPtr.IsValid() &&
				m_extremumProcessorCompPtr.IsValid()){
		Timer performanceTimer(this, "Extrema calculation");
		const imeas::IDataSequence* sequencePtr = m_sequenceProviderCompPtr->GetDataSequence();

		int processingState = m_extremumProcessorCompPtr->DoProcessing(GetModelParametersSet(), sequencePtr, &result);
		switch (processingState){
		case iproc::IProcessor::TS_OK:
			return WS_OK;

		case iproc::IProcessor::TS_CANCELED:
			return WS_CANCELED;

		default:
			return WS_ERROR;
		}
	}

	SendCriticalMessage(0, "Bad component archtecture. Data sequence provider or extremum processor were not set");
	
	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CExtremumCaliperSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_sequenceProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_sequenceProviderModelCompPtr.GetPtr(), m_sequenceSupplierCompPtr.GetPtr());
	}
}


} // namespace iipr


