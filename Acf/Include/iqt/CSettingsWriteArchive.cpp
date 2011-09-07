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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CSettingsWriteArchive.h"


// ACF includes
#include "iqt/iqt.h"


namespace iqt
{


// public methods

CSettingsWriteArchive::CSettingsWriteArchive(
			const QString& organizationName, 
			const QString& productName,
			const iser::IVersionInfo* versionInfoPtr)
:	BaseClass(versionInfoPtr),
	BaseClass2(organizationName, productName)
{
}


// reimplemented (iser::IArchive)

bool CSettingsWriteArchive::BeginTag(const iser::CArchiveTag& tag)
{
	if (!m_openTagsList.empty()){
		TagInfo& multiTag = m_openTagsList.back();
		if (multiTag.subTagId == tag.GetId()){
			multiTag.count--;
		}
	}
	
	m_openTagsList.push_back(TagInfo(tag.GetId()));

	return true;
}


bool CSettingsWriteArchive::BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count)
{
	I_ASSERT(!tag.GetId().empty());

	m_openTagsList.push_back(TagInfo(tag.GetId(), count + 1, subTag.GetId()));

	QString registryKey = CreateKey(false);

	BaseClass2::setValue(registryKey, count);

	return true;
}


bool CSettingsWriteArchive::EndTag(const iser::CArchiveTag& /*tag*/)
{
	I_ASSERT(!m_openTagsList.empty());

	TagInfo& currentTag = m_openTagsList.back();
	if (currentTag.count <= 1){		
		m_openTagsList.pop_back();
	}

	return true;
}


bool CSettingsWriteArchive::Process(std::string& value)
{
	if (m_openTagsList.empty()){
		return false;
	}

	QString registryKey = CreateKey();

	BaseClass2::setValue(registryKey, QString(value.c_str()));

	return true;
}


bool CSettingsWriteArchive::Process(istd::CString& value)
{
	std::string str(value.ToString());

	return Process(str);
}


} // namespace iqt


