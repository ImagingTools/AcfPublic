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
#include <iocv/COcvProcessorCompBase.h>


namespace iocv
{


/**
	Adaptive double threshold binarization processor.
*/
class COcvBandPassBinarizationComp: public iocv::COcvProcessorCompBase
{
public:
	typedef iocv::COcvProcessorCompBase BaseClass;
	
	I_BEGIN_COMPONENT(COcvBandPassBinarizationComp);
		I_ASSIGN(m_thresholdLowParamsIdAttrPtr, "ThresholdLowParamsId", "ID of the threshold low parameter in the parameter set", true, "ThresholdLow");
		I_ASSIGN(m_thresholdHighIdAttrPtr, "ThresholdHighParamsId", "ID of the threshold high parameter in the parameter set", true, "ThresholdHigh");
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual iproc::IProcessor::TaskState DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL) override;

private:
	I_ATTR(QByteArray, m_thresholdLowParamsIdAttrPtr);
	I_ATTR(QByteArray, m_thresholdHighIdAttrPtr);
};


} // namespace iocv


