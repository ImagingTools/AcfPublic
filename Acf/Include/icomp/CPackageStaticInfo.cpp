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


#include "icomp/CPackageStaticInfo.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace icomp
{


CPackageStaticInfo::CPackageStaticInfo()
{
}


CPackageStaticInfo::CPackageStaticInfo(
			const QString& description,
			const QString& keywords)
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
	static iser::CArchiveTag descriptionTag("Description", "Human readable description", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag keywordsTag("Keywords", "Human readable keywords", iser::CArchiveTag::TT_LEAF);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(descriptionTag);
	retVal = retVal && archive.Process(m_description);
	retVal = retVal && archive.EndTag(descriptionTag);

	retVal = retVal && archive.BeginTag(keywordsTag);
	retVal = retVal && archive.Process(m_keywords);
	retVal = retVal && archive.EndTag(keywordsTag);

	return retVal;
}


void CPackageStaticInfo::RegisterEmbeddedComponentInfo(const QByteArray& embeddedId, const IComponentStaticInfo* componentInfoPtr)
{
	m_embeddedComponentInfos[embeddedId] = componentInfoPtr;
}


// reimplemented (icomp::IPackageStaticInfo)

const IComponentStaticInfo* CPackageStaticInfo::GetEmbeddedComponentInfo(const QByteArray& embeddedId) const
{
	EmbeddedComponentInfos::ConstIterator foundIter = m_embeddedComponentInfos.constFind(embeddedId);
	if (foundIter != m_embeddedComponentInfos.constEnd()){
		return foundIter.value();
	}
	else{
		return NULL;
	}
}


IElementStaticInfo::Ids CPackageStaticInfo::GetMetaIds(int metaGroupId) const
{
	Ids retVal;

	if (metaGroupId == MGI_EMBEDDED_COMPONENTS){
		for (		EmbeddedComponentInfos::const_iterator iter = m_embeddedComponentInfos.begin();
					iter != m_embeddedComponentInfos.end();
					++iter){
			retVal.insert(iter.key());
		}
	}

	return retVal;
}


const QString& CPackageStaticInfo::GetDescription() const
{
	return m_description;
}


const QString& CPackageStaticInfo::GetKeywords() const
{
	return m_keywords;
}


} // namespace icomp


