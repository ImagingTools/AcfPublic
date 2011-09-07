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


