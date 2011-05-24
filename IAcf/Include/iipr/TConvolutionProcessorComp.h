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


#ifndef iipr_TConvolutionProcessorComp_included
#define iipr_TConvolutionProcessorComp_included


#include "iipr/TImageParamProcessorCompBase.h"

#include "iipr/CConvolutionKernel2d.h"


namespace iipr
{


/**
	Implementation of general convolution operator.
*/
template <typename PixelType, class ParameterType> 
class TConvolutionProcessorComp: public iipr::TImageParamProcessorCompBase<ParameterType>
{
public:
	typedef iipr::TImageParamProcessorCompBase<ParameterType> BaseClass;

protected:		
	// abstract methods
	virtual CConvolutionKernel2d* CreateKernel(const ParameterType* paramsPtr) = 0;

	// reimplemented (iipr::TImageParamProcessorCompBase<ParameterType>)
	virtual bool ParamProcessImage(
				const ParameterType* paramsPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);
};


// reimplemented (iipr::TImageParamProcessorCompBase<ParameterType>)

template <typename PixelType, class ParameterType> 
bool TConvolutionProcessorComp<PixelType, ParameterType, Kernel>::ParamProcessImage(
			const ParameterType* paramsPtr,
			const iimg::IBitmap& inputImage,
			iimg::IBitmap& outputImage)
{
	if (paramsPtr == NULL){
		return false;
	}

	bool retVal = true;

	istd::TDelPtr<CConvolutionKernel2d> filterKernelPtr(CreateKernel(paramsPtr));
	if (!filterKernelPtr.IsValid()){
		return false;
	}

	// initialize kernel with input image:
	filterKernelPtr->InitForBitmap(inputImage);

	outputImage

	return retVal;
}


} // namespace iipr


#endif // !iipr_TConvolutionProcessorComp_included

