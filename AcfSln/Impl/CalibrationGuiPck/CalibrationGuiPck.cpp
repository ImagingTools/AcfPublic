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


#include "CalibrationGuiPck.h"


#include <icomp/export.h>


namespace CalibrationGuiPck
{


I_EXPORT_PACKAGE(
			"AcfSln/Qt/Gui/Calibration",
			"GUI for calibration package",
			IM_PROJECT("ACF-Solutions") IM_TAG("Qt Viewport Calibration") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			NoneCalibrationShape,
			"Displays uncalibrated grid on view console",
			"Uncalibrated None Calibration 2D Grid Shape");

I_EXPORT_COMPONENT(
			AffiniteCalibrationShape,
			"Shows affine calibration grid on calibrated view",
			"Calibration Affine Display Observer 2D Grid Shape");

I_EXPORT_COMPONENT(
			PerspectiveCalibrationShape,
			"Shows perpective calibration grid on calibrated view",
			"Calibration Perspective Display Observer 2D Grid Shape");

I_EXPORT_COMPONENT(
			PerspectiveCalibEditor,
			"Editor of perspective calibration parameters",
			"Perspective Calibration Transformation Matrix Translation" IM_TAG("GUI Editor 2D"));

I_EXPORT_COMPONENT(
			SimpleLensCorrectionEditor,
			"Editor of lens correction parameters",
			"Lens Correction Calibration Transformation Matrix Translation" IM_TAG("GUI Editor 2D"));


} // namespace CalibrationGuiPck


