/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CFileConvertOverProcessorComp.h"

#include "istd/CStaticServicesProvider.h"

#include "isys/CSectionBlocker.h"


namespace ibase
{


// public methods

CFileConvertOverProcessorComp::CFileConvertOverProcessorComp()
	:m_progressSessionId(0)
{
	m_lock = istd::CreateService<isys::ICriticalSection>();
}


// reimplemented (ibase::IFileConvertCopy)

bool CFileConvertOverProcessorComp::ConvertFile(
			const istd::CString& inputFilePath,
			const istd::CString& outputFilePath,
			const iprm::IParamsSet* /*paramsSetPtr*/) const
{
	isys::CSectionBlocker blocker(m_lock.GetPtr());

	if (!m_inputFileLoaderCompPtr.IsValid()){
		SendErrorMessage(0, "No file loader defined", "File processing component");

		return false;
	}

	if (!m_inputDataCompPtr.IsValid()){
		SendErrorMessage(0, "Input data definition was not set", "File processing component");

		return false;
	}

	if (!m_outputDataCompPtr.IsValid()){
		SendErrorMessage(0, "Output data definition was not set", "File processing component");

		return false;
	}

	if (!m_inputFileLoaderCompPtr->IsOperationSupported(m_inputDataCompPtr.GetPtr(), &inputFilePath, iser::IFileLoader::QF_NO_SAVING)){
		SendErrorMessage(0, "File could not be loaded", "File processing component");
		
		return false;
	}

	if (m_inputFileLoaderCompPtr->LoadFromFile(*m_inputDataCompPtr.GetPtr(), inputFilePath) != iser::IFileLoader::StateOk){
		SendErrorMessage(0, "File could not be loaded", "File processing component");
		
		return false;
	}

	if (!m_processorCompPtr.IsValid()){
		SendErrorMessage(0, "File processor not set", "File processing component");

		return false;
	}

	int processingResult = m_processorCompPtr->DoProcessing(
				m_processingParamsSetCompPtr.GetPtr(),
				m_inputDataCompPtr.GetPtr(),
				m_outputDataCompPtr.GetPtr(),
				m_progressManagerCompPtr.GetPtr());
	if (processingResult != iproc::IProcessor::TS_OK){
		return false;
	}

	iser::IFileLoader* outputFileLoader = m_inputFileLoaderCompPtr.GetPtr();
	if (m_outputFileLoaderCompPtr.IsValid()){
		outputFileLoader = m_outputFileLoaderCompPtr.GetPtr(); 
	}

	I_ASSERT(outputFileLoader != NULL);

	return (outputFileLoader->SaveToFile(*m_outputDataCompPtr.GetPtr(), outputFilePath) == iser::IFileLoader::StateOk);
}


} // namespace ibase


