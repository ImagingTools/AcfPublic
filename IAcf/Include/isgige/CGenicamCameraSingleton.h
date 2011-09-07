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


#ifndef isgige_CGenicamCameraSingleton_included
#define isgige_CGenicamCameraSingleton_included


// Qt includes
#include <QObject>

// GigE includes
#include "gige_cpp/GigEVisionSDK.h"
#include "gige_cpp/ICallbackEvent.h"


namespace isgige{


class CGenicamCameraComp;


class CGenicamCameraSingleton:
			public QObject,
			protected gige::ICallbackEvent
{
	Q_OBJECT

public:
	CGenicamCameraSingleton();
	virtual ~CGenicamCameraSingleton();

	gige::IGigEVisionAPI gigeApi;

signals:
	void CameraEventLog(int type, QString message);

protected:
	// reimplemented (gige::ICallbackEvent)
	virtual void OnConnect(gige::IDevice devicePtr);
	virtual void OnDisconnect(gige::IDevice devicePtr);
	virtual void OnLog(gige::IDevice devicePtr, gige::EventMessage eMessage);
};


} // namespace isgige


#endif //! isgige_CGenicamCameraSingleton_included


