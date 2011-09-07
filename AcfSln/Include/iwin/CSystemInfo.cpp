/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


// ACF-Solutions includes
#include "iwin/CSystemInfo.h"


// Windows includes
#include <winsock2.h>
#include <mbstring.h>
#include <iphlpapi.h>


namespace iwin
{


// public methods

CSystemInfo::CSystemInfo()
{
	GetSystemInfo();
}


// protected methods

void CSystemInfo::GetSystemInfo()
{
	char computerNameBuffer[1024] = {0};
	DWORD bufferSize = 1024;
	::GetComputerName(computerNameBuffer, &bufferSize);
	m_computerName = computerNameBuffer;

	SYSTEM_INFO info;
	::GetSystemInfo(&info);

	m_processorIds.resize(info.dwNumberOfProcessors);

	for (int processorIndex = 0; processorIndex < int(m_processorIds.size()); processorIndex++){
		m_processorIds[processorIndex] = info.wProcessorRevision;
	}

	m_networkAdapters = GetNetworkAdapters();
}


// private static methods

CSystemInfo::NetworkAdapters CSystemInfo::GetNetworkAdapters()
{
	NetworkAdapters adapters;

    IP_ADAPTER_INFO adapterInfo[100];
    DWORD dwBufLen = sizeof(adapterInfo);
    
	DWORD dwStatus = GetAdaptersInfo(adapterInfo, &dwBufLen);
	if (dwStatus != ERROR_SUCCESS){
        return adapters;
	}

    PIP_ADAPTER_INFO adapterInfoPtr = adapterInfo;
    char szBuffer[256];
    while (adapterInfoPtr != NULL){
        if (adapterInfoPtr->Type == MIB_IF_TYPE_ETHERNET){
			sprintf_s(szBuffer, sizeof(szBuffer), "%.2x-%.2x-%.2x-%.2x-%.2x-%.2x"
                        , adapterInfoPtr->Address[0]
                        , adapterInfoPtr->Address[1]
                        , adapterInfoPtr->Address[2]
                        , adapterInfoPtr->Address[3]
                        , adapterInfoPtr->Address[4]
                        , adapterInfoPtr->Address[5]);
			adapters.push_back(szBuffer);
        }
      
		adapterInfoPtr = adapterInfoPtr->Next;
    }

	return adapters;
}


} // namespace iwin

