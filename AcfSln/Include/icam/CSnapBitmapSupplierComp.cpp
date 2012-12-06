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


#include "icam/CSnapBitmapSupplierComp.h"


// ACF includes
#include "i2d/CAffineTransformation2d.h"
#include "imath/CGeneralUnitInfo.h"

namespace icam
{


const imeas::INumericConstraints* CSnapBitmapSupplierComp::GetScaleConstraints(CSnapBitmapSupplierComp&)
{


	const struct: public imeas::INumericConstraints
	{


		/**
			Get number of expected numeric values.
		 */
		virtual int GetNumericValuesCount() const
		{
			return 2;
		}


		/**
			Get human readable name of numeric value for specified list index.
			\param	index	index of numeric value.
		 */
		virtual QString GetNumericValueName(int index) const
		{
			switch (index){
				case 0: return "X";
				case 1: return "Y";
				default: return "";
			}
		}


		/**
			Get human readable description of numeric value for specified list index.
			\param	index	index of numeric value.
		 */
		virtual QString GetNumericValueDescription(int index) const
		{
			switch (index){
				case 0: return "X scale in pixels per millimeter";
				case 1: return "Y scale in pixels per millimeter";
				default: return QString("invalid value index: %").arg(index);
			}
		}


		/**
			Get range of possible numeric values for specified list index.
			\param	index	index of numeric value.
		 */
		virtual const imath::IUnitInfo & GetNumericValueUnitInfo(int index) const
		{
			const imath::CGeneralUnitInfo info(imath::IUnitInfo::UT_TECHNICAL, "scale", 1.0, istd::CRange(0.0, 100.0));
			return info;
		}

	} ScaleConstraints;


	return &ScaleConstraints;
}


// reimplemented (iipr::IBitmapProvider)

const iimg::IBitmap* CSnapBitmapSupplierComp::GetBitmap() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->second.GetPtr();
	}
	else{
		return NULL;
	}
}


// reimplemented (i2d::ICalibrationProvider)

const i2d::ICalibration2d* CSnapBitmapSupplierComp::GetCalibration() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->first.GetPtr();
	}
	else{
		return NULL;
	}
}


// protected methods

// reimplemented (iproc::TSupplierCompWrap)

bool CSnapBitmapSupplierComp::InitializeWork()
{
	if (m_bitmapAcquisitionCompPtr.IsValid()){
		m_bitmapAcquisitionCompPtr->InitProcessor(GetModelParametersSet());

		return true;
	}

	return false;
}


int CSnapBitmapSupplierComp::ProduceObject(ProductType& result) const
{
	if (!m_bitmapCompFact.IsValid()){
		return WS_CRITICAL;
	}

	result.first.Reset();

	if (!result.second.IsValid()){
		result.second.SetPtr(m_bitmapCompFact.CreateInstance());
		if (!result.second.IsValid()){
			return WS_CRITICAL;
		}
	}

	if (result.second.IsValid() && m_bitmapAcquisitionCompPtr.IsValid()){
		Timer performanceTimer(this, "Image acquisition");

		int status = m_bitmapAcquisitionCompPtr->DoProcessing(GetModelParametersSet(), NULL, result.second.GetPtr());
		switch (status){
			case iproc::IProcessor::TS_OK:
			{
				istd::CIndex2d bitmapSize = result.second->GetImageSize();
				i2d::CVector2d center(bitmapSize.GetX() * 0.5, bitmapSize.GetY() * 0.5);
				if (m_calibrationCompPtr.IsValid()){
					i2d::CAffineTransformation2d transform;
					transform.Reset(-center);
					result.first.SetPtr(m_calibrationCompPtr->CreateCombinedCalibration(transform));
				}
				else{
					i2d::CAffineTransformation2d* transformPtr = new i2d::CAffineTransformation2d();
					transformPtr->Reset(-center);
					result.first.SetPtr(transformPtr);
				}
			}
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

