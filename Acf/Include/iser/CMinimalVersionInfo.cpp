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


#include "iser/CMinimalVersionInfo.h"


// ACF includes
#include "iser/ISerializable.h"


namespace iser
{


CMinimalVersionInfo::CMinimalVersionInfo(const ISerializable* serializablePtr, bool addStandardIds)
:	m_serializable(*serializablePtr)
{
	Q_ASSERT(serializablePtr != NULL);

	if (addStandardIds){
		AddId(AcfVersionId, "ACF Framework");
	}
}


bool CMinimalVersionInfo::AddId(int versionId, const QString& description)
{
	Versions::ConstIterator iter = m_versions.constFind(versionId);
	if (iter != m_versions.constEnd()){
		return false;
	}

	Info& info = m_versions[versionId];

	info.description = description;
	info.version = m_serializable.GetMinimalVersion(versionId);

	return true;
}


// reimplemented (iser::IVersionInfo)

bool CMinimalVersionInfo::GetVersionNumber(int versionId, quint32& result) const
{
	Versions::ConstIterator iter = m_versions.constFind(versionId);
	if (m_versions.find(versionId) != m_versions.constEnd()){
		const Info& info = iter.value();

		result = info.version;

		return true;
	}

	result = 0xffffffff;

	return false;
}


QString CMinimalVersionInfo::GetVersionIdDescription(int versionId) const
{
	Versions::ConstIterator iter = m_versions.constFind(versionId);
	if (m_versions.find(versionId) != m_versions.constEnd()){
		const Info& info = iter.value();

		return info.description;
	}

	static QString description("<unregistered>");

	return description;
}


IVersionInfo::VersionIds CMinimalVersionInfo::GetVersionIds() const
{
	VersionIds retVal;

	for (		Versions::const_iterator iter = m_versions.begin();
				iter != m_versions.end();
				++iter){
		retVal.insert(iter.key());
	}

	return retVal;
}


QString CMinimalVersionInfo::GetEncodedVersionName(int /*versionId*/, quint32 /*versionNumber*/) const
{
	return "";
}


} // namespace iser


