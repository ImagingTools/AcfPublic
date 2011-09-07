/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "CGzXmlWriteArchive.h"


namespace izlib
{


CGzXmlWriteArchive::CGzXmlWriteArchive(
			const istd::CString& filePath,
			const iser::IVersionInfo* versionInfoPtr,
			bool serializeHeader,
			const iser::CArchiveTag& rootTag)
:	BaseClass(versionInfoPtr, rootTag),
	BaseClass2(filePath)
{
	m_file = gzopen(filePath.ToString().c_str(), "wb");

	SerializeXmlHeader();

	if (serializeHeader){
		SerializeAcfHeader();
	}
}


CGzXmlWriteArchive::~CGzXmlWriteArchive()
{
	Flush();

	if (m_file != NULL){
		gzclose(m_file);
	}
}


// protected methods

// reimplemented (iser::CXmlWriteArchiveBase)

bool CGzXmlWriteArchive::WriteString(const std::string& value)
{
	if (!value.empty()){
		return (m_file != NULL) && gzwrite(m_file, value.c_str(), int(value.size())) != 0;
	}
	else{
		return true;
	}
}


} // namespace izlib


