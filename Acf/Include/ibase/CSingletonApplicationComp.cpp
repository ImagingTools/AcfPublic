/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "ibase/CSingletonApplicationComp.h"


// Qt includes
#include <QtCore/QString>
#include <QtCore/QThread>
#include <QtGui/QApplication>

#ifdef Q_OS_MAC
#include <Carbon/Carbon.h>
#endif


namespace ibase
{


CSingletonApplicationComp::CSingletonApplicationComp()
	:m_isAlreadyRunning(false)
{
}


// reimplemented (ibase::IApplication)

bool CSingletonApplicationComp::InitializeApplication(int argc, char** argv)
{
	if (m_isAlreadyRunning){
		qDebug("Application already started");

		return false;
	}

	if (m_slaveApplicationCompPtr.IsValid()){
		return m_slaveApplicationCompPtr->InitializeApplication(argc, argv);
	}

	return false;
}


int CSingletonApplicationComp::Execute(int argc, char** argv)
{
	if (m_isAlreadyRunning){
		qDebug("Application already started");

		return 0;	
	}

	if (m_slaveApplicationCompPtr.IsValid()){
		return m_slaveApplicationCompPtr->Execute(argc, argv);
	}

	return -1;
}


QString CSingletonApplicationComp::GetHelpText() const
{
	if (m_slaveApplicationCompPtr.IsValid()){
		return m_slaveApplicationCompPtr->GetHelpText();
	}

	return QString();
}


QStringList CSingletonApplicationComp::GetApplicationArguments() const
{
	if (m_slaveApplicationCompPtr.IsValid()){
		return m_slaveApplicationCompPtr->GetApplicationArguments();
	}

	return QStringList();
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CSingletonApplicationComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_applicationInfoCompPtr.IsValid()){	
		QString applicationId = QString("%1/%2/%3")
					.arg(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_PRODUCT_NAME))
					.arg(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME))
					.arg(m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_SUBNAME));

		m_processData.SetPtr(new QSharedMemory(applicationId));
		
		m_isAlreadyRunning = false;

		if (!m_processData->attach()){
			if (m_processData->create(sizeof(RunningProcessInfo))){
				if (m_processData->lock()){
					RunningProcessInfo* dataPtr = (RunningProcessInfo*)m_processData->data();
					if (dataPtr != NULL){
						dataPtr->processId = QCoreApplication::applicationPid();
					}
				}

				m_processData->unlock();
			}
		}
		else{
			RunningProcessInfo* dataPtr = (RunningProcessInfo*)(m_processData->data());
			if (dataPtr->processId == 0){
				dataPtr->processId = QCoreApplication::applicationPid();
			}
			else{
#ifdef Q_OS_MAC
				ProcessSerialNumber psn;
				if (GetProcessForPID(dataPtr->processId, &psn) == 0){
					m_isAlreadyRunning = true;
				}
#else
				m_isAlreadyRunning = true;
#endif//!Q_OS_MAC
			}
		}
	}
}


void CSingletonApplicationComp::OnComponentDestroyed()
{
	if (m_processData->isAttached()){
		RunningProcessInfo* dataPtr = (RunningProcessInfo*)m_processData->data();
		if (dataPtr->processId == QCoreApplication::applicationPid()){
			dataPtr->processId = 0;
		}
		m_processData->detach();
	}

	BaseClass::OnComponentDestroyed();
}

} // namespace ibase



