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


#include "QtMmPck.h"


#include "icomp/export.h"

#include "iqt/CDefaultServicesProvider.h"


namespace QtMmPck
{


using namespace icomp;


I_EXPORT_SERVICES_PROVIDER(iqt::CDefaultServicesProvider);

I_EXPORT_PACKAGE(
			"QtMm",
			"Qt multimedia package",
			"Media" IM_PROJECT("ACF") IM_TAG("Qt Multimedia") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			VideoPlayerGui,
			"GUI used to create video player with parameters and control bar",
			"Qt Video File Loader Play" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			PhononVideoViewGui,
			"Video widget based on Phonon library",
			"Phonon Widget Video Play" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			MediaLoader,
			"Loader for multimedia files",
			"Video File Loader Play" IM_TAG("Loader"));

I_EXPORT_COMPONENT(
			PlaybackControllerGui,
			"Simple playback controller",
			"Play Controller Frame Sequence Video File Loader Play" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			FrameSeqVideoController,
			"Video controller playing images from directory on external bitmaps",
			"Frame Sequence Bitmaps Images Video Medium Multimedia Directory Play" IM_TAG("Image"));

I_EXPORT_COMPONENT(
			SvgBitmapLoader,
			"Loader for vector graphics SVG files rendering it to bitmap",
			"Bitmap Vector Renderer SVG QT Scalable Graphics" IM_TAG("Image File Loader"));


} // namespace QtMmPck


