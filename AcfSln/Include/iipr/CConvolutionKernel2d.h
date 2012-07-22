/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CConvolutionKernel2d_included
#define iipr_CConvolutionKernel2d_included


// ACF includes
#include "imath/CSampledFunction2d.h"

// IACF includes
#include "iipr/IConvolutionKernel2d.h"


namespace iipr
{


/**
	Implementation of a general 2D convolution kernel. 
	Internally the kernel is represented by an array of filter weights and offset positions
	for fast access to the corresponding bitmap values.

	For access and iterating through the kernel values you can use the Begin() and End() function, 
	which returns an iterator/accessor.
*/
class CConvolutionKernel2d:
			virtual public imath::CSampledFunction2d,
			virtual public IConvolutionKernel2d
{
public:
	typedef imath::CSampledFunction2d BaseClass;

	CConvolutionKernel2d();
	CConvolutionKernel2d(const imath::ISampledFunction2d& function2d);

	// reimplemented (iipr::IConvolutionKernel2d)
	virtual istd::CIndex2d GetKernelSize() const;
	virtual void SetKernelSize(const istd::CIndex2d& kernelSize);
	virtual double GetKernelElement(const istd::CIndex2d& index) const;
	virtual bool SetKernelElement(const istd::CIndex2d& index, double value);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);
	virtual quint32 GetMinimalVersion(int versionId) const;
};


} // namespace iipr


#endif // !iipr_CConvolutionKernel2d_included

