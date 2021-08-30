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
#include <i2d/ICalibration2d.h>
#include <iipr/CImageProcessorCompBase.h>


namespace iocv
{


/**
	Processor used for removing the image distorsions caused by optical system according to the given camera calibration.
*/
class COcvUndistortImageProcessorComp : public iipr::CImageProcessorCompBase
{
public:
	typedef iipr::CImageProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(COcvUndistortImageProcessorComp);
		I_ASSIGN(m_cameraCalibrationParamIdAttrPtr, "CameraCalibrationParamId", "Parameter-ID of the calibration object in parameter set", false, "CameraCalibration");
		I_ASSIGN(m_defaultCameraCalibrationCompPtr, "DefaultCameraCalibration", "Default camera calibration", false, "DefaultCameraCalibration");
	I_END_COMPONENT;

protected:
	// reimplemented (CImageProcessorCompBase)
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage) const override;

private:
	I_REF(i2d::ICalibration2d, m_defaultCameraCalibrationCompPtr);
	I_ATTR(QByteArray, m_cameraCalibrationParamIdAttrPtr);
};


} // namespace iocv



