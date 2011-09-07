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


#include "iqt/CSettingsReadArchive.h"


// Qt includes
#include <QStringList>


// ACF includes
#include "iqt/iqt.h"


namespace iqt
{


// public methods

CSettingsReadArchive::CSettingsReadArchive(	const QString& organizationName,
											const QString& applicationName)
	:BaseClass2(organizationName, applicationName)
{
}


// reimplemented (iser::IArchive)

bool CSettingsReadArchive::BeginTag(const iser::CArchiveTag& tag)
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


bool CSettingsReadArchive::BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count)
{
	m_openTagsList.push_back(TagInfo(tag.GetId(), 0, subTag.GetId()));

	QString registryKey = CreateKey(false);

	count = BaseClass2::value(registryKey).toInt();

	m_openTagsList.back().count = count + 1;

	return true;
}


bool CSettingsReadArchive::EndTag(const iser::CArchiveTag& /*tag*/)
{
	I_ASSERT(!m_openTagsList.empty());

	TagInfo& currentTag = m_openTagsList.back();
	if (currentTag.count <= 1){		
		m_openTagsList.pop_back();
	}
	
	return true;
}


bool CSettingsReadArchive::Process(std::string& value)
{
	if (m_openTagsList.empty()){
		return false;
	}

	QString registryKey = CreateKey();

	value = BaseClass2::value(registryKey).toString().toStdString();

	return true;
}


bool CSettingsReadArchive::Process(istd::CString& value)
{
	std::string str(value.ToString());

	if (Process(str)){
		value = str;

		return true;
	}

	return false;
}


} // namespace iqt

