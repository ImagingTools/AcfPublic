/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF-Solutions includes
#include <iproc/TSyncProcessorCompBase.h>
#include <iimg/IBitmap.h>
#include <iprm/IParamsSet.h>

// OpenCV includes
#include <opencv2/imgproc/imgproc.hpp>


namespace iocv
{


class COcvProcessorCompBase : public iproc::CSyncProcessorCompBase
{
public:
	typedef iproc::CSyncProcessorCompBase BaseClass;
	
	I_BEGIN_BASE_COMPONENT(COcvProcessorCompBase);
		I_ASSIGN(m_aoiIdAttrPtr, "AoiParamId", "ID of the AOI parameter in the parameter set", false, "AoiParamId");
	I_END_COMPONENT;

protected:
	bool GetBitmaps(const istd::IPolymorphic* inputPtr, 
				istd::IChangeable* outputPtr, 
				const iimg::IBitmap* &inputBitmapPtr,
				iimg::IBitmap* &outputBitmapPtr) const;

	void MakeProcessedRegionMatrices(const iimg::IBitmap* inputBitmapPtr,
				const iimg::IBitmap* outputBitmapPtr,
				const iprm::IParamsSet* paramsPtr,
				cv::Mat& inputMatrix, 
				cv::Mat& outputMatrix) const;

	bool EmplaceProcessedRegionBack(iimg::IBitmap* outputBitmapPtr,
				const iprm::IParamsSet* paramsPtr,
				cv::Mat& outputMatrix) const;

protected:
	I_ATTR(QByteArray, m_aoiIdAttrPtr);
};


} // namespace iocv


