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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CImageNormalizeProcessorComp.h"


// ACF includes
#include "imath/CFixedPointManip.h"
#include "iimg/CGeneralBitmap.h"


namespace iipr
{


// reimplemented (iipr::CImageProcessorCompBase)

bool CImageNormalizeProcessorComp::ProcessImage(
			const iprm::IParamsSet* paramsPtr,
			const iimg::IBitmap& inputImage,
			iimg::IBitmap& outputImage)
{
	if (paramsPtr == NULL){
		return outputImage.CopyFrom(inputImage);
	}

	istd::CIndex2d imageSize = inputImage.GetImageSize();
	int imageWidth = imageSize.GetX();
	int imageHeight = imageSize.GetY();

	int outputImageLeft = 0;
	int outputImageRight = imageWidth - 1;
	int outputImageTop = 0;
	int outputImageBottom = imageHeight - 1;

	const i2d::CRectangle* aoiPtr = m_defaultAoiParamCompPtr.GetPtr();
	if (m_aoiParamIdAttrPtr.IsValid()){
		aoiPtr = dynamic_cast<const i2d::CRectangle*>(paramsPtr->GetParameter(*m_aoiParamIdAttrPtr));
	}

	if (aoiPtr != NULL){
		outputImageLeft = qMax(outputImageLeft, int(aoiPtr->GetLeft()));
		outputImageRight = qMin(outputImageRight, int(qCeil(aoiPtr->GetRight())));
		outputImageTop = qMax(outputImageTop, int(aoiPtr->GetLeft()));
		outputImageBottom = qMin(outputImageBottom, int(qCeil(aoiPtr->GetRight())));
	}

	if ((outputImageLeft > outputImageRight) || (outputImageTop > outputImageBottom)){	// if output image should be empty
		outputImage.ResetImage();

		return true;
	}

	const imeas::ILinearAdjustParams* adjustParamsPtr = m_defaultAdjustParamsCompPtr.GetPtr();
	if (m_adjustParamsIdAttrPtr.IsValid()){
		adjustParamsPtr = dynamic_cast<const imeas::ILinearAdjustParams*>(paramsPtr->GetParameter(*m_adjustParamsIdAttrPtr));
	}

	double contrast = 1;
	double brightness = 0;
	if (adjustParamsPtr != NULL){
		contrast = adjustParamsPtr->GetScaleFactor();
		brightness = adjustParamsPtr->GetOffsetFactor() * 255;
	}

	if (!outputImage.CreateBitmap(
				inputImage.GetPixelFormat(),
				istd::CIndex2d(outputImageRight - outputImageLeft + 1, outputImageBottom - outputImageTop + 1))){
		SendWarningMessage(0, "Could not create output image");

		return false;
	}

	if ((contrast != 1) || (brightness != 0)){
		for (int lineIndex = outputImageTop; lineIndex <= outputImageBottom; ++lineIndex){
			const quint8* inputLinePtr = static_cast<const quint8*>(inputImage.GetLinePtr(lineIndex));
			quint8* outputLinePtr = static_cast<quint8*>(outputImage.GetLinePtr(lineIndex - outputImageTop));

			for (int x = outputImageLeft; x <= outputImageRight; ++x){
				int outputValue = int(inputLinePtr[x] * contrast + brightness);
				if (outputValue < 0){
					outputValue = 0;
				}
				else if (outputValue > 255){
					outputValue = 255;
				}
				outputLinePtr[x - outputImageLeft] = quint8(outputValue);
			}
		}
	}
	else{
		for (int lineIndex = outputImageTop; lineIndex <= outputImageBottom; ++lineIndex){
			const quint8* inputLinePtr = static_cast<const quint8*>(inputImage.GetLinePtr(lineIndex));
			quint8* outputLinePtr = static_cast<quint8*>(outputImage.GetLinePtr(lineIndex - outputImageTop));

			for (int x = outputImageLeft; x <= outputImageRight; ++x){
				outputLinePtr[x - outputImageLeft] = inputLinePtr[x];
			}
		}
	}

	return true;
}


} // namespace iipr

