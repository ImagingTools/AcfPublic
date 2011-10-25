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


#include "iipr/CRingPatternGeneratorComp.h"


// ACF includes
#include "istd/CIndex2d.h"


// IACF includes
#include "iipr/IRingPatternGeneratorParams.h"


namespace iipr
{


// reimplemented (iproc::IProcessor)

int CRingPatternGeneratorComp::DoProcessing(
			const iprm::IParamsSet* /*paramsPtr*/,
			const istd::IPolymorphic* /*inputPtr*/,
			istd::IChangeable* outputPtr,
			iproc::IProgressManager* /*progressManagerPtr*/)
{
	iimg::IBitmap* outputBitmapPtr = dynamic_cast<iimg::IBitmap*>(outputPtr);
	if (outputBitmapPtr == NULL){
		SendErrorMessage(0, "Output bitmap is not defined");

		return TS_INVALID;
	}
						
	int outputImageWidth = 512;
	int outputImageHeight = 512;

	if (!outputBitmapPtr->CreateBitmap(iimg::IBitmap::PF_GRAY, istd::CIndex2d(outputImageWidth, outputImageHeight))){
		SendErrorMessage(0, "Output bitmap coud not be created");

		return TS_INVALID;
	}

	int halfHeight  = outputImageHeight >> 1;
	int halfWidth  = outputImageWidth >> 1;
	double waveLength = 8.0;

	double patternFrequency = 1.0 / waveLength;
	double minFrequency = 1.0 / halfHeight;
	int patternGenerationMode = iipr::IRingPatternGeneratorParams::PT_DYNAMIC_WAVELENGTH;	

	double maxRadius = halfHeight - waveLength / 2.0; // margin
	for( int y = 0; y < outputImageHeight; y++){
		I_BYTE* imageLinePtr = (I_BYTE*)outputBitmapPtr->GetLinePtr(y);
		for(int x = 0; x < outputImageWidth; x++){
			int dx = x - halfWidth;
			int dy = y - halfHeight;

			double radius = sqrt(double(dx * dx + dy * dy));
			if (radius > maxRadius){
				*(imageLinePtr + x) = 0;
				
				continue;
			}

			double usedFrequency = patternFrequency;
			if (patternGenerationMode == iipr::IRingPatternGeneratorParams::PT_DYNAMIC_WAVELENGTH){
				double relativeRadius = radius / maxRadius;

				usedFrequency = (1.0 - relativeRadius) * minFrequency + relativeRadius * patternFrequency;
			}

			double outputValue = cos(radius * usedFrequency * I_2PI);
				
			*(imageLinePtr + x) = I_BYTE(127 * outputValue + 128);
		}
	}
	
	return TS_OK;
}


} // namespace iipr


