/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#include "ibase/CFileCopyOverLoaderComp.h"


namespace ibase
{


// reimplemented (ibase::IFileConvertCopy)

bool CFileCopyOverLoaderComp::CopyFile(
			const istd::CString& inputFilePath,
			const istd::CString& outputFilePath,
			const iprm::IParamsSet* /*paramsSetPtr*/) const
{
	if (!m_inputLoaderCompPtr.IsValid() || !m_outputLoaderCompPtr.IsValid() || !m_objectCompPtr.IsValid()){
		return false;
	}

	istd::CString usedOutputPath = outputFilePath;

	if (usedOutputPath.IsEmpty()){
		istd::CStringList extensions;
		m_outputLoaderCompPtr->GetFileExtensions(extensions);

		if (extensions.empty()){
			return false;
		}

		istd::CString::size_type pointPos = inputFilePath.rfind('.');

		if (pointPos != istd::CString::npos){
			usedOutputPath = inputFilePath.substr(0, pointPos + 1) + extensions.front();
		}
		else{
			usedOutputPath = inputFilePath + extensions.front();
		}
	}

	return		(m_inputLoaderCompPtr->LoadFromFile(*m_objectCompPtr, inputFilePath) == iser::IFileLoader::StateOk) &&
				(m_outputLoaderCompPtr->SaveToFile(*m_objectCompPtr, usedOutputPath) == iser::IFileLoader::StateOk);
}


} // namespace ibase


