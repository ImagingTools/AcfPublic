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


#include "ifpf/CFileListConverterComp.h"


// Qt includes
#include <QtCore/QStringList>
#include <QtCore/QDir>

// ACF-Solutions includes
#include <ifpf/CFilePathesContainer.h>


namespace ifpf
{


// public methods

// reimplemented (iproc:IProcessor)

int CFileListConverterComp::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			iproc::IProgressManager* progressManagerPtr)
{
	if (!m_fileConvertCompPtr.IsValid()){
		return TS_INVALID;
	}

	if (!m_outputFileNameCompPtr.IsValid()){
		return TS_INVALID;
	}

	const ibase::IFileListProvider* inputFileListProviderPtr = dynamic_cast<const ibase::IFileListProvider*>(inputPtr);
	if (inputFileListProviderPtr == NULL){
		return TS_INVALID;
	}

	int progressSessionId = 0;
	
	if (progressManagerPtr != NULL){
		progressSessionId = progressManagerPtr->BeginProgressSession("ConvertFiles", "Convert files", true);
	}

	int retVal = TS_OK;

	CFilePathesContainer* convertedFileListPtr = dynamic_cast<CFilePathesContainer*>(outputPtr);

	QStringList fileList = inputFileListProviderPtr->GetFileList();
	int filesCount = fileList.count();

	double progressStep = 1.0 / (double)filesCount;
	
	if (convertedFileListPtr != NULL){
		convertedFileListPtr->ResetFiles();
	}

	for (int inputFileIndex = 0; inputFileIndex < filesCount; inputFileIndex++){
		const QString& inputFile = fileList[inputFileIndex];

		const QString outputFileName = m_outputFileNameCompPtr->GetFilePath(inputFile);

		QFileInfo outputFileInfo(outputFileName);

		QDir outputDirectory(outputFileInfo.absoluteDir());
		if (!outputDirectory.mkpath(outputFileInfo.absolutePath())){
			SendErrorMessage(0, QObject::tr("Output directry doesn't exist").arg(outputFileInfo.absolutePath()));			
		}

		if (!m_fileConvertCompPtr->ConvertFile(inputFile, outputFileName, paramsPtr)){
			SendErrorMessage(0, QObject::tr("Processing of %1 failed").arg(inputFile));
		}
		else{
			if (convertedFileListPtr != NULL){
				convertedFileListPtr->InsertFile(outputFileName);
			}
		}

		if (progressManagerPtr != NULL){
			progressManagerPtr->OnProgress(progressSessionId, inputFileIndex * progressStep);

			if (progressManagerPtr->IsCanceled(progressSessionId)){
				progressManagerPtr->EndProgressSession(progressSessionId);
			
				return iproc::IProcessor::TS_CANCELED;
			}
		}
	}

	if (progressManagerPtr != NULL){
		progressManagerPtr->EndProgressSession(progressSessionId);
	}

	return retVal;
}


} // namespace ifpf


