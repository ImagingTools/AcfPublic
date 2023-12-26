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


#pragma once


// ACF includes
#include <istd/IChangeable.h>


namespace iweb
{


/**
	Interface for the web-server status description.
*/
class IWebServerStatus: virtual public istd::IChangeable
{
public:
	/**
		Server status.
	*/
	enum ServerStatus
	{
		/**
			Status is not available.
		*/
		SS_NONE,

		/**
			Server is currently in the initialization stage. The requests cannot be processed.
		*/
		SS_STARTING,

		/**
			Server is started. All requests can be processed
		*/
		SS_READY,

		/**
			Server is started and processing some maintenance tasks currently.
			It is possible, that some requests cannot be processed.
		*/
		SS_MAINTENANCE
	};

	I_DECLARE_ENUM(ServerStatus, SS_NONE, SS_STARTING, SS_READY, SS_MAINTENANCE);

	/**
		Get the current server status.
	*/
	virtual ServerStatus GetServerStatus() const = 0;

	/**
		Set current server status.
	*/
	virtual void SetServerStatus(ServerStatus status) = 0;
};


} // namespace iweb


