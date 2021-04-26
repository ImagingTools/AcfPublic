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


#include <iser/CJsonStringReadArchive.h>


namespace iser
{


// public methods

CJsonStringReadArchive::CJsonStringReadArchive(const QByteArray &inputString)
	: CTextReadArchiveBase()
{
	QJsonParseError error;
	m_document = QJsonDocument::fromJson(inputString, &error);
	if (error.error != QJsonParseError::NoError && IsLogConsumed()){
		SendLogMessage(
			istd::IInformationProvider::IC_ERROR,
			MI_TAG_ERROR,
			error.errorString(),
			"CJsonStringReadArchive",
			istd::IInformationProvider::ITF_SYSTEM);
	}
}


// reimplemented (iser::IArchive)

bool CJsonStringReadArchive::BeginTag(const iser::CArchiveTag& tag)
{
//	if(!(*m_objIterator).toObject().contains(tag.GetId()))
//	{
//		LogJsonArchiveError(QString("Unbalanced tags, begin tag '%1', not found in JSON data.").arg(tag.GetId().constData()));
//		return false;
//	}

//	m_lastTag = tag.GetId();

	Q_ASSERT(m_currentAttribute.isEmpty());

	QString tagId(tag.GetId());

	m_currentAttribute.clear();

	if (m_tagsStack.isEmpty() || (m_tagsStack.back() == NULL) || (m_tagsStack.back()->GetTagType() != iser::CArchiveTag::TT_MULTIPLE)){
		int tagType = tag.GetTagType();
		if (m_allowAttribute && (tagType == iser::CArchiveTag::TT_LEAF)){
			m_currentAttribute = tag.GetId();

			m_tagsStack.push_back(NULL);

			return true;
		}
		else if (tagType == iser::CArchiveTag::TT_WEAK){
			m_tagsStack.push_back(NULL);

			return true;
		}
	}
	QJsonObject::const_iterator objIterator;

	objIterator = m_objectsStack.last();

//	QDomElement element = m_currentParent.firstChildElement(tagId);
//	if (!element.isNull()){
//		m_currentParent = element;
//	}
	QJsonObject jsonObject = (*objIterator).toObject();
	objIterator = jsonObject.find(tagId);
	if (objIterator != jsonObject.end() && jsonObject.value(tagId).isObject()){
		m_objectsStack.push_back(objIterator);
	}
	else{
		if (IsLogConsumed()){
			SendLogMessage(
						istd::IInformationProvider::IC_ERROR,
						MI_TAG_ERROR,
						QString("Tag '%1' not found!").arg(QString(tagId)),
						"CJsonStringReadArchive",
						istd::IInformationProvider::ITF_SYSTEM);
		}

		return false;
	}

	m_tagsStack.push_back(&tag);

	m_allowAttribute = true;

	return true;
}


bool CJsonStringReadArchive::BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count)
{
	QString tagId(tag.GetId());
	QJsonObject::const_iterator objIterator;

	objIterator = m_objectsStack.last();

//		if(!(*m_objIterator).toObject().contains(tag.GetId()))
	//	{
	//		LogJsonArchiveError(QString("Unbalanced tags, begin tag '%1', not found in JSON data.").arg(tag.GetId().constData()));
	//		return false;
	//	}
//	QDomElement element = m_currentParent.firstChildElement(tagId);
//	if (!element.isNull()){
	QJsonObject jsonObject = (*objIterator).toObject();
	objIterator = jsonObject.find(tagId);
	if (objIterator != jsonObject.end() && jsonObject.value(tagId).isArray()){
		m_objectsStack.push_back(objIterator);
	}
	else{
		if (IsLogConsumed()){
			SendLogMessage(
						istd::IInformationProvider::IC_ERROR,
						MI_TAG_ERROR,
						QString("Tag '%1' not found!").arg(QString(tagId)),
						"CJsonStringReadArchive",
						istd::IInformationProvider::ITF_SYSTEM);
		}

		return false;
	}

//	int tempCount = 0;
//	tempCount = jsonObject.value(tagId).toArray().count();
//	for (		QDomElement child = element.firstChildElement(QString(subTag.GetId()));
//				!child.isNull();
//				child = child.nextSiblingElement(QString(subTag.GetId()))){
//		tempCount++;
//	}
//	count = tempCount;

	count = jsonObject.value(tagId).toArray().count();

	m_tagsStack.push_back(&tag);

	m_allowAttribute = true;

	return true;
}


bool CJsonStringReadArchive::EndTag(const iser::CArchiveTag& tag)
{
	m_currentAttribute.clear();

	if (m_tagsStack.isEmpty()){
		return false;
	}

	const iser::CArchiveTag* lastTagPtr = m_tagsStack.back();
	m_tagsStack.pop_back();

	if (lastTagPtr == NULL){
		return true;
	}

	if (&tag != lastTagPtr){
		SendLogMessage(
					istd::IInformationProvider::IC_ERROR,
					MI_TAG_ERROR,
					QString("Closing tag '%1' was not opened!").arg(QString(tag.GetId())),
					"CompactXmlReader",
					istd::IInformationProvider::ITF_SYSTEM);

		return false;
	}

	QString tagId(tag.GetId());
	QJsonObject::const_iterator objIterator;

	objIterator = m_objectsStack.last();
	QJsonObject jsonObject = (*objIterator).toObject();

//	Q_ASSERT (lastTagPtr->GetId() == m_currentParent.tagName().toLatin1());
	Q_ASSERT (jsonObject.contains(lastTagPtr->GetId()));

	m_objectsStack.pop_back();

//	QDomNode parent = m_currentParent.parentNode();

//	parent.removeChild(m_currentParent);

//	m_currentParent = parent.toElement();

	if (m_isNewFormat){
		m_allowAttribute = false;
	}

	return true;

}




bool CJsonStringReadArchive::Process(QString& value)
{
	return ReadStringNode(value);
}


// protected methods

bool CJsonStringReadArchive::ReadStringNode(QString &text)
{
	if (m_currentAttribute.isEmpty()){
		return false;
	}
	else{
		QJsonObject::const_iterator objIterator;

		objIterator = m_objectsStack.last();
		QJsonObject jsonObject = (*objIterator).toObject();
//		const iser::CArchiveTag* lastTagPtr = m_tagsStack.back();

	//	Q_ASSERT (lastTagPtr->GetId() == m_currentParent.tagName().toLatin1());
//		Q_ASSERT (jsonObject.contains(lastTagPtr->GetId()));

//		if (m_currentParent.hasAttribute(m_currentAttribute)){
//			text = m_currentParent.attribute(m_currentAttribute);
//		}
		if (jsonObject.contains(m_currentAttribute)){
			text = jsonObject.value(m_currentAttribute).toString();
		}
		else{
			if (IsLogConsumed()){
				SendLogMessage(
							istd::IInformationProvider::IC_ERROR,
							MI_TAG_ERROR,
							QString("No attribute '%1' found!").arg(QString(m_currentAttribute)),
							"CompactXmlReader",
							istd::IInformationProvider::ITF_SYSTEM);
			}

			return false;
		}
	}

	return true;

}


} // namespace iser
