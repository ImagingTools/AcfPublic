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


#ifndef iser_CCompactXmlMemReadArchive_included
#define iser_CCompactXmlMemReadArchive_included


// Qt includes
#include <QtCore/QBuffer>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>

// ACF includes
#include <iser/CCompactXmlReadArchiveBase.h>


namespace iser
{


/**
	Qt-based implementation of archive reading from XML file.

	\ingroup Persistence
*/
class CCompactXmlMemReadArchive: public CCompactXmlReadArchiveBase
{
public:
	typedef CCompactXmlReadArchiveBase BaseClass;

	/**
		Constructor initializing archive from memory.
	*/
	CCompactXmlMemReadArchive(
				const QByteArray& inputString,
				bool serializeHeader = true,
				const iser::CArchiveTag& rootTag = s_acfRootTag);

protected:
	// reimplemented (istd::ILogger)
	virtual void DecorateMessage(
				istd::IInformationProvider::InformationCategory category,
				int id,
				int flags,
				QString& message,
				QString& messageSource) const;

private:
	QBuffer m_buffer;
};


} // namespace iser


#endif // !iser_CCompactXmlMemReadArchive_included


