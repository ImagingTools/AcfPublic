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


#ifndef isys_IProcessEnvironment_included
#define isys_IProcessEnvironment_included


// STL includes
#include <map>


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/CString.h"

#include "isys/isys.h"


namespace isys
{


/**
	Interface for access of some system dependent features and infos.

	\ingroup System
*/
class IProcessEnvironment: virtual public istd::IPolymorphic
{
public:
	typedef std::map<istd::CString, istd::CString> EnvironmentVariables;
	
	/**
		Get current thread ID.
	*/
	virtual int GetMainThreadId() const = 0;

	/**
		Suspend the current thread for \c seconds.
	*/
	virtual void Sleep(double seconds) = 0;

	/**
		Returns the standard temp path, that will be used by the application.
	*/
	virtual istd::CString GetTempDirPath() const = 0;

	/**
		Returns the working directory of application.
	*/
	virtual istd::CString GetWorkingDirectory() const = 0;

	/**
		Returns the arguments of command line for running application process.
	*/
	virtual istd::CStringList GetApplicationArguments() const = 0;

	/**
		Returns the module file name. If the \c useApplicationModule is \c true returns the name of application file/directory,
		otherwise the file name or (directory path) of module in which context this function was called.
		if \c onlyDirectory is \c true only directory path will be returned.
	*/
	virtual istd::CString GetModulePath(bool useApplicationModule = false, bool onlyDirectory = false) const = 0;

	/**
		Returns the environment variables of the application process.
		The key of the EnvironmentVariables map is the name of the environment variable.
	*/
	virtual EnvironmentVariables GetEnvironmentVariables() const = 0;

	/**
		Set/Add the value of a system variable to the current process.
		\param variableName Name of the system variable
		\param variableValue Value of the system variable
	*/
	virtual void SetEnvironmentVariableValue(const istd::CString& variableName, const istd::CString& value) = 0;
};


} // namespace isys


#endif // !isys_IProcessEnvironment_included
