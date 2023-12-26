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


#include <icam/CProcessedCameraComp.h>


namespace icam
{


// public methods

// reimplemented (iproc::IProcessor)

int CProcessedCameraComp::BeginTask(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* progressManagerPtr)
{
	BaseClass::InitProcessor(paramsPtr);

	const iprm::IParamsSet* workingParamsPtr = GetWorkingParamsSet(paramsPtr);

	if (m_preProcessorCompPtr.IsValid()){
		m_preProcessorCompPtr->InitProcessor(workingParamsPtr);

		m_preProcessorCompPtr->BeginTask(workingParamsPtr, inputPtr, outputPtr, progressManagerPtr);
	}

	int retVal = TS_OK;
	if (m_slaveCameraCompPtr.IsValid()){
		retVal = BaseClass::BeginTask(paramsPtr, inputPtr, outputPtr, progressManagerPtr);
	}

	if (m_postProcessorCompPtr.IsValid()){
		m_postProcessorCompPtr->InitProcessor(workingParamsPtr);

		m_postProcessorCompPtr->BeginTask(workingParamsPtr, outputPtr, outputPtr, progressManagerPtr);
	}

	return retVal;
}


int CProcessedCameraComp::DoProcessing(
		const iprm::IParamsSet* paramsPtr,
		const istd::IPolymorphic* inputPtr,
		istd::IChangeable* outputPtr,
		ibase::IProgressManager* progressManagerPtr)
{
	const iprm::IParamsSet* workingParamsPtr = GetWorkingParamsSet(paramsPtr);

	BaseClass::InitProcessor(paramsPtr);

	if (m_preProcessorCompPtr.IsValid()){
		m_preProcessorCompPtr->InitProcessor(workingParamsPtr);

		m_preProcessorCompPtr->DoProcessing(workingParamsPtr, inputPtr, outputPtr, progressManagerPtr);
	}

	int retVal = TS_OK;
	if (m_slaveCameraCompPtr.IsValid()){
		retVal = BaseClass::DoProcessing(paramsPtr, inputPtr, outputPtr, progressManagerPtr);
	}

	if (m_postProcessorCompPtr.IsValid()){
		m_postProcessorCompPtr->InitProcessor(workingParamsPtr);

		m_postProcessorCompPtr->DoProcessing(workingParamsPtr, outputPtr, outputPtr, progressManagerPtr);
	}

	return retVal;
}


} // namespace icam


