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


#include <icam/CMemoryAcquisitionComp.h>


#include <istd/CChangeNotifier.h>

#include <iprm/IParamsSet.h>



namespace icam
{


// reimplemented (iproc::IProcessor)

int CMemoryAcquisitionComp::DoProcessing(
			const iprm::IParamsSet* /*paramsPtr*/,
			const istd::IPolymorphic* /*inputPtr*/,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* /*progressManagerPtr*/)
{
	iimg::IBitmap* outputImagePtr = dynamic_cast<iimg::IBitmap*>(outputPtr);
	if (outputImagePtr == NULL){
		return TS_INVALID;
	}

	if (!outputImagePtr->CopyFrom(*this)){
		return TS_INVALID;
	}

	return TS_OK;
}


// reimplemented (icam::IBitmapAcquisition)

istd::CIndex2d CMemoryAcquisitionComp::GetBitmapSize(const iprm::IParamsSet* /*paramsPtr*/) const
{
	return BaseClass2::GetImageSize();
}


} // namespace icam


