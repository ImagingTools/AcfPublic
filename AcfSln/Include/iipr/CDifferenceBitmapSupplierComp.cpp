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


#include <iipr/CDifferenceBitmapSupplierComp.h>


// ACF includes
#include <imath/CFixedPointManip.h>
#include <ilog/CMessage.h>
#include <iprm/TParamsPtr.h>
#include <iimg/CPixelFormatList.h>
#include <iipr/CBitmapOperations.h>


namespace iipr
{


CDifferenceBitmapSupplierComp::CDifferenceBitmapSupplierComp()
{
	static imath::CFixedPointManip percentManip(3);

	imath::CGeneralUnitInfo unitInfo(imath::IUnitInfo::UT_RELATIVE, "%", 100, istd::CRange(0, 1), &percentManip);

	m_offsetContraints.InsertValueInfo(QObject::tr("Offset"), QObject::tr("Offset added to each pixel as percentage"), "Offset", unitInfo);
}


// reimplemented (iimg::IBitmapProvider)

const iimg::IBitmap* CDifferenceBitmapSupplierComp::GetBitmap() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->second.GetPtr();
	}

	return NULL;
}


// reimplemented (i2d::ICalibrationProvider)

const i2d::ICalibration2d* CDifferenceBitmapSupplierComp::GetCalibration() const
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

bool CDifferenceBitmapSupplierComp::EnsureBitmapCreated(ProductType& result) const
{
	if (!m_bitmapCompFact.IsValid()){
		return false;
	}

	if (!result.second.IsValid()){
		result.second.SetPtr(m_bitmapCompFact.CreateInstance());
	}

	return result.second.IsValid();
}


// reimplemented (iinsp::TSupplierCompWrap)

int CDifferenceBitmapSupplierComp::ProduceObject(ProductType& result) const
{
	if (!m_firstBitmapProviderCompPtr.IsValid() || !m_secondBitmapProviderCompPtr.IsValid()){
		return WS_FAILED;
	}

	if (!EnsureBitmapCreated(result)){
		return WS_FAILED;
	}
	Q_ASSERT(result.second.IsValid());

	result.first = NULL;

	const iimg::IBitmap* firstBitmapPtr = m_firstBitmapProviderCompPtr->GetBitmap();
	if (firstBitmapPtr == NULL){
		AddMessage(new ilog::CMessage(ilog::CMessage::IC_ERROR, 0, QObject::tr("First input image could not be provided"), "DifferenceBitmapSupplier"));

		return WS_FAILED;
	}

	const iimg::IBitmap* secondBitmapPtr = m_secondBitmapProviderCompPtr->GetBitmap();
	if (secondBitmapPtr == NULL){
		AddMessage(new ilog::CMessage(ilog::CMessage::IC_ERROR, 0, QObject::tr("Second input image could not be provided"), "DifferenceBitmapSupplier"));

		return WS_FAILED;
	}

	iimg::IBitmap::PixelFormat pixelFormat = firstBitmapPtr->GetPixelFormat();

	if (pixelFormat != secondBitmapPtr->GetPixelFormat()){
		AddMessage(new ilog::CMessage(ilog::CMessage::IC_ERROR, 0, QObject::tr("Format of input images differs"), "DifferenceBitmapSupplier"));

		return WS_FAILED;
	}

	double offset = 0;
	iprm::TParamsPtr<imeas::INumericValue> thresholdValuePtr(GetModelParametersSet(), m_offsetParamIdAttrPtr, m_defaultOffsetCompPtr, false);
	if (thresholdValuePtr.IsValid()){
		imath::CVarVector values = thresholdValuePtr->GetValues();
		if (values.GetElementsCount() >= 1){
			offset = values[0];
		}
	}

	Timer performanceTimer(this, "Image difference");

	return iipr::CBitmapOperations::CaclulateBitmapDifference(*firstBitmapPtr, *secondBitmapPtr, *result.second, offset, GetLogPtr()) ? WS_OK : WS_FAILED;
}


// reimplemented (icomp::CComponentBase)

void CDifferenceBitmapSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_firstBitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_firstBitmapProviderModelCompPtr.GetPtr(), m_firstBitmapSupplierCompPtr.GetPtr());
	}

	if (m_secondBitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_secondBitmapProviderModelCompPtr.GetPtr(), m_secondBitmapSupplierCompPtr.GetPtr());
	}
}


} // namespace iipr


