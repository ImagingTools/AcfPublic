/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef istd_ITimeStamp_included
#define istd_ITimeStamp_included


// Qt includes
#include <QtCore/QDateTime>

// ACF includes
#include "istd/IChangeable.h"


namespace istd
{


/**
	Common interface for timer implementations.

	\ingroup System
*/
class ITimeStamp: virtual public istd::IChangeable
{
public:
	/**
		Start the timer.
		\param	elapsed	optional current elapsed time.
	*/
	virtual void Start(double elapsedTime = 0) = 0;

	/**
		Get point in time of latest start.
	*/
	virtual QDateTime GetStartTime() const = 0;

	/**
		Return the time in seconds from start until this call.
	*/
	virtual double GetElapsed() const = 0;

	/**
		Get time difference to second timer.
	*/
	virtual double GetTimeTo(const ITimeStamp& timer) const = 0;

	/**
		Wait for specific timer elapsed value is reached.
	*/
	virtual void WaitTo(double time) const = 0;

	/**
		Return the timer resolution in seconds.
	*/
	virtual double GetTimerResolution() const = 0;
};


} // namespace istd


#endif // !istd_ITimeStamp_included

