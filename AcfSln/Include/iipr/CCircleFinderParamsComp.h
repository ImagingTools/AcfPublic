/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
		I_ASSIGN(m_distanceUnitInfoCompPtr, "DistanceUnitInfo", "Provide information about distance units", false, "DistanceUnitInfo");
		I_ASSIGN(m_isOutlierEliminationEnabledAttrPtr, "OutlierEliminationEnabled", "Enable outliers elimination", false, false);
		I_ASSIGN(m_minOutlierDistanceAttrPtr, "MinOutlierDistance", "Minimal outliers distance in pixel", false, 5.0);
		I_ASSIGN(m_raysCountAttrPtr, "RaysCount", "Maximal number of projection rays, -1 for automatic calculation", false, -1);
		I_ASSIGN(m_caliperModeAttrPtr, "CaliperMode", "Mode of caliper\n\t0 - first candidate\n\t1 - best candidate", true, 0);
	I_END_COMPONENT;

	// reimplemented (iipr::ICircleFinderParams)
	virtual const imath::IUnitInfo* GetDistanceUnitInfo() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(imath::IUnitInfo, m_distanceUnitInfoCompPtr);
	I_ATTR(bool, m_isOutlierEliminationEnabledAttrPtr);
	I_ATTR(double, m_minOutlierDistanceAttrPtr);
	I_ATTR(int, m_raysCountAttrPtr);
	I_ATTR(int, m_caliperModeAttrPtr);
};


} // namespace iipr


#endif // !iipr_CCircleFinderParamsComp_included


