/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef i2d_CTubePolylineComp_included
#define i2d_CTubePolylineComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "i2d/CTubePolyline.h"


namespace i2d
{


/**
	Component definition of the tube region based on a polyline.
*/
class CTubePolylineComp:
			public icomp::CComponentBase,
			public CTubePolyline
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CTubePolyline BaseClass2;

	I_BEGIN_COMPONENT(CTubePolylineComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(IObject2d);
		I_ASSIGN(m_minTubeRangeValueAttrPtr, "DefaultLeftTubeRange", "Default left tube range value", false, -10);
		I_ASSIGN(m_maxTubeRangeValueAttrPtr, "DefaultRightTubeRange", "Default right tube range value", false, 10);
	I_END_COMPONENT;

    // reimplemented (i2d::CPolygon)
	virtual bool InsertNode(const i2d::CVector2d& node);
	virtual bool InsertNode(int index, const i2d::CVector2d& node);

protected:
    // reimplemented (i2d::CPolygon)
	virtual void SetNodesCount(int count);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_minTubeRangeValueAttrPtr);
	I_ATTR(double, m_maxTubeRangeValueAttrPtr);

	istd::CRange m_defaultTubeRange;
};


} // namespace i2d


#endif // !i2d_CTubePolylineComp_included


