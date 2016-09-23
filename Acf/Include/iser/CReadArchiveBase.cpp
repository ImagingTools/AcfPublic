/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iser/CReadArchiveBase.h>


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
	if (bytesCount == int(sizeof(quint32))){
		quint32 mask = (1 << bitsCount) - 1;
		quint32 word = *((quint32*)dataPtr);
		quint32 result = word & mask;

		return Process(result);
	}

	return false;
}


// protected methods

bool CReadArchiveBase::SerializeAcfHeader()
{
	return m_versionInfo.SerializeArchiveHeader(*this);
}


} // namespace iser


