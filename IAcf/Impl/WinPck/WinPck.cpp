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


#include "icomp/export.h"

#include "WinPck.h"


namespace WinPck
{


I_EXPORT_PACKAGE(
			"WinPck",
			"Widows dependend standard package",
			"Win32 Windows" IM_PROJECT("IACF") IM_TAG("General") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\""));


I_EXPORT_COMPONENT(
			TimeStampCache,
			"Implementation of time stamp provider used to hold a copy of another provider",
			"Time Stamp Provider Copy Cache");


} // namespace WinPck


