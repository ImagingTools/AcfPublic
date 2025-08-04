/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <i2d/ICalibrationProvider.h>

// ACF-Solutions includes
#include <iinsp/TSupplierCompWrap.h>

// IACF includes
#include <iocv/COcvIntrinsicCameraCalibration.h>
#include <iocv/CLensDistorsionCalibration.h>


namespace iocv
{

class CLensDistorsionCalibrationProviderComp:
			public iinsp::TSupplierCompWrap<CLensDistorsionCalibration>,
			virtual public i2d::ICalibrationProvider
{
public:
	typedef iinsp::TSupplierCompWrap<CLensDistorsionCalibration> BaseClass;

	I_BEGIN_COMPONENT(CLensDistorsionCalibrationProviderComp);
		I_REGISTER_INTERFACE(i2d::ICalibrationProvider);
		I_ASSIGN(m_calibrationCompPtr, "IntrinsicCameraCalibration", "Intrinsic camera calibration", true, "IntrinsicCameraCalibration");
		I_ASSIGN_TO(m_ocvCalibrationCompPtr, m_calibrationCompPtr, true);
	I_END_COMPONENT;

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ICalibration2d* GetCalibration() const override;

protected:
	// reimplemented (iinsp::TSupplierCompWrap)
	virtual WorkStatus ProduceObject(ProductType& result) const override;

private:
	I_REF(i2d::ICalibration2d, m_calibrationCompPtr);
	I_REF(iocv::COcvIntrinsicCameraCalibration, m_ocvCalibrationCompPtr);
};


} // namespace iocv


