/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#include <icomm/CCommonVersionInfo.h>


namespace icomm
{


CCommonVersionInfo::CCommonVersionInfo()
:	m_masterVersionInfoPtr(NULL)
{
}


void CCommonVersionInfo::SetMasterVersionInfo(const iser::IVersionInfo* versionInfoPtr)
{
	m_masterVersionInfoPtr = versionInfoPtr;

	CCommonVersionInfo::Reset();
}


void CCommonVersionInfo::Reset()
{
	m_versionIdList.clear();

	if (m_masterVersionInfoPtr != NULL){
		CCommonVersionInfo::MergeVersions(*m_masterVersionInfoPtr);
	}
}


void CCommonVersionInfo::MergeVersions(const iser::IVersionInfo& versionInfo)
{
	iser::IVersionInfo::VersionIds ids = versionInfo.GetVersionIds();
	for (		iser::IVersionInfo::VersionIds::ConstIterator iter = ids.begin();
				iter != ids.end();
				++iter){
		int versionId = *iter;

		quint32 versionNumber;
		if (!versionInfo.GetVersionNumber(versionId, versionNumber)){
			continue;
		}

		VersionElements::Iterator findIter = m_versionIdList.find(versionId);
		if (findIter != m_versionIdList.end()){
			VersionIdElement& element = *findIter;
			element.versionNumber = qMin(element.versionNumber, versionNumber);
			if (element.description.isEmpty()){
				element.description = versionInfo.GetVersionIdDescription(versionId);
			}
		}
		else{
			VersionIdElement& element = m_versionIdList[versionId];
			element.versionNumber = versionNumber;
			element.description = versionInfo.GetVersionIdDescription(versionId);
		}
	}
}


// reimplemented (iser::IVersionInfo)

CCommonVersionInfo::VersionIds CCommonVersionInfo::GetVersionIds() const
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
	QList<int> keys = m_versionIdList.keys();

	return QSet<int>(keys.begin(), keys.end());
#else
	return m_versionIdList.keys().toSet();
#endif
}


bool CCommonVersionInfo::GetVersionNumber(int versionId, quint32& result) const
{
	VersionElements::ConstIterator findIter = m_versionIdList.constFind(versionId);
	if (findIter != m_versionIdList.constEnd()){
		result = findIter.value().versionNumber;

		return true;
	}

	result = 0xffffffff;

	return false;
}


QString CCommonVersionInfo::GetVersionIdDescription(int versionId) const
{
	VersionElements::ConstIterator findIter = m_versionIdList.constFind(versionId);
	if (findIter != m_versionIdList.constEnd()){
		return findIter.value().description;
	}

	return QString();
}


QString CCommonVersionInfo::GetEncodedVersionName(int versionId, quint32 versionNumber) const
{
	if (m_masterVersionInfoPtr != NULL){
		return m_masterVersionInfoPtr->GetEncodedVersionName(versionId, versionNumber);
	}

	return QString();
}


} // namespace icomm


