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


#ifndef icntl_IObjectInspection_included
#define icntl_IObjectInspection_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "isys/ITimer.h"


namespace icntl
{


/**
	Represent single inspection session for one unit and one object.
*/
class IObjectInspection: virtual public istd::IPolymorphic
{
public:
	/**
		Get object ID identifying physical object.
		This ID is identical for all inspections of the same physical object.
	*/
	virtual I_DWORD GetObjectId() const = 0;
	/**
		Get timestamp of this inspection.
		Typically camera trigger timestamp is taken.
	*/
	virtual const isys::ITimer& GetTimestamp() const = 0;
	/**
		Set ejector should be used for this object.
	*/
	virtual bool SetEjector(int ejectorIndex) = 0;
};


} // namespace icntl


#endif // !icntl_IObjectInspection_included


