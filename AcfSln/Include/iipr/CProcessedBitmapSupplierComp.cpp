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


#include <iipr/CProcessedBitmapSupplierComp.h>


// ACF includes
#include <ilog/CMessage.h>


namespace iipr
{


// reimplemented (iimg::IBitmapProvider)

const iimg::IBitmap* CProcessedBitmapSupplierBase::GetBitmap() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->GetPtr();
	}

	return NULL;
}


//protected methods

bool CProcessedBitmapSupplierBase::EnsureBitmapCreated(ProductType& result) const
{
	if (!result.IsValid()){
		result.SetPtr(CreateBitmap());
	}

	return result.IsValid();
}


iproc::IProcessor* CProcessedBitmapSupplierBase::GetImageProcessor() const
{
	return m_imageProcessorCompPtr.GetPtr();
}


// reimplemented (iinsp::TSupplierCompWrap)

int CProcessedBitmapSupplierBase::ProduceObject(ProductType& result) const
{
	iproc::IProcessor* imageProcessorPtr = GetImageProcessor();

	if (!m_bitmapProviderCompPtr.IsValid() || (imageProcessorPtr == NULL)){
		return WS_CRITICAL;
	}

	if (!EnsureBitmapCreated(result)){
		return WS_CRITICAL;
	}
	Q_ASSERT(result.IsValid());

	const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
	if (bitmapPtr == NULL){
		AddMessage(new ilog::CMessage(ilog::CMessage::IC_ERROR, 0, QObject::tr("No input image"), "BitmapProcessing"));

		return WS_ERROR;
	}

	Timer performanceTimer(this, "Bitmap processing");

	int status = imageProcessorPtr->DoProcessing(GetModelParametersSet(), bitmapPtr, result.GetPtr());
	switch (status){
		case iproc::IProcessor::TS_OK:
			return WS_OK;

		case iproc::IProcessor::TS_CANCELED:
			return WS_CANCELED;

		default:
			return WS_ERROR;
	}

	// should not get here
	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CProcessedBitmapSupplierBase::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr(), m_bitmapSupplierCompPtr.GetPtr());
	}

	m_bitmapProviderCompPtr.EnsureInitialized();
	m_imageProcessorCompPtr.EnsureInitialized();
}


} // namespace iipr


