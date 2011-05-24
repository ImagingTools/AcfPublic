/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef QtCamPck_included
#define QtCamPck_included


#include "iqtcam/CFileAcquisitionComp.h"
#include "iqtcam/CSnapImageGuiComp.h"
#include "iqtcam/CExposureParamsGuiComp.h"
#include "iqtcam/CBitmapSupplierGuiComp.h"


/**
	Qt camera package.
*/
namespace QtCamPck
{


typedef iqtcam::CFileAcquisitionComp FileAcquisition;
typedef iqtcam::CSnapImageGuiComp SnapImageGui;
typedef iqtcam::CExposureParamsGuiComp ExposureParamsGui;
typedef iqtcam::CBitmapSupplierGuiComp SnapBitmapSupplierGui;


} // namespace QtCamPck


#endif // !QtCamPck_included


