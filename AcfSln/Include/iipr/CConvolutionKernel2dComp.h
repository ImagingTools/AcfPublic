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


#ifndef iipr_CConvolutionKernel2dComp_included
#define iipr_CConvolutionKernel2dComp_included


// ACF includes
#include <icomp/CComponentBase.h>

// ACF-Solutions includes
#include <iipr/CConvolutionKernel2d.h>


namespace iipr
{


class CConvolutionKernel2dComp: public icomp::CComponentBase, public CConvolutionKernel2d
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CConvolutionKernel2d BaseClass2;

	I_BEGIN_COMPONENT(CConvolutionKernel2dComp);
		I_REGISTER_INTERFACE(IConvolutionKernel2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(imath::ISampledFunction2d);
		I_ASSIGN_MULTI_0(m_kernelAttrPtr, "Kernel", "List of kernel coefficients", false);
		I_ASSIGN(m_kernelWidthAttrPtr, "KernelWidth", "Width of the filter kernel", false, 0);
		I_ASSIGN(m_kernelHeightAttrPtr, "KernelHeight", "Height of the filter kernel", false, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

private:
	I_ATTR(int, m_kernelWidthAttrPtr);
	I_ATTR(int, m_kernelHeightAttrPtr);
	I_MULTIATTR(double, m_kernelAttrPtr);
};


} // namespace iipr


#endif // !iipr_CConvolutionKernel2dComp_included

