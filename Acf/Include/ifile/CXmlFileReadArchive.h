/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ifile_CXmlFileReadArchive_included
#define ifile_CXmlFileReadArchive_included


// Qt includes
#include <QtCore/QFile>

// ACF includes
#include "iser/CXmlStreamReadArchiveBase.h"
#include "ifile/CFileArchiveInfo.h"


namespace ifile
{


/**
	Simple implementation of archive reading from XML file.
	This implementation doesn't use any external parser.
	It uses only single pass and is very fast, but it doesn't support of tags skipping and
	it needs \c counter attribute indicating number of subtags for each mutli tag node.
	XML file in this format can be created using \c ifile::CXmlFileWriteArchive.

	\ingroup Persistence
*/
class CXmlFileReadArchive:
			public iser::CXmlStreamReadArchiveBase,
			public CFileArchiveInfo
{
public:
	typedef iser::CXmlStreamReadArchiveBase BaseClass;
	typedef CFileArchiveInfo BaseClass2;

	explicit CXmlFileReadArchive(const QString& filePath, bool serializeHeader = true, const iser::CArchiveTag& rootTag = s_acfRootTag);
	virtual ~CXmlFileReadArchive();

protected:
	// reimplemented (istd::ILogger)
	virtual void DecorateMessage(
				istd::IInformationProvider::InformationCategory category,
				int id,
				int flags,
				QString& message,
				QString& messageSource) const;

private:
	QFile m_file;
};


} // namespace ifile


#endif // !ifile_CXmlFileReadArchive_included


