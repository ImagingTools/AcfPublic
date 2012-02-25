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


#ifndef iwin_CProcessEnvironment_included
#define iwin_CProcessEnvironment_included


#include "isys/IProcessEnvironment.h"


namespace iwin
{


/**
	Windows based implementation of interface \c isys::IProcessEnvironment.

	\ingroup Windows
*/
class CProcessEnvironment: virtual public isys::IProcessEnvironment
{
public:
	// reimplemented (isys::IProcessEnvironment)
	virtual int GetMainThreadId() const;
	virtual void Sleep(double seconds);
	virtual QString GetTempDirPath() const;
	virtual QString GetWorkingDirectory() const;
	virtual QStringList GetApplicationArguments() const;
	virtual QString GetModulePath(bool useApplicationModule = false, bool onlyDirectory = false) const;
	virtual EnvironmentVariables GetEnvironmentVariables() const;
	virtual void SetEnvironmentVariableValue(const QString& variableName, const QString& value);
};


} // namespace iwin


#endif // !iwin_CProcessEnvironment_included
