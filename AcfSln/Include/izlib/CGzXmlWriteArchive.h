/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef zlib_CGzXmlWriteArchive_included
#define zlib_CGzXmlWriteArchive_included


// ZLIB includes
#include "zlib.h"

// STL includes
#include <fstream>

// ACF includes
#include "istd/CString.h"
#include "iser/CXmlWriteArchiveBase.h"
#include "iser/CFileArchiveInfo.h"


namespace izlib
{


/**
	ZLIB compressed implementation of archive for writing in XML format.
	This implementation doesn't use any external parser, it uses ZLIB library for file compressing.
	It creates \c counter attribute indicating number of subtags for each mutli tag node.
	Compressed XML file in this format are needed by \c izlib::CGzXmlReadArchive.

	\ingroup Persistence
*/
class CGzXmlWriteArchive:
			public iser::CXmlWriteArchiveBase,
			public iser::CFileArchiveInfo
{
public:
	typedef iser::CXmlWriteArchiveBase BaseClass;
	typedef iser::CFileArchiveInfo BaseClass2;

	CGzXmlWriteArchive(
				const istd::CString& filePath,
				const iser::IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);
	virtual ~CGzXmlWriteArchive();

protected:
	enum{
		CHUNK_SIZE = 16384
	};

	// reimplemented (iser::CXmlWriteArchiveBase)
	virtual bool WriteString(const std::string& value);

private:
	gzFile m_file;
};


} // namespace izlib


#endif // !zlib_CGzXmlWriteArchive_included


