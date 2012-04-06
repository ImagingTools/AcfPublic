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

#include "SmaGigEPck.h"


namespace SmaGigEPck
{


I_EXPORT_PACKAGE(
			"Iacf/Camera/GigE/Smartek",
			"GigE Vision camera package based on Smartek SDK",
			"GigE Vision Qt Standard" IM_PROJECT("IACF") IM_TAG("Qt \"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\""));


I_EXPORT_COMPONENT(
			GenicamCamera,
			"Implementation of camera interface using Genicam interface",
			"Genicam Grabber Camera Acquisition Bitmap Image");


} // namespace SmaGigEPck


