/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef idev_IDeviceDescription_included
#define idev_IDeviceDescription_included


#include "istd/CString.h"


namespace idev
{


/**
	An interface for device description.
*/
class IDeviceDescription: virtual public iser::ISerializable
{
public:
	/**
		Get device description.
	*/
	virtual istd::CString GetDeviceDescription() const = 0;

	/**
		Set device description.
	*/
	virtual void SetDeviceDescription(const istd::CString& deviceDescription) = 0;

	/**
		Get device name.
	*/
	virtual istd::CString GetDeviceName() const = 0;

	/**
		Set device name. \c deviceName is a free user defined string.
	*/
	virtual void SetDeviceName(const istd::CString& deviceName) = 0;
};


} // namespace idev


#endif //!INCLUDED_idev_IDeviceDescription_h


