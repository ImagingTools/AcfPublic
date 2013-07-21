/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef i2d_CCircleComp_included
#define i2d_CCircleComp_included


// ACF includes
#include "i2d/TObject2dCompWrap.h"
#include "i2d/CCircle.h"


namespace i2d
{


/**
	Implementation of a circle as a component.
	It gives the possibility to define a circle model via component attributes.
*/
class CCircleComp: public TObject2dCompWrap<CCircle>
{
public:
	typedef TObject2dCompWrap<CCircle> BaseClass;

	I_BEGIN_COMPONENT(CCircleComp);
		I_REGISTER_INTERFACE(CCircle);
		I_REGISTER_INTERFACE(CPosition2d);
		I_ASSIGN(m_centerXAttrPtr, "X", "X-Position of the circle center", true, 0);
		I_ASSIGN(m_centerYAttrPtr, "Y", "Y-Position of the circle center", true, 0);
		I_ASSIGN(m_radiusAttrPtr, "Radius", "Radius of the circle", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_centerXAttrPtr);
	I_ATTR(double, m_centerYAttrPtr);
	I_ATTR(double, m_radiusAttrPtr);
};


} // namespace i2d


#endif // !i2d_CCircleComp_included


