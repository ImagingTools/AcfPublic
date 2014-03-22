/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef icam_IExposureParams_included
#define icam_IExposureParams_included


#include "iser/ISerializable.h"

#include "icam/icam.h"


namespace icam
{


class IExposureConstraints;


class IExposureParams: virtual public iser::ISerializable
{
public:
	/**
		Get constrints describing allowed value ranges.
	*/
	virtual const IExposureConstraints* GetExposureConstraints() const = 0;

	/**
		Get shutter time (exposure time).
		\return	shutter time in seconds or negative value if this value isn't active.
	*/
	virtual double GetShutterTime() const = 0;

	/**
		Set shutter time (exposure time).
		\param	time	shutter time in seconds.
		\return	true, if success.
	*/
	virtual bool SetShutterTime(double time) = 0;

	/**
		Get delay time.
		Delay time is time between trigger and exposure begin.
		\return	delay time in seconds or negative value if this value isn't active.
	*/
	virtual double GetDelayTime() const = 0;

	/**
		Set delay time.
		Delay time is time between trigger and exposure begin.
		\param	time	delay time in seconds.
		\return	true, if success.
	*/
	virtual bool SetDelayTime(double time) = 0;

	/**
		Get exposure enabled (EEN) signal delay time.
		\return	delay time in seconds or negative value if this value isn't active.
	*/
	virtual double GetEenDelay() const = 0;

	/**
		Set exposure enabled (EEN) signal delay time.
		\param	time	exposure enabled (EEN) signal delay time in seconds.
		\return	true, if success.
	*/
	virtual bool SetEenDelay(double time) = 0;
};


} // namespace icam


#endif // !icam_IExposureParams_included


