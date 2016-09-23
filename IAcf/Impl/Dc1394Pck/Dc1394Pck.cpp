/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include "Dc1394Pck.h"


#include <icomp/export.h>


namespace Dc1394Pck
{


I_EXPORT_PACKAGE(
			"Iacf/Dc1394",
			"Package based on dc1394 library",
			"IACF 1394 FireWire" IM_PROJECT("IACF") IM_COMPANY("ImagingTools"));

I_EXPORT_COMPONENT(
			SimpleCamera,
			"Simple camera implementation using FireWire communication",
			"Camera Image Bitmap Acquisition Snap Grabber" IM_TAG("Camera") IM_AUTHOR("\"Witold Gantzke\""));


} // namespace Dc1394Pck


