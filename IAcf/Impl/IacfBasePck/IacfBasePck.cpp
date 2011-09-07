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


#include "icomp/export.h"

#include "IacfBasePck.h"


namespace IacfBasePck
{


I_EXPORT_DEFAULT_SERVICES

I_EXPORT_PACKAGE(
			"IacfBase",
			"General, system-independent image processing package",
			"Standard Base Imaging Tools" IM_PROJECT("IACF") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));


I_EXPORT_COMPONENT(
			ExposureParams,
			"Parameters for exposure parameter control",
			"Exposure Shutter Delay Time EEN Image Bitmap Acquisition Snap Parameters");

I_EXPORT_COMPONENT(
			SnapBitmapSupplier,
			"Implementation of bitmap supplier getting image from camera",
			"Image Bitmap Acquisition Snap Supplier Parameters");

I_EXPORT_COMPONENT(
			MemoryAcquisition,
			"Image acquisition from the image itself",
			"Image Bitmap Camera Snap Acquisition");

I_EXPORT_COMPONENT(
			AcquisitionConstraints,
			"Static acquisition constraints for some device",
			"Image Bitmap Camera Snap Acquisition Constraints");

I_EXPORT_COMPONENT(
			SamplingParams,
			"Sampling params based on fixed boundary values",
			"Sample Sampling Acquisition Model Parameters");

I_EXPORT_COMPONENT(
			TriggerParams,
			"Trigger params for cameras",
			"Camera Acquisition Trigger Parameters Snap");

I_EXPORT_COMPONENT(
			InspectionTask,
			"Group set of suppliers into single inspection task",
			"Task Model Supplier Product Process Cascade" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model"));

I_EXPORT_COMPONENT(
			Inspection,
			"Group set of inspection tasks into single one",
			"Task Model Supplier Product Composite Cascade" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model"));


} // namespace IacfBasePck


