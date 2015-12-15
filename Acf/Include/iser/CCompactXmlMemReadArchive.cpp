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


#include "iser/CCompactXmlMemReadArchive.h"


// include STL
#include <cstring>

// Qt includes
#include <QtCore/QFile>
#include <QtXml/QDomNodeList>


namespace iser
{


CCompactXmlMemReadArchive::CCompactXmlMemReadArchive(
			const QByteArray& inputString,
			bool serializeHeader,
			const iser::CArchiveTag& rootTag)
:	BaseClass(serializeHeader, rootTag)
{
	m_buffer.setData(inputString);

	if (!BaseClass::SetContent(&m_buffer)){
		return;
	}
}


// protected methods

// reimplemented (istd::ILogger)

void CCompactXmlMemReadArchive::DecorateMessage(
			istd::IInformationProvider::InformationCategory category,
			int id,
			int flags,
			QString& message,
			QString& messageSource) const
{
	BaseClass::DecorateMessage(category, id, flags, message, messageSource);

	int lineNumber = m_currentParent.lineNumber();
	if (lineNumber >= 0){
		message = QObject::tr("%1 (Line: %2)").arg(message).arg(lineNumber);
	}
}


} // namespace iser


