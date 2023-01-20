/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <idoc/CStandardDocumentMetaInfo.h>


// Qt includes
#include <QtCore/QIODevice>
#include <QtCore/QDataStream>

// ACF includes
#include <istd/TDelPtr.h>
#include <istd/CChangeNotifier.h>
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace idoc
{


const istd::IChangeable::ChangeSet s_setMetaInfoChangeSet(idoc::IDocumentMetaInfo::CF_METAINFO, QObject::tr("Change document information"));


// public methods

// reimplemented (idoc::IDocumentMetaInfo)

CStandardDocumentMetaInfo::MetaInfoTypes CStandardDocumentMetaInfo::GetMetaInfoTypes(bool /*allowReadOnly*/) const
{
	QSet<int> metaInfoTypes;

	for (QByteArray metainfoId: m_infosMap.keys()){
		int metaInfoType;
		if (GetMetaInfoType(metaInfoType, metainfoId)){
			metaInfoTypes.insert(metaInfoType);
		}
	}

	return metaInfoTypes;
}


QVariant CStandardDocumentMetaInfo::GetMetaInfo(int metaInfoType) const
{
	QByteArray metaInfoId = GetMetaInfoId(metaInfoType);

	return GetMetaInfo(metaInfoId);
}


QVariant CStandardDocumentMetaInfo::GetMetaInfo(QByteArray metaInfoId) const
{
	static QVariant emptyValue;

	if (m_infosMap.contains(metaInfoId)){
		return m_infosMap[metaInfoId];
	}

	return emptyValue;
}


bool CStandardDocumentMetaInfo::SetMetaInfo(int metaInfoType, const QVariant& metaInfo)
{
	QByteArray metaInfoId = GetMetaInfoId(metaInfoType);

	return SetMetaInfo(metaInfoId, metaInfo);
}

bool CStandardDocumentMetaInfo::SetMetaInfo(QByteArray metaInfoId, const QVariant &metaInfo)
{
	if(!metaInfoId.isEmpty() && !m_infosMap.contains(metaInfoId)){
		istd::CChangeNotifier notifier(this, &s_setMetaInfoChangeSet);
		Q_UNUSED(notifier);

		m_infosMap[metaInfoId] = metaInfo;
		return true;
	}

	return false;
}


QByteArray CStandardDocumentMetaInfo::GetMetaInfoId(int metaInfoType) const
{
	static QByteArray emptyId;

	switch (metaInfoType){
	case MIT_TITLE:
		return ("Title");

	case MIT_AUTHOR:
		return ("Author");

	case MIT_CREATOR:
		return ("Creator");

	case MIT_DESCRIPTION:
		return ("Description");

	case MIT_CREATION_TIME:
		return ("CreationTime");

	case MIT_MODIFICATION_TIME:
		return ("ModificationTime");

	case MIT_CREATOR_VERSION:
		return ("CreatorVersion");

	case MIT_DOCUMENT_VERSION:
		return ("Version");

	case MIT_CONTENT_CHECKSUM:
		return ("Checksum");

	default:
		return emptyId;
	}
}


QString CStandardDocumentMetaInfo::GetMetaInfoName(int metaInfoType) const
{
	static QString emptyName;

	switch (metaInfoType){
	case MIT_TITLE:
		return QObject::tr("Title");

	case MIT_AUTHOR:
		return QObject::tr("Author");

	case MIT_CREATOR:
		return QObject::tr("Creator");

	case MIT_DESCRIPTION:
		return QObject::tr("Description");

	case MIT_CREATION_TIME:
		return QObject::tr("Creation Time");

	case MIT_MODIFICATION_TIME:
		return QObject::tr("Modification Time");

	case MIT_CREATOR_VERSION:
		return QObject::tr("Creator Version");

	case MIT_DOCUMENT_VERSION:
		return QObject::tr("Version");

	case MIT_CONTENT_CHECKSUM:
		return QObject::tr("Checksum");

	default:
		return emptyName;
	}
}


QString CStandardDocumentMetaInfo::GetMetaInfoDescription(int metaInfoType) const
{
	static QString emptyName;

	switch (metaInfoType){
	case MIT_TITLE:
		return QObject::tr("Title of the document");

	case MIT_AUTHOR:
		return QObject::tr("Author of the document");

	case MIT_CREATOR:
		return QObject::tr("Creator of the document");

	case MIT_DESCRIPTION:
		return QObject::tr("Document description");

	case MIT_CREATION_TIME:
		return QObject::tr("Time of document's creation");

	case MIT_MODIFICATION_TIME:
		return QObject::tr("Time of last document's modification");

	case MIT_CREATOR_VERSION:
		return QObject::tr("Version of the creation tool");

	case MIT_DOCUMENT_VERSION:
		return QObject::tr("Version of the document");

	case MIT_CONTENT_CHECKSUM:
		return QObject::tr("Checksum of the document content");

	default:
		return emptyName;
	}
}


bool CStandardDocumentMetaInfo::IsMetaInfoWritable(int metaInfoType) const
{
	switch (metaInfoType){
		case MIT_CREATION_TIME:
		case MIT_MODIFICATION_TIME:
			return false;
		default:
			return true;
	}
}


// reimplemented (iser::ISerializable)

bool CStandardDocumentMetaInfo::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag metaInfoMapTag("MetaInfoMap", "Mapping between meta info and its type", iser::CArchiveTag::TT_MULTIPLE);
	static iser::CArchiveTag metaInfoTag("MetaInfo", "Single meta information", iser::CArchiveTag::TT_GROUP, &metaInfoMapTag);
	static iser::CArchiveTag typeTag("Type", "Type of the meta information", iser::CArchiveTag::TT_LEAF, &metaInfoTag);
	static iser::CArchiveTag valueTag("Value", "Value of the meta information", iser::CArchiveTag::TT_LEAF, &metaInfoTag);
	static iser::CArchiveTag sizeTag("Size", "Size of the data block", iser::CArchiveTag::TT_LEAF, &metaInfoTag);

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this, &GetAllChanges());
	Q_UNUSED(notifier);

	bool retVal = true;

	int metaInfosCount = m_infosMap.size();
	retVal = retVal && archive.BeginMultiTag(metaInfoMapTag, metaInfoTag, metaInfosCount);

	if (archive.IsStoring()){
		for (		MetaInfoMap::ConstIterator index = m_infosMap.constBegin();
					index != m_infosMap.constEnd();
					++index){
			retVal = retVal && archive.BeginTag(metaInfoTag);

			int type;
			GetMetaInfoType(type, index.key());
			retVal = retVal && archive.BeginTag(typeTag);
			retVal = retVal && archive.Process(type);
			retVal = retVal && archive.EndTag(typeTag);

			QByteArray variantData;
			QDataStream variantStream(&variantData, QIODevice::ReadWrite);
			QVariant value = index.value();
			variantStream << value;

			const iser::IVersionInfo& versionInfo = archive.GetVersionInfo();	// TODO: Remove it when backward compatibility to older versions will not be no more important
			quint32 frameworkVersion = 0;
			if (versionInfo.GetVersionNumber(iser::IVersionInfo::AcfVersionId, frameworkVersion) && (frameworkVersion < 4001)){
				retVal = retVal && archive.BeginTag(valueTag);
				retVal = retVal && archive.Process(variantData);
				retVal = retVal && archive.EndTag(valueTag);
			}
			else{
				int dataSize = variantData.size();
				retVal = retVal && archive.BeginTag(sizeTag);
				retVal = retVal && archive.Process(dataSize);
				retVal = retVal && archive.EndTag(sizeTag);

				retVal = retVal && archive.BeginTag(valueTag);
				retVal = retVal && archive.ProcessData(variantData.data(), dataSize);
				retVal = retVal && archive.EndTag(valueTag);
			}

			retVal = retVal && archive.EndTag(metaInfoTag);
		}
	}
	else{
		m_infosMap.clear();

		for (int itemIndex = 0; itemIndex < metaInfosCount; ++itemIndex){
			retVal = retVal && archive.BeginTag(metaInfoTag);

			int type = -1;
			retVal = retVal && archive.BeginTag(typeTag);
			retVal = retVal && archive.Process(type);
			retVal = retVal && archive.EndTag(typeTag);

			QByteArray variantData;

			const iser::IVersionInfo& versionInfo = archive.GetVersionInfo();	// TODO: Remove it when backward compatibility to older versions will not be no more important
			quint32 frameworkVersion = 0;
			if (versionInfo.GetVersionNumber(iser::IVersionInfo::AcfVersionId, frameworkVersion) && (frameworkVersion < 4001)){
				retVal = retVal && archive.BeginTag(valueTag);
				retVal = retVal && archive.Process(variantData);
				retVal = retVal && archive.EndTag(valueTag);
			}
			else{
				int dataSize = 0;
				retVal = retVal && archive.BeginTag(sizeTag);
				retVal = retVal && archive.Process(dataSize);
				retVal = retVal && archive.EndTag(sizeTag);

				variantData.resize(dataSize);
				retVal = retVal && archive.BeginTag(valueTag);
				retVal = retVal && archive.ProcessData(variantData.data(), dataSize);
				retVal = retVal && archive.EndTag(valueTag);
			}

			QVariant variantValue;
			QDataStream variantStream(variantData);
			variantStream >> variantValue;

			if (retVal){
				QByteArray metaInfoId = GetMetaInfoId(type);
				Q_ASSERT(metaInfoId.isEmpty());
				m_infosMap[metaInfoId] = variantValue;
			}

			retVal = retVal && archive.EndTag(metaInfoTag);
		}
	}

	retVal = retVal && archive.EndTag(metaInfoMapTag);

	return retVal;
}


// reimplemented (istd::IChangeable)

bool CStandardDocumentMetaInfo::IsEqual(const IChangeable& object) const
{
	const CStandardDocumentMetaInfo* infoPtr = dynamic_cast<const CStandardDocumentMetaInfo*>(&object);
	if (infoPtr != NULL){
		return (m_infosMap == infoPtr->m_infosMap);
	}

	return false;
}


bool CStandardDocumentMetaInfo::CopyFrom(const IChangeable& object, CompatibilityMode /*mode = CM_WITHOUT_REFS*/)
{
	const CStandardDocumentMetaInfo* infoPtr = dynamic_cast<const CStandardDocumentMetaInfo*>(&object);
	if (infoPtr != NULL){
		istd::CChangeNotifier notifier(this, &s_setMetaInfoChangeSet);

		m_infosMap = infoPtr->m_infosMap;
		return true;
	}

	return false;
}


istd::IChangeable* CStandardDocumentMetaInfo::CloneMe(CompatibilityMode mode) const
{
	istd::TDelPtr<CStandardDocumentMetaInfo> clonePtr(new CStandardDocumentMetaInfo);
	if (clonePtr->CopyFrom(*this, mode))
	{
		return clonePtr.PopPtr();
	}

	return NULL;
}


bool CStandardDocumentMetaInfo::ResetData(CompatibilityMode /*mode*/)
{
	if (!m_infosMap.isEmpty()){
		istd::CChangeNotifier notifier(this, &s_setMetaInfoChangeSet);

		m_infosMap.clear();
	}

	return true;
}

bool CStandardDocumentMetaInfo::GetMetaInfoType(int &metainfoType, const QByteArray &metaInfoId) const
{
	if (metaInfoId == "Title"){
		metainfoType = MIT_TITLE;

		return true;
	}

	if (metaInfoId == "Author"){
		metainfoType = MIT_AUTHOR;

		return true;
	}

	if (metaInfoId == "Creator"){
		metainfoType = MIT_CREATOR;

		return true;
	}

	if (metaInfoId == "Description"){
		metainfoType = MIT_DESCRIPTION;

		return true;
	}

	if (metaInfoId == "CreationTime"){
		metainfoType = MIT_CREATION_TIME;

		return true;
	}

	if (metaInfoId == "ModificationTime"){
		metainfoType = MIT_MODIFICATION_TIME;

		return true;
	}

	if (metaInfoId == "CreatorVersion"){
		metainfoType = MIT_CREATOR_VERSION;

		return true;
	}

	if (metaInfoId == "Version"){
		metainfoType = MIT_DOCUMENT_VERSION;

		return true;
	}

	if (metaInfoId == "Checksum"){
		metainfoType = MIT_CONTENT_CHECKSUM;

		return true;
	}

	return false;
}


} // namespace idoc


