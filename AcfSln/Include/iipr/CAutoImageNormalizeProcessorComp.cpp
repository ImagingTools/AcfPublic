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


#include "iipr/CAutoImageNormalizeProcessorComp.h"


// ACF includes
#include "imath/CFixedPointManip.h"
#include "iimg/CGeneralBitmap.h"
#include "iprm/TParamsPtr.h"


namespace iipr
{


// reimplemented (iipr::CImageProcessorCompBase)

bool CAutoImageNormalizeProcessorComp::ProcessImage(
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

	iprm::TParamsPtr<i2d::CRectangle> aoiPtr(m_defaultAoiParamCompPtr.GetPtr());
	if (m_aoiParamIdAttrPtr.IsValid()){
		aoiPtr.Init(paramsPtr, *m_aoiParamIdAttrPtr);
	}

	if (aoiPtr != NULL){
		outputImageLeft = qMax(outputImageLeft, int(aoiPtr->GetLeft()));
		outputImageRight = qMin(outputImageRight, int(qCeil(aoiPtr->GetRight())));
		outputImageTop = qMax(outputImageTop, int(aoiPtr->GetTop()));
		outputImageBottom = qMin(outputImageBottom, int(qCeil(aoiPtr->GetBottom())));
	}

	if ((outputImageLeft > outputImageRight) || (outputImageTop > outputImageBottom)){	// if output image should be empty
		outputImage.ResetImage();

		return true;
	}

	iprm::TParamsPtr<imeas::INumericValue> clippingThresholdParamsPtr(m_defaultClippingThresholdCompPtr.GetPtr());
	if (m_clippingThresholdIdAttrPtr.IsValid()){
		clippingThresholdParamsPtr.Init(paramsPtr, *m_clippingThresholdIdAttrPtr);
	}

	double clippingThreshold = 0.0;
	if (clippingThresholdParamsPtr.IsValid()){
		imath::CVarVector values = clippingThresholdParamsPtr->GetValues();
		if (values.GetElementsCount() > 0){
			clippingThreshold = values[0];
		}
	}

	if (!outputImage.CreateBitmap(
				inputImage.GetPixelFormat(),
				istd::CIndex2d(outputImageRight - outputImageLeft, outputImageBottom - outputImageTop))){
		SendWarningMessage(0, "Could not create output image");

		return false;
	}

	int channelsCount = inputImage.GetComponentsCount();

	for (int channelIndex = 0; channelIndex < channelsCount; ++channelIndex){
		qint32 channelHistogram[256] = {0};
		int pixelCount = 0;

		for (int lineIndex = outputImageTop; lineIndex <= outputImageBottom; ++lineIndex){
			const quint8* inputLinePtr = static_cast<const quint8*>(inputImage.GetLinePtr(lineIndex));

			for (int x = outputImageLeft; x <= outputImageRight; ++x){
				++channelHistogram[inputLinePtr[x]];
				++pixelCount;
			}
		}

		// Get clipped histogram minimum:
		double histogramMin = 255;
		for (int histogramIndex = 0; histogramIndex < 256; histogramIndex++){
			double histogramValue = channelHistogram[histogramIndex] / double(pixelCount);
			if ((channelHistogram[histogramIndex] > 0) && (histogramValue >= clippingThreshold)){
				histogramMin = histogramIndex;
				break;
			}
		}

		double histogramMax = 0;
		for (int histogramIndex = 255; histogramIndex >= 0; histogramIndex--){
			double histogramValue = channelHistogram[histogramIndex] / double(pixelCount);
			if ((channelHistogram[histogramIndex] > 0) && (histogramValue >= clippingThreshold)){
				histogramMax = histogramIndex;
				break;
			}
		}

		double scaleFactor = 255.0 / fabs(histogramMax - histogramMin);

		for (int lineIndex = outputImageTop; lineIndex < outputImageBottom; ++lineIndex){
			const quint8* inputLinePtr = static_cast<const quint8*>(inputImage.GetLinePtr(lineIndex));
			quint8* outputLinePtr = static_cast<quint8*>(outputImage.GetLinePtr(lineIndex - outputImageTop));

			for (int x = outputImageLeft; x < outputImageRight; ++x){
				quint8 pixelValue = inputLinePtr[x];

				int outputValue = (pixelValue - histogramMin) * scaleFactor;
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

	return true;
}


} // namespace iipr

