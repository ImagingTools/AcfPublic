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
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QUdpSocket>

// ACF includes
#include <icomp/CComponentBase.h>
#include <ibase/IApplicationInfo.h>
#include <icomm/IResponse.h>
#include <icomm/IStationState.h>


namespace icomm
{


class CTcpClientsManagerComp:
			public QObject,
			public icomp::CComponentBase
{
	Q_OBJECT
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CTcpClientsManagerComp);
		I_ASSIGN(m_applicationInfoCompPtr, "ApplicationInfo", "ApplicationInfo", true, "ApplicationInfo");
		I_ASSIGN(m_stationStateCompPtr, "StationState", "StationState", true, "StationState");
		I_ASSIGN_MULTI_0(m_responsesCompPtr, "Responses", "Responses", true);
		I_ASSIGN(m_portNumberAttrPtr, "PortNumber", "PortNumber", true, 4321);
		I_ASSIGN(m_heartbeatPortAttrPtr, "HeartbeatPort", "HeartbeatPort", false, 4322);
	I_END_COMPONENT;

	CTcpClientsManagerComp();

public Q_SLOTS:
	void OnNewConnection();
	void OnHeartbeatRead();

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	QTcpServer m_tcpServer;
	QUdpSocket m_heartbeatSocket;

	I_REF(ibase::IApplicationInfo, m_applicationInfoCompPtr);
	I_REF(icomm::IStationState, m_stationStateCompPtr);
	I_MULTIREF(icomm::IResponse, m_responsesCompPtr);

	I_ATTR(int, m_portNumberAttrPtr);
	I_ATTR(int, m_heartbeatPortAttrPtr);
};


} // namespace icomm


