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


#include <iipr/CProjectionSupplierComp.h>


namespace iipr
{


// public methods
	
// reimplemented (imeas::IDataSequenceProvider)

const imeas::IDataSequence* CProjectionSupplierComp::GetDataSequence() const
{
	return GetWorkProduct();
}


// protected methods

// reimplemented (iinsp::TSupplierCompWrap)

int CProjectionSupplierComp::ProduceObject(ProductType& result) const
{
	if (		m_bitmapProviderCompPtr.IsValid() &&
				m_projectionProcessorCompPtr.IsValid()){
		Timer performanceTimer(this, "Projection calculation");
		const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
		
		int processingState = m_projectionProcessorCompPtr->DoProcessing(GetModelParametersSet(), bitmapPtr, &result);
		switch (processingState){
			case iproc::IProcessor::TS_OK:
				return WS_OK;
			case iproc::IProcessor::TS_CANCELED:
				return WS_CANCELED;
			default:
				return WS_ERROR;
		}
	}

	SendCriticalMessage(0, "Bad component archtecture. Bitmap provider or projection processor were not set");
	
	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CProjectionSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr(), m_bitmapSupplierCompPtr.GetPtr());
	}
}


} // namespace iipr


