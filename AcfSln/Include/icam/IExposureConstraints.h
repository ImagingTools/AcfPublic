/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef icam_IExposureConstraints_included
#define icam_IExposureConstraints_included


#include <istd/IChangeable.h>
#include <istd/TRange.h>

#include <icam/icam.h>


namespace icam
{


class IExposureConstraints: virtual public istd::IChangeable
{
public:
	/**
		Get range of posible shutter time (exposure time) values.
		\return	range of shutter time, or empty range is this time cannot be controlled.
	*/
	virtual istd::CRange GetShutterTimeRange(int cameraIndex) const = 0;

	/**
		Get range of posible delay time values.
		Delay time is time between trigger and exposure begin.
		\return	range of delay time, or empty range is this time cannot be controlled.
	*/
	virtual istd::CRange GetDelayTimeRange(int cameraIndex) const = 0;

	/**
		Get range of posible exposure enabled (EEN) signal delay time values.
		\return	range of delay time, or empty range is this time cannot be controlled.
	*/
	virtual istd::CRange GetEenDelayRange(int cameraIndex) const = 0;

	// Gain range
	virtual istd::CIntRange GetGainRange(int cameraIndex) const = 0;
};


} // namespace icam


#endif // !icam_IExposureConstraints_included


