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


#include "iqt/CSettingsArchiveBase.h"


// ACF includes
#include "iqt/iqt.h"


namespace iqt
{


// public methods

CSettingsArchiveBase::CSettingsArchiveBase(
			const QString& organizationName,
			const QString& applicationName,
			const QString& rootKey)
:	BaseClass(organizationName, applicationName),
	m_rootKey(rootKey),
	m_valuesCount(0)
{
}


// protected methods

bool CSettingsArchiveBase::EnterTag(const std::string& tagId)
{
	m_openTagsList.push_back(TagInfo(tagId, m_valuesCount));

	m_valuesCount = 0;

	return true;
}


bool CSettingsArchiveBase::LeaveTag(const std::string& tagId)
{
	if (m_openTagsList.empty()){
		return false;
	}

	if (m_openTagsList.back().tagId != tagId){
		return false;
	}

	TagInfo& tagInfo = m_openTagsList.back();
	m_valuesCount = tagInfo.siblingsCount + 1;

	m_openTagsList.pop_back();

	return true;
}


QString CSettingsArchiveBase::GetCurrentCountKey() const
{
	return GetBaseKey() + "count";

	return true;
}


QString CSettingsArchiveBase::CreateNextValueKey()
{
	static const QString valueSuffix("_value");

	QString retVal = GetBaseKey() + QString::number(++m_valuesCount) + valueSuffix;

	return retVal;
}


QString CSettingsArchiveBase::GetBaseKey() const
{
	QString registryKey;

	if (!m_rootKey.isEmpty()){
		registryKey = m_rootKey + "/";
	}

	for (		OpenTagsList::const_iterator tagIter = m_openTagsList.begin();
				tagIter != m_openTagsList.end();
				tagIter++){
		const TagInfo& tagInfo = *tagIter;

		static const QString separator("_");

		registryKey += QString::number(tagInfo.siblingsCount + 1) + separator + iqt::GetQString(tagInfo.tagId);

		registryKey += "/";
	}

	return registryKey;
}


} // namespace iqt


