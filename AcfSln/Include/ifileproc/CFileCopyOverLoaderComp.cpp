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


#include <ifileproc/CFileCopyOverLoaderComp.h>


// Qt includes
#include <QtCore/QStringList>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>


namespace ifileproc
{


// reimplemented (ifileproc::IFileConversion)

int CFileCopyOverLoaderComp::ConvertFiles(
			const QString& inputPath,
			QString& outputPath,
			const iprm::IParamsSet* /*paramsSetPtr*/,
			ibase::IProgressManager* /*progressManagerPtr*/) const
{
	if (!m_inputLoaderCompPtr.IsValid()){
		SendErrorMessage(0, QObject::tr("Input data loader is not defined"), "FileCopyOverLoader");

		return iproc::IProcessor::TS_INVALID;
	}

	if (!m_outputLoaderCompPtr.IsValid()){
		SendErrorMessage(0, QObject::tr("Output data loader is not defined"), "FileCopyOverLoader");

		return iproc::IProcessor::TS_INVALID;
	}

	if (!m_objectCompPtr.IsValid()){
		SendErrorMessage(0, QObject::tr("Data object for copy operaration is not set"));

		return iproc::IProcessor::TS_INVALID;
	}

	QStringList outputExtensions;
	m_outputLoaderCompPtr->GetFileExtensions(outputExtensions);

	if (outputPath.isEmpty()){
		if (outputExtensions.isEmpty()){
			SendErrorMessage(0, QObject::tr("File extension list is empty"));
	
			return iproc::IProcessor::TS_INVALID;
		}

		int pointPos = inputPath.lastIndexOf(".");
		if (pointPos != -1){
			outputPath = inputPath.left(pointPos + 1) + outputExtensions.front();
		}
		else{
			outputPath = inputPath + outputExtensions.front();
		}
	}
	else if (!outputExtensions.isEmpty()){
		QFileInfo outputFileInfo(outputPath);
		QString currentExtension = outputFileInfo.suffix();

		if (currentExtension.isEmpty() || !outputExtensions.contains(currentExtension)){
			outputPath = outputFileInfo.absoluteDir().absoluteFilePath(outputFileInfo.baseName() + "." + outputExtensions.front());
		}
	}

	QFileInfo inputFileInfo(inputPath);
	if (!inputFileInfo.exists()){
		SendWarningMessage(0, QObject::tr("Input file %1 doesn't exist").arg(inputPath));
	}

	int loadState = m_inputLoaderCompPtr->LoadFromFile(*m_objectCompPtr, inputPath);
	if (loadState != ifile::IFilePersistence::OS_OK){
		SendErrorMessage(0, QObject::tr("Data could not be loaded from %1").arg(inputPath));

		return iproc::IProcessor::TS_INVALID;
	}

	int saveState = m_outputLoaderCompPtr->SaveToFile(*m_objectCompPtr, outputPath);
	if (saveState != ifile::IFilePersistence::OS_OK){
		SendErrorMessage(0, QObject::tr("Data could not be saved to %1").arg(outputPath));

		return iproc::IProcessor::TS_INVALID;
	}

	if (IsVerboseEnabled()){
		SendVerboseMessage(QObject::tr("Converted %1 to %2").arg(inputPath).arg(outputPath));
	}

	return iproc::IProcessor::TS_OK;
}


} // namespace ifileproc


