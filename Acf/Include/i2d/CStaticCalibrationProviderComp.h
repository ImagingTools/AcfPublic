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


#ifndef i2d_CStaticCalibrationProviderComp_included
#define i2d_CStaticCalibrationProviderComp_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "i2d/ICalibration2d.h"
#include "i2d/ICalibrationProvider.h"


namespace i2d
{		


/**
	Implementation of a annulus as a component.
	It gives the possibility to define a annulus segment model via component attributes.
*/
class CStaticCalibrationProviderComp: public icomp::CComponentBase, public ICalibrationProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CStaticCalibrationProviderComp);
		I_REGISTER_INTERFACE(ICalibrationProvider);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN(m_calibrationCompPtr, "Calibration", "Static calibration object", true, "Calibration");
	I_END_COMPONENT;

protected:
	// reimplemented (ICalibrationProvider)
	virtual const ICalibration2d* GetCalibration() const;

private:
	I_REF(ICalibration2d, m_calibrationCompPtr);
};


} // namespace i2d


#endif // !i2d_CStaticCalibrationProviderComp_included


