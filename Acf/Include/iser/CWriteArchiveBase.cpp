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


#include "iser/CWriteArchiveBase.h"


// ACF includes
#include "iser/CArchiveHeaderInfo.h"


namespace iser
{


// reimplemented (iser::IArchive)

bool CWriteArchiveBase::IsStoring() const
{
	return true;
}


const IVersionInfo& CWriteArchiveBase::GetVersionInfo() const
{
	if (m_versionInfoPtr != NULL){
		return *m_versionInfoPtr;
	}
	else{
		return s_emptyVersionInfo;
	}
}


bool CWriteArchiveBase::ProcessBits(void* dataPtr, int bitsCount, int bytesCount)
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

CWriteArchiveBase::CWriteArchiveBase(const IVersionInfo* versionInfoPtr)
:	m_versionInfoPtr(versionInfoPtr)
{
}


bool CWriteArchiveBase::SerializeAcfHeader()
{	
	return CArchiveHeaderInfo::WriteArchiveHeader(*this, m_versionInfoPtr);
}


// public methods of embedded class EmptyVersionInfo

// reimplemented (iser::IVersionInfo)

bool CWriteArchiveBase::EmptyVersionInfo::GetVersionNumber(int /*versionId*/, quint32& result) const
{
	result = 0xffffffff;

	return false;
}


QString CWriteArchiveBase::EmptyVersionInfo::GetVersionIdDescription(int /*versionId*/) const
{
	return "";
}


iser::IVersionInfo::VersionIds CWriteArchiveBase::EmptyVersionInfo::GetVersionIds() const
{
	return iser::IVersionInfo::VersionIds();
}


QString CWriteArchiveBase::EmptyVersionInfo::GetEncodedVersionName(int /*versionId*/, quint32 /*versionNumber*/) const
{
	return "";
}


// static attributes

CWriteArchiveBase::EmptyVersionInfo CWriteArchiveBase::s_emptyVersionInfo;


} // namespace iser


