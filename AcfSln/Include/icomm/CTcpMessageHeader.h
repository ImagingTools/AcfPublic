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


// Qt includes
#include <QtCore/QtGlobal>


namespace icomm
{


/**
	Data definition for simple communication header.
*/
class CTcpMessageHeader
{
public:
	enum ClientCommand
	{
		/**
			Client set its version to the server.
		*/
		CC_VERSION_COMMAND,
		/**
			Client call server-side request.
		*/
		CC_REQUEST_COMMAND,
		/**
			Server send the response to the client request.
		*/
		CC_RESPONSE_COMMAND
	};

	quint32 command;
	quint32 size;
};


}// namespace icomm


