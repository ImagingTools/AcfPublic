/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef itutacf_CInterpolationTestComp_included
#define itutacf_CInterpolationTestComp_included


// ACF includes
#include "imod/TSingleModelObserverBase.h"
#include "icomp/CComponentBase.h"
#include "ibase/TModelObserverCompWrap.h"
#include "i2d/CPolygon.h"


namespace itutacf
{


class CInterpolationTestCompBase:
			public icomp::CComponentBase,
			public imod::TSingleModelObserverBase<i2d::CPolygon>
{
};


/**
	Component for synchronization between some polyline and his interpolated slave.
*/
class CInterpolationTestComp:
			public ibase::TModelObserverCompWrap<CInterpolationTestCompBase>
{
public:
	typedef ibase::TModelObserverCompWrap<CInterpolationTestCompBase> BaseClass;

	I_BEGIN_COMPONENT(CInterpolationTestComp);
		I_ASSIGN(m_slaveObjectCompPtr, "SlaveObject", "Reference data object", true, "SlaveObject");
		I_ASSIGN(m_interpolatedNodesCountAttrPtr, "InterpolatedNodesCount", "Number of interpolated nodes", true, 100);
	I_END_COMPONENT;
	
protected:
	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	I_REF(i2d::CPolygon, m_slaveObjectCompPtr);
	I_ATTR(int, m_interpolatedNodesCountAttrPtr);
};


} // namespace itutacf


#endif // !itutacf_CInterpolationTestComp_included


