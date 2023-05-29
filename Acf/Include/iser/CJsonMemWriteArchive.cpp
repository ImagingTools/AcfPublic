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


#include <iser/CJsonMemWriteArchive.h>


// Qt includes
#include <QtCore/QJsonDocument>


namespace iser
{


// public methods

CJsonMemWriteArchive::CJsonMemWriteArchive(
			QByteArray &inputString,
			const IVersionInfo* versionInfoPtr,
			QJsonDocument::JsonFormat jsonFormat)
	:BaseClass(versionInfoPtr)
{
	bool serializeHeader = versionInfoPtr != nullptr;
	InitArchive(inputString, serializeHeader);
}


CJsonMemWriteArchive::~CJsonMemWriteArchive()
{
	if (m_buffer.isOpen()){
		if (m_rootTagEnabled){
			EndTag(m_rootTag);
		}
		m_buffer.close();
	}
}


} // namespace iser


