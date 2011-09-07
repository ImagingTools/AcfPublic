/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iwin_CSystemEnvironment_included
#define iwin_CSystemEnvironment_included


#include "isys/CSystemEnvironmentBase.h"


namespace iwin
{


/**
	System implementation of ISystemEnvironment interface on Windows plattform.

	\ingroup Windows
*/
class CSystemEnvironment: virtual public isys::CSystemEnvironmentBase
{
public:
	typedef isys::CSystemEnvironmentBase BaseClass;

	// reimplemented (isys::ISystemEnvironment)
	virtual istd::CString GetUser() const;
	virtual istd::CString GetTempDirPath() const;
	virtual istd::CString GetUniqueIdentifier() const;
};


} // namespace iwin


#endif // iwin_CSystemEnvironment_included


