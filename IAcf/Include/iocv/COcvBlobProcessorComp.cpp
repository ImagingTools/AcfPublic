/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <iocv/COcvBlobProcessorComp.h>


// OpenCV includes
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

// ACF includes
#include <istd/CChangeNotifier.h>
#include <iimg/CBitmapBase.h>
#include <iprm/TParamsPtr.h>
#include <i2d/CPolygon.h>

// ACF-Solutions includes
#include <iblob/CBlobFeature.h>


namespace iocv
{


// protected methods

// reimplemented (iblob::CBlobProcessorCompBase)

bool COcvBlobProcessorComp::CalculateBlobs(
			const iprm::IParamsSet* /*paramsPtr*/,
			const iblob::IBlobFilterParams* filterParamsPtr,
			const iimg::IBitmap& image,
			iipr::IFeaturesConsumer& result)
{
	istd::CChangeNotifier resultNotifier(&result);

	result.ResetFeatures();

	// Initialize input bitmap:
	void* imageDataBufferPtr = const_cast<void*>(image.GetLinePtr(0));
	cv::Mat inputBitmap(image.GetImageSize().GetY(), image.GetImageSize().GetX(), CV_8UC1, imageDataBufferPtr, image.GetLineBytesCount());

	// Get contours from the binary image:
	cv::Mat tmpBinaryImage = inputBitmap.clone();
	std::vector<std::vector<cv::Point> > contours;
	findContours(tmpBinaryImage, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

	// Get found blobs:
	for (int contourIndex = 0; contourIndex < int(contours.size()); contourIndex++){
		cv::Moments moms = cv::moments(cv::Mat(contours[contourIndex]));

		double area = moms.m00;
		if (qFuzzyCompare(area, 0.0)){
			continue;
		}

		double perimeter = cv::arcLength(cv::Mat(contours[contourIndex]), true);

		cv::Point2d location = cv::Point2d(moms.m10 / moms.m00, moms.m01 / moms.m00);
		double circularity = 0.0;
		
		if (perimeter > 0){
			circularity = 4 * I_PI * area / (perimeter * perimeter);
		}

		bool passedByFilter = true;

		if (filterParamsPtr != NULL){
			passedByFilter = IsBlobAcceptedByFilter(*filterParamsPtr, area, perimeter, circularity);
		}

		if (passedByFilter){
			iblob::CBlobFeature* blobFeaturePtr = new iblob::CBlobFeature(area, perimeter, i2d::CVector2d(location.x, location.y));

			result.AddFeature(blobFeaturePtr);
		}
	}

	return true;
}


} // namespace iocv


