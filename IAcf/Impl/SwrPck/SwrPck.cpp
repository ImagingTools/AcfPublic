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

#include "SwrPck.h"


namespace SwrPck
{


I_EXPORT_DEFAULT_SERVICES

I_EXPORT_PACKAGE(
			"SwrPck",
			"Standard SwissRanger integration package",
			"SwissRanger TOF Qt \"Image Processing\"" IM_PROJECT("IACF") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			SwissRangerAcquisition,
			"Implementation of camera interface using SwissRanger API",
			"SwissRanger Camera 3D Acquisition Bitmap Image");

I_EXPORT_COMPONENT(
			SwissRangerParams,
			"SwissRanger parameters",
			"SwissRanger Camera 3D Acquisition Parameter");

I_EXPORT_COMPONENT(
			AttributedSwissRangerParams,
			"Attributed SwissRanger parameters",
			"SwissRanger Camera 3D Acquisition Parameter");

I_EXPORT_COMPONENT(
			SwissRangerAcquisitionData,
			"SwissRanger acquisition data",
			"SwissRanger Camera 3D Acquisition Parameter Image");


} // namespace SwrPck


