/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtex_CXslTransformationReadArchive_included
#define iqtex_CXslTransformationReadArchive_included


// Qt includes
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>


// ACF includes
#include "istd/ILogger.h"

#include "iser/CXmlDocumentInfoBase.h"
#include "iser/CTextReadArchiveBase.h"

#include "iqtex/iqtex.h"


namespace iqtex
{


/**
	Qt-based implementation of archive reading from XML file.

	\ingroup Persistence
*/
class CXslTransformationReadArchive: public iser::CTextReadArchiveBase, public iser::CXmlDocumentInfoBase
{
public:
	CXslTransformationReadArchive(
				const QString& filePath = "",
				const QString& xslFilePath = "",
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);

	bool OpenFile(const QString& filePath, const QString& xslFilePath);

	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(QString& value);

protected:
	bool ReadStringNode(QString& text);

	// reimplemented (iser::CTextReadArchiveBase)
	virtual bool ReadTextNode(QByteArray& text);

private:
	QDomDocument m_document;
	QDomNode m_currentNode;

	bool m_serializeHeader;
	iser::CArchiveTag m_rootTag;
};


} // namespace iqtex


#endif // !iqtex_CXslTransformationReadArchive_included


