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


#ifndef isig_ITriggerParams_included
#define isig_ITriggerParams_included


#include "iser/ISerializable.h"

#include "isig/isig.h"


namespace isig
{


class ITriggerConstraints;


/**
	Interface for AVT camera parameters.
*/
class ITriggerParams: virtual public iser::ISerializable
{
public:
	/**
		Describe working mode of trigger signal.
	*/
	enum TriggerMode
	{
		/**
			There is no trigger, no signal acquisition will be done.
		*/
		TM_NONE,
		/**
			There is no external trigger, permanently signal acquisition will be done.
		*/
		TM_CONTINUOUS,
		/**
			There external trigger with rising edge.
		*/
		TM_RISING_EDGE,
		/**
			There external trigger with falling edge.
		*/
		TM_FALLING_EDGE,
		/**
			There external trigger with positive edge control.
		*/
		TM_POSITIVE_LEVEL,
		/**
			There external trigger with negative edge control.
		*/
		TM_NEGATIVE_LEVEL,
		TM_SOFTWARE
	};

	/**
		Get constrints describing supported parameter states.
	*/
	virtual const ITriggerConstraints* GetTriggerConstraints() const = 0;

	/**
		Get trigger mode.
		Normal trigger modes are defined in \c isig::ITriggerParams::TriggerMode.
	*/
	virtual int GetTriggerMode() const = 0;

	/**
		Set trigger mode.
		Normal trigger modes are defined in \c isig::ITriggerParams::TriggerMode.
	*/
	virtual void SetTriggerMode(int triggerMode) = 0;
};


} // namespace isig


#endif // !isig_ITriggerParams_included


