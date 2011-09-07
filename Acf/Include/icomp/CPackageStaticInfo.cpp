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


#include "icomp/CPackageStaticInfo.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace icomp
{


CPackageStaticInfo::CPackageStaticInfo()
{
}


CPackageStaticInfo::CPackageStaticInfo(
			const istd::CString& description,
			const istd::CString& keywords)
:	m_description(description),
	m_keywords(keywords)
{
}


void CPackageStaticInfo::Reset()
{
	m_embeddedComponentInfos.clear();
}


bool CPackageStaticInfo::SerializeMeta(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag descriptionTag("Description", "Human readable description");
	retVal = retVal && archive.BeginTag(descriptionTag);
	retVal = retVal && archive.Process(m_description);
	retVal = retVal && archive.EndTag(descriptionTag);

	static iser::CArchiveTag keywordsTag("Keywords", "Human readable keywords");
	retVal = retVal && archive.BeginTag(keywordsTag);
	retVal = retVal && archive.Process(m_keywords);
	retVal = retVal && archive.EndTag(keywordsTag);

	return retVal;
}


void CPackageStaticInfo::RegisterEmbeddedComponentInfo(const std::string& embeddedId, const IComponentStaticInfo* componentInfoPtr)
{
	m_embeddedComponentInfos[embeddedId] = componentInfoPtr;
}


// reimplemented (icomp::IPackageStaticInfo)

const IComponentStaticInfo* CPackageStaticInfo::GetEmbeddedComponentInfo(const std::string& embeddedId) const
{
	EmbeddedComponentInfos::const_iterator foundIter = m_embeddedComponentInfos.find(embeddedId);
	if (foundIter != m_embeddedComponentInfos.end()){
		return foundIter->second;
	}
	else{
		return NULL;
	}
}


IComponentStaticInfo::Ids CPackageStaticInfo::GetMetaIds(int metaGroupId) const
{
	Ids retVal;

	if (metaGroupId == MGI_EMBEDDED_COMPONENTS){
		for (		EmbeddedComponentInfos::const_iterator iter = m_embeddedComponentInfos.begin();
					iter != m_embeddedComponentInfos.end();
					++iter){
			retVal.insert(iter->first);
		}
	}

	return retVal;
}


const istd::CString& CPackageStaticInfo::GetDescription() const
{
	return m_description;
}


const istd::CString& CPackageStaticInfo::GetKeywords() const
{
	return m_keywords;
}


}//namespace icomp


