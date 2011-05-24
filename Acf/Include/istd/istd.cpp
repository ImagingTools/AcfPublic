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


#include "istd/istd.h"


// STL includes
#include <assert.h>
#include <iostream>


// ACF includes
#include "istd/ITrace.h"
#include "istd/CStaticServicesProvider.h"


namespace istd
{


// public methods of class CGroupRegistrator

CGroupRegistrator::CGroupRegistrator(const char* groupId)
{
	ITrace* tracePtr = GetService<ITrace>();

	if (tracePtr != NULL){
		tracePtr->RegisterGroupId(groupId);
	}
}


// public functions

void OnSoftwareError(const char* fileName, int line)
{
	ITrace* tracePtr = GetService<ITrace>();

	if (tracePtr != NULL){
		static const char* groupId = "assert";

		if (tracePtr->IsTraceEnabled(CriticalLevel, groupId)){
			tracePtr->LogMessage(CriticalLevel, groupId, "assertion error", fileName, line);

			assert(false);
		}
	}
	else{
		assert(false);
	}
}



bool CheckTraceEnabled(TraceLevel level, const char* groupId)
{
	ITrace* tracePtr = GetService<ITrace>();

	if (tracePtr != NULL){
		return tracePtr->IsTraceEnabled(level, groupId);
	}
	else{
		return false;
	}
}


void SendTraceMessage(TraceLevel level, const char* groupId, const char* message, const char* fileName, int line)
{
	ITrace* tracePtr = GetService<ITrace>();

	if (tracePtr != NULL){
		tracePtr->LogMessage(level, groupId, message, fileName, line);
	}
	else{
		std::cerr << level << "\t" << groupId << "\t" << message << " [fileName: " << line << "]" << std::endl;
	}
}


} // namespace istd


