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


#include "iqt/CTrace.h"


// Qt includes
#include <QString>


// ACF includes
#include "iqt/iqt.h"


namespace iqt
{


// public methods

CTrace::CTrace()
{
	RegisterGroupId("assert");
	RegisterGroupId("info");
}


// reimplemented (istd::ITrace)

void CTrace::LogMessage(
			istd::TraceLevel level,
			const std::string& groupId,
			const istd::CString& message,
			const std::string& fileName,
			int line) const
{
	if (IsTraceEnabled(level, groupId)){
		QString traceMessage = iqt::GetQString(message);
		if (!fileName.empty() && line >= 0){
			QString fileMessage = QString ("%1, Line: %2: ").arg(fileName.c_str()).arg(line);

			traceMessage = fileMessage + traceMessage;
		}

		qDebug(traceMessage.toLatin1());
	}
}


bool CTrace::IsTraceEnabled(istd::TraceLevel /*level*/, const std::string& groupId) const
{
	if (m_groupIds.find(groupId) != m_groupIds.end()){
		return true;
	}

	return false;
}


void CTrace::RegisterGroupId(const std::string& groupId)
{
	m_groupIds.insert(groupId);
}


} // namespace iqt


