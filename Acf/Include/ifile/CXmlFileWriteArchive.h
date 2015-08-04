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


#ifndef ifile_CXmlFileWriteArchive_included
#define ifile_CXmlFileWriteArchive_included


// Qt includes
#include <QtCore/QFile>

// ACF includes
#include "iser/CXmlWriteArchiveBase.h"
#include "ifile/CFileArchiveInfo.h"


namespace ifile
{


/**
	Simple implementation of archive for writing in XML format.
	This implementation doesn't use any external parser.
	It creates \c counter attribute indicating number of subtags for each mutli tag node.
	XML file in this format are needed by \c ifile::CXmlFileReadArchive.

	\ingroup Persistence
*/
class CXmlFileWriteArchive:
			public iser::CXmlWriteArchiveBase,
			public CFileArchiveInfo
{
public:
	typedef iser::CXmlWriteArchiveBase BaseClass;
	typedef CFileArchiveInfo BaseClass2;

	explicit CXmlFileWriteArchive(
				const QString& filePath,
				const iser::IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);
	virtual ~CXmlFileWriteArchive();

protected:
	// reimplemented (iser::CXmlWriteArchiveBase)
	virtual bool WriteString(const QByteArray& value);

private:
	QTextStream m_stream;
	QFile m_file;
};


} // namespace ifile


#endif // !ifile_CXmlFileWriteArchive_included


