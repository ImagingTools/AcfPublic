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


#ifndef IprPck_included
#define IprPck_included


// ACF includes
#include "imod/TModelWrap.h"
#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "iipr/CRectImageSmoothProcessorComp.h"
#include "iipr/CProcessedAcquisitionComp.h"
#include "iipr/TUnaryTransformProcessorComp.h"
#include "iipr/CCaliperParamsComp.h"
#include "iipr/CExtremumCaliperProcessorComp.h"
#include "iipr/CLineProjectionProcessorComp.h"
#include "iipr/CCircleFindProcessorComp.h"
#include "iipr/CDelegatedBitmapSupplierComp.h"
#include "iipr/CProcessedBitmapSupplierComp.h"
#include "iipr/CPositionFromImageSupplierComp.h"
#include "iipr/CRectDerivativeProcessorComp.h"
#include "iipr/CFeaturesContainer.h"
#include "iipr/CSingleFeatureConsumer.h"
#include "iipr/CFeatureToImageMapperProcessorComp.h"
#include "iipr/CSearchBasedFeaturesSupplierComp.h"
#include "iipr/CLineProjectionSupplierComp.h"
#include "iipr/CImageHistogramProcessorComp.h"
#include "iipr/CCircleFinderParamsComp.h"
#include "iipr/CImagePolarTransformProcessorComp.h"
#include "iipr/CImageCropProcessorComp.h"
#include "iipr/CImageInterpolationParams.h"
#include "iipr/CRingPatternGeneratorComp.h"
#include "iipr/CRingPatternGeneratorParamsComp.h"


/**
	System-undependent image processing package.
*/
namespace IprPck
{


typedef iipr::CProcessedAcquisitionComp ProcessedCamera;
typedef iipr::CRectImageSmoothProcessorComp RectImageSmoothProcessor;
typedef iipr::CInvertOperatorComp InvertOperator;
typedef icomp::TModelCompWrap<iipr::CCaliperParamsComp> CaliperParams;
typedef icomp::TModelCompWrap<iipr::CCircleFinderParamsComp> CircleFinderParams;
typedef iipr::CExtremumCaliperProcessorComp ExtremumCaliperProcessor;
typedef iipr::CLineProjectionProcessorComp LineProjectionProcessor;
typedef iipr::CCircleFindProcessorComp CircleFindProcessor;
typedef icomp::TMakeComponentWrap<
			imod::TModelWrap<iipr::CFeaturesContainer>,
			iipr::IFeaturesConsumer,
			iipr::IFeaturesContainer,
			iser::ISerializable,
			istd::IChangeable,
			imod::IModel> FeaturesContainer;
typedef iipr::CFeatureToImageMapperProcessorComp FeatureToImageMapperProcessor;
typedef icomp::TModelCompWrap<iipr::CDelegatedBitmapSupplierComp> DelegatedBitmapSupplier;
typedef icomp::TModelCompWrap<iipr::CProcessedBitmapSupplierComp> ProcessedBitmapSupplier;
typedef icomp::TModelCompWrap<iipr::CPositionFromImageSupplierComp> PositionFromImageSupplier;
typedef icomp::TModelCompWrap<iipr::CSearchBasedFeaturesSupplierComp> SearchBasedFeaturesSupplier;
typedef icomp::TModelCompWrap<iipr::CLineProjectionSupplierComp> ProjectionSupplier;

typedef iipr::CRectDerivativeProcessorComp RectDerivativeProcessor;
typedef iipr::CImageHistogramProcessorComp ImageHistogramProcessor;
typedef iipr::CImagePolarTransformProcessorComp ImagePolarTransformProcessor;
typedef iipr::CImageCropProcessorComp ImageCropProcessor;
typedef iipr::CRingPatternGeneratorComp RingPatternGenerator;

typedef icomp::TMakeComponentWrap<
			imod::TModelWrap<iipr::CImageInterpolationParams>,
			iipr::IImageInterpolationParams,
			iser::ISerializable,
			istd::IChangeable,
			imod::IModel> ImageInterpolationParams;

typedef icomp::TModelCompWrap<iipr::CRingPatternGeneratorParamsComp> RingPatternGeneratorParams;


} // namespace IprPck


#endif // !IprPck_included


