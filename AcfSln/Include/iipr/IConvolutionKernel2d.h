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


#ifndef iipr_IConvolutionKernel2d_included
#define iipr_IConvolutionKernel2d_included


// ACF includes
#include "iser/ISerializable.h"


namespace iipr
{


class IConvolutionKernel2d: virtual public iser::ISerializable
{
public:
	/**
		Get size of this kernel.
	*/
	virtual istd::CIndex2d GetKernelSize() const = 0;
	virtual double GetKernelElement(const istd::CIndex2d& index) const = 0;
	virtual bool SetKernelElement(const istd::CIndex2d& index, double value) = 0;
};


} // namespace iipr


#endif // !iipr_IConvolutionKernel2d_included


