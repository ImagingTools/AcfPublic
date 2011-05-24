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


#include "iqt/CSystemEnvironment.h"


// Qt includes
#include <QUuid>
#include <QDir>


namespace iqt
{


// reimplemented (isys::ISystemEnvironment)

istd::CString CSystemEnvironment::GetUser() const
{
	return GetSystemVariableValue("USER");
}


istd::CString CSystemEnvironment::GetTempDirPath() const
{
	return iqt::GetCString(QDir::tempPath());
}


istd::CString CSystemEnvironment::GetUniqueIdentifier() const
{
	return iqt::GetCString(QUuid::createUuid().toString());
}


} // namespace isys


