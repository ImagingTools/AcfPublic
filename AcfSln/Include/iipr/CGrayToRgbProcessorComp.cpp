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


#include <iipr/CGrayToRgbProcessorComp.h>


// Qt includes
#include <QtCore/QObject>

 // ACF includes
#include <istd/CChangeNotifier.h>
#include <ibase/CSize.h>


namespace iipr
{


// reimplemented (iproc::IProcessor)

iproc::IProcessor::TaskState CGrayToRgbProcessorComp::DoProcessing(
				const iprm::IParamsSet* /*paramsPtr*/,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* /*progressManagerPtr*/)
{
	const iimg::IBitmap* inputBitmapPtr = dynamic_cast<const iimg::IBitmap*>(inputPtr);
	if (inputBitmapPtr == NULL){
		return TS_INVALID;
	}

	iimg::IBitmap* outputBitmapPtr = dynamic_cast<iimg::IBitmap*>(outputPtr);
	if (outputBitmapPtr == NULL){
		return TS_INVALID;
	}

	return ConvertImage(*inputBitmapPtr, *outputBitmapPtr) ? TS_OK : TS_INVALID;
}


// private methods

bool CGrayToRgbProcessorComp::ConvertImage(
			const iimg::IBitmap& inputBitmap,
			iimg::IBitmap& outputBitmap) const
{
	if (inputBitmap.IsEmpty()){
		return true;
	}

	int inputFormat = inputBitmap.GetPixelFormat();
	if ((inputFormat == iimg::IBitmap::PF_RGB) || (inputFormat == iimg::IBitmap::PF_RGBA)){
		return outputBitmap.CopyFrom(inputBitmap);
	}
	else if (inputFormat != iimg::IBitmap::PF_GRAY){
		SendErrorMessage(0, QObject::tr("Image format must be Grayscale (8-Bit)"), "GrayToRgbProcessor");

		return false;
	}

	ibase::CSize imageSize = inputBitmap.GetImageSize();

	istd::CChangeNotifier resultNotifier(&outputBitmap);
	Q_UNUSED(resultNotifier);

	if (!outputBitmap.CreateBitmap(iimg::IBitmap::PF_RGB, imageSize)){
		return false;
	}

	for (int y = 0; y < imageSize.GetY(); ++y){
		quint8* inputImageLinePtr = (quint8*)inputBitmap.GetLinePtr(y);
		quint32* outputImageLinePtr = (quint32*)outputBitmap.GetLinePtr(y);

		for (int x = 0; x < imageSize.GetX(); ++x){
			quint8 value = *(inputImageLinePtr + x);

			outputImageLinePtr[x] = (value << 16) + (value << 8) + (value);
		}
	}

	const i2d::ICalibration2d* inputCalibrationPtr = inputBitmap.GetCalibration();
	if (inputCalibrationPtr != NULL){
		istd::TUniqueInterfacePtr<i2d::ICalibration2d> outputCalibrationPtr;
		outputCalibrationPtr.MoveCastedPtr(inputCalibrationPtr->CloneMe());

		outputBitmap.SetCalibration(outputCalibrationPtr.PopInterfacePtr(), true);
	}

	return true;
}


} // namespace iipr


