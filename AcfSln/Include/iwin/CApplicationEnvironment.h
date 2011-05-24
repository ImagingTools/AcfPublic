/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iwin_CApplicationEnvironment_included
#define iwin_CApplicationEnvironment_included


#include "isys/IApplicationEnvironment.h"


namespace iwin
{


/**
	Windows based implementation of interface \c isys::IApplicationEnvironment.

	\ingroup Windows
*/
class CApplicationEnvironment: virtual public isys::IApplicationEnvironment
{
public:
	// reimplemented (isys::IApplicationEnvironment)
	virtual istd::CString GetTempDirPath() const;
	virtual istd::CString GetWorkingDirectory() const;
	virtual istd::CStringList GetApplicationArguments() const;
	virtual istd::CString GetModulePath(bool useApplicationModule = false, bool onlyDirectory = false) const;
	virtual EnvironmentVariables GetEnvironmentVariables() const;
	virtual void SetEnvironmentVariableValue(const istd::CString& variableName, const istd::CString& value);
};


} // namespace iwin


#endif // !iwin_CApplicationEnvironment_included
