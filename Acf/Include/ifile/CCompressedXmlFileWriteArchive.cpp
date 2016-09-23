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


#include <ifile/CCompressedXmlFileWriteArchive.h>


// Qt includes
#include <QtXml/QDomNodeList>
#include <QtCore/QTextStream>


namespace ifile
{


CCompressedXmlFileWriteArchive::CCompressedXmlFileWriteArchive(
			const QString& filePath,
			const iser::IVersionInfo* versionInfoPtr,
			bool serializeHeader,
			const iser::CArchiveTag& rootTag)
:	BaseClass(versionInfoPtr, serializeHeader, rootTag),
	BaseClass2(filePath)
{
	if (!filePath.isEmpty()){
		OpenFile(filePath);
	}
}


CCompressedXmlFileWriteArchive::~CCompressedXmlFileWriteArchive()
{
	Flush();
}


bool CCompressedXmlFileWriteArchive::OpenFile(const QString& filePath)
{
	m_file.setFileName(filePath);

	if (m_file.open(QIODevice::WriteOnly | QIODevice::Text)){
		return InitArchive(&m_buffer);
	}

	return false;
}


bool CCompressedXmlFileWriteArchive::Flush()
{
	BaseClass::Flush();

	if (m_file.isOpen()){
		QByteArray data = qCompress(m_buffer.buffer());

		return (m_file.write(data) > 0);
	}

	return false;
}


} // namespace ifile


