/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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


#include <ilog/CLogCompBase.h>


// Qt includes
#include <QtCore/QDateTime>
#include <QtCore/QThread>
#include <QtCore/QMetaType>


namespace ilog
{


// public methods

CLogCompBase::CLogCompBase()
{
	qRegisterMetaType<MessagePtr>("MessagePtr");

	connect(
				this,
				SIGNAL(EmitAddMessage(const MessagePtr&)),
				this,
				SLOT(OnAddMessage(const MessagePtr&)),
				Qt::QueuedConnection);
}


void CLogCompBase::AddMessage(const MessagePtr& messagePtr)
{
	if (messagePtr.IsValid() && IsMessageSupported(messagePtr->GetInformationCategory())){
		QCoreApplication* applicationPtr = QCoreApplication::instance();
		bool isMainThread = (applicationPtr == NULL) || (QThread::currentThread() == applicationPtr->thread());
		if (!isMainThread){
			Q_EMIT EmitAddMessage(messagePtr);
		}
		else{
			OnAddMessage(messagePtr);
		}
	}
}

// private slots

void CLogCompBase::OnAddMessage(const MessagePtr& messagePtr)
{
	BaseClass::AddMessage(messagePtr);

	WriteMessageToLog(messagePtr);
}



} // namespace ilog


