/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <icomm/CRequestHeader.h>


// Qt includes
#include <QtCore/QUuid>

// ACF includes
#include <istd/CChangeNotifier.h>
#include <iser/IArchive.h>


namespace icomm
{


CRequestHeader::CRequestHeader()
{
	m_requestId = QUuid::createUuid().toByteArray();
}


CRequestHeader::CRequestHeader(const QByteArray& command, const QByteArray& requestId)
:	m_command(command),
	m_requestId(requestId)
{
	if (requestId.isEmpty()){
		m_requestId = QUuid::createUuid().toByteArray();
	}
}


// reimplemented (iser::ISerializable)

bool CRequestHeader::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);

	bool retVal = true;

	retVal = retVal && archive.Process(m_command);
	retVal = retVal && archive.Process(m_requestId);

	return retVal;
}


} // namespace icomm


