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
#include "iprm/ISelectionParam.h"
#include "iimg/CPixelFormatList.h"

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
		I_ASSIGN(m_normalizeKernelAttrPtr, "NormalizeKernel", "If true then kernel will be automatically normalized", true, false);
		I_ASSIGN(m_outputPixelTypeAttrPtr, "OutputPixelType", "Type of output pixel if not defined over parameters:\n\t0 - As input\n\t1 - Mono\n\t2 - Grayscale\n\t3 - RGB\n\t4 - RGBA\n\t5 - Grayscale 16\n\t6 - Grayscale 32\n\t7 - Float 32\n\t8 - Float 64", true, 0);
		I_ASSIGN(m_outputPixelTypeIdAttrPtr, "OutputPixelTypeId", "ID of output pixel type in parameter set (type iprm::ISelectionParam)", false, "OutputPixelType");
		I_ASSIGN(m_defaultOutputPixelTypeParamCompPtr, "DefaultOutputPixelType", "Default output pixel type if not defined in parameter set", false, "DefaultOutputPixelType");
	I_END_COMPONENT;

protected:
	// reimplemented (iipr::TImageParamProcessorCompBase)
	virtual bool ParamProcessImage(
				const iprm::IParamsSet* paramsPtr,
				const IConvolutionKernel2d* procParamPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);

private:
	I_ATTR(bool, m_normalizeKernelAttrPtr);
	I_ATTR(int, m_outputPixelTypeAttrPtr);
	I_ATTR(QByteArray, m_outputPixelTypeIdAttrPtr);
	I_REF(iprm::ISelectionParam, m_defaultOutputPixelTypeParamCompPtr);

	iimg::CPixelFormatList m_formatList;
};


} // namespace iipr


#endif // !iipr_CConvolutionProcessorComp_included

