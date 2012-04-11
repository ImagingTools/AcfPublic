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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CFileCopyOverLoaderComp.h"


// Qt includes
#include <QtCore/QStringList>


namespace ibase
{


// reimplemented (ibase::IFileConvertCopy)

bool CFileCopyOverLoaderComp::ConvertFile(
			const QString& inputFilePath,
			const QString& outputFilePath,
			const iprm::IParamsSet* /*paramsSetPtr*/) const
{
	if (!m_inputLoaderCompPtr.IsValid()){
		SendErrorMessage(0, "Input data loader is not defined", "FileCopyOverLoader");

		return false;
	}

	if (!m_outputLoaderCompPtr.IsValid()){
		SendErrorMessage(0, "Output data loader is not defined", "FileCopyOverLoader");

		return false;
	}

	if (!m_objectCompPtr.IsValid()){
		SendErrorMessage(0, "Data object for copy operaration is not set", "FileCopyOverLoader");

		return false;
	}

	QString usedOutputPath = outputFilePath;

	if (usedOutputPath.isEmpty()){
		QStringList extensions;
		m_outputLoaderCompPtr->GetFileExtensions(extensions);

		if (extensions.isEmpty()){
			SendErrorMessage(0, "File extension list is empty", "FileCopyOverLoader");
	
			return false;
		}

		int pointPos = inputFilePath.lastIndexOf(".");
		if (pointPos != -1){
			usedOutputPath = inputFilePath.left(pointPos + 1) + extensions.front();
		}
		else{
			usedOutputPath = inputFilePath + extensions.front();
		}
	}

	int loadState = m_inputLoaderCompPtr->LoadFromFile(*m_objectCompPtr, inputFilePath);
	if (loadState != iser::IFileLoader::StateOk){
		SendErrorMessage(0, "Data could not be loaded", "FileCopyOverLoader");

		return false;
	}

	int saveState = m_outputLoaderCompPtr->SaveToFile(*m_objectCompPtr, usedOutputPath);
	if (saveState != iser::IFileLoader::StateOk){
		SendErrorMessage(0, "Data could not be saved", "FileCopyOverLoader");

		return false;
	}

	return true;
}


} // namespace ibase


