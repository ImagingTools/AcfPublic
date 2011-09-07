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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iser/CXmlFileReadArchive.h"


namespace iser
{


CXmlFileReadArchive::CXmlFileReadArchive(const istd::CString& filePath, bool serializeHeader, const CArchiveTag& rootTag)
:	BaseClass(rootTag),
	BaseClass2(filePath)
{
	m_stream.open(filePath.ToString().c_str(), std::fstream::in);

	SerializeXmlHeader();

	if (serializeHeader){
		SerializeAcfHeader();
	}
}


// protected methods

// reimplemented (istd::ILogger)

void CXmlFileReadArchive::DecorateMessage(
			MessageCategory /*category*/,
			int /*id*/,
			int /*flags*/,
			istd::CString& message,
			istd::CString& /*messageSource*/) const
{
	message = m_filePath + "(" + istd::CString::FromNumber(m_lastReadLine) + ") : " + message;
}


} // namespace iser


