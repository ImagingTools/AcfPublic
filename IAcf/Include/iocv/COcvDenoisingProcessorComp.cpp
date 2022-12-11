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


#include <iocv/COcvDenoisingProcessorComp.h>


// OpenCV includes
#include <opencv2/photo.hpp>

// ACF includes
#include <istd/CIndex2d.h>
#include <ibase/CSize.h>
#include <iprm/TParamsPtr.h>
#include <iimg/IBitmap.h>
#include <iimg/CBitmap.h>
#include <imeas/INumericValue.h>
#include <iocv/COcvImage.h>


namespace iocv
{


// protected methods

// reimplemented (iproc::IProcessor)

int COcvDenoisingProcessorComp::DoProcessing(
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

	istd::CIndex2d inputBitmapSize = inputBitmapPtr->GetImageSize();

	int imageWidth = inputBitmapSize.GetX();
	int imageHeight = inputBitmapSize.GetY();

	cv::Mat inputMatrix;
	
	if (!COcvImage::ConvertFromBitmap(*inputBitmapPtr, inputMatrix)) {
		return TS_INVALID;
	}

	cv::Mat outputMatrix(imageWidth, imageHeight, CV_8UC1, inputBitmapPtr->GetLineBytesCount());
	cv::fastNlMeansDenoising(inputMatrix, outputMatrix);

	if (!COcvImage::ConvertToBitmap(outputMatrix, *outputBitmapPtr))
	{
		return TS_INVALID;
	}

	return TS_OK;
}


} // namespace iocv


