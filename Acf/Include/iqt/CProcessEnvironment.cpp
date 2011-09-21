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
	return *static_cast<int*>(QThread::currentThreadId());
}


void CProcessEnvironment::Sleep(double seconds)
{
	CQtThread::Sleep(seconds);
}


istd::CString CProcessEnvironment::GetTempDirPath() const
{
	return iqt::GetCString(QDir::tempPath());
}


istd::CString CProcessEnvironment::GetWorkingDirectory() const
{
	return iqt::GetCString(QDir::currentPath());
}


istd::CStringList CProcessEnvironment::GetApplicationArguments() const
{
	return iqt::GetCStringList(QCoreApplication::arguments());
}


istd::CString CProcessEnvironment::GetModulePath(bool /*useApplicationModule = false*/, bool onlyDirectory /*= false*/) const
{
	if (!onlyDirectory){
		return iqt::GetCString(QCoreApplication::applicationFilePath());
	}

	return iqt::GetCString(QCoreApplication::applicationDirPath());
}


CProcessEnvironment::EnvironmentVariables CProcessEnvironment::GetEnvironmentVariables() const
{
	QStringList processEnvironment = QProcess::systemEnvironment();
	EnvironmentVariables environmentVariables;

	for (int variableIndex = 0; variableIndex < int(processEnvironment.count()); variableIndex++){
		QString variableEntry = processEnvironment[variableIndex];
		QStringList splitted = variableEntry.split('=');

		if (splitted.count() == 2){
			istd::CString variableName = iqt::GetCString(splitted[0]);
			istd::CString variableValue = iqt::GetCString(splitted[1]);

			environmentVariables[variableName.ToUpper()] = variableValue;
		}
	}

	return environmentVariables;
}


void CProcessEnvironment::SetEnvironmentVariableValue(const istd::CString&/* variableName*/, const istd::CString&/* value*/)
{
	// not implemented yet.
	I_CRITICAL();
}


} // namespace iqt


