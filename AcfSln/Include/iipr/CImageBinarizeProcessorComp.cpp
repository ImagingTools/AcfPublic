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


#include "iipr/CImageBinarizeProcessorComp.h"


 // ACF includes
#include "istd/TChangeNotifier.h"
#include "iprm/TParamsPtr.h"

#include "ibase/CSize.h"


namespace iipr
{


// reimplemented (iproc::IProcessor)

int CImageBinarizeProcessorComp::DoProcessing(
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

	iprm::TParamsPtr<imeas::INumericValue> thresholdParamsPtr;
	if (paramsPtr != NULL && m_binarizationParamsIdAttrPtr.IsValid()){
		thresholdParamsPtr.Init(paramsPtr, *m_binarizationParamsIdAttrPtr);
	}

	if (!thresholdParamsPtr.IsValid()){
		SendErrorMessage(0, "Threshold parameter is not set");

		return TS_INVALID;
	}

	return ConvertImage(*inputBitmapPtr, *thresholdParamsPtr, *outputBitmapPtr) ? TS_OK : TS_INVALID;
}


// private methods

bool CImageBinarizeProcessorComp::ConvertImage(
			const iimg::IBitmap& inputBitmap,
			const imeas::INumericValue& thresholdParams,
			iimg::IBitmap& outputBitmap) const
{
	if (inputBitmap.IsEmpty()){
		SendWarningMessage(0, "Input bitmap is empty.");

		return false;
	}

	if (!outputBitmap.CreateBitmap(inputBitmap.GetPixelFormat(), inputBitmap.GetImageSize())){
		return false;
	}

	int imageWidth = inputBitmap.GetImageSize().GetX();
	int imageHeight = inputBitmap.GetImageSize().GetY();

	imath::CVarVector values = thresholdParams.GetValues();
	if (values.GetElementsCount() < 1){
		SendErrorMessage(0, "Wrong processing parameters");

		return false;
	}

	double threshold = values[0];

	for(int y = 0; y < imageHeight; ++y){
		quint8* outputImageBufferPtr = (quint8*)outputBitmap.GetLinePtr(y);
		quint8* inputImageBufferPtr = (quint8*)inputBitmap.GetLinePtr(y);

		for (int x = 0; x < imageWidth; ++x){
			*outputImageBufferPtr = *inputImageBufferPtr > threshold ? 255 : 0;

			++outputImageBufferPtr, ++inputImageBufferPtr;
		}
	}

	return true;
}


} // namespace iipr


