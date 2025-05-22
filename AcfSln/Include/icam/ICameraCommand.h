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


#pragma once


// ACF includes
#include <iprm/IParamsSet.h>


namespace icam
{


/**
	Allows to perform additional actions on the camera.
	Typically, in order to execute camera command,
	you need to call camera's DoProcessing() with ICameraCommand implementation
	as input parameter.
*/
class ICameraCommand: virtual public istd::IPolymorphic
{
public:
	enum CommandIds
	{
		CI_RESET_BUFFERS = 0,			// Force reset of image buffers
		CI_RESCAN_CAMERAS,
		CI_READ_SETTINGS,
		CI_STORE_SETTINGS,
		CI_SET_PARAMETERS,
		CI_START_ACQUISITION,
		CI_STOP_ACQUISITION,
		CI_READ_BUFFER,
		CI_READ_LAST_IN_BUFFER,
		CI_USER = 1024					// User defined
	};

	enum CommandStatus
	{
		CS_NONE = 0,			// no command recognized
		CS_OK,					// command executed successfully
		CS_ERROR,				// command executed with errors
		CS_UNKNOWN				// unknown command
	};

	/**
		Returns ID of the command.
	*/
	virtual int GetCommandId() const = 0;
};


} // namespace qcam


