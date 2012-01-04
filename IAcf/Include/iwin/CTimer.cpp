/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iwin/CTimer.h"


// Windows includes
#include <windows.h>

// ACF includes
#include "istd/TChangeNotifier.h"


namespace iwin
{


CTimer::CTimer()
{
	m_startCounter = 0;

	if (s_isTimerFrequenceValid){
		Start();
	}
}


bool CTimer::IsVaild() const
{
	return s_isTimerFrequenceValid;
}


double CTimer::GetTimeTo(const CTimer& timer) const
{
	return (m_startCounter - timer.m_startCounter) / double(s_timerFrequence);
}


I_QWORD CTimer::GetNativeRepresentation() const
{
	return I_QWORD(m_startCounter);
}


void CTimer::SetNativeRepresentation(I_QWORD value)
{
	istd::CChangeNotifier notifier(this);

	m_startCounter = I_SQWORD(value);
}


// reimplemented (isys::ITimer)

void CTimer::Start(double elapsedTime)
{
	I_ASSERT(sizeof(I_SQWORD) == sizeof(LARGE_INTEGER));

	istd::CChangeNotifier notifier(this);

	LARGE_INTEGER currentCounter;
	::QueryPerformanceCounter(&currentCounter);

	m_startCounter = (I_SQWORD&)currentCounter - I_SQWORD(elapsedTime * s_timerFrequence);
}


double CTimer::GetElapsed() const
{
	I_ASSERT(sizeof(I_SQWORD) == sizeof(LARGE_INTEGER));

	I_SQWORD endCounter;
	::QueryPerformanceCounter((LARGE_INTEGER*)&endCounter);

	return double(endCounter - m_startCounter) / s_timerFrequence;
}


double CTimer::GetTimeTo(const ITimer& timer) const
{
	const CTimer* natTimerPtr = dynamic_cast<const CTimer*>(&timer);
	if (natTimerPtr != NULL){
		return GetTimeTo(*natTimerPtr);
	}
	else{
		return GetElapsed() - timer.GetElapsed();
	}
}


void CTimer::WaitTo(double time) const
{
	int restMs;
	while ((restMs = int((time - GetElapsed()) * 1000)) > 0){
		::SleepEx(I_DWORD(restMs), FALSE);
	}
}


double CTimer::GetTimerResolution() const
{
	return 1.0 / double(s_timerFrequence);
}


// reimplemented (istd::IChangeable)

int CTimer::GetSupportedOperations() const
{
	return SO_COPY;
}


bool CTimer::CopyFrom(const istd::IChangeable& object)
{
	const CTimer* nativeTimerPtr = dynamic_cast<const CTimer*>(&object);
	if (nativeTimerPtr != NULL){
		SetNativeRepresentation(nativeTimerPtr->GetNativeRepresentation());

		return true;
	}
	else{
		const isys::ITimer* timerPtr = dynamic_cast<const isys::ITimer*>(&object);
		if (timerPtr != NULL){
			Start(timerPtr->GetElapsed());

			return true;
		}
	}

	return false;
}


// static attributes

I_SQWORD CTimer::s_timerFrequence;
bool CTimer::s_isTimerFrequenceValid = (::QueryPerformanceFrequency((LARGE_INTEGER*)&CTimer::s_timerFrequence) != 0);


} // namespace iwin

