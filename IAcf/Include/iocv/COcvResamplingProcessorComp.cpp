/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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


#include <iocv/COcvResamplingProcessorComp.h>


 // ACF includes
#include <istd/CIndex2d.h>
#include <ibase/CSize.h>
#include <iprm/TParamsPtr.h>
#include <iimg/IBitmap.h>

// OpenCV includes
#include <opencv2/imgproc/imgproc.hpp>


namespace iocv
{


// protected methods

// reimplemented (iproc::IProcessor)

int COcvResamplingProcessorComp::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* /*progressManagerPtr*/)
{
	const iimg::IBitmap* inputBitmapPtr = dynamic_cast<const iimg::IBitmap*>(inputPtr);
	if (inputBitmapPtr == NULL){
		SendWarningMessage(0, "Input bitmap is not set");

		return TS_INVALID;
	}

	if (inputBitmapPtr->IsEmpty()){
		SendWarningMessage(0, "Input bitmap is empty.");

		return TS_INVALID;
	}

	iimg::IBitmap* outputBitmapPtr = dynamic_cast<iimg::IBitmap*>(outputPtr);
	if (outputBitmapPtr == NULL){
		SendWarningMessage(0, "Output bitmap is not set");

		return TS_INVALID;
	}

	iprm::TParamsPtr<imeas::INumericValue> scaleParamPtr(paramsPtr, m_scaleParamIdAttrPtr, m_defaultScaleCompPtr);
	if (!scaleParamPtr.IsValid()){
		SendErrorMessage(0, "No target scale was set");

		return TS_INVALID;
	}

	imath::CVarVector scales = scaleParamPtr->GetValues();
	int scalesCount = scales.GetElementsCount();
	if (scalesCount < 1){
		SendErrorMessage(0, "Processing scale can't have dimension smaller 1");

		return TS_INVALID;
	}

	istd::CIndex2d inputBitmapSize = inputBitmapPtr->GetImageSize();
	int inputImageWidth = inputBitmapSize.GetX();
	int inputImageHeight = inputBitmapSize.GetY();

	double scaleX = scales[0];
	double scaleY = scaleX;
	if (scalesCount > 1){
		scaleY = scales[1];
	}

	int outputImageWidth = inputImageWidth * scaleX;
	int outputImageHeight = inputImageHeight * scaleY;

	if (!outputBitmapPtr->CreateBitmap(
					inputBitmapPtr->GetPixelFormat(),
					istd::CIndex2d(outputImageWidth, outputImageHeight),
					inputBitmapPtr->GetPixelBitsCount(),
					inputBitmapPtr->GetComponentsCount())){
		SendErrorMessage(0, "Data could not be copied from input bitmap to the output");

		return TS_INVALID;
	}

	cv::Mat inputMatrix(inputImageHeight, inputImageWidth, CV_8UC1, (qint8*)inputBitmapPtr->GetLinePtr(0));
	cv::Mat outputMatrix(outputImageHeight, outputImageWidth, CV_8UC1, (qint8*)outputBitmapPtr->GetLinePtr(0));

	cv::_InputArray input(inputMatrix);
	cv::_OutputArray output(outputMatrix);

	cv::resize(input, output, cv::Size(outputImageWidth, outputImageHeight), 0.0, 0.0, cv::INTER_LINEAR);

	return TS_OK;
}


} // namespace iocv


