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


#include "iser/CXmlStringWriteArchive.h"


namespace iser
{


CXmlStringWriteArchive::CXmlStringWriteArchive(
			const IVersionInfo* versionInfoPtr,
			bool serializeHeader,
			const CArchiveTag& rootTag)
:	BaseClass(versionInfoPtr, rootTag)
{
	if (m_buffer.open(QIODevice::WriteOnly | QIODevice::Text)){
		m_stream.setDevice(&m_buffer);

		WriteXmlHeader();

		if (serializeHeader){
			SerializeAcfHeader();
		}
	}
}


CXmlStringWriteArchive::~CXmlStringWriteArchive()
{
	EnsureArchiveClosed();
}


const QByteArray& CXmlStringWriteArchive::GetString() const
{
	const_cast<CXmlStringWriteArchive*>(this)->EnsureArchiveClosed();

	return m_buffer.data();
}


// protected methods

void CXmlStringWriteArchive::EnsureArchiveClosed()
{
	if (m_buffer.isOpen()){
		BaseClass::WriteXmlFooter();
		
		m_stream.setDevice(NULL);

		m_buffer.close();
	}
}


// reimplemented (iser::CXmlWriteArchiveBase)

bool CXmlStringWriteArchive::WriteString(const QByteArray& value)
{
	m_stream << value;

	return m_stream.status() == QTextStream::Ok;
}


} // namespace iser


