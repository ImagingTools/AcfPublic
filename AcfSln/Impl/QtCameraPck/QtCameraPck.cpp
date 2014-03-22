/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "QtCameraPck.h"


#include "icomp/export.h"


namespace QtCameraPck
{


I_EXPORT_PACKAGE(
			"AcfSln/QtCamera",
			"Qt camera package",
			"Qt Camera GUI" IM_PROJECT("ACF-Solutions") IM_TAG("\"Image Processing\" Camera") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			FileAcquisition,
			"Acquise bitmap from file, load and save bitmaps in binary format as file loader",
			"Image Bitmap Acquisition Binary Loader Load Save JPG JPEG PNG BMP");

I_EXPORT_COMPONENT(
			SnapImageGui,
			"Show snapped image and allow to change snap parameters",
			"View Image Bitmap Camera Snap Parameters");

I_EXPORT_COMPONENT(
			ExposureParamsGui,
			"Gui for exposure parameters",
			"Image Bitmap Camera Snap Acquisition Exposure Parameters");

I_EXPORT_COMPONENT(
			SnapBitmapSupplierGui,
			"Gui getting image from camera and connecting it to display console", 
			"Image Bitmap Camera Snap Acquisition Supplier Parameters");

I_EXPORT_COMPONENT(
			SnapMultiBitmapSupplierGui,
			"Gui getting a set of images from camera and connecting one of them to display console", 
			"Multi Image Bitmap Camera Snap Acquisition Supplier Parameters GUI Qt");

I_EXPORT_COMPONENT(
			ScaleCalibrationEditor,
			"Editor for scale calibration parameters",
			"Scale Calibration Numeric Values Filter Ranges Parameter Editor");

I_EXPORT_COMPONENT(
			CameraInfoGui,
			"Gui showing selected camera information",
			"GUI Camera Information");

} // namespace QtCameraPck
