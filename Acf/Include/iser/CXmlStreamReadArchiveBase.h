/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#ifndef iser_CXmlStreamReadArchiveBase_included
#define iser_CXmlStreamReadArchiveBase_included


// Qt includes
#include <QtCore/QTextStream>

// ACF includes
#include "iser/CXmlReadArchiveBase.h"


namespace iser
{


/**
	Base implementation of a reading archive for XML format using a stream implementation.
*/
class CXmlStreamReadArchiveBase: public CXmlReadArchiveBase
{
public:
	typedef CXmlReadArchiveBase BaseClass;

	int GetLastReadLine() const;

protected:
	CXmlStreamReadArchiveBase(const CArchiveTag& rootTag = s_acfRootTag);

	// reimplemented (iser::CXmlReadArchiveBase)
	virtual bool ReadToDelimeter(
				const QByteArray& delimeters,
				QByteArray& result,
				bool skipDelimeter = true,
				char* foundDelimeterPtr = NULL);

	// reimplemented (istd::ILogger)
	virtual void DecorateMessage(
				istd::IInformationProvider::InformationCategory category,
				int id,
				int flags,
				QString& message,
				QString& messageSource) const;

	QTextStream m_stream;

private:
	char m_lastReadChar;
	bool m_useLastReadChar;

	int m_lastReadLine;
};


} // namespace iser


#endif // !iser_CXmlStreamReadArchiveBase_included


