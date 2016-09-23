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


#ifndef iser_CXmlStringWriteArchive_included
#define iser_CXmlStringWriteArchive_included


// Qt includes
#include <QtCore/QBuffer>

// ACF includes
#include <iser/CXmlWriteArchiveBase.h>


namespace iser
{


/**
	Simple implementation of archive for writing of XML given as a string.

	\ingroup Persistence
*/
class CXmlStringWriteArchive: public CXmlWriteArchiveBase
{
public:
	typedef CXmlWriteArchiveBase BaseClass;

	CXmlStringWriteArchive(
				const IVersionInfo* versionInfoPtr = NULL,
				bool serializeHeader = true,
				const CArchiveTag& rootTag = s_acfRootTag);
	virtual ~CXmlStringWriteArchive();

	/**
		Close the archive and get the created XML string.
	*/
	virtual const QByteArray& GetString() const;

protected:
	void EnsureArchiveClosed();

	// reimplemented (iser::CXmlWriteArchiveBase)
	virtual bool WriteString(const QByteArray& value);

private:
	QTextStream m_stream;
	QBuffer m_buffer;
};


} // namespace iser


#endif // !iser_CXmlStringWriteArchive_included


