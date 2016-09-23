/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef imm_IVideoController_included
#define imm_IVideoController_included


#include <iimg/IBitmap.h>

#include <imm/IMediaController.h>
#include <imm/IVideoInfo.h>


namespace imm
{


class IVideoController: virtual public IMediaController, virtual public IVideoInfo
{
public:
	enum SupportedFeatures
	{
		SF_GRAB_ANY = 0x100
	};

	/**
		Get index of current frame.
	*/
	virtual int GetCurrentFrame() const = 0;

	/**
		Set index of current frame.
		This works similiar to imm::IMediaController::SetCurrentPosition, but the parameter is frame index.
	*/
	virtual bool SetCurrentFrame(int frameIndex) = 0;
};


} // namespace imm


#endif // !imm_IVideoController_included


