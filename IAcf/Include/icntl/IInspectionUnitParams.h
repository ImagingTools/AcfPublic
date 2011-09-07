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


