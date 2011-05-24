/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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



