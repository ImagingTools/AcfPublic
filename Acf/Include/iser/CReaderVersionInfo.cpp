/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iser/CReaderVersionInfo.h"


// ACF includes
#include "istd/CChangeNotifier.h"


namespace iser
{


// local variables
static istd::IChangeable::ChangeSet versionChangeIds(CReaderVersionInfo::CF_VERSIONS_UPDATED);
static istd::IChangeable::ChangeSet allDataChangeIds(CReaderVersionInfo::CF_VERSIONS_UPDATED, istd::IChangeable::CF_ALL_DATA);


void CReaderVersionInfo::Reset()
{
	istd::CChangeNotifier notifier(this, versionChangeIds);

	m_versionIdList.clear();
}


bool CReaderVersionInfo::InsertVersionId(int versionId, quint32 versionNumber, const QString& description)
{
	istd::CChangeNotifier notifier(this, versionChangeIds);

	VersionIdElement& element = m_versionIdList[versionId];
	element.versionNumber = versionNumber;
	element.description = description;

	return true;
}


bool CReaderVersionInfo::RemoveVersionId(int versionId)
{
	istd::CChangeNotifier notifier(this, versionChangeIds);

	return m_versionIdList.remove(versionId) > 0;
}


// reimplemented (iser::IVersionInfo)

CReaderVersionInfo::VersionIds CReaderVersionInfo::GetVersionIds() const
{
	return m_versionIdList.keys().toSet();
}


bool CReaderVersionInfo::GetVersionNumber(int versionId, quint32& result) const
{
	VersionElements::ConstIterator findIter = m_versionIdList.constFind(versionId);
	if (findIter != m_versionIdList.constEnd()){
		result = findIter.value().versionNumber;

		return true;
	}

	result = 0xffffffff;

	return false;
}


QString CReaderVersionInfo::GetVersionIdDescription(int versionId) const
{
	VersionElements::ConstIterator findIter = m_versionIdList.constFind(versionId);
	if (findIter != m_versionIdList.constEnd()){
		return findIter.value().description;
	}

	return QString();
}


QString CReaderVersionInfo::GetEncodedVersionName(int /*versionId*/, quint32 /*versionNumber*/) const
{
	return "";
}


// reimplemented (istd::IChangeable)

bool CReaderVersionInfo::CopyFrom(const istd::IChangeable& object, CompatibilityMode /*mode*/)
{
	const iser::IVersionInfo* versionInfoPtr = dynamic_cast<const iser::IVersionInfo*>(&object);
	if (versionInfoPtr == NULL){
		return false;
	}

	istd::CChangeNotifier notifier(this, allDataChangeIds);

	iser::IVersionInfo::VersionIds ids = versionInfoPtr->GetVersionIds();
	for (		iser::IVersionInfo::VersionIds::const_iterator iter = ids.begin();
				iter != ids.end();
				++iter){
		int versionId = *iter;

		quint32 versionNumber;
		if (!versionInfoPtr->GetVersionNumber(versionId, versionNumber)){
			continue;
		}

		VersionIdElement& element = m_versionIdList[versionId];
		element.versionNumber = versionNumber;
		element.description = versionInfoPtr->GetVersionIdDescription(versionId);
	}

	return true;
}


} // namespace iser


