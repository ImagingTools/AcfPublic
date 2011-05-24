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


#ifndef icntl_IInspectionUnitController_included
#define icntl_IInspectionUnitController_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "isys/ITimer.h"

#include "icntl/icntl.h"


namespace icntl
{


class IObjectInspection;


/**
	Parameters of single inspection unit.
*/
class IInspectionUnitController: virtual public istd::IPolymorphic
{
public:
	/**
		Get next inspection object and remove it from waiting to inspection queue.
		\return	inspection object or NULL, if no object is waiting for inspection.
				Please note, that returned instance is owned by caller.
	*/
	virtual IObjectInspection* PopObjectInspection() = 0;
	/**
		Do camera trigger for this inspection unit.
		\return	pointer to timer object representing time point of trigger or NULL if trigger was impossible.
				Please note, that returned instance is owned by caller.
	*/
	virtual isys::ITimer* DoCameraTrigger() = 0;
};


} // namespace icntl


#endif // !icntl_IInspectionUnitController_included


