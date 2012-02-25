/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef zlib_CGzXmlReadArchive_included
#define zlib_CGzXmlReadArchive_included


// ZLIB includes
#include "zlib.h"

// ACF includes
#include <QString>
#include "iser/CXmlReadArchiveBase.h"
#include "iser/CFileArchiveInfo.h"


namespace izlib
{


/**
	ZLIB compressed implementation of simple archive reading from XML file.
	This imlementation doesn't use any external parser, it uses ZLIB library for file decompressing.
	It uses only single pass and is very fast, but it doesn't support of tags skipping and
	it needs \c counter attribute indicating number of subtags for each mutli tag node.
	Compressed XML file in this format can be created using \c izlib::CGzXmlWriteArchive.

	\ingroup Persistence
*/
class CGzXmlReadArchive:
			public iser::CXmlReadArchiveBase,
			public iser::CFileArchiveInfo
{
public:
	typedef iser::CXmlReadArchiveBase BaseClass;
	typedef iser::CFileArchiveInfo BaseClass2;

	CGzXmlReadArchive(const QString& filePath, bool serializeHeader = true, const iser::CArchiveTag& rootTag = s_acfRootTag);
	virtual ~CGzXmlReadArchive();

	// reimplemented (iser::CXmlReadArchiveBase)
	virtual bool ReadToDelimeter(
				const std::string& delimeters,
				std::string& result,
				bool skipDelimeter = true,
				char* foundDelimeterPtr = NULL);

private:
	gzFile m_file;

	int m_lastReadChar;
	bool m_useLastReadChar;
};


} // namespace izlib


#endif // !zlib_CGzXmlReadArchive_included


