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


#include <icomm/CResponseHeader.h>


// ACF includes
#include <istd/CChangeNotifier.h>
#include <iser/IArchive.h>


#include <icomm/CRequestHeader.h>


namespace icomm
{


CResponseHeader::CResponseHeader()
:	m_requestId(0)
{
	m_flags = RF_INVALID;
	m_errorType = ET_NONE;
}


void CResponseHeader::SetOk(const CRequestHeader& request)
{
	m_errorType = ET_NONE;
	m_flags = RF_SERIALIZED;
	m_requestId = request.GetRequestId();
}


void CResponseHeader::SetError(ErrorType errorType, const CRequestHeader& request, const QString& errorMessage, bool serialized)
{
	Q_ASSERT(errorType != ET_NONE);

	m_errorType = errorType;
	m_flags = serialized? RF_ERROR | RF_SERIALIZED: RF_ERROR;
	m_errorMessage = errorMessage;
	m_requestId = request.GetRequestId();
}


void CResponseHeader::SetToKeepAliveMessage(const CRequestHeader& request)
{
	m_errorType = ET_NONE;
	m_flags = RF_KEEP_ALIVE;
	m_requestId = request.GetRequestId();
}


// reimplemented (iser::ISerializable)

bool CResponseHeader::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);

	archive.Process(m_requestId);

	int flags = m_flags;
	int errorType = m_errorType;
	bool result = archive.Process(errorType);
	result = result && archive.Process(flags);

	Q_ASSERT(!result || (errorType != ET_NONE) == ((flags & RF_ERROR) != 0));
	
	if (result && ((flags & RF_ERROR) != 0)){
		result = archive.Process(m_errorMessage) && result;
	}
	else{
		m_errorMessage = "";
	}
	m_flags = ResponseFlags(flags);

	return result;
}


} // namespace icomm


