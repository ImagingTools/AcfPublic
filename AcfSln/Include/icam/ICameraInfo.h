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


#ifndef icam_ICameraInfo_included
#define icam_ICameraInfo_included


// ACF includes
#include <istd/IPolymorphic.h>


namespace icam
{


/**
	Provides common information about the camera.
*/
class ICameraInfo: virtual public istd::IPolymorphic
{
public:
	enum CameraAttribute
	{
		CA_VENDOR,
		CA_MODEL,
		CA_DEVICE_VERSION,
		CA_FIRMWARE_VERSION,
		CA_DEVICE_ID,
		CA_DEVICE_NAME,
		CA_DEVICE_CLASS,
		CA_SERIAL_NUMBER,
		CA_IP_ADDRESS,
		CA_MAC_ADDRESS,
		CA_MAX_WIDTH,
		CA_MAX_HEIGHT,
		CA_PORT,
		CA_USER = 100
	};

	/**
		Get value of camera attribute.
		\param	cameraIndex	index of the camera in the enumerated list
		\param	attributeId	ID of camera attribute \sa CameraAttribute.
	*/
	virtual QString GetCameraAttribute(int cameraIndex, int attributeId) const = 0;
};


} // namespace icam


#endif // !icam_ICameraInfo_included
