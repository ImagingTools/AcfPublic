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


#ifndef QtCameraPck_included
#define QtCameraPck_included


#include "iqtcam/CFileAcquisitionComp.h"
#include "iqtcam/CSnapImageGuiComp.h"
#include "iqtcam/CExposureParamsGuiComp.h"
#include "iqtcam/CBitmapSupplierGuiComp.h"
#include "iqtcam/CMultiBitmapSupplierGuiComp.h"
#include "iqtcam/CScaleCalibrationEditorComp.h"
#include "iqtcam/CCameraInfoGuiComp.h"


/**
	Qt camera package.
*/
namespace QtCameraPck
{


typedef iqtcam::CFileAcquisitionComp FileAcquisition;
typedef iqtcam::CSnapImageGuiComp SnapImageGui;
typedef iqtcam::CExposureParamsGuiComp ExposureParamsGui;
typedef iqtcam::CBitmapSupplierGuiComp SnapBitmapSupplierGui;
typedef iqtcam::CMultiBitmapSupplierGuiComp SnapMultiBitmapSupplierGui;
typedef iqtcam::CScaleCalibrationEditorComp ScaleCalibrationEditor;
typedef iqtcam::CCameraInfoGuiComp CameraInfoGui;


} // namespace QtCameraPck


#endif // !QtCameraPck_included


