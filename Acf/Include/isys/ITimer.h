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


#ifndef isys_ITimer_included
#define isys_ITimer_included


#include "isys/isys.h"


#include "istd/IPolymorphic.h"


namespace isys
{


/**
	Common interface for timer implementations.

	\ingroup System
*/
class ITimer: virtual public istd::IPolymorphic
{
public:
	/**
		Start the timer.
	*/
	virtual void Start() = 0;

	/**
		Return the time in seconds from start until this call.
	*/
	virtual double GetElapsed() const = 0;

	/**
		Get time difference to second timer.
	*/
	virtual double GetTimeTo(const ITimer& timer) const = 0;

	/**
		Wait for specific timer elapsed value is reached.
	*/
	virtual void WaitTo(double time) const = 0;

	/**
		Return the timer resolution in seconds.
	*/
	virtual double GetTimerResolution() const = 0;
};


} // namespace isys


#endif // !isys_ITimer_included

