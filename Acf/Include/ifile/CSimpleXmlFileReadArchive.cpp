/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <ifile/CSimpleXmlFileReadArchive.h>


namespace ifile
{


CSimpleXmlFileReadArchive::CSimpleXmlFileReadArchive(const QString& filePath, bool serializeHeader, const iser::CArchiveTag& rootTag)
:	BaseClass(rootTag),
	BaseClass2(filePath),
	m_file(filePath)
{
	if (m_file.open(QIODevice::ReadOnly | QIODevice::Text)){
		m_stream.setDevice(&m_file);

		ReadXmlHeader();

		if (serializeHeader){
			SerializeAcfHeader();
		}
	}
}


CSimpleXmlFileReadArchive::~CSimpleXmlFileReadArchive()
{
	if (m_file.isOpen()){
		ReadXmlFooter();

		m_stream.setDevice(NULL);

		m_file.close();
	}
}


// protected methods

// reimplemented (istd::ILogger)

void CSimpleXmlFileReadArchive::DecorateMessage(
			istd::IInformationProvider::InformationCategory /*category*/,
			int /*id*/,
			int /*flags*/,
			QString& message,
			QString& /*messageSource*/) const
{
	message = m_filePath + "(" + QString("%1").arg(GetLastReadLine()) + ") : " + message;
}


} // namespace ifile


