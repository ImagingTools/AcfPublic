/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef imm_IVideoInfo_included
#define imm_IVideoInfo_included


#include <istd/IPolymorphic.h>
#include <istd/CIndex2d.h>

#include <imm/imm.h>


namespace imm
{


class IVideoInfo: virtual public istd::IPolymorphic
{
public:
	/**
		Return length of video in seconds.
	*/
	virtual int GetFramesCount() const = 0;

	/**
		Return time difference between frames.
		If unknown, negative value will be returned.
	*/
	virtual double GetFrameIntervall() const = 0;

	/**
		Return size in pixels of single frame.
		If size is unknown, it returns invalid index object. \sa istd::CIndex2d::IsValid().
	*/
	virtual istd::CIndex2d GetFrameSize() const = 0;

	/**
		Get frame aspect ratio.
		Pixel aspect ratio is proportion of pixel with to pixel height.
		If unknown, negative value will be returned.
	*/
	virtual double GetPixelAspectRatio() const = 0;
};


} // namespace imm


#endif // !imm_IVideoInfo_included


