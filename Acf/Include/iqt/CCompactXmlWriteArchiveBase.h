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


#ifndef iqt_CCompactXmlWriteArchiveBase_included
#define iqt_CCompactXmlWriteArchiveBase_included


#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QtCore/QFile>

// ACF includes
#include "iser/CTextWriteArchiveBase.h"
#include "iser/CXmlDocumentInfoBase.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	Base class of compact XML write archive.
*/
class CCompactXmlWriteArchiveBase:
			public iser::CTextWriteArchiveBase,
			public iser::CXmlDocumentInfoBase
{
public:
	typedef iser::CTextWriteArchiveBase BaseClass;

	/**
		Close the archive and get the created XML string.
	*/
	virtual QByteArray GetString() const;

	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(QString& value);
	using BaseClass::Process;

protected:
	CCompactXmlWriteArchiveBase(
				const iser::IVersionInfo* versionInfoPtr,
				bool serializeHeader,
				const iser::CArchiveTag& rootTag);

	bool WriteStringNode(const QString& text);

		// reimplemented (iser::CTextWriteArchiveBase)
	bool WriteTextNode(const QByteArray& text);

	QDomDocument m_document;
	QDomElement m_currentParent;

private:
	QByteArray m_currentAttribute;

	bool m_serializeHeader;
	iser::CArchiveTag m_rootTag;

	bool m_isSeparatorNeeded;

	QList<const iser::CArchiveTag*> m_tagsStack;
};


} // namespace iqt


#endif // !iqt_CCompactXmlWriteArchiveBase_included


