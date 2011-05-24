/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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


