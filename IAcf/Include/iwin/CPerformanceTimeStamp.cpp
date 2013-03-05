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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iwin/CPerformanceTimeStamp.h"


// Windows includes
#include <windows.h>

// ACF includes
#include "istd/TChangeNotifier.h"


namespace iwin
{


CPerformanceTimeStamp::CPerformanceTimeStamp()
{
	m_startCounter = 0;

	if (s_isTimerFrequenceValid){
		Start();
	}
}


bool CPerformanceTimeStamp::IsVaild() const
{
	return s_isTimerFrequenceValid;
}


double CPerformanceTimeStamp::GetTimeTo(const CPerformanceTimeStamp& timeStamp) const
{
	return (m_startCounter - timeStamp.m_startCounter) / double(s_timerFrequence);
}


quint64 CPerformanceTimeStamp::GetNativeRepresentation() const
{
	return quint64(m_startCounter);
}


void CPerformanceTimeStamp::SetNativeRepresentation(quint64 value)
{
	istd::CChangeNotifier notifier(this);

	m_startCounter = qint64(value);
}


// reimplemented (istd::ITimeStamp)

void CPerformanceTimeStamp::Start(double elapsedTime)
{
	Q_ASSERT(sizeof(qint64) == sizeof(LARGE_INTEGER));

	istd::CChangeNotifier notifier(this);

	LARGE_INTEGER currentCounter;
	::QueryPerformanceCounter(&currentCounter);

	m_startCounter = (qint64&)currentCounter - qint64(elapsedTime * s_timerFrequence);
}


QDateTime CPerformanceTimeStamp::GetStartTime() const
{
	QDateTime retVal = QDateTime::currentDateTime();

	retVal.addMSecs(quint64(GetElapsed() * 1000));

	return retVal;
}


double CPerformanceTimeStamp::GetElapsed() const
{
	Q_ASSERT(sizeof(qint64) == sizeof(LARGE_INTEGER));

	qint64 endCounter;
	::QueryPerformanceCounter((LARGE_INTEGER*)&endCounter);

	return double(endCounter - m_startCounter) / s_timerFrequence;
}


double CPerformanceTimeStamp::GetTimeTo(const istd::ITimeStamp& timeStamp) const
{
	const CPerformanceTimeStamp* natTimeStampPtr = dynamic_cast<const CPerformanceTimeStamp*>(&timeStamp);
	if (natTimeStampPtr != NULL){
		return GetTimeTo(*natTimeStampPtr);
	}
	else{
		return GetElapsed() - timeStamp.GetElapsed();
	}
}


void CPerformanceTimeStamp::WaitTo(double time) const
{
	int restMs;
	while ((restMs = int((time - GetElapsed()) * 1000)) > 0){
		::SleepEx(quint32(restMs), FALSE);
	}
}


double CPerformanceTimeStamp::GetTimerResolution() const
{
	return 1.0 / double(s_timerFrequence);
}


// reimplemented (istd::IChangeable)

int CPerformanceTimeStamp::GetSupportedOperations() const
{
	return SO_COPY;
}


bool CPerformanceTimeStamp::CopyFrom(const istd::IChangeable& object, CompatibilityMode /*mode*/)
{
	const CPerformanceTimeStamp* nativeTimerPtr = dynamic_cast<const CPerformanceTimeStamp*>(&object);
	if (nativeTimerPtr != NULL){
		SetNativeRepresentation(nativeTimerPtr->GetNativeRepresentation());

		return true;
	}
	else{
		const istd::ITimeStamp* timerPtr = dynamic_cast<const istd::ITimeStamp*>(&object);
		if (timerPtr != NULL){
			Start(timerPtr->GetElapsed());

			return true;
		}
	}

	return false;
}


// static attributes

qint64 CPerformanceTimeStamp::s_timerFrequence;
bool CPerformanceTimeStamp::s_isTimerFrequenceValid = (::QueryPerformanceFrequency((LARGE_INTEGER*)&CPerformanceTimeStamp::s_timerFrequence) != 0);


} // namespace iwin

