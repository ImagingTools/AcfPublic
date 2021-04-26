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


#include <iser/CJsonStringWriteArchive.h>

// Qt includes
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

namespace iser
{


// public methods

CJsonStringWriteArchive::CJsonStringWriteArchive(
		QByteArray &inputString,
		const IVersionInfo *versionInfoPtr,
		QJsonDocument::JsonFormat jsonFormat)
	: CTextWriteArchiveBase(versionInfoPtr),
	  m_stream(&inputString),
	  m_jsonFormat(jsonFormat)
{
//	m_stream << "{";
	m_firstTag = true;
}

CJsonStringWriteArchive::~CJsonStringWriteArchive()
{
//	m_stream << "}";
	m_stream.flush();
}

bool CJsonStringWriteArchive::IsTagSkippingSupported() const
{
	return true;
}

bool CJsonStringWriteArchive::BeginTag(const CArchiveTag &tag)
{

//	Q_ASSERT(!m_currentAttribute.isEmpty());

//	if (m_document.isEmpty()){
//		QJsonObject object;
//		m_document.setObject(object);
//		m_objectsStack.append(m_document.object().begin());
//	}
	m_isSeparatorNeeded = false;
	m_currentAttribute.clear();

	if (m_tagsStack.isEmpty() || (m_tagsStack.back() == NULL) || (m_tagsStack.back()->GetTagType() != iser::CArchiveTag::TT_MULTIPLE)){
		int tagType = tag.GetTagType();
		if (m_allowAttribute && (tagType == iser::CArchiveTag::TT_LEAF)){
			m_currentAttribute = tag.GetId();
			writeTag(tag, "");

			m_tagsStack.push_back(NULL);

			return true;
		}
		else if (tagType == iser::CArchiveTag::TT_WEAK){
			m_tagsStack.push_back(NULL);
			writeTag(tag, "{");

			return true;
		}
	}
//	m_currentAttribute = tag.GetId();
//	//m_xmlWriter.writeStartElement(tag.GetId());
//	QJsonObject::iterator objIterator = m_objectsStack.last();
////	objIterator.value().toObject()
//	QJsonObject jsonObject; // = (*objIterator).toObject();
//	(*objIterator).toObject().insert(m_currentAttribute,jsonObject);
//	m_objectsStack.append(jsonObject.begin());
	writeTag(tag, "{", false);
//	m_stream << "{";
	m_firstTag = true;

	m_tagsStack.push_back(&tag);

	m_allowAttribute = true;

	return true;
}

bool CJsonStringWriteArchive::BeginMultiTag(const CArchiveTag &tag, const CArchiveTag &subTag, int &count)
{
////	m_xmlWriter.writeStartElement(tag.GetId());
//	QJsonObject::iterator objIterator = m_objectsStack.last();
////	objIterator.value().toObject()
//	QJsonArray jsonArray; // = (*objIterator).toObject();
//	(*objIterator).toObject().insert(m_currentAttribute,jsonArray);
//	m_objectsStack.append(jsonArray.begin());
	writeTag(tag,"[");
	m_firstTag = true;

	m_tagsStack.push_back(&tag);

	m_allowAttribute = true;

	m_isSeparatorNeeded = false;

	return true;
}

bool CJsonStringWriteArchive::EndTag(const CArchiveTag &tag)
{
	m_currentAttribute.clear();

	if (m_tagsStack.isEmpty()){
		return false;
	}

	const iser::CArchiveTag* lastTagPtr = m_tagsStack.back();
	m_tagsStack.pop_back();

	if (lastTagPtr == NULL){
//		m_stream << "}";
		return true;
	}

//	m_allowAttribute = false;

	if (lastTagPtr->GetTagType() == iser::CArchiveTag::TT_MULTIPLE){
		m_stream << "]";
	}
	else if (lastTagPtr->GetTagType() == iser::CArchiveTag::TT_GROUP){
		m_stream << "}";
	}

//	m_xmlWriter.writeEndElement();

	return true;
}

bool CJsonStringWriteArchive::Process(QString &value)
{
	return WriteTextNode("\"" + value.toUtf8() + "\"");
}

void CJsonStringWriteArchive::writeTag(const CArchiveTag &tag, QString separator, bool isWriteTag)
{
	if (!m_firstTag){
		m_stream << ",";
	}
	if (isWriteTag){
		m_stream << "\"" << tag.GetId() << "\":";
	}
	m_stream << separator;
	m_firstTag = false;
}


bool CJsonStringWriteArchive::WriteTextNode(const QByteArray &text)
{
	m_stream << text;
	return true;
}


	



} // namespace iser
