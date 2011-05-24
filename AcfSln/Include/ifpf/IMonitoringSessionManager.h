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


#ifndef ifpf_IMonitoringSessionManager_included
#define ifpf_IMonitoringSessionManager_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/CString.h"


// ACF-Solutions includes
#include "ifpf/IMonitoringSession.h"


namespace ifpf
{


/**
	Common interface for a monitoring session's manager.
	Over this interface a directory monitor can get its monitoring session object for a given directory path.
*/
class IMonitoringSessionManager: virtual public istd::IPolymorphic
{
public:

	/**
		Clear all session data.
	*/
	virtual void ResetSessions() = 0;

	/**
		Get monitoring session for the given monitor and directory path.
	*/
	virtual ifpf::IMonitoringSession* GetSession(const istd::CString& directoryPath) const = 0;
};


} // namespace ifpf


#endif // !ifpf_IMonitoringSessionManager_included


