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


#ifndef iqt_CCompactXmlMemWriteArchive_included
#define iqt_CCompactXmlMemWriteArchive_included


#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QtCore/QFile>

// ACF includes
#include "iqt/CCompactXmlWriteArchiveBase.h"


namespace iqt
{


/**
	Qt-based implementation of archive for writing in XML format.
	Please note that it doesn't create \c counter attribute needed by \c ifile::CXmlFileReadArchive.

	\ingroup Persistence
*/
class CCompactXmlMemWriteArchive:
			public CCompactXmlWriteArchiveBase
{
public:
	typedef CCompactXmlWriteArchiveBase BaseClass;

	/**
		Constructor initializing archive to work with memory.
		Use \c GetString() to get the created XML buffer.
	*/
	CCompactXmlMemWriteArchive(
				const iser::IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);

	/**
		Close the archive and get the created XML string.
	*/
	virtual QByteArray GetString() const;
};


} // namespace iqt


#endif // !iqt_CCompactXmlMemWriteArchive_included


