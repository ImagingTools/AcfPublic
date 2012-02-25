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


#include "iser/CReaderVersionInfo.h"


namespace iser
{


void CReaderVersionInfo::Reset()
{
	m_versionIdList.clear();
}


bool CReaderVersionInfo::InsertVersionId(int id, I_DWORD version, const QString& description)
{
	VersionIdElement element(version, description);

	std::pair<VersionElements::iterator, bool> status = m_versionIdList.insert(VersionElements::value_type(id, element));

	return status.second;
}


bool CReaderVersionInfo::RemoveVersionId(int id)
{
	return m_versionIdList.erase(id) > 0;
}


// reimplemented (iser::IVersionInfo)

bool CReaderVersionInfo::GetVersionNumber(int versionId, I_DWORD& result) const
{
	const VersionIdElement& element = GetVersionIdElement(versionId);

	if (&element != &s_element){
		result = element.version;

		return true;
	}

	result = 0xffffffff;

	return false;
}


QString CReaderVersionInfo::GetVersionIdDescription(int versionId) const
{
	const VersionIdElement& element = GetVersionIdElement(versionId);

	return element.description;
}


CReaderVersionInfo::VersionIds CReaderVersionInfo::GetVersionIds() const
{
	VersionIds ids;

	for (		VersionElements::const_iterator iter = m_versionIdList.begin();
				iter != m_versionIdList.end();
				++iter){
		ids.insert(iter->first);
	}

	return ids;
}


QString CReaderVersionInfo::GetEncodedVersionName(int /*versionId*/, I_DWORD /*versionNumber*/) const
{
	return "";
}


// protected methods

const CReaderVersionInfo::VersionIdElement& CReaderVersionInfo::GetVersionIdElement(int versionId) const
{
	VersionElements::const_iterator iter = m_versionIdList.find(versionId);

	if (iter != m_versionIdList.end()){
		return iter->second;
	}

	return s_element;
}


// static attributes

CReaderVersionInfo::VersionIdElement CReaderVersionInfo::s_element(I_DWORD(UnknownVersion), "");


} // namespace iser


