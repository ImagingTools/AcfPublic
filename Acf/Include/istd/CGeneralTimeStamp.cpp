/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "istd/CGeneralTimeStamp.h"


// Qt includes
#include <QtCore/QThread>

// ACF includes
#include "istd/CChangeNotifier.h"


class ThreadBrute: public QThread
{
public:
	using QThread::usleep;
};


namespace istd
{


CGeneralTimeStamp::CGeneralTimeStamp()
{
	m_timeShift = 0;

#if QT_VERSION >= 0x040700
	m_timer.start();
#else
	m_timer = QDateTime::currentDateTime();
#endif
}


double CGeneralTimeStamp::GetTimeTo(const CGeneralTimeStamp& timeStamp) const
{
#if QT_VERSION >= 0x040700
	return m_timer.msecsTo(timeStamp.m_timer) * 0.001 + timeStamp.m_timeShift - m_timeShift;
#else
	return m_timer.time().msecsTo(timeStamp.m_timer.time()) * 0.001 + timeStamp.m_timeShift - m_timeShift;
#endif
}


// reimplemented (istd::ITimeStamp)

void CGeneralTimeStamp::Start(double elapsedTime)
{
	static const ChangeSet startChangeSet(CF_START_SET);
	istd::CChangeNotifier notifier(this, &startChangeSet);
	Q_UNUSED(notifier);

	m_timeShift = elapsedTime;

#if QT_VERSION >= 0x040700
	m_timer.start();
#else
	m_timer = QDateTime::currentDateTime();
#endif
}


QDateTime CGeneralTimeStamp::GetStartTime() const
{
#if QT_VERSION >= 0x040700
	return QDateTime::currentDateTime().addMSecs(m_timer.elapsed());
#else
	return m_timer;
#endif
}


double CGeneralTimeStamp::GetElapsed() const
{
#if QT_VERSION >= 0x040800
	return m_timer.nsecsElapsed() * 0.000000001 + m_timeShift;
#else
#if QT_VERSION >= 0x040700
	return m_timer.elapsed() * 0.001 + m_timeShift;
#else
	return QDateTime::currentDateTime().time().msecsTo(m_timer.time()) * 0.001 + m_timeShift;
#endif
#endif
}


double CGeneralTimeStamp::GetTimeTo(const ITimeStamp& timeStamp) const
{
	const CGeneralTimeStamp* natTimeStampPtr = dynamic_cast<const CGeneralTimeStamp*>(&timeStamp);
	if (natTimeStampPtr != NULL){
		return GetTimeTo(*natTimeStampPtr);
	}
	else{
		return GetElapsed() - timeStamp.GetElapsed();
	}
}


void CGeneralTimeStamp::WaitTo(double time) const
{
	double restMicroseconds;
	while ((restMicroseconds = (time - GetElapsed()) * 1000000) >= 1){
		ThreadBrute::usleep(quint32(restMicroseconds));
	}
}


double CGeneralTimeStamp::GetTimerResolution() const
{
#if QT_VERSION >= 0x040700
	return 0.000001;
#else
	return 0.001;
#endif
}


} // namespace istd


