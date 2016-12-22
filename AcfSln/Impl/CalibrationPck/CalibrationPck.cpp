/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#include "CalibrationPck.h"


#include <icomp/export.h>


namespace CalibrationPck
{


I_EXPORT_PACKAGE(
			"AcfSln/Calibration",
			"Calibration related package",
			IM_PROJECT("ACF-Solutions") IM_TAG("Calibration") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			AffineCalibration2d,
			"Affine calibration",
			"Affine Calibration Tranformation" IM_CATEGORY(I_DATA_MODEL) IM_TAG("2D Model"));

I_EXPORT_COMPONENT(
			PerspectiveCalibration2d,
			"Perspectivic calibration",
			"Perspective Calibration Tranformation" IM_CATEGORY(I_DATA_MODEL) IM_TAG("2D Model"));

I_EXPORT_COMPONENT(
			SimpleLensCorrection,
			"Lens correction calibration based on single distortion factor",
			"Lens Correction Distortion Calibration Tranformation" IM_CATEGORY(I_DATA_MODEL) IM_TAG("2D Model"));

I_EXPORT_COMPONENT(
			StaticCalibrationProvider,
			"Provider of a static calibration object",
			"2D Tranformation Calibration" IM_CATEGORY(I_DATA_MODEL) IM_TAG("2D"));

I_EXPORT_COMPONENT(
			Calibration2dProxy,
			"Proxy of a 2D calibration using calibration provider",
			"2D Tranformation Calibration Proxy Provider" IM_CATEGORY(I_DATA_MODEL) IM_TAG("2D"));


} // namespace CalibrationPck


