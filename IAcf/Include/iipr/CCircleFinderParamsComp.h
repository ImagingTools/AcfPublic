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


#ifndef iipr_CCircleFinderParamsComp_included
#define iipr_CCircleFinderParamsComp_included


#include "icomp/CComponentBase.h"

#include "iipr/CCircleFinderParams.h"


namespace iipr
{


class CCircleFinderParamsComp: public icomp::CComponentBase, public iipr::CCircleFinderParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CCircleFinderParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(iipr::ICircleFinderParams);
		I_ASSIGN(m_isOutlierEliminationEnabledAttrPtr, "OutlierEliminationEnabled", "Enable outliers elimination", false, false);
		I_ASSIGN(m_minOutlierDistanceAttrPtr, "MinOutlierDistance", "Minimal outliers distance in pixel", false, 5.0);
		I_ASSIGN(m_raysCountAttrPtr, "RaysCount", "Maximal number of projection rays, -1 for automatic calculation", false, -1);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(bool, m_isOutlierEliminationEnabledAttrPtr);
	I_ATTR(double, m_minOutlierDistanceAttrPtr);
	I_ATTR(int, m_raysCountAttrPtr);
};


} // namespace iipr


#endif // !iipr_CCircleFinderParamsComp_included


