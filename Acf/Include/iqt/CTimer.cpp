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


#include "iqt/CTimer.h"


// Qt includes
#include <QThread>


class ThreadBrute: public QThread
{
public:
	using QThread::usleep;
};


namespace iqt
{


CTimer::CTimer()
{
	m_time.start();
}


double CTimer::GetTimeTo(const CTimer& timer) const
{
	return m_time.msecsTo(timer.m_time) * 0.001;
}


unsigned long long CTimer::GetNativeRepresentation() const
{
	return 0;
}


void CTimer::SetNativeRepresentation(unsigned long long/* value*/)
{
	I_CRITICAL();	// not implemented yet!
}


// reimplemented (isys::ITimer)

void CTimer::Start()
{
	m_time.start();
}


double CTimer::GetElapsed() const
{
	return m_time.elapsed() * 0.001;
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
	double restMis;
	while ((restMis = (time - GetElapsed()) * 1000000) >= 1){
		ThreadBrute::usleep(I_DWORD(restMis));
	}
}


double CTimer::GetTimerResolution() const
{
	return 0.001;
}



} // namespace iqt


