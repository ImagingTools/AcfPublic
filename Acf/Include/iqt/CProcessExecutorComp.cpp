/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CProcessExecutorComp.h"


// Qt includes
#include <QProcess>
#include <QMetaType>


namespace iqt
{


// public methods

CProcessExecutorComp::CProcessExecutorComp()
	:m_isFailed(false)
{
	qRegisterMetaType<QProcess::ProcessError>("QProcess::ProcessError");

	connect(&m_applicationProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(OnError(QProcess::ProcessError)));
	connect(&m_applicationProcess, SIGNAL(readyReadStandardError()), this, SLOT(OnReadyReadStandardError()));
	connect(&m_applicationProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(OnReadyReadStandardOutput()));
}


// reimplemented (ibase::IProcessExecutor)
	
void CProcessExecutorComp::SetEnvironment(const isys::IProcessEnvironment& processEnvironment)
{
	QMutexLocker blockProcessing(&m_lock);

	if (m_applicationProcess.state() != QProcess::NotRunning){
		SendErrorMessage(0, "Process already running. Environment cannot be set.");

		return;
	}

	isys::IProcessEnvironment::EnvironmentVariables environmentVariables = processEnvironment.GetEnvironmentVariables();

	QProcessEnvironment qtProcessEvironment;

	for (		isys::IProcessEnvironment::EnvironmentVariables::const_iterator index = environmentVariables.begin();
				index != environmentVariables.end();
				index++){
		qtProcessEvironment.insert(iqt::GetQString(index->first), iqt::GetQString(index->second));
	}

	m_applicationProcess.setProcessEnvironment(qtProcessEvironment);

	m_applicationProcess.setWorkingDirectory(iqt::GetQString(processEnvironment.GetWorkingDirectory()));
}


int CProcessExecutorComp::ExecuteProcess(const istd::CString& executablePath, const istd::CStringList& processArguments)
{
	QMutexLocker blockProcessing(&m_lock);

	m_isFailed = false;

	m_applicationProcess.start(iqt::GetQString(executablePath), iqt::GetQStringList(processArguments));

	m_applicationProcess.waitForFinished(-1);

	if (m_isFailed || m_applicationProcess.error() != QProcess::UnknownError){
		return -1;
	}

	return m_applicationProcess.exitCode();
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CProcessExecutorComp::OnComponentDestroyed()
{
	QMutexLocker blockProcessing(&m_lock);

	if (m_applicationProcess.state() == QProcess::Running){
		m_applicationProcess.terminate();

		if (!m_applicationProcess.waitForFinished(2000)){
			m_applicationProcess.kill();
		}
	}

	BaseClass::OnComponentDestroyed();
}


// protected slots:

void CProcessExecutorComp::OnError(QProcess::ProcessError error)
{   
	m_isFailed = true;

	switch (error){
		case QProcess::FailedToStart:
			SendErrorMessage(0, "Process could not be started.");
			break;
		case QProcess::Crashed:
			SendErrorMessage(0, "The process crashed during execution.");
			break;
		case QProcess::ReadError:
			SendErrorMessage(0, "An error occurred when attempting to read from the process.");
			break;
		case QProcess::WriteError:
			SendErrorMessage(0, "An error occurred when attempting to write to the process.");
			break;
		case QProcess::UnknownError:
		default:
			SendErrorMessage(0, "An unknown error is occured.");
	}
}


void CProcessExecutorComp::OnReadyReadStandardError()
{
	QString errorOutput = m_applicationProcess.readAllStandardError();
	
	errorOutput = errorOutput.simplified();

	SendErrorMessage(0, iqt::GetCString(errorOutput));
}


void CProcessExecutorComp::OnReadyReadStandardOutput()
{
	QString standardOutput = m_applicationProcess.readAllStandardOutput();

	standardOutput = standardOutput.simplified();

	SendInfoMessage(0, iqt::GetCString(standardOutput));
}


} // namespace iqt


