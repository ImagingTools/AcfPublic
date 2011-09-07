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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt_CTrace_included
#define iqt_CTrace_included


// STL includes
#include <set>


// ACF includes
#include "istd/istd.h"
#include "istd/ITrace.h"


namespace iqt
{


class CTrace: virtual public istd::ITrace
{
public:
	CTrace();

	// reimplemented (istd::ITrace)
	virtual void LogMessage(
				istd::TraceLevel level,
				const std::string& groupId,
				const istd::CString& message,
				const std::string& fileName = std::string(),
				int line = -1) const;
	virtual bool IsTraceEnabled(istd::TraceLevel level, const std::string& groupId) const;
	virtual void RegisterGroupId(const std::string& groupId);

private:
	typedef std::set<std::string> GroupIds;

	GroupIds m_groupIds;
};


} // namespace iqt


#endif // !iqt_CTrace_included


