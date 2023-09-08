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


#include <icomm/CUserRequest.h>


// ACF includes
#include <iser/IArchive.h>


#include <icomm/CResponseHeader.h>


namespace icomm{


CUserRequest::CUserRequest(const QByteArray& command, ISerializable* slavePtr, double timeout)
{
	Q_ASSERT(slavePtr != NULL);

	m_command = command;
	m_slavePtr = slavePtr;
	m_timeOut = timeout;
}


// reimplemented (icomm::IRequest)

double CUserRequest::GetTimeOut() const
{
	return m_timeOut;
}


QByteArray CUserRequest::GetCommand() const
{
	return m_command;
}


QString CUserRequest::ExtractMessage(const CResponseHeader& header) const
{
	return header.GetErrorMessage();
}


// reimplemented (iser::ISerializable)

bool CUserRequest::Serialize(iser::IArchive& archive)
{
	Q_ASSERT(m_slavePtr != NULL);

	if (archive.IsStoring()){
		return true;
	}
	else{
		return m_slavePtr->Serialize(archive);
	}
}


} // namespace icomm


