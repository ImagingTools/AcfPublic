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


#include "iqt/CXmlFileReadArchive.h"


// include STL
#include <cstring>

// Qt includes
#include <QtCore/QFile>
#include <QtXml/QDomNodeList>


namespace iqt
{


CXmlFileReadArchive::CXmlFileReadArchive(
			const QString& filePath,
			bool serializeHeader,
			const iser::CArchiveTag& rootTag)
:	m_serializeHeader(serializeHeader),
	m_rootTag(rootTag)
{
	if (!filePath.isEmpty()){
		OpenFile(filePath);
	}
}


bool CXmlFileReadArchive::OpenFile(const QString& filePath)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		return false;
	}

	if (!m_document.setContent(&file)){
		file.close();

		return false;
	}

	if (m_currentNode.nodeValue() != m_rootTag.GetId()){
		QDomElement mainElement = m_document.documentElement();

		m_currentNode = mainElement;
	}

	bool retVal = !m_currentNode.isNull();

	if (m_serializeHeader){
		retVal = retVal && SerializeAcfHeader();
	}

	return retVal;
}


// reimplemented (iser::IArchive)

bool CXmlFileReadArchive::IsTagSkippingSupported() const
{
	return true;
}


bool CXmlFileReadArchive::BeginTag(const iser::CArchiveTag& tag)
{
	QString tagId(tag.GetId());

	QDomElement element = m_currentNode.firstChildElement(tagId);
	if (!element.isNull()){
		m_currentNode = element;
	}
	return !element.isNull();
}


bool CXmlFileReadArchive::BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count)
{
	QString tagId(tag.GetId());

	QDomElement element = m_currentNode.firstChildElement(tagId);
	if (!element.isNull()){
		m_currentNode = element;
	}
	else{
		return false;
	}

	int tempCount = 0;
	QDomElement child = element.firstChildElement(QString(subTag.GetId()));
	while (!child.isNull()){
		tempCount++;
		child = child.nextSiblingElement(QString(subTag.GetId()));
	}
	count = tempCount;

	return !element.isNull();
}


bool CXmlFileReadArchive::EndTag(const iser::CArchiveTag& /*tag*/)
{
	QDomNode parent = m_currentNode.parentNode();
	
	parent.removeChild(m_currentNode);

	m_currentNode = parent;

	return !m_currentNode.isNull();
}


bool CXmlFileReadArchive::Process(QString& value)
{
	return ReadStringNode(value);
}


// protected methods

bool CXmlFileReadArchive::ReadStringNode(QString& text)
{
	QDomNode node = m_currentNode.firstChild();
	//Kill separator tags (<br/>)
	while (node.nodeName() == "br"){
		QDomNode brNode = node;
		node = node.nextSibling();
		m_currentNode.removeChild(brNode);
	}
	
	text = node.nodeValue();

	m_currentNode.removeChild(node);

	return !m_currentNode.isNull();
}


// reimplemented (iser::CTextReadArchiveBase)

bool CXmlFileReadArchive::ReadTextNode(QByteArray& text)
{
	QString stringText;

	if (ReadStringNode(stringText)){
		text = stringText.toLocal8Bit();

		return true;
	}

	return false;
}


} // namespace iqt


