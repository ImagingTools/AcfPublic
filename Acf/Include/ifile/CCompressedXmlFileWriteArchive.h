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


#ifndef ifile_CCompressedXmlFileWriteArchive_included
#define ifile_CCompressedXmlFileWriteArchive_included


#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QtCore/QFile>
#include <QtCore/QBuffer>

// ACF includes
#include "ifile/CFileArchiveInfo.h"
#include "iser/CCompactXmlWriteArchiveBase.h"


namespace ifile
{


/**
	Qt-based implementation of archive for writing in compact XML format.

	\ingroup Persistence
*/
class CCompressedXmlFileWriteArchive:
			public iser::CCompactXmlWriteArchiveBase,
			public ifile::CFileArchiveInfo
{
public:
	typedef iser::CCompactXmlWriteArchiveBase BaseClass;
	typedef ifile::CFileArchiveInfo BaseClass2;

	/**
		Constructor initializing archive to open file immediatelly.
	*/
	CCompressedXmlFileWriteArchive(
				const QString& filePath,
				const iser::IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);
	~CCompressedXmlFileWriteArchive();

	bool OpenFile(const QString& filePath);

	bool Flush();

private:
	QBuffer m_buffer;
	QFile m_file;
};


} // namespace ifile


#endif // !ifile_CCompressedXmlFileWriteArchive_included


