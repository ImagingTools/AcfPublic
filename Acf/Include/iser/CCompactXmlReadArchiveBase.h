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


#ifndef iser_CCompactXmlReadArchiveBase_included
#define iser_CCompactXmlReadArchiveBase_included


// Qt includes
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>

// ACF includes
#include <iser/CXmlDocumentInfoBase.h>
#include <iser/CTextReadArchiveBase.h>

#include <iser/iser.h>


namespace iser
{


/**
	Qt-based implementation of archive reading from XML file.

	\ingroup Persistence
*/
class CCompactXmlReadArchiveBase: public iser::CTextReadArchiveBase, public iser::CXmlDocumentInfoBase
{
public:
	CCompactXmlReadArchiveBase(
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);

	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(QString& value);
	using BaseClass::Process;

protected:
	bool ReadStringNode(QString& text);

	bool SetContent(QIODevice* devicePtr);

	// reimplemented (iser::CTextReadArchiveBase)
	virtual bool ReadTextNode(QByteArray& text);

	// reimplemented (istd::ILogger)
	virtual void DecorateMessage(
				istd::IInformationProvider::InformationCategory category,
				int id,
				int flags,
				QString& message,
				QString& messageSource) const;

	QDomDocument m_document;
	QDomElement m_currentParent;

private:
	QByteArray m_currentAttribute;

	bool m_serializeHeader;
	iser::CArchiveTag m_rootTag;

	bool m_isNewFormat;			// idicate that new format is enabled
	bool m_allowAttribute;		// indicate if attribute outputting is allowed now

	typedef QList<const iser::CArchiveTag*> TagsList;
	TagsList m_tagsStack;
};


} // namespace iser


#endif // !iser_CCompactXmlReadArchiveBase_included


