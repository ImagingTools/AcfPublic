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


#ifndef iipr_ICaliperParams_included
#define iipr_ICaliperParams_included


#include "iser/ISerializable.h"

#include "iipr/iipr.h"


namespace iipr
{


class ICaliperParams: virtual public iser::ISerializable
{
public:
	/**
		Describe mode of polarity acceptance.
	*/
	enum PolarityMode
	{
		/**
			Only riseing edges (dark to bright) will be accepted.
		*/
		PM_RISED,
		/**
			Only droping edges (bright to dark) will be accepted.
		*/
		PM_DROPPED,
		/**
			Any polarity will be accepted.
		*/
		PM_ALL
	};

	/**
		Describe mode of search direction.
	*/
	enum DirectionMode
	{
		DM_FORWARD,
		DM_BACKWARD,
		DM_OUTSIDE,
		DM_INSIDE,
		DM_DONT_CARE
	};

	/**
		Get feature weight threshold will be used to cut weak fetures off.
	*/
	virtual double GetWeightThreshold() const = 0;

	/**
		Set feature weight threshold will be used to cut weak fetures off.
	*/
	virtual void SetWeightThreshold(double threshold) = 0;

	/**
		Get polarity mode.
		\sa PolarityMode.
	*/
	virtual int GetPolarityMode() const = 0;

	/**
		Set polarity mode.
		\sa PolarityMode.
	*/
	virtual void SetPolarityMode(int mode) = 0;

	/**
		Get direction mode.
		\sa DirectionMode.
	*/
	virtual int GetDirectionMode() const = 0;

	/**
		Set direction mode.
		\sa DirectionMode.
	*/
	virtual void SetDirectionMode(int mode) = 0;
};


} // namespace iipr


#endif // !iipr_ICaliperParams_included


