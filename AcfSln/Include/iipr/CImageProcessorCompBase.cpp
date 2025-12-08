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


#include <iipr/CImageProcessorCompBase.h>


// ACF includes
#include <iprm/TParamsPtr.h>
#include <iimg/CGeneralBitmap.h>

// ACF-Solutions includes
#include <iipr/CImageProcessorCompBase.h>


namespace iipr
{


// protected methods

CImageProcessorCompBase::BackgroundFillMode CImageProcessorCompBase::GetBackgroundMode(const iprm::IParamsSet* /*paramsPtr*/) const
{
	return BackgroundFillMode(*m_backgroundModeAttrPtr);
}


iimg::IBitmap::PixelFormat CImageProcessorCompBase::GetOutputPixelFormat(const iprm::IParamsSet* paramsPtr) const
{
	iimg::IBitmap::PixelFormat outputPixelFormat = iimg::IBitmap::PixelFormat(*m_outputPixelTypeAttrPtr);
	iprm::TParamsPtr<iprm::ISelectionParam> outputFormatParamPtr(paramsPtr, m_outputPixelTypeIdAttrPtr, m_defaultOutputPixelTypeParamCompPtr, false);
	if (outputFormatParamPtr.IsValid()){
		outputPixelFormat = iimg::IBitmap::PixelFormat(outputFormatParamPtr->GetSelectedOptionIndex());
	}

	return outputPixelFormat;
}


CImageProcessorCompBase::AoiMode CImageProcessorCompBase::GetAoiMode(const iprm::IParamsSet* /*paramsPtr*/) const
{
	return AoiMode(*m_aoiModeAttrPtr);
}


// reimplemented (iproc::IProcessor)

iproc::IProcessor::TaskState CImageProcessorCompBase::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* /*progressManagerPtr*/)
{
	if (outputPtr == NULL){
		return TS_OK;
	}

	const iimg::IBitmap* inputBitmapPtr = dynamic_cast<const iimg::IBitmap*>(inputPtr);
	iimg::IBitmap* outputBitmapPtr = dynamic_cast<iimg::IBitmap*>(outputPtr);

	if ((inputBitmapPtr == NULL) || (outputBitmapPtr == NULL)){
		return TS_INVALID;
	}

	// do image processing:
	if (!ProcessImage(paramsPtr, *inputBitmapPtr, *outputBitmapPtr)){
		return TS_INVALID;
	}

	if (*m_useInputCalibrationAttrPtr){
		const i2d::ICalibration2d* inputCalibrationPtr = inputBitmapPtr->GetCalibration();
		if (inputCalibrationPtr != NULL){
			istd::TUniqueInterfacePtr<i2d::ICalibration2d> outputCalibrationPtr;
			outputCalibrationPtr.MoveCastedPtr(inputCalibrationPtr->CloneMe());

			outputBitmapPtr->SetCalibration(outputCalibrationPtr.PopInterfacePtr(), true);
		}
	}

	return TS_OK;
}


} // namespace iipr


