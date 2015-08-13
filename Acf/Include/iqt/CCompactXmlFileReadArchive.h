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


#ifndef iqt_CCompactXmlFileReadArchive_included
#define iqt_CCompactXmlFileReadArchive_included


// Qt includes
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>

// ACF includes
#include "iser/CXmlDocumentInfoBase.h"
#include "iser/CReadArchiveBase.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	Qt-based implementation of archive reading from XML file.

	\ingroup Persistence
*/
class CCompactXmlFileReadArchive: public iser::CReadArchiveBase, public iser::CXmlDocumentInfoBase
{
public:
	CCompactXmlFileReadArchive(
				const QString& filePath = "",
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);

	bool OpenFile(const QString& filePath);

	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(bool& value);
	virtual bool Process(char& value);
	virtual bool Process(quint8& value);
	virtual bool Process(qint8& value);
	virtual bool Process(quint16& value);
	virtual bool Process(qint16& value);
	virtual bool Process(quint32& value);
	virtual bool Process(qint32& value);
	virtual bool Process(quint64& value);
	virtual bool Process(qint64& value);
	virtual bool Process(float& value);
	virtual bool Process(double& value);
	virtual bool Process(QByteArray& value);
	virtual bool Process(QString& value);
	virtual bool ProcessData(void* dataPtr, int size);

protected:
	/**
		Find the next text node and move the current node to the next sibling.
	*/
	QString PullTextNode();

private:
	QDomDocument m_document;
	QDomElement m_currentParent;

	QByteArray m_currentAttribute;

	bool m_serializeHeader;
	iser::CArchiveTag m_rootTag;

	QList<const iser::CArchiveTag*> m_tagsStack;
};


} // namespace iqt


#endif // !iqt_CCompactXmlFileReadArchive_included


