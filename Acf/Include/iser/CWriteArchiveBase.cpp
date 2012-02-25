/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iser/CWriteArchiveBase.h"


// ACF includes
#include "istd/CStaticServicesProvider.h"

#include "iser/TVersionInfoSerializer.h"


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
	if (bytesCount == int(sizeof(I_DWORD))){
		I_DWORD mask = (1 << bitsCount) - 1;
		I_DWORD word = *((I_DWORD*)dataPtr);
		I_DWORD result = word & mask;

		return Process(result);
	}

	return false;
}


// protected methods

CWriteArchiveBase::CWriteArchiveBase(const IVersionInfo* versionInfoPtr)
:	m_versionInfoPtr(versionInfoPtr)
{
	if (m_versionInfoPtr == NULL){
		m_versionInfoPtr = istd::GetService<IVersionInfo>();
	}
}


bool CWriteArchiveBase::SerializeAcfHeader()
{	
	return TVersionInfoSerializer<IVersionInfo>::WriteVersion(m_versionInfoPtr, *this);
}


// public methods of embedded class EmptyVersionInfo

// reimplemented (iser::IVersionInfo)

bool CWriteArchiveBase::EmptyVersionInfo::GetVersionNumber(int /*versionId*/, I_DWORD& result) const
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


QString CWriteArchiveBase::EmptyVersionInfo::GetEncodedVersionName(int /*versionId*/, I_DWORD /*versionNumber*/) const
{
	return "";
}


// static attributes

CWriteArchiveBase::EmptyVersionInfo CWriteArchiveBase::s_emptyVersionInfo;


} // namespace iser


