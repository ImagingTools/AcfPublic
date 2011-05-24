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


#ifndef icam_ITriggerConstraints_included
#define icam_ITriggerConstraints_included


#include "istd/IPolymorphic.h"


namespace icam
{


/**
	Interface for AVT camera parameters.
*/
class ITriggerConstraints: virtual public istd::IPolymorphic
{
public:
	/**
		Check if trigger enabling/disabling is supported.
		Please note, that for implementations using only triggered acuisition it should return also false.
	*/
	virtual bool IsTriggerSupported() const = 0;

	/**
		Check if specified trigger mode is supported.
		Default mode should be always supported.
		Normal trigger modes are defined in \c icam::ITriggerParams::TriggerMode.
	*/
	virtual bool IsTriggerModeSupported(int triggerMode) const = 0;
};


} // namespace icam


#endif // !icam_ITriggerConstraints_included


