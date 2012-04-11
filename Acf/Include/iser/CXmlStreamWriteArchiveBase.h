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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iser_CXmlStreamWriteArchiveBase_included
#define iser_CXmlStreamWriteArchiveBase_included


// Qt includes
#include <QtCore/QTextStream>

// ACF includes
#include "iser/CXmlWriteArchiveBase.h"


namespace iser
{


/**
	Base implementation of archive for writing in XML format using a stream implementation.
*/
class CXmlStreamWriteArchiveBase: public CXmlWriteArchiveBase
{
public:
	typedef CXmlWriteArchiveBase BaseClass;

	virtual ~CXmlStreamWriteArchiveBase();

protected:
	CXmlStreamWriteArchiveBase(const IVersionInfo* versionInfoPtr, const CArchiveTag& rootTag);

	// reimplemented (iser::CXmlWriteArchiveBase)
	virtual bool WriteString(const QByteArray& value);

protected:
	QTextStream m_stream;
};


} // namespace iser


#endif // !iser_CXmlStreamWriteArchiveBase_included


