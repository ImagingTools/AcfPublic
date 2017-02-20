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


#include <ifileproc/CBitmapPreviewGeneratorComp.h>


// ACF includes
#include <iprm/TParamsPtr.h>
#include <iimg/CBitmap.h>


namespace ifileproc
{


// public methods

// reimplemented (iproc::IProcessor)

int CBitmapPreviewGeneratorComp::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* /*progressManagerPtr*/)
{
	if (outputPtr == NULL){
		return TS_OK;
	}

	const iimg::CBitmap* inputBitmapPtr = dynamic_cast<const iimg::CBitmap*>(inputPtr);
	iimg::CBitmap* outputBitmapPtr = dynamic_cast<iimg::CBitmap*>(outputPtr);
	if ((inputBitmapPtr == NULL) || (outputBitmapPtr == NULL)){
		return TS_INVALID;
	}

	istd::CIndex2d size(256, 256);

	iprm::TParamsPtr<i2d::CRectangle> previewRectParamPtr(paramsPtr, "PreviewRect");
	if (previewRectParamPtr.IsValid()){
		size.SetX(previewRectParamPtr->GetWidth());
		size.SetY(previewRectParamPtr->GetHeight());
	}

	outputBitmapPtr->CopyImageFrom(inputBitmapPtr->GetQImage().scaled(size.GetX(), size.GetY(), Qt::KeepAspectRatioByExpanding));

	return TS_OK;
}


} // namespace ifileproc


