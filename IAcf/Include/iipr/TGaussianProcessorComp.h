/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iipr_TGaussianProcessorComp_included
#define iipr_TGaussianProcessorComp_included


#include "iipr/TConvolutionProcessorComp.h"
#include "iipr/TGaussianKernel2d.h"
#include "iipr/CGaussian2dFilterParams.h"


namespace iipr
{


/**
	Implementation of general gaussian filter.
*/

template <typename PixelType>
class TGaussianProcessorComp: public iipr::TConvolutionProcessorComp<
			PixelType,
			iipr::CGaussian2dFilterParams,
			iipr::CGaussianKernel2d>
{
public:
	typedef iipr::TConvolutionProcessorComp<
				PixelType,
				iipr::CGaussian2dFilterParams,
				iipr::CGaussianKernel2d> BaseClass;

protected:		
	// reimplemented (iipr::TConvolutionProcessorComp)
	virtual iipr::CGaussianKernel2d* CreateKernel(const iipr::CGaussian2dFilterParams* paramsPtr);
};


// reimplemented (iipr::TConvolutionProcessorComp)

template <typename PixelType>
iipr::CGaussianKernel2d* TGaussianProcessorComp<PixelType>::CreateKernel(const iipr::CGaussian2dFilterParams* paramsPtr)
{
	if (paramsPtr == NULL){
		return NULL;
	}

	iipr::CGaussianKernel2d* kernelPtr = new iipr::CGaussianKernel2d(	paramsPtr->GetSigma1(),
																		paramsPtr->GetSigma2(),
																		paramsPtr->GetAngle());
	return kernelPtr;
}


typedef TGaussianProcessorComp<I_BYTE> CGaussianFilterComp;


} // namespace iipr


#endif // !iipr_TGaussianProcessorComp_included

