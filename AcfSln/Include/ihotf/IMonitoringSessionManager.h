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


#ifndef ihotf_IMonitoringSessionManager_included
#define ihotf_IMonitoringSessionManager_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "istd/IChangeable.h"
#include "ihotf/IMonitoringSession.h"


namespace ihotf
{


/**
	Common interface for a monitoring session's manager.
	Over this interface a directory monitor can get its monitoring session object for a given directory path.
*/
class IMonitoringSessionManager: virtual public istd::IChangeable
{
public:

	/**
		Clear all session data.
	*/
	virtual void ResetSessions() = 0;

	/**
		Get monitoring session for the given monitor and directory path.
	*/
	virtual ihotf::IMonitoringSession* GetSession(const QString& directoryPath) const = 0;

	/**
		Remove the monitoring session for a given directory path.
	*/
	virtual void RemoveSession(const QString& directoryPath) = 0;
};


} // namespace ihotf


#endif // !ihotf_IMonitoringSessionManager_included


