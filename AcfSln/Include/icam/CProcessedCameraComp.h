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


#pragma once


// ACF includes
#include <icam/CCameraDelegatorComp.h>


namespace icam
{


/**
	Camera delegator with integrated pre- and post-processing.
*/
class CProcessedCameraComp: public icam::CCameraDelegatorComp
{
public:
	typedef icam::CCameraDelegatorComp BaseClass;

	I_BEGIN_COMPONENT(CProcessedCameraComp);
		I_ASSIGN(m_preProcessorCompPtr, "PreProcessor", "Processor called before snap with camera parameters", false, "PreProcessor");
		I_ASSIGN(m_postProcessorCompPtr, "PostProcessor", "Processor called after snap with camera parameters", false, "PostProcessor");
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int BeginTask(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

private:
	I_REF(iproc::IProcessor, m_preProcessorCompPtr);
	I_REF(iproc::IProcessor, m_postProcessorCompPtr);
};


} // namespace icam


