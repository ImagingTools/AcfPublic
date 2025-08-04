/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iipr/CCheckerboardPatternGeneratorComp.h>


// ACF includes
#include <istd/CIndex2d.h>


namespace iipr
{


// reimplemented (iproc::IProcessor)

iproc::IProcessor::TaskState CCheckerboardPatternGeneratorComp::DoProcessing(
			const iprm::IParamsSet* /*paramsPtr*/,
			const istd::IPolymorphic* /*inputPtr*/,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* /*progressManagerPtr*/)
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

	int patternSize = 32;

	for ( int y = 0; y < outputImageHeight; y++){
		quint8* imageLinePtr = (quint8*)outputBitmapPtr->GetLinePtr(y);

		int yIndex = y / patternSize;
		for (int x = 0; x < outputImageWidth; x += patternSize){
	
			int xIndex = x / patternSize;
			qint8 currentPatternValue = 255 * (xIndex % 2);

			if (yIndex % 2){
				currentPatternValue = 255 - currentPatternValue;
			}
			
			memset(imageLinePtr + x, currentPatternValue, patternSize);
		}
	}
	
	return TS_OK;
}


} // namespace iipr


