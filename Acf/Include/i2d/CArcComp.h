/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef i2d_CArcComp_included
#define i2d_CArcComp_included


// ACF includes
#include "i2d/TObject2dCompWrap.h"
#include "i2d/CArc.h"


namespace i2d
{


/**
	Implementation of a arc as a component.
	It gives the possibility to define a arc model via component attributes.
*/
class CArcComp: public TObject2dCompWrap<CArc>
{
public:
	typedef TObject2dCompWrap<CArc> BaseClass;

	I_BEGIN_COMPONENT(CArcComp);
		I_REGISTER_INTERFACE(CArc);
		I_REGISTER_INTERFACE(CCircle);
		I_REGISTER_INTERFACE(CPosition2d);
		I_ASSIGN(m_centerXAttrPtr, "X", "X-Position of the arc center", true, 0);
		I_ASSIGN(m_centerYAttrPtr, "Y", "Y-Position of the arc center", true, 0);
		I_ASSIGN(m_radiusAttrPtr, "Radius", "Radius of the arc", true, 0);
		I_ASSIGN(m_startAngleAttrPtr, "StartAngle", "Start angle of the arc", true, 0);
		I_ASSIGN(m_endAngleAttrPtr, "EndAngle", "End angle of the arc", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_centerXAttrPtr);
	I_ATTR(double, m_centerYAttrPtr);
	I_ATTR(double, m_radiusAttrPtr);
	I_ATTR(double, m_startAngleAttrPtr);
	I_ATTR(double, m_endAngleAttrPtr);
};


} // namespace i2d


#endif // !i2d_CArcComp_included


