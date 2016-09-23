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


#include <iipr/CImageHistogramSupplierComp.h>


namespace iipr
{


// public methods

// reimplemented (imeas::IDataSequenceProvider)

const imeas::IDataSequence* CImageHistogramSupplierComp::GetDataSequence() const
{
	(const_cast<CImageHistogramSupplierComp*>(this))->EnsureWorkInitialized();

	return GetWorkProduct();
}


// protected methods

// reimplemented (iinsp::TSupplierCompWrap)

int CImageHistogramSupplierComp::ProduceObject(imod::TModelWrap<imeas::CSimpleSamplesSequence32>& result) const
{
	if (		m_bitmapProviderCompPtr.IsValid() &&
				m_histogramProcessorCompPtr.IsValid()){
		const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
		if (bitmapPtr == NULL){
			AddMessage(new ilog::CMessage(ilog::CMessage::IC_ERROR, 0, QObject::tr("No input image"), "ImageHistogram"));

			return WS_ERROR;
		}

		Timer performanceTimer(this, "Histogram calculation");
		Q_UNUSED(performanceTimer);

		int processingState = m_histogramProcessorCompPtr->DoProcessing(
						GetModelParametersSet(),
						bitmapPtr,
						&result);

		if (processingState != iproc::IProcessor::TS_OK){
			return WS_ERROR;
		}

		return WS_OK;
	}

	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CImageHistogramSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr(), m_bitmapSupplierCompPtr.GetPtr());
	}
}


void CImageHistogramSupplierComp::OnComponentDestroyed()
{
	BaseClass::OnComponentDestroyed();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		UnregisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr());
	}
}


} // namespace iipr


