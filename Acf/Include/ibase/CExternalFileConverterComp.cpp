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


#include "ibase/CExternalFileConverterComp.h"


// Qt includes
#include <QtCore/QStringList>
#include <QtCore/QProcess>


namespace ibase
{


// reimplemented (ibase::IFileConvertCopy)

bool CExternalFileConverterComp::ConvertFile(
			const QString& inputFilePath,
			const QString& outputFilePath,
			const iprm::IParamsSet* /*paramsSetPtr*/) const
{
	if (!m_executablePathCompPtr.IsValid()){
		SendErrorMessage(0, "Path for an executable was not set");

		return false;
	}

	if (m_executablePathCompPtr->GetPathType() != iprm::IFileNameParam::PT_FILE){
		SendErrorMessage(0, "Wrong executable path type. Must be path to a file.");

		return false;
	}

	QStringList arguments;

	// setup command line arguments:
	if (!m_processArgumentsAttrPtr.IsValid()){
		arguments.push_back(inputFilePath);
		arguments.push_back(outputFilePath);
	}
	else{
		QString applicationArguments = *m_processArgumentsAttrPtr;

		arguments = applicationArguments.split(" ");

		for (int argIndex = 0; argIndex < int(arguments.size()); argIndex++){
			arguments[argIndex].replace("$(Input)", inputFilePath);
			arguments[argIndex].replace("$(Output)", outputFilePath);
		}
	}

	m_conversionProcess.start(m_executablePathCompPtr->GetPath(), arguments);

	m_conversionProcess.waitForFinished(-1);

	if (m_conversionProcess.error() != QProcess::UnknownError){
		return false;
	}

	return (m_conversionProcess.exitCode() == 0);
}


// protected methods

// reimplemented (icomp::CComponentBase)
	
void CExternalFileConverterComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	connect(&m_conversionProcess, SIGNAL(readyReadStandardError()), this, SLOT(OnReadyReadStandardError()));
	connect(&m_conversionProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(OnReadyReadStandardOutput()));
}


// private slots

void CExternalFileConverterComp::OnReadyReadStandardError()
{
	QString errorOutput = m_conversionProcess.readAllStandardError();
	
	errorOutput = errorOutput.simplified();

	SendErrorMessage(0, errorOutput);
}


void CExternalFileConverterComp::OnReadyReadStandardOutput()
{
	QString standardOutput = m_conversionProcess.readAllStandardOutput();

	standardOutput = standardOutput.simplified();

	SendInfoMessage(0, standardOutput);
}



} // namespace ibase


