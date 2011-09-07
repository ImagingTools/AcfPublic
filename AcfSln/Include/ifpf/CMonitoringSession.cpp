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


#include "ifpf/CMonitoringSession.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace ifpf
{	


// public methods

// reimplemented (ifpf::IMonitoringSession)

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


// reimplemented (iser::ISerializable)

bool CMonitoringSession::Serialize(iser::IArchive& archive)
{	
	bool retVal = true;

	static iser::CArchiveTag directorySnapShotTag("DirectorySnapshot", "List of already monitored files");
	static iser::CArchiveTag monitoredFileTag("MonitoredFile", "Already monitored file");
	
	int filesCount = m_sessionFiles.size();
	retVal = retVal && archive.BeginMultiTag(directorySnapShotTag, monitoredFileTag, filesCount);
	if (archive.IsStoring()){
		for (int fileIndex = 0; fileIndex < filesCount; fileIndex++){
			retVal = retVal && archive.BeginTag(monitoredFileTag);

			retVal = retVal && m_sessionFiles[fileIndex].Serialize(archive);
			
			retVal = retVal && archive.EndTag(monitoredFileTag);		
		}
	}
	else{
		m_sessionFiles.clear();

		for (int fileIndex = 0; fileIndex < filesCount; fileIndex++){
			retVal = retVal && archive.BeginTag(monitoredFileTag);

			isys::CFileInfo fileItem;
			retVal = retVal && fileItem.Serialize(archive);
				
			if (retVal){
				m_sessionFiles.push_back(fileItem);
			}

			retVal = retVal && archive.EndTag(monitoredFileTag);		
		}	
	}

	retVal = retVal && archive.EndTag(directorySnapShotTag);

	return retVal;
}


} // namespace ifpf


