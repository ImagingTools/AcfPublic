/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "isgige/CGenicamCameraSingleton.h"


// Qt includes
#include <QHostAddress>


namespace isgige{


CGenicamCameraSingleton::CGenicamCameraSingleton()
{
	gige::InitGigEVisionAPI();

	gigeApi = gige::GetGigEVisionAPI();
	if (gigeApi != NULL){
		gigeApi->RegisterCallback(this);
	}
}


CGenicamCameraSingleton::~CGenicamCameraSingleton()
{
	if (gigeApi != NULL){
		gigeApi->UnregisterCallback(this);

		gigeApi = NULL;
	}

	gige::ExitGigEVisionAPI();
}


// protected methods

// reimplemented (gige::ICallbackEvent)

void CGenicamCameraSingleton::OnConnect(gige::IDevice devicePtr)
{
	QHostAddress address(devicePtr->GetIpAddress());

	QString message = tr("Connected to camera with IP: %1").arg(address.toString());

	emit CameraEventLog(gige_EM_TYPE_INFO, message);
}


void CGenicamCameraSingleton::OnDisconnect(gige::IDevice devicePtr)
{
	QHostAddress address(devicePtr->GetIpAddress());

	QString message = tr("Disconnected from camera with IP: %1").arg(address.toString());

	emit CameraEventLog(gige_EM_TYPE_INFO, message);
}


void CGenicamCameraSingleton::OnLog(gige::IDevice /*devicePtr*/, gige::EventMessage eMessage)
{
	emit CameraEventLog(eMessage.messageType, "Internal: " + QString(eMessage.messageString.c_str()));
}


} // namespace isgige


// include of c to cpp bridge from GigEVision SDK
#include "gige_cpp/GigEVisionSDK.cpp"


