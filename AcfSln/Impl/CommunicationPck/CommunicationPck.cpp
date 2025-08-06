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


#include "CommunicationPck.h"


#include <icomp/export.h>


namespace CommunicationPck
{


I_EXPORT_PACKAGE(
			"AcfSln/CommunicationPck",
			"Package for basic components used for communcation",
			IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_TAG("Communication") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			TcpRequestsManager,
			"Request manager for TCP-Protocol",
			"TCP Request Manager" IM_TAG("Network"));

I_EXPORT_COMPONENT(
			TcpClientsManager,
			"Clients manager for TCP-Protocol",
			"TCP Clients Manager" IM_TAG("Network"));

I_EXPORT_COMPONENT(
			UdpServersManager,
			"Server manager for UDP-Protocol",
			"UDP Server Manager" IM_TAG("Network"));

I_EXPORT_COMPONENT(
			UdpStream,
			"Simple UDP datagram receiver",
			"Socket Stream UDP")

I_EXPORT_COMPONENT(
			TcpStream,
			"Simple TCP/IP streamer",
			"Socket Stream TCP IP")


} // namespace CommunicationPck


