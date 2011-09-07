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


 #ifndef ifpf_CMonitoringSessionsManager_included
#define ifpf_CMonitoringSessionsManager_included


// STL includes
#include <map>


// ACF includes
#include "istd/TDelPtr.h"


// AcfSln includes
#include "ifpf/IMonitoringSessionManager.h"
#include "ifpf/CMonitoringSession.h"


namespace ifpf
{


class CMonitoringSessionsManager:
			virtual public iser::ISerializable,
			virtual public ifpf::IMonitoringSessionManager
{
public:
	// reimplemented (ifpf::IMonitoringSessionManager)
	virtual void ResetSessions();
	virtual ifpf::IMonitoringSession* GetSession(const istd::CString& directoryPath) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	typedef std::map<istd::CString, istd::TDelPtr<ifpf::CMonitoringSession> > MonitoringSessionsMap;
	mutable MonitoringSessionsMap m_monitorSessionsMap;
};


} // namespace ifpf


#endif // !ifpf_CMonitoringSessionsManager_included


