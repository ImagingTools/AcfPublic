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


#include "iwin/CProcessEnvironment.h"


// Windows includes
#include <windows.h>


EXTERN_C IMAGE_DOS_HEADER __ImageBase;


namespace iwin
{


// public methods
	
// reimplemented (isys::IProcessEnvironment)

int CProcessEnvironment::GetMainThreadId() const
{
	return ::GetCurrentThreadId();
}


void CProcessEnvironment::Sleep(double seconds)
{
	::Sleep(DWORD(seconds * 1000));
}


istd::CString CProcessEnvironment::GetTempDirPath() const
{
	wchar_t tempPath[MAX_PATH] = {0};
	::GetTempPathW(MAX_PATH, tempPath);

	int length = wcslen(tempPath);

	if (tempPath[length - 1] == '\\'){
		tempPath[length - 1] = '\0';
	}

	return istd::CString(tempPath);
}


istd::CString CProcessEnvironment::GetWorkingDirectory() const
{
	wchar_t workingDirectory[MAX_PATH] = {0};

	if (::GetCurrentDirectoryW(MAX_PATH, workingDirectory) != 0){
		return istd::CString(workingDirectory);
	}

	return istd::CString();
}


istd::CStringList CProcessEnvironment::GetApplicationArguments() const
{
	istd::CStringList applicationArguments;

	LPWSTR commandLinePtr = GetCommandLineW();
	if (commandLinePtr != NULL){
		int argumentsCount = 0;
		LPWSTR* applicationArgumentsPtr = CommandLineToArgvW(commandLinePtr, &argumentsCount);
		if (applicationArgumentsPtr != NULL){
			for (int argumentIndex = 0; argumentIndex < argumentsCount; argumentIndex++){
				applicationArguments.push_back(applicationArgumentsPtr[argumentIndex]);
			}
		}
	}

	return applicationArguments;
}


istd::CString CProcessEnvironment::GetModulePath(bool useApplicationModule /*= false*/, bool onlyDirectory /*= false*/) const
{
	WCHAR moduleFileName[MAX_PATH] = {0};

	HINSTANCE moduleBasePtr = useApplicationModule ? NULL : (HINSTANCE)&__ImageBase;

	::GetModuleFileNameW(moduleBasePtr, moduleFileName, MAX_PATH);

	if (onlyDirectory){
		for (int i = MAX_PATH - 1; i >= 0; i--)   {   
			if (moduleFileName[i] == '\\' || moduleFileName[i] == '/'){   
				moduleFileName[i] = '\0';
				break;
			}
		}   	
	}

	return istd::CString(moduleFileName);
}


CProcessEnvironment::EnvironmentVariables CProcessEnvironment::GetEnvironmentVariables() const
{
	EnvironmentVariables environmentVariables;

	LPWCH environmentStringsPtr = GetEnvironmentStringsW();
	if (environmentStringsPtr != NULL){
		LPCWSTR lpszVariable = (LPCWSTR)environmentStringsPtr;
		while (*lpszVariable){
			istd::CString varPair = lpszVariable;
			istd::CString::size_type separatorIndex = varPair.rfind('=');
			if (separatorIndex != istd::CString::npos){
				istd::CString variableName = varPair.substr(0, separatorIndex);
				istd::CString variableValue = varPair.substr(separatorIndex + 1, varPair.length());
			
				environmentVariables[variableName] = variableValue;
			}

			lpszVariable += lstrlenW(lpszVariable) + 1;
		}

		FreeEnvironmentStringsW(environmentStringsPtr);
	}

	return environmentVariables;
}


void CProcessEnvironment::SetEnvironmentVariableValue(const istd::CString& variableName, const istd::CString& value)
{
	::SetEnvironmentVariable(variableName.ToString().c_str(), value.ToString().c_str());
}


} // namespace iwin


