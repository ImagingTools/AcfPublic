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


#ifndef iipr_CConvolutionProcessorComp_included
#define iipr_CConvolutionProcessorComp_included


// ACF includes
#include "iimg/CScanlineMask.h"

// ACF-Solutions includes
#include "iipr/TImageParamProcessorCompBase.h"
#include "iipr/IConvolutionKernel2d.h"


namespace iipr
{


/**
	Implementation of image processor using convolution kernel.
*/
class CConvolutionProcessorComp: public iipr::TImageParamProcessorCompBase<IConvolutionKernel2d>
{
public:
	typedef iipr::TImageParamProcessorCompBase<IConvolutionKernel2d> BaseClass;

	I_BEGIN_COMPONENT(CConvolutionProcessorComp);
	I_END_COMPONENT;

	// static methods
	static bool DoConvolutionFilter(
				const IConvolutionKernel2d& kernel,
				int backgroundMode,
				iimg::IBitmap::PixelFormat outputPixelFormat,
				const iimg::IBitmap& inputImage,
				const iimg::CScanlineMask& resultMask,
				iimg::IBitmap& outputImage,
				istd::ILogger* loggerPtr = NULL);

protected:
	// reimplemented (iipr::TImageParamProcessorCompBase)
	virtual bool ParamProcessImage(
				const iprm::IParamsSet* paramsPtr,
				const IConvolutionKernel2d* procParamPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);
};


} // namespace iipr


#endif // !iipr_CConvolutionProcessorComp_included

