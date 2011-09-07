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

#include "QtSwrPck.h"


namespace QtSwrPck
{


I_EXPORT_DEFAULT_SERVICES

I_EXPORT_PACKAGE(
			"QtSwrPck",
			"Standard SwissRanger integration package based on Qt",
			"SwissRanger TOF Qt \"Image Processing\"" IM_PROJECT("IACF") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
		SwissRangerParamsGui,
		"SwissRanger parameter editor",
		"SwissRanger Camera 3D Acquisition Parameter GUI Editor");

I_EXPORT_COMPONENT(
			SwissRangerAcquisitionDataView,
			"SwissRanger image view",
			"SwissRanger Camera 3D Acquisition Parameter GUI View Image");


} // namespace QtSwrPck


