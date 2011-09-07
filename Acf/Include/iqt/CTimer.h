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


#ifndef iqt_CTimer_included
#define iqt_CTimer_included


#include <QTime>

#include "isys/ITimer.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	An timer implementation for Qt library.
*/
class CTimer: virtual public isys::ITimer
{
public:
	CTimer();

	double GetTimeTo(const CTimer& timer) const;

	/**
		Dummie implementation, provided only for compatibility with iwin::CTimer.
		Please don't use!
	*/
	unsigned long long GetNativeRepresentation() const;
	/**
		Dummie implementation, provided only for compatibility with iwin::CTimer.
		Please don't use!
	*/
	void SetNativeRepresentation(unsigned long long value);

	// reimplemented (isys::ITimer)
	virtual void Start();
	virtual double GetElapsed() const;
	virtual double GetTimeTo(const ITimer& timer) const;
	virtual void WaitTo(double time) const;
	virtual double GetTimerResolution() const;

private:
	QTime m_time;
};


} // namespace iqt


#endif // !iqt_CTimer_included
