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


#ifndef iipr_CLocalDifferenceProcessorComp_included
#define iipr_CLocalDifferenceProcessorComp_included


// ACF includes
#include "istd/CString.h"
#include "iprm/ILinearAdjustParams.h"

#include "iipr/IMultidimensionalFilterParams.h"
#include "iipr/CImageProcessorCompBase.h"


namespace iipr
{
	

/**
	Implementation of horizontal differential operator.
*/
class CLocalDifferenceProcessorComp:
			public CImageProcessorCompBase
{
public:
	typedef CImageProcessorCompBase BaseClass;

	I_BEGIN_BASE_COMPONENT(CLocalDifferenceProcessorComp)
		I_ASSIGN(m_adjustParamsIdAttrPtr, "AdjustParamsId", "ID of parameters for contrast and brightness in parameter set", false, "AdjustParamsId");
		I_ASSIGN(m_filterParamIdAttrPtr, "FilterParamId", "ID of parameter for filter length in parameter set", false, "FilterParamId");
		I_ASSIGN(m_defaultAdjustParamsCompPtr, "DefaultAdjustParams", "Default adjust parameters, if no parameters are specified", false, "DefaultAdjustParams");
		I_ASSIGN(m_defaultFilterParamCompPtr, "DefaultFilterParam", "Default parameter for filter length, if no parameters are specified", false, "DefaultFilterParam");
	I_END_COMPONENT

protected:
	// reimplemented (iipr::CImageProcessorCompBase)
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);

private:
	I_ATTR(istd::CString, m_adjustParamsIdAttrPtr);
	I_ATTR(istd::CString, m_filterParamIdAttrPtr);
	I_REF(iprm::ILinearAdjustParams, m_defaultAdjustParamsCompPtr);
	I_REF(IMultidimensionalFilterParams, m_defaultFilterParamCompPtr);
};


} // namespace iipr


#endif // !iipr_CLocalDifferenceProcessorComp_included

