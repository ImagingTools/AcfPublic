/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
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


