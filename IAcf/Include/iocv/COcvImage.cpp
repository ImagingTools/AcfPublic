/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iocv/COcvImage.h"


namespace iocv
{


// public methods

COcvImage::COcvImage(const IplImage& image)
{
	ConvertToBitmap(image, *this);
}


// public static methods

bool COcvImage::ConvertToBitmap(const IplImage& image, iimg::IBitmap& outputBitmap)
{	
	switch (image.nChannels){
		case 1:
			return !outputBitmap.CreateBitmap(
						iimg::IBitmap::PF_GRAY,
						istd::CIndex2d(image.width, image.height),
						image.imageData,
						true,
						image.widthStep);
		case 3:
			if (outputBitmap.CreateBitmap(iimg::IBitmap::PF_RGB, istd::CIndex2d(image.width, image.height))){
				quint8* outputBitmapLinePtr = (quint8*)outputBitmap.GetLinePtr(0);
				std::memset(outputBitmapLinePtr, 255, outputBitmap.GetLineBytesCount() * outputBitmap.GetImageSize().GetY());

				for (int y = 0; y < image.height; y++){
					quint8* outputBitmapLinePtr = (quint8*)outputBitmap.GetLinePtr(y);
					quint8* inputBitmapLinePtr = (quint8*)image.imageData + y * image.widthStep;

					for (int x = 0; x < outputBitmap.GetLineBytesCount(); x += 4){
						int ix = (x >> 2) * 3;

						std::memcpy(outputBitmapLinePtr + x,  inputBitmapLinePtr + ix, 3);
					}
				}

				return true;
			}
			break;
		default:
			I_CRITICAL();
	}

	return false;	
}


} // namespace iocv


