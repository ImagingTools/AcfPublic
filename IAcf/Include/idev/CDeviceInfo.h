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


