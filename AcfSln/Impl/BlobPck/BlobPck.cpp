/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "BlobPck.h"


#include "icomp/export.h"


namespace BlobPck
{


I_EXPORT_PACKAGE(
			"AcfSln/BlobPck",
			"Blob extraction and processing package",
			"Blob Search Imaging Tools" IM_PROJECT("ACF-Solutions") IM_TAG("\"Image Blob Processing\"") IM_COMPANY("ImagingTools"));

I_EXPORT_COMPONENT(
			BlobFilterParams,
			"Parameters for the blob filtering",
			"Blob Filter Parameters Search" IM_CATEGORY(I_DATA_MODEL));

I_EXPORT_COMPONENT(
			BlobFilterParamsGui,
			"Editor for the blob filter parameters",
			"Blob Filter Parameters Editor UI GUI");


} // namespace BlobPck


