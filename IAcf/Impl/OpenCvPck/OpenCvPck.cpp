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


#include "OpenCvPck.h"


#include <icomp/export.h>


namespace OpenCvPck
{


I_EXPORT_PACKAGE(
			"Iacf/OpenCv",
			"OpenCV integration",
			"OpenCV" IM_PROJECT("IACF") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			OpenCvAcquisition,
			"Implementation of camera interface using OpenCV API",
			"Camera Acquisition Bitmap Image" IM_TAG("Camera"));

I_EXPORT_COMPONENT(
			OpenCvVideoController,
			"OpenCV-based video controller",
			"Video Multimedia Controller" IM_TAG("Multimedia"));

I_EXPORT_COMPONENT(
			OpenCvBlobExtractor,
			"OpenCV-based blob extraction",
			"Blob Search Object");

I_EXPORT_COMPONENT(
			OpenCvCorrSearchProcessor,
			"OpenCV-based normalized correlation search processor",
			"Normalized Correlation Search Processor Model Image Find Pattern Matching");

I_EXPORT_COMPONENT(
			OpenCvMedianProcessor,
			"OpenCV-based median blur processor",
			"Median Blue Smoothing Processor");

I_EXPORT_COMPONENT(
			OpenCvHoughBasedSearchProcessor,
			"OpenCV-based search processor based on hough transformation",
			"Search Circle Line Processor Feature Hough");

I_EXPORT_COMPONENT(
			OpenCvResamplingProcessor,
			"OpenCV-based resampling processor",
			"Size Resampling Interpolation Processor Transformation");

I_EXPORT_COMPONENT(
			OpenCvEdgeExtractor,
			"OpenCV-based edge extractor",
			"Edge Contour Extractor Object Model");

I_EXPORT_COMPONENT(
			OpenCvAdaptiveBinarization,
			"OpenCV-based adaptive binaraization",
			"Threshold Binarization Segmentation");

I_EXPORT_COMPONENT(
			OpenCvMorphologicalProcessor, 
			"Morphological processor based on OpenCV",
			"Morphology Filter");


} // namespace OpenCvPck


