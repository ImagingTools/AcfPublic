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


#ifndef iipr_CFeatureToImageMapperProcessorComp_included
#define iipr_CFeatureToImageMapperProcessorComp_included


// ACF includes
#include "i2d/CPosition2d.h"
#include "icomp/CComponentBase.h"
#include "iproc/TSyncProcessorWrap.h"

#include "iipr/IFeatureToFeatureProcessor.h"
#include "iipr/IFeatureToImageMapper.h"
#include "iipr/TFeatureWrap.h"


namespace iipr
{


/**
	Processor converting feature container into set of positions using image position mapper.
	It can be used to achive set of image positions from set of caliper results.
*/
class CFeatureToImageMapperProcessorComp:
			public icomp::CComponentBase,
			public iproc::TSyncProcessorWrap<IFeatureToFeatureProcessor>
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CFeatureToImageMapperProcessorComp);
		I_REGISTER_INTERFACE(IFeatureToFeatureProcessor);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_ASSIGN(m_featuresMapperCompPtr, "FeaturesMapper", "Calculate position from caliper extracted features", true, "FeaturesMapper");
		I_ASSIGN(m_ignoreNotMappableAttrPtr, "IgnoreNonMappable", "Enable ignoring of non-mappable features, if it is false and some feature cannot be mapped, error occures", true, false);
	I_END_COMPONENT;

	// reimplemented (iipr::IFeatureToFeatureProcessor)
	virtual int DoConvertFeatures(
				const iprm::IParamsSet* paramsPtr,
				const IFeaturesContainer& container,
				IFeaturesConsumer& results);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

protected:
	typedef TFeatureWrap<i2d::CPosition2d> PositionFeature;

private:
	I_REF(iipr::IFeatureToImageMapper, m_featuresMapperCompPtr);
	I_ATTR(bool, m_ignoreNotMappableAttrPtr);
};


} // namespace iipr


#endif // !iipr_CFeatureToImageMapperProcessorComp_included


