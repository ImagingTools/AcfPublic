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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CProcessEnvironment.h"


// Qt includes
#include <QDir>
#include <QCoreApplication>
#include <QProcess>
#include <QThread>


namespace iqt
{


/*
	Helper implementation.
*/
class CQtThread: private QThread
{
public:
	static void Sleep(double seconds)
	{
		QThread::usleep(seconds * 1000000);
	}
};


// public methods

// reimplemented (isys::IProcessEnvironment)

int CProcessEnvironment::GetMainThreadId() const
{
#if defined(Q_WS_X11)
	return int(QThread::currentThreadId());
#else
	return *static_cast<int*>(QThread::currentThreadId());
#endif
}


void CProcessEnvironment::Sleep(double seconds)
{
	CQtThread::Sleep(seconds);
}


QString CProcessEnvironment::GetTempDirPath() const
{
	return QDir::tempPath();
}


QString CProcessEnvironment::GetWorkingDirectory() const
{
	return QDir::currentPath();
}


QStringList CProcessEnvironment::GetApplicationArguments() const
{
	return QCoreApplication::arguments();
}


QString CProcessEnvironment::GetModulePath(bool /*useApplicationModule = false*/, bool onlyDirectory /*= false*/) const
{
	if (!onlyDirectory){
		return QCoreApplication::applicationFilePath();
	}

	return QCoreApplication::applicationDirPath();
}


CProcessEnvironment::EnvironmentVariables CProcessEnvironment::GetEnvironmentVariables() const
{
	QStringList processEnvironment = QProcess::systemEnvironment();
	EnvironmentVariables environmentVariables;

	for (int variableIndex = 0; variableIndex < int(processEnvironment.count()); variableIndex++){
		QString variableEntry = processEnvironment[variableIndex];
		QStringList splitted = variableEntry.split('=');

		if (splitted.count() == 2){
			QString variableName = splitted[0];
			QString variableValue = splitted[1];

			environmentVariables[variableName.toUpper()] = variableValue;
		}
	}

	return environmentVariables;
}


void CProcessEnvironment::SetEnvironmentVariableValue(const QString&/* variableName*/, const QString&/* value*/)
{
	// not implemented yet.
	I_CRITICAL();
}


} // namespace iqt


