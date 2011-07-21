/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iser/CReadArchiveBase.h"


// ACF includes
#include "iser/TVersionInfoSerializer.h"


namespace iser
{


// reimplemented (iser::IArchive)

bool CReadArchiveBase::IsStoring() const
{
	return false;
}


const IVersionInfo& CReadArchiveBase::GetVersionInfo() const
{
	return m_versionInfo;
}


bool CReadArchiveBase::ProcessBits(void* dataPtr, int bitsCount, int bytesCount)
{
	if (bytesCount == int(sizeof(I_DWORD))){
		I_DWORD mask = (1 << bitsCount) - 1;
		I_DWORD word = *((I_DWORD*)dataPtr);
		I_DWORD result = word & mask;

		return Process(result);
	}

	return false;
}


// protected methods

bool CReadArchiveBase::SerializeAcfHeader()
{
	return TVersionInfoSerializer<CReaderVersionInfo>::ReadVersion(&m_versionInfo, *this);
}


} // namespace iser


