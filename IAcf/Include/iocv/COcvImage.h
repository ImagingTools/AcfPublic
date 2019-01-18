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


#ifndef iocv_COcvImage_included
#define iocv_COcvImage_included


// OpenCV includes
#include <opencv/cv.h>
#include <opencv/highgui.h>
#undef min
#undef max

// ACF includes
#include <iimg/CBitmapBase.h>


namespace iocv
{


/**
	Wrapper for Ipl image.
	This implementation can be used for conversion from OpenCV image structure to standard ACF bitmap.
*/
class COcvImage: virtual iimg::CBitmapBase
{
public:
	COcvImage(const IplImage& image);

	/**
		Convert OpenCV image to standard ACF bitmap.
	*/
	static bool ConvertToBitmap(const IplImage& image, iimg::IBitmap& outputBitmap);

	/**
		Convert standard ACF bitmap to OpenCV image.
	*/
	static bool ConvertFromBitmap(const iimg::IBitmap& bitmap, cv::Mat& outputImage);

	/**
		Convert OpenCV image to standard ACF bitmap.
	*/
	static bool ConvertToBitmap(const cv::Mat& image, iimg::IBitmap& outputBitmap);
};


} // namespace iocv


#endif // !iocv_COcvImage_included


