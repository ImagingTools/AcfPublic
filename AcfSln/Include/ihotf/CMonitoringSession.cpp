/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "ihotf/CMonitoringSession.h"


// ACF includes
#include "istd/CChangeNotifier.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"
#include "iser/CPrimitiveTypesSerializer.h"


namespace ihotf
{	


// public methods

// reimplemented (ihotf::IMonitoringSession)

const CMonitoringSession::FileItems& CMonitoringSession::GetFileInfoList() const
{
	return m_sessionFiles;
}


void CMonitoringSession::SetFileInfoList(const FileItems& fileList)
{
	if (m_sessionFiles != fileList){
		istd::CChangeNotifier changePtr(this);

		m_sessionFiles = fileList;
	}
}


void CMonitoringSession::RemoveFile(const QString& filePath)
{
	if (m_sessionFiles.contains(filePath)){
		istd::CChangeNotifier changePtr(this);

		m_sessionFiles.remove(filePath);
	}
}


// reimplemented (iser::ISerializable)

bool CMonitoringSession::Serialize(iser::IArchive& archive)
{	
	bool retVal = true;

	static iser::CArchiveTag directorySnapShotTag("DirectorySnapshot", "List of already monitored files");
	static iser::CArchiveTag monitoredFileTag("MonitoredFile", "Already monitored file");
	static iser::CArchiveTag filePathTag("FilePath", "File path");
	static iser::CArchiveTag fileTimeStampTag("ModificationTime", "Time stamp of the last file modification");

	int filesCount = m_sessionFiles.size();
	retVal = retVal && archive.BeginMultiTag(directorySnapShotTag, monitoredFileTag, filesCount);
	if (archive.IsStoring()){
		for (FileItems::Iterator fileIter = m_sessionFiles.begin(); fileIter != m_sessionFiles.end(); ++fileIter){
			retVal = retVal && archive.BeginTag(monitoredFileTag);

			retVal = retVal && archive.BeginTag(filePathTag);
			QString filePath = fileIter.key();
			retVal = retVal && archive.Process(filePath);
			retVal = retVal && archive.EndTag(filePathTag);		

			retVal = retVal && archive.BeginTag(fileTimeStampTag);
			retVal = retVal && iser::CPrimitiveTypesSerializer::SerializeDateTime(archive, fileIter.value());
			retVal = retVal && archive.EndTag(fileTimeStampTag);		
			
			retVal = retVal && archive.EndTag(monitoredFileTag);		
		}
	}
	else{
		m_sessionFiles.clear();

		for (int fileIndex = 0; fileIndex < filesCount; fileIndex++){
			retVal = retVal && archive.BeginTag(monitoredFileTag);

			retVal = retVal && archive.BeginTag(filePathTag);
			QString filePath;
			retVal = retVal && archive.Process(filePath);
			retVal = retVal && archive.EndTag(filePathTag);		

			retVal = retVal && archive.BeginTag(fileTimeStampTag);
			QDateTime modificationTime;
			retVal = retVal && iser::CPrimitiveTypesSerializer::SerializeDateTime(archive, modificationTime);
			retVal = retVal && archive.EndTag(fileTimeStampTag);		
				
			if (!retVal){
				return false;
			}

			m_sessionFiles[filePath] = modificationTime;

			retVal = retVal && archive.EndTag(monitoredFileTag);		
		}	
	}

	retVal = retVal && archive.EndTag(directorySnapShotTag);

	return retVal;
}


} // namespace ihotf


