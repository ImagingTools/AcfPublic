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


#ifndef idev_IDeviceInfo_included
#define idev_IDeviceInfo_included


#include "istd/CString.h"

#include "iser/ISerializable.h"


namespace idev
{


/**
	An interface for device description.
*/
class IDeviceInfo: virtual public iser::ISerializable
{
public:
	/**
		Get device id.
	*/
	virtual istd::CString GetDeviceId() const = 0;
	
	/**
		Set device id.
	*/
	virtual void SetDeviceId(const istd::CString& deviceId) = 0;

	/**
		Get device driver version.
	*/
	virtual I_DWORD GetDeviceDriverVersion() const = 0;

	/**
		Set device driver version.
	*/
	virtual void SetDeviceDriverVersion(I_DWORD deviceVersion) = 0;

	/**
		Gets device API version.
	*/
	virtual I_DWORD GetDeviceLibraryVersion() const = 0;

	/**
		Set device driver version.
	*/
	virtual void SetDeviceLibraryVersion(I_DWORD libararyVersion) = 0;
};



} // namespace idev



#endif //!INCLUDED_idev_IDeviceInfo_h



