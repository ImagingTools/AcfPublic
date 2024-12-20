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


#include <ifile/CFileReadSecureArchive.h>


namespace ifile
{


CFileReadSecureArchive::CFileReadSecureArchive(
			const QString& filePath,
			bool supportTagSkipping,
			bool serializeHeader)
	:BaseClass(filePath, supportTagSkipping, serializeHeader)
{
}


// reimplemented (ifile::CFileReadArchive)

bool CFileReadSecureArchive::ProcessData(void* data, int size)
{
	if (size <= 0){
		return true;
	}

	quint8* dataPtr = (quint8*)data;

	QVector<quint8> buffer(size);

	return BaseClass::ProcessData(&buffer[0], size) && Decode(&buffer[0], dataPtr, size);
}


}	// namespace ifile


