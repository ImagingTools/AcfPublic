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


#ifndef idev_CDeviceInfo_included
#define idev_CDeviceInfo_included


#include "idev/IDeviceInfo.h"


namespace idev
{


class CDeviceInfo: virtual public idev::IDeviceInfo
{
public:
	CDeviceInfo();

	// reimplemented (idev::IDeviceInfo)
	virtual istd::CString GetDeviceId() const;
	virtual void SetDeviceId(const istd::CString& deviceId);
	virtual I_DWORD GetDeviceDriverVersion() const;
	virtual void SetDeviceDriverVersion(I_DWORD deviceVersion);
	virtual I_DWORD GetDeviceLibraryVersion() const;
	virtual void SetDeviceLibraryVersion(I_DWORD libararyVersion);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	istd::CString m_deviceId;
	I_DWORD m_deviceDriverVersion;
	I_DWORD m_deviceLibraryVersion;
};


} // namespace idev


#endif //!idev_CDeviceInfo_included


