/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CImageCopyProcessorComp_included
#define iipr_CImageCopyProcessorComp_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "i2d/CRectangle.h"
#include "iimg/CScanlineMask.h"

// ACF-Solutions includes
#include "imeas/ILinearAdjustParams.h"
#include "imeas/INumericValue.h"
#include "iipr/CImageProcessorCompBase.h"


namespace iipr
{


/**
	Implementation of image copy with convertion of image type.
*/
class CImageCopyProcessorComp: public iipr::CImageProcessorCompBase
{
public:
	typedef iipr::CImageProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(CImageCopyProcessorComp);
	I_END_COMPONENT;

	static bool DoImageCopy(
				iimg::IBitmap::PixelFormat outputPixelFormat,
				const iimg::IBitmap& inputImage,
				const iimg::CScanlineMask& resultMask,
				iimg::IBitmap& outputImage,
				istd::ILogger* loggerPtr = NULL);

protected:
	// reimplemented (iipr::CImageProcessorCompBase)
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);
};


} // namespace iipr


#endif // !iipr_CImageCopyProcessorComp_included


