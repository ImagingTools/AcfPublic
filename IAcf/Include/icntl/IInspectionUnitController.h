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


