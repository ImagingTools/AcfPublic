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


#include "iqtfpf/CFileNamingComp.h"


// STL includes
#include <algorithm>


// Qt includes
#include <QFileInfo>
#include <QDir>

#include "iqt/iqt.h"


namespace iqtfpf
{


// public methods

// reimplemented (ifpf::IFileNaming)

istd::CString CFileNamingComp::GetFilePath(const istd::CString& inputFilePath) const
{
	if (!m_directoryPathCompPtr.IsValid()){
		return istd::CString::GetEmpty();
	}

	QFileInfo inputFileInfo(iqt::GetQString(inputFilePath));
	QString baseFileName = inputFileInfo.completeBaseName();
	istd::CString outputExtension = iqt::GetCString(inputFileInfo.suffix());

	// calculate the base file name:
	if (m_fileNamingParamsCompPtr.IsValid()){
		baseFileName = iqt::GetQString(m_fileNamingParamsCompPtr->GetPrefix()) + baseFileName;
		baseFileName += iqt::GetQString(m_fileNamingParamsCompPtr->GetSuffix());
	}

	// calculate the new extension:
	if (m_fileTypeInfoCompPtr.IsValid()){
		istd::CStringList supportedExtensions;
		m_fileTypeInfoCompPtr->GetFileExtensions(supportedExtensions, iser::IFileLoader::QF_NO_LOADING);

		istd::CStringList::const_iterator inputFoundIter = std::find(supportedExtensions.begin(), supportedExtensions.end(), outputExtension);
		if (inputFoundIter == supportedExtensions.end()){
			if (supportedExtensions.empty()){
				outputExtension.clear();
			}
			else{
				outputExtension = supportedExtensions[0];
			}
		}
	}

	QString newFileName = baseFileName + "." + iqt::GetQString(outputExtension);

	QString outputDirectoryPath = iqt::GetQString(m_directoryPathCompPtr->GetPath());

	if (!outputDirectoryPath.isEmpty()){
		QDir outputDirectory(outputDirectoryPath);

		QString outputFilePath = outputDirectory.absoluteFilePath(newFileName);

		if (m_fileNamingParamsCompPtr.IsValid()){
			if (m_fileNamingParamsCompPtr->GetRenamingMode() == ifpf::IFileNamingParams::RM_OVERWRITE){
				return iqt::GetCString(outputFilePath);
			}
			else{
				int counter = 0;
				while (true){
					QFileInfo outputFileInfo(outputFilePath);
					if (outputFileInfo.exists()){
						newFileName = QString("%1_%2").arg(baseFileName).arg(++counter, 3, 10, QChar('0')) + "." + iqt::GetQString(outputExtension);
						
						outputFilePath = outputDirectory.absoluteFilePath(newFileName);
					}
					else{
						break;
					}
				}
			}
		}

		return iqt::GetCString(outputDirectory.absoluteFilePath(newFileName));
	}

	return istd::CString();
}


} // namespace iqtfpf


