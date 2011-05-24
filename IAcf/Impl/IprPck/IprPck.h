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

#include "iipr/TMorphoProcessorComp.h"
#include "iipr/CRectImageSmoothProcessorComp.h"
#include "iipr/CMultidimensionalFilterParamsComp.h"
#include "iipr/CProcessedAcquisitionComp.h"
#include "iipr/CLocalDifferenceProcessorComp.h"
#include "iipr/TUnaryTransformProcessorComp.h"
#include "iipr/TGaussianProcessorComp.h"
#include "iipr/CGaussian2dFilterParams.h"
#include "iipr/CCaliperParamsComp.h"
#include "iipr/CExtremumCaliperProcessorComp.h"
#include "iipr/CLineProjectionProcessorComp.h"
#include "iipr/CCircleFindProcessorComp.h"
#include "iipr/CPositionFromImageSupplierComp.h"
#include "iipr/CRectDerivativeProcessorComp.h"
#include "iipr/CFeaturesContainer.h"
#include "iipr/CSingleFeatureConsumer.h"
#include "iipr/CFeatureToImageMapperProcessorComp.h"
#include "iipr/CSearchBasedFeaturesSupplierComp.h"
#include "iipr/CLineProjectionSupplierComp.h"
#include "iipr/CImageHistogramProcessorComp.h"
#include "iipr/CCircleFinderParamsComp.h"


/**
	system-undependent image processing package.
*/
namespace IprPck
{


typedef iipr::CProcessedAcquisitionComp ProcessedCamera;
typedef iipr::CRectImageSmoothProcessorComp RectImageSmoothProcessor;
typedef icomp::TModelCompWrap<iipr::CMultidimensionalFilterParamsComp> MultidimensionalFilterParams;
typedef iipr::CLocalDifferenceProcessorComp LocalDifferenceProcessor;	
typedef iipr::CMorphoMaxOperatorComp MorphoMaxOperator;
typedef iipr::CMorphoMinOperatorComp MorphoMinOperator;
typedef iipr::CInvertOperatorComp InvertOperator;
typedef iipr::CGaussianFilterComp GaussianFilter;
typedef icomp::TMakeComponentWrap<imod::TModelWrap<iipr::CGaussian2dFilterParams>, iser::ISerializable> GaussianFilterParams;
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
typedef icomp::TModelCompWrap<iipr::CPositionFromImageSupplierComp> PositionFromImageSupplier;
typedef icomp::TModelCompWrap<iipr::CSearchBasedFeaturesSupplierComp> SearchBasedFeaturesSupplier;
typedef icomp::TModelCompWrap<iipr::CLineProjectionSupplierComp> ProjectionSupplier;

typedef iipr::CRectDerivativeProcessorComp RectDerivativeProcessor;
typedef iipr::CImageHistogramProcessorComp ImageHistogramProcessor;


} // namespace IprPck


#endif // !IprPck_included


