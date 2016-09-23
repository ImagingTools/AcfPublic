/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


 #ifndef ihotf_CMonitoringSessionsManager_included
#define ihotf_CMonitoringSessionsManager_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include <istd/TDelPtr.h>

// AcfSln includes
#include <ihotf/IMonitoringSessionManager.h>
#include <ihotf/CMonitoringSession.h>


namespace ihotf
{


class CMonitoringSessionsManager:
			virtual public iser::ISerializable,
			virtual public ihotf::IMonitoringSessionManager
{
public:
	// reimplemented (ihotf::IMonitoringSessionManager)
	virtual void ResetSessions();
	virtual ihotf::IMonitoringSession* GetSession(const QString& directoryPath) const;
	virtual void RemoveSession(const QString& directoryPath);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	typedef QMap<QString, istd::TDelPtr<ihotf::CMonitoringSession> > MonitoringSessionsMap;
	mutable MonitoringSessionsMap m_monitorSessionsMap;
};


} // namespace ihotf


#endif // !ihotf_CMonitoringSessionsManager_included


