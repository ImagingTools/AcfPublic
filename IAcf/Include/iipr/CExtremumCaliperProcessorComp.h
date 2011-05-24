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


#ifndef iipr_CExtremumCaliperProcessorComp_included
#define iipr_CExtremumCaliperProcessorComp_included


// ACF includes
#include "istd/CString.h"
#include "icomp/CComponentBase.h"
#include "iproc/TSyncProcessorWrap.h"

#include "iipr/ICaliperProcessor.h"
#include "iipr/IFeatureToProjectionMapper.h"


namespace iipr
{


class CExtremumCaliperProcessorComp:
			public icomp::CComponentBase,
			public iproc::TSyncProcessorWrap<ICaliperProcessor>,
			virtual public IFeatureToProjectionMapper
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef iproc::TSyncProcessorWrap<ICaliperProcessor> BaseClass2;

	I_BEGIN_COMPONENT(CExtremumCaliperProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_REGISTER_INTERFACE(ICaliperProcessor);
		I_REGISTER_INTERFACE(IFeatureToProjectionMapper);
		I_ASSIGN(m_caliperParamsIdAttrPtr, "CaliperParamsId", "ID of caliper parameters in parameter set", true, "CaliperParams");
	I_END_COMPONENT;

	// reimplemented (iipr::ICaliperProcessor)
	virtual bool DoCaliper(
				const imeas::IDataSequence& derivative,
				const ICaliperParams* paramsPtr,
				IFeaturesConsumer& results);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (iipr::IFeatureToProjectionMapper)
	virtual bool GetProjectionPosition(
				const IFeature& feature,
				const iprm::IParamsSet* paramsPtr,
				double& result) const;

private:
	I_ATTR(istd::CString, m_caliperParamsIdAttrPtr);
};


} // namespace iipr


#endif // !iipr_CExtremumCaliperProcessorComp_included


