/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef i2d_IMultiCalibrationProvider_included
#define i2d_IMultiCalibrationProvider_included


// ACF includes
#include <istd/IChangeable.h>
#include <i2d/ICalibration2d.h>
#include <iprm/IOptionsList.h>


namespace i2d
{


/**
	Common interface for an object, which delivers a list of 2D-calibration objects.
*/
class IMultiCalibrationProvider: virtual public istd::IChangeable
{
public:
	/**
		Get optional information about calibration objects in form of section contraints.
		It allows to get name and description of each calibration object.
	*/
	virtual const iprm::IOptionsList* GetCalibrationSelectionContraints() const = 0;

	/**
		Get number of available calibrations.
	*/
	virtual int GetCalibrationsCount() const = 0;

	/**
		Get access to transformation object with a given index, which transforms a local logical coordinate system to global one.
		\return		Pointer to transformation if it is accessible, or NULL.
	*/
	virtual const ICalibration2d* GetCalibration(int calibrationIndex) const = 0;
};


} // namespace i2d


#endif // !i2d_IMultiCalibrationProvider_included


