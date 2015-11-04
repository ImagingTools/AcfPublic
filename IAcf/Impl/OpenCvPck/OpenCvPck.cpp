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


#include "icomp/export.h"

#include "OpenCvPck.h"


namespace OpenCvPck
{


I_EXPORT_PACKAGE(
			"Iacf/OpenCv",
			"OpenCV integration",
			"OpenCV" IM_PROJECT("IACF") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			OpenCvAcquisition,
			"Implementation of camera interface using OpenCV API",
			"OpenCV Camera Acquisition Bitmap Image" IM_TAG("Camera"));

I_EXPORT_COMPONENT(
			OpenCvVideoController,
			"OpenCV-based video controller",
			"OpenCV Video Multimedia Controller" IM_TAG("Multimedia"));

I_EXPORT_COMPONENT(
			OpenCvBlobExtractor,
			"OpenCV-based blob extraction",
			"OpenCV Blob Search Object");

I_EXPORT_COMPONENT(
			CorrSearchProcessor,
			"OpenCV-based normalized correlation search processor",
			"OpenCV Normalized Correlation Search Processor Model Image Find Pattern Matching");


} // namespace OpenCvPck


