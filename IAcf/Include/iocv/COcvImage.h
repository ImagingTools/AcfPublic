/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iocv_COcvImage_included
#define iocv_COcvImage_included


// OpenCV includes
#include "cxtypes.h"
#include "cv.h"
#include "highgui.h"


// ACF includes
#include "iimg/CBitmapBase.h"


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
};


} // namespace iocv


#endif // !iocv_COcvImage_included


