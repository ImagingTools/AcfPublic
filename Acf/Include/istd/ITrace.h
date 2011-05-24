/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#ifndef istd_ITrace_included
#define istd_ITrace_included


#include <string>

#include "istd/IPolymorphic.h"
#include "istd/CString.h"


namespace istd
{


/**
	Provide system logging.
*/
class ITrace: virtual public IPolymorphic
{
public:
	/**
	Send message to log system.
	\param	level		priority of this message.
	\param	groupId		ID of trace group, it is used to allow enable/disable of traceing of specified groups.
	\param	message		log message text.
	\param	fileName	optional file name. If it is empty string, no file is specified.
	\param	line		optional line number in file. If it is negative value, no line is specified.
	*/
	virtual void LogMessage(
				TraceLevel level,
				const std::string& groupId,
				const CString& message,
				const std::string& fileName = "",
				int line = -1) const = 0;
	/**
	Check if traceing of this element is enabled.
	This must be checked before LogMessage will be called.
	*/
	virtual bool IsTraceEnabled(TraceLevel level, const std::string& groupId) const = 0;
	/**
	Register ID of group.
	It is used to create list of possible groups.
	*/
	virtual void RegisterGroupId(const std::string& groupId) = 0;
};


} // namespace istd


#endif // !istd_ITrace_included


