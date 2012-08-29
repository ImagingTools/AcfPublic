/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "CGzXmlWriteArchive.h"


namespace izlib
{


CGzXmlWriteArchive::CGzXmlWriteArchive(
			const QString& filePath,
			const iser::IVersionInfo* versionInfoPtr,
			bool serializeHeader,
			const iser::CArchiveTag& rootTag)
:	BaseClass(versionInfoPtr, rootTag),
	BaseClass2(filePath)
{
	m_file = gzopen(filePath.toLocal8Bit(), "wb");

	if (m_file != NULL){
		WriteXmlHeader();
	
		if (serializeHeader){
			SerializeAcfHeader();
		}
	}
}


CGzXmlWriteArchive::~CGzXmlWriteArchive()
{
	if (m_file != NULL){
		WriteXmlFooter();

		gzclose(m_file);
	}
}


// protected methods

// reimplemented (iser::CXmlWriteArchiveBase)

bool CGzXmlWriteArchive::WriteString(const QByteArray& value)
{
	if (!value.isEmpty()){
		return (m_file != NULL) && gzwrite(m_file, value, int(value.size())) != 0;
	}
	else{
		return true;
	}
}


} // namespace izlib


