/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
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


