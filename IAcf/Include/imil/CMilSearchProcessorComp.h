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


#ifndef imil_CMilSearchProcessorComp_included
#define imil_CMilSearchProcessorComp_included


// ACF includes
#include "iimg/IBitmap.h"
#include "iproc/TSyncProcessorCompBase.h"

#include "iipr/IFeaturesConsumer.h"
#include "iipr/IImageToFeatureProcessor.h"

#include "imil/CMilSearchParams.h"
#include "imil/CMilSearchModel.h"
#include "imil/CMilEngine.h"


namespace imil
{


class CMilSearchProcessorComp:
			public iproc::TSyncProcessorCompBase<iipr::IImageToFeatureProcessor>
{
public:
	typedef iproc::TSyncProcessorCompBase<iipr::IImageToFeatureProcessor> BaseClass;

	enum FeatureTypeId
	{
		/**
			Unique ID of caliper fearutes.
		*/
		FTI_MIL_SEARCH_FEATURE = 73731
	};

	I_BEGIN_COMPONENT(CMilSearchProcessorComp)
		I_ASSIGN(m_milParamsIdAttrPtr, "MilParamsId", "ID of MIL-specific parameters", true, "MilParamsId");
		I_ASSIGN(m_aoiParamIdAttrPtr, "AoiParamsId", "ID of rectangle area of interest", true, "AoiParamsId");
	I_END_COMPONENT

	// reimplemented (iipr::IImageToFeatureProcessor)
	virtual int DoExtractFeatures(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& image,
				iipr::IFeaturesConsumer& results);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

protected:
	virtual bool DoModelSearch(
				const CMilSearchParams& params,
				const iimg::IBitmap& bitmap,
				const i2d::CRectangle* aoiPtr,
				iipr::IFeaturesConsumer& result);

private:
	imil::CMilEngine m_engine;

	I_ATTR(istd::CString, m_milParamsIdAttrPtr);
	I_ATTR(istd::CString, m_aoiParamIdAttrPtr);
};


} // namespace iipr


#endif // !imil_CMilSearchProcessorComp_included


