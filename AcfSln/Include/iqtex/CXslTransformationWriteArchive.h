/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtex_CXslTransformationWriteArchive_included
#define iqtex_CXslTransformationWriteArchive_included


// Qt includes
#include <QDomDocument>
#include <QDomNode>
#include <QFile>
#include <QBuffer>


// ACF includes
#include "iser/CWriteArchiveBase.h"
#include "iser/CFileArchiveInfo.h"
#include "iser/CXmlDocumentInfoBase.h"

#include "iqtex/iqtex.h"


namespace iqtex
{


/**
	Qt-based implementation of archive for writing in XML format.
	Please note that it doesn't create \c counter attribute needed by \c iser::CXmlFileReadArchive.

	\ingroup Persistence
*/
class CXslTransformationWriteArchive:
			public iser::CWriteArchiveBase,
			public iser::CFileArchiveInfo,
			public iser::CXmlDocumentInfoBase
{
public:
	typedef iser::CWriteArchiveBase BaseClass;
	typedef iser::CFileArchiveInfo BaseClass2;

	CXslTransformationWriteArchive(
				const QString& filePath = "",
				const QString& xslFilePath = "",
				const iser::IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);
	~CXslTransformationWriteArchive();



	bool Flush();

	bool OpenDocument(const QString& filePath, const QString& xslFilePath);

	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginTag(const iser::CArchiveTag& tag);
	virtual bool BeginMultiTag(const iser::CArchiveTag& tag, const iser::CArchiveTag& subTag, int& count);
	virtual bool EndTag(const iser::CArchiveTag& tag);
	virtual bool Process(bool& value);
	virtual bool Process(char& value);
	virtual bool Process(I_BYTE& value);
	virtual bool Process(I_SBYTE& value);
	virtual bool Process(I_WORD& value);
	virtual bool Process(I_SWORD& value);
	virtual bool Process(I_DWORD& value);
	virtual bool Process(I_SDWORD& value);
	virtual bool Process(I_QWORD& value);
	virtual bool Process(I_SQWORD& value);
	virtual bool Process(float& value);
	virtual bool Process(double& value);
	virtual bool Process(std::string& value);
	virtual bool Process(QString& value);
	virtual bool ProcessData(void* dataPtr, int size);

protected:
	/**
		Find the next text node and move the current node to the next sibling.
	*/
	bool PushTextNode(const QString& text);

	virtual bool SendLogMessage(
		MessageCategory category,
		int id,
		const QString& message,
		const QString& messageSource,
		int flags = 0) const
	{
		return iser::CWriteArchiveBase::SendLogMessage(category, id, message, messageSource, flags);
	}
private:
	friend class WriteArchiveMessageHandler;

	QDomDocument m_document;
	QDomElement m_currentParent;

	QFile m_file;
	QString m_xslFilePath;

	bool m_serializeHeader;
	iser::CArchiveTag m_rootTag;

	bool m_isSeparatorNeeded;
};


} // namespace iqtex


#endif // !iqtex_CXslTransformationWriteArchive_included


