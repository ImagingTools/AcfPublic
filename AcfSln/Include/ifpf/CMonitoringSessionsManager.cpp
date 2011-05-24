/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "ifpf/CMonitoringSessionsManager.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchivetag.h"


namespace ifpf
{	


// public methods

// reimplemented (ifpf::IMonitoringSessionManager)

void CMonitoringSessionsManager::ResetSessions()
{
	m_monitorSessionsMap.clear();
}


ifpf::IMonitoringSession* CMonitoringSessionsManager::GetSession(const istd::CString& directoryPath) const
{
	MonitoringSessionsMap::const_iterator sessionIter = m_monitorSessionsMap.find(directoryPath);
	if (sessionIter != m_monitorSessionsMap.end()){
		return sessionIter->second.GetPtr();
	}

	ifpf::CMonitoringSession* newSessionPtr = new ifpf::CMonitoringSession;

	m_monitorSessionsMap[directoryPath] = newSessionPtr;

	return newSessionPtr;
}


// reimplemented (iser::ISerializable)

bool CMonitoringSessionsManager::Serialize(iser::IArchive& archive)
{	
	bool retVal = true;

	static iser::CArchiveTag monitoringSessionsTag("MonitoringSessionsManager", "Session list");
	static iser::CArchiveTag monitoringSessionTag("MonitoringSession", "Single session");
	static iser::CArchiveTag directoryPathTag("MonitoringDirectory", "Monitoring directory path");

	int sessionsCount = m_monitorSessionsMap.size();
	retVal = retVal && archive.BeginMultiTag(monitoringSessionsTag, monitoringSessionTag, sessionsCount);
	if (archive.IsStoring()){
		for (MonitoringSessionsMap::iterator index = m_monitorSessionsMap.begin(); index != m_monitorSessionsMap.end(); index++){
			istd::CString directoryPath = index->first;

			retVal = retVal && archive.BeginTag(monitoringSessionTag);
		
			retVal = retVal && archive.BeginTag(directoryPathTag);
			retVal = retVal && archive.Process(directoryPath);
			retVal = retVal && archive.EndTag(directoryPathTag);
			
			retVal = retVal && index->second->Serialize(archive);

			retVal = retVal && archive.EndTag(monitoringSessionTag);		
		}
	}
	else{
		m_monitorSessionsMap.clear();

		for (int fileIndex = 0; fileIndex < sessionsCount; fileIndex++){
			ifpf::CMonitoringSession* sessionPtr = new ifpf::CMonitoringSession;

			retVal = retVal && archive.BeginTag(monitoringSessionTag);

			istd::CString directoryPath;
			retVal = retVal && archive.BeginTag(directoryPathTag);
			retVal = retVal && archive.Process(directoryPath);
			retVal = retVal && archive.EndTag(directoryPathTag);
			

			retVal = retVal && sessionPtr->Serialize(archive);

			retVal = retVal && archive.EndTag(monitoringSessionTag);

			if (retVal){
				m_monitorSessionsMap[directoryPath] = sessionPtr;
			}
		}	
	}

	retVal = retVal && archive.EndTag(monitoringSessionsTag);

	return retVal;
}


} // namespace ifpf


