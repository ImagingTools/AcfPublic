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


#ifndef icntl_IInspectionUnitParams_included
#define icntl_IInspectionUnitParams_included


// ACF includes
#include "istd/INamed.h"
#include "istd/IEnableable.h"
#include "iser/ISerializable.h"

#include "icntl/icntl.h"


namespace icntl
{


/**
	Parameters of single inspection unit.
*/
class IInspectionUnitParams:
			virtual public iser::ISerializable,
			virtual public istd::INamed,
			virtual public istd::IEnableable
{
public:
	/**
		Get offset between light barrier trigger point and trigger position.
	*/
	virtual double GetTriggerOffset() const = 0;
	/**
		Set offset between light barrier trigger point and trigger position.
	*/
	virtual void SetTriggerOffset(double position) = 0;

	/**
		Set object position factor of light barrier trigger.
		If this is 0 object begin is mean, if it is 1 object end.
	*/
	virtual double GetTriggerAlpha() const = 0;
	/**
		Set object position factor of light barrier trigger.
		If this is 0 object begin is mean, if it is 1 object end.
	*/
	virtual void SetTriggerAlpha(double value) = 0;
};


} // namespace icntl


#endif // !icntl_IInspectionUnitParams_included


