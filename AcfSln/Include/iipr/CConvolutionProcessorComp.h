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
#include <iimg/CScanlineMask.h>

// ACF-Solutions includes
#include <iipr/CImageProcessorCompBase.h>
#include <iipr/IConvolutionKernel2d.h>


namespace iipr
{


/**
	Implementation of image processor using convolution kernel.
*/
class CConvolutionProcessorComp: public iipr::CImageProcessorCompBase
{
public:
	typedef iipr::CImageProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(CConvolutionProcessorComp);
		I_ASSIGN(m_trySeparateKernelAttrPtr, "TrySeparateKernel", "If active, detection of kernel separation will be enabled", true, true);
		I_ASSIGN(m_kernelParamsIdAttrPtr, "KernelParamsId", "ID of convolution kernel parameters in the parameter set (iipr::IConvolutionKernel2d)", false, "KernelParams");
		I_ASSIGN(m_defaultKernelParamsCompPtr, "DefaultKernelParams", "Default convolution kernel parameters", false, "DefaultKernelParams");
	I_END_COMPONENT;

	// static methods
	/**
		Calculate complete convolution with all parameters as static function.
		\param	kernel				convolution kernel for this filter.
		\param	backgroundMode		mode of background fill.
		\param	outputPixelFormat	format of output pixel, if equals \c iimg::IBitmap::PF_UNKNOWN will automatically calculated.
		\param	inputImage			input image.
		\param	resultMask			AOI mask where the result pixels should be calculated.
		\param	outputImage			output image.
		\param	loggerPtr			optional object collecting processing messages.
	*/
	static bool DoConvolutionFilter(
				const IConvolutionKernel2d& kernel,
				BackgroundFillMode backgroundMode,
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

private:
	I_ATTR(bool, m_trySeparateKernelAttrPtr);
	I_ATTR(QByteArray, m_kernelParamsIdAttrPtr);
	I_REF(IConvolutionKernel2d, m_defaultKernelParamsCompPtr);
};


} // namespace iipr


#endif // !iipr_CConvolutionProcessorComp_included

