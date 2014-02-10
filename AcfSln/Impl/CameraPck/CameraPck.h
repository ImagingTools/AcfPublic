/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#ifndef IacfBasePck_included
#define IacfBasePck_included


// ACF includes
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "icam/CExposureParamsComp.h"
#include "icam/CSnapBitmapSupplierComp.h"
#include "icam/CMemoryAcquisitionComp.h"
#include "icam/CAcquisitionConstraintsComp.h"
#include "icam/CSelectionParamCameraComp.h"
#include "icam/CCameraDelegatorComp.h"
#include "icam/CMultiCameraBitmapSupplierComp.h"
#include "icam/CSelectableBitmapSupplierComp.h"
#include "icam/CMultiLayerBitmapSupplierComp.h"


/**
	Base system-independent general package.
*/
namespace CameraPck
{


typedef icomp::TModelCompWrap<icam::CExposureParamsComp> ExposureParams;
typedef icomp::TModelCompWrap<icam::CSnapBitmapSupplierComp> SnapBitmapSupplier;
typedef icam::CMemoryAcquisitionComp MemoryAcquisition;
typedef icam::CAcquisitionConstraintsComp AcquisitionConstraints;
typedef icam::CSelectionParamCameraComp SelectionParamCamera;
typedef icam::CCameraDelegatorComp CameraDelegator;
typedef icomp::TModelCompWrap<icam::CMultiCameraBitmapSupplierComp> MultiCameraBitmapSupplier;
typedef icomp::TModelCompWrap<icam::CSelectableBitmapSupplierComp> SelectableBitmapSupplier;
typedef icomp::TModelCompWrap<icam::CMultiLayerBitmapSupplierComp> MultiLayerBitmapSupplier;


} // namespace CameraPck


#endif // !IacfBasePck_included


