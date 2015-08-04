/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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


#include "iwin/CTimeStampCacheComp.h"


namespace iwin
{


// reimplemented (iinsp::ITimeStampProvider)

const istd::ITimeStamp* CTimeStampCacheComp::GetCurrentTimeStamp() const
{
	if (m_isTimerValid){
		return &m_timer;
	}

	return NULL;
}


// reimplemented (istd::IChangeable)

bool CTimeStampCacheComp::CopyFrom(const IChangeable& object, CompatibilityMode /*mode*/)
{
	const iinsp::ITimeStampProvider* providerPtr = dynamic_cast<const iinsp::ITimeStampProvider*>(&object);
	if (providerPtr != NULL){
		const istd::ITimeStamp* timerPtr = providerPtr->GetCurrentTimeStamp();
		if (timerPtr != NULL){
			m_isTimerValid = m_timer.CopyFrom(*timerPtr);
		}
		else{
			m_isTimerValid = false;
		}
		return true;
	}

	return false;
}


} // namespace iwin


