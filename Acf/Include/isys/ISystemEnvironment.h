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


#ifndef isys_ISystemEnviroment_included
#define isys_ISystemEnviroment_included


#include "istd/IPolymorphic.h"
#include "istd/CString.h"


namespace isys
{

/**
	Interface to getting the information about the currently system configuration.

	\ingroup System
*/
class ISystemEnvironment: virtual public istd::IPolymorphic
{
public:
	/**
		Return the name of currently logged user.
	*/
	virtual istd::CString GetUser() const = 0;

	/**
		Return the path of the system temp directory.
	*/
	virtual istd::CString GetTempDirPath() const = 0;

	/**
		Get the value of system variable.
		\param variableName Name of the system variable
	*/
	virtual istd::CString GetSystemVariableValue(const istd::CString& variableName) const = 0;

	/**
		Generate unique identifier.
	*/
	virtual istd::CString GetUniqueIdentifier() const = 0;
};


} // namespace isys


#endif // isys_ISystemEnvironment_included


