/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef QtMmPck_included
#define QtMmPck_included


#include "icomp/TModelCompWrap.h"

#include "iqtmm/CVideoPlayerGuiComp.h"
#include "iqtmm/CPhononVideoViewGuiComp.h"
#include "iqtmm/CMediaLoaderComp.h"
#include "iqtmm/CPlaybackControllerGuiComp.h"
#include "iqtmm/CFrameSeqVideoControllerComp.h"
#include "iqtmm/CSvgBitmapLoaderComp.h"


/**
	Qt based multimedia package.
*/
namespace QtMmPck
{


typedef iqtmm::CVideoPlayerGuiComp VideoPlayerGui;
typedef iqtmm::CPhononVideoViewGuiComp PhononVideoViewGui;
typedef iqtmm::CMediaLoaderComp MediaLoader;
typedef iqtmm::CPlaybackControllerGuiComp PlaybackControllerGui;
typedef icomp::TModelCompWrap<iqtmm::CFrameSeqVideoControllerComp> FrameSeqVideoController;
typedef iqtmm::CSvgBitmapLoaderComp SvgBitmapLoader;


} // namespace QtMmPck


#endif // !QtMmPck_included


