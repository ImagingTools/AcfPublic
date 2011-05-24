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


#ifndef iipr_TGaussianKernel_included
#define iipr_TGaussianKernel_included


#include "iipr/TKernel2d.h"


namespace iipr
{


template <typename PixelType, typename KernelType> 
class TGaussianKernel2d: public iipr::TKernel2d<PixelType, KernelType>
{
public:
	typedef iipr::TKernel2d<PixelType, KernelType> BaseClass;

	TGaussianKernel2d();
	TGaussianKernel2d(double sigma1, double sigma2, double angle, const iimg::IBitmap* bitmapPtr = NULL);

protected:
	void CreateKernel(double sigma1, double sigma2, double angle);
};


template <typename PixelType, typename KernelType> 
TGaussianKernel2d<PixelType, KernelType>::TGaussianKernel2d()
{
	I_CRITICAL();
}


template <typename PixelType, typename KernelType> 
TGaussianKernel2d<PixelType, KernelType>::TGaussianKernel2d(
			double sigma1,
			double sigma2, 
			double angle, 
			const iimg::IBitmap* bitmapPtr)
{
	CreateKernel(sigma1, sigma2, angle);

	if (bitmapPtr != NULL){
		BaseClass::InitForBitmap(*bitmapPtr);
	}
}


// protected methods

template <typename PixelType, typename KernelType> 
void TGaussianKernel2d<PixelType, KernelType>::CreateKernel(double /*sigma1*/, double /*sigma2*/, double /*angle*/)
{
//	I_ASSERT(sigma1 != 0);
//	I_ASSERT(sigma2 != 0);

	BaseClass::m_values.resize(25, std::make_pair(0, KernelType(1)));
	BaseClass::m_kernelSize = ibase::CSize(5, 5);
	BaseClass::m_sumWeights = 25;
}


typedef TGaussianKernel2d<I_BYTE, float> CGaussianKernel2d;


} // namespace iipr


#endif // !iipr_TGaussianKernel_included

