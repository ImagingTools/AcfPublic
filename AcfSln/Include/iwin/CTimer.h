/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iwin_CTimer_included
#define iwin_CTimer_included


#include "istd/istd.h"

#include "isys/ITimer.h"


namespace iwin
{


/**
	An timer implementation for the Windows plattform

	\ingroup Windows
*/
class CTimer: virtual public isys::ITimer
{
public:
	CTimer();

	bool IsVaild() const;

	double GetTimeTo(const CTimer& timer) const;

	I_QWORD GetNativeRepresentation() const;
	void SetNativeRepresentation(I_QWORD value);

	// reimplemented (isys::ITimer)
	virtual void Start();
	virtual double GetElapsed() const;
	virtual double GetTimeTo(const ITimer& timer) const;
	virtual void WaitTo(double time) const;
	virtual double GetTimerResolution() const;

private:
	long long m_startCounter;

	// static attributes
	static I_QWORD s_timerFrequence;
	static bool s_isTimerFrequenceValid;
};


// inline methods

inline I_QWORD CTimer::GetNativeRepresentation() const
{
	return m_startCounter;
}


inline void CTimer::SetNativeRepresentation(I_QWORD value)
{
	m_startCounter = value;
}


} // namespace iwin


#endif // !iwin_CTimer_included
