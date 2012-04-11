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


#include "iipr/CImagePolarTransformProcessorComp.h"


 // ACF includes
#include "istd/TChangeNotifier.h"

#include "ibase/CSize.h"

#include "iimg/CBitmapRegion.h"


// IACF includes
#include "iipr/TImagePixelInterpolator.h"


namespace iipr
{


// reimplemented (iproc::IProcessor)

int CImagePolarTransformProcessorComp::DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* /*progressManagerPtr*/)
{
	const iimg::IBitmap* inputBitmapPtr = dynamic_cast<const iimg::IBitmap*>(inputPtr);
	if (inputBitmapPtr == NULL){
		return TS_INVALID;
	}

	iimg::IBitmap* outputBitmapPtr = dynamic_cast<iimg::IBitmap*>(outputPtr);
	if (outputBitmapPtr == NULL){
		return TS_INVALID;
	}

	const i2d::IObject2d* aoiPtr = NULL;
	if (paramsPtr != NULL && m_aoiParamIdAttrPtr.IsValid()){
		aoiPtr = dynamic_cast<const i2d::IObject2d*>(paramsPtr->GetParameter(*m_aoiParamIdAttrPtr));
	}

	return ConvertImage(*inputBitmapPtr, aoiPtr, *outputBitmapPtr) ? TS_OK : TS_INVALID;
}


// private methods

bool CImagePolarTransformProcessorComp::ConvertImage(
			const iimg::IBitmap& input,
			const i2d::IObject2d* aoiPtr,
			iimg::IBitmap& outputBitmap) const
{
	if (input.IsEmpty()){
		return true;
	}

	const i2d::IObject2d* realAoiPtr = aoiPtr;
	i2d::CRectangle imageRect(input.GetImageSize());
	if (aoiPtr == NULL){
		realAoiPtr = &imageRect;
	}

	iimg::CBitmapRegion bitmapRegion(&input);
	if (!bitmapRegion.CreateFromGeometry(*realAoiPtr)){
		return false;
	}

	if (bitmapRegion.IsBitmapRegionEmpty()){
		SendWarningMessage(0, "Cannot process an empty region");
		
		return false;
	}

	i2d::CRectangle regionRect = bitmapRegion.GetBoundingBox();
	i2d::CVector2d aoiCenter = regionRect.GetCenter();
	i2d::CVector2d diffVector = aoiCenter - regionRect.GetTopLeft();
	int radius = int(qCeil(diffVector.GetLength()));
	int angleRange = int(radius * I_PI + 0.5);

	int r1 = 0;
	int r2 = radius;

	const i2d::CAnnulus* annulusPtr = dynamic_cast<const i2d::CAnnulus*>(realAoiPtr);
	if (annulusPtr != NULL){
		r1 = int(qCeil(annulusPtr->GetInnerRadius()));
		r2 = int(qFloor(annulusPtr->GetOuterRadius()));
		radius = (r2 - r1);
	}

	const i2d::CCircle* circlePtr = dynamic_cast<const i2d::CCircle*>(realAoiPtr);
	if (circlePtr != NULL){
		r1 = 0;
		r2 = int(qFloor(circlePtr->GetRadius()));
		radius = r2;
	}

	if (!outputBitmap.CreateBitmap(input.GetPixelFormat(), istd::CIndex2d(angleRange, radius))){
		return false;
	}

	iipr::TImagePixelInterpolator<quint8> pixelInterpolator(input, iipr::IImageInterpolationParams::IM_NO_INTERPOLATION);
	int pixelComponentsCount = input.GetComponentsCount();

	for (int componentIndex = 0; componentIndex < pixelComponentsCount; componentIndex++){
		for (int r = 0; r < radius; r++){
			quint8* outputImageBeginPtr = (quint8*)outputBitmap.GetLinePtr(r);
		
			for (int alpha = 0; alpha < angleRange; alpha++){
				double angle = alpha / double(angleRange) * I_2PI;
		
				double x = (r + r1) * qCos(angle); 			
				double y = (r  + r1) * qSin(angle);

				x += aoiCenter.GetX();
				y += aoiCenter.GetY();

				*(outputImageBeginPtr +  alpha * pixelComponentsCount + componentIndex) = pixelInterpolator.GetInterpolatedValue(x, y, componentIndex);
			}
		}
	}

	return true;
}


} // namespace iipr


