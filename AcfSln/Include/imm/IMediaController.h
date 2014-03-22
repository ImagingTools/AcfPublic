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


#ifndef imm_IMediaController_included
#define imm_IMediaController_included


// ACF includes
#include "istd/IChangeable.h"
#include <QtCore/QString>
#include "ifile/IFileTypeInfo.h"

#include "imm/imm.h"


namespace imm
{


class IMediaController:
			virtual public istd::IChangeable,
			virtual public ifile::IFileTypeInfo
{
public:
	enum ChangeFlags
	{
		CF_STATUS = 1 << 28,
		CF_MEDIA_POSITION = 1 << 29,
	};

	enum SupportedFeatures
	{
		SF_OPEN_MEDIA = 0x1,
		SF_PLAY = 0x2,
		SF_SEEK = 0x4,
		SF_AUTO_PLAY = 0x8
	};

	/**
		Get URL of the medium object.
	*/
	virtual QString GetOpenedMediumUrl() const = 0;

	/**
		Open some media file.
	*/
	virtual bool OpenMediumUrl(const QString& url, bool autoPlay = true) = 0;

	/**
		Close this media player.
		It stops playing and closes media file.
	*/
	virtual void CloseMedium() = 0;

	/**
		Return true, if media is currntly playing.
	*/
	virtual bool IsPlaying() const = 0;

	/**
		Play or pause current media.
	*/
	virtual bool SetPlaying(bool state = true) = 0;

	/**
		Return length of opened media.
	*/
	virtual double GetMediumLength() const = 0;

	/**
		Get current position.
	*/
	virtual double GetCurrentPosition() const = 0;

	/**
		Skip to some position of media stream.
	*/
	virtual bool SetCurrentPosition(double position) = 0;

	/**
		Get info about features, that are supported by this media controller.
		\sa SupportedFeatures
	*/
	virtual int GetSupportedFeatures() const = 0;
};


} // namespace imm


#endif // !imm_IMediaController_included


