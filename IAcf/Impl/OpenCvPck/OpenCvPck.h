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


#ifndef OpenCvPck_included
#define OpenCvPck_included


// ACF includes
#include <icomp/TModelCompWrap.h>
#include <icomp/TMakeComponentWrap.h>

// IACF includes
#include <iocv/COcvAcquisitionComp.h>
#include <iocv/COcvVideoControllerComp.h>
#include <iocv/COcvBlobProcessorComp.h>
#include <iocv/CCorrSearchProcessorComp.h>
#include <iocv/COcvMedianProcessorComp.h>
#include <iocv/CHoughBasedSearchProcessorComp.h>
#include <iocv/COcvResamplingProcessorComp.h>
#include <iocv/COcvEdgeExtractorComp.h>
#include <iocv/COcvAdaptiveBinarizationComp.h>
#include <iocv/COcvMorphologicalProcessorComp.h>
#include <iocv/COcvPointGridExtractorComp.h>
#include <iocv/COcvIntrinsicCameraCalibration.h>
#include <iocv/COcvIntrinsicCameraCalibrationSupplierComp.h>
#include <iocv/COcvUndistortImageProcessorComp.h>


/**
	OpenCV-specific package.
*/
namespace OpenCvPck
{


typedef iocv::COcvAcquisitionComp OpenCvAcquisition;
typedef icomp::TModelCompWrap<iocv::COcvVideoControllerComp> OpenCvVideoController;
typedef iocv::COcvBlobProcessorComp OpenCvBlobExtractor;
typedef iocv::CCorrSearchProcessorComp OpenCvCorrSearchProcessor;
typedef iocv::COcvMedianProcessorComp OpenCvMedianProcessor;
typedef iocv::CHoughBasedSearchProcessorComp OpenCvHoughBasedSearchProcessor;
typedef iocv::COcvResamplingProcessorComp OpenCvResamplingProcessor;
typedef iocv::COcvEdgeExtractorComp OpenCvEdgeExtractor;
typedef iocv::COcvAdaptiveBinarizationComp OpenCvAdaptiveBinarization;
typedef iocv::COcvMorphologicalProcessorComp OpenCvMorphologicalProcessor;
typedef iocv::COcvPointGridExtractorComp OpenCvPointGridExtractor;
typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						iocv::COcvIntrinsicCameraCalibration,
						i2d::ICalibration2d,
						iser::ISerializable>> OpenCvIntrinsicCameraCalibration;
typedef icomp::TModelCompWrap<iocv::COcvIntrinsicCameraCalibrationSupplierComp> OpenCvIntrinsicCameraCalibrationSupplier;
typedef iocv::COcvUndistortImageProcessorComp OpenCvUndistortImageProcessor;


} // namespace OpenCvPck


#endif // !OpenCvPck_included


