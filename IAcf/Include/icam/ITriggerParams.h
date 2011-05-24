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


#ifndef icam_ITriggerParams_included
#define icam_ITriggerParams_included


#include "iser/ISerializable.h"

#include "icam/icam.h"


namespace icam
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
		TM_DEFAULT,
		TM_RISING_EDGE,
		TM_FALLING_EDGE,
		TM_POSITIVE_LEVEL,
		TM_NEGATIVE_LEVEL
	};

	/**
		Get constrints describing supported parameter states.
	*/
	virtual const ITriggerConstraints* GetConstraints() const = 0;

	/**
		Check if trigger is enabled.
	*/
	virtual bool IsTriggerEnabled() const = 0;
	/**
		Set trigger enabling state.
	*/
	virtual void SetTriggerEnabled(bool isEnabled) = 0;

	/**
		Get trigger mode.
		Normal trigger modes are defined in \c icam::ITriggerParams::TriggerMode.
	*/
	virtual int GetTriggerMode() const = 0;

	/**
		Set trigger mode.
		Normal trigger modes are defined in \c icam::ITriggerParams::TriggerMode.
	*/
	virtual void SetTriggerMode(int triggerMode) = 0;
};


} // namespace icam


#endif // !icam_ITriggerParams_included


