/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "BitmapPck.h"


#include "icomp/export.h"


namespace BitmapPck
{


I_EXPORT_PACKAGE(
			"Acf/Bitmap",
			"Bitmap package",
			IM_PROJECT("ACF") IM_TAG("Bitmap") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			Bitmap,
			"QImage based bitmap implementation",
			"QImage" IM_TAG("Image Model"));

I_EXPORT_COMPONENT(
			GeneralBitmap,
			"Buffer based bitmap implementation",
			"Bitmap" IM_TAG("Image Model"));

I_EXPORT_COMPONENT(
			BitmapSurface,
			"QImage based bitmap implementation with surface extension",
			"Sampled Function QImage Surface" IM_TAG("Image Model 3D"));

I_EXPORT_COMPONENT(
			BitmapLoader,
			"Loader loading bitmaps using Qt standard implementations",
			IM_TAG("Image File Loader"));

I_EXPORT_COMPONENT(
			MultiPageBitmap,
			"Multi-page bitmap document",
			IM_TAG("Image Bitmap Document Pages Page"));

I_EXPORT_COMPONENT(
			ComposedBitmapProvider,
			"Provider of the composed bitmap list",
			IM_TAG("Image Bitmap List Multi"));

I_EXPORT_COMPONENT(
			BitmapDocumentLoader,
			"Multi bitmap serializer",
			"Bitmap Multi Loader File Serializer" IM_CATEGORY(I_DATA_PERSISTENCE) IM_TAG("Bitmap Loader"));


} // namespace BitmapPck


