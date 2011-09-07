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


#include "idev/CDeviceInfo.h"


namespace idev
{


CDeviceInfo::CDeviceInfo()
{
}


// reimplemented (idev::IDeviceInfo)

istd::CString CDeviceInfo::GetDeviceId() const
{
	return m_deviceId;
}


void CDeviceInfo::SetDeviceId(const istd::CString& /*deviceId*/)
{
}


I_DWORD CDeviceInfo::GetDeviceDriverVersion() const
{
	return m_deviceDriverVersion;
}


void CDeviceInfo::SetDeviceDriverVersion(I_DWORD /*deviceVersion*/)
{
}


I_DWORD CDeviceInfo::GetDeviceLibraryVersion() const
{
	return m_deviceLibraryVersion;
}


void CDeviceInfo::SetDeviceLibraryVersion(I_DWORD /*libararyVersion*/)
{
}


// reimplemented (iser::ISerializable)

bool CDeviceInfo::Serialize(iser::IArchive& /*archive*/)
{
	return true;
}


} // namespace idev


