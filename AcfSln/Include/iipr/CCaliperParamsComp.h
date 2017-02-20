/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iipr_CCaliperParamsComp_included
#define iipr_CCaliperParamsComp_included


#include <icomp/CComponentBase.h>

#include <iipr/CCaliperParams.h>


namespace iipr
{


class CCaliperParamsComp: public icomp::CComponentBase, public CCaliperParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CCaliperParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(ICaliperParams);
		I_ASSIGN(m_weightThresholdAttrPtr, "WeightThreshold", "Threshold of edge strength in range (0, 1)", true, 0.1);
		I_ASSIGN(m_polarityModeAttrPtr, "PolarityMode", "Mode of polarity, 0 - reised, 1 - dropped, 2 - any", true, PM_ALL);
		I_ASSIGN(m_directionModeAttrPtr, "DirectionMode", "Mode of direction, 0 - forward, 1 - backwards", true, DM_FORWARD);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_weightThresholdAttrPtr);
	I_ATTR(int, m_polarityModeAttrPtr);
	I_ATTR(int, m_directionModeAttrPtr);
};


} // namespace iipr


#endif // !iipr_CCaliperParamsComp_included


