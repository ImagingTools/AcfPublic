/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
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

