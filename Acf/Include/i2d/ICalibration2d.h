/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef i2d_ICalibration2d_included
#define i2d_ICalibration2d_included


// ACF includes
#include "imath/IUnitInfo.h"
#include "i2d/ITransformation2d.h"


namespace i2d
{


class ICalibration2d: virtual public ITransformation2d
{
public:
	/**
		Get unit description of calibration input (transformation function argument).
		\return	unit description of function argument or \c NULL, if this information is unsupported.
	*/
	virtual const imath::IUnitInfo* GetArgumentUnitInfo() const = 0;
	/**
		Get unit description of calibration output (transformation function result).
		\return	unit description of function result or \c NULL, if this information is unsupported.
	*/
	virtual const imath::IUnitInfo* GetResultUnitInfo() const = 0;

	/**
		Create new calibration being combination of this calibration and the second one.
		Please note, that created object is owned by the caller and the caller must remove them.
		\return	new calibration object (owned by the caller) or NULL if creation was impossible.
	*/
	virtual const ICalibration2d* CreateCombinedCalibration(const ICalibration2d& calibration) const = 0;
};


} // namespace i2d


#endif // !i2d_ICalibration2d_included


