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


#ifndef i2d_CLine2dComp_included
#define i2d_CLine2dComp_included


// ACF includes
#include <i2d/TObject2dCompWrap.h>
#include <i2d/CLine2d.h>


namespace i2d
{


/**
	Implementation of a 2D-line as a component.
	It gives the possibility to define a 2D-line model via component attributes.
*/
class CLine2dComp: public TObject2dCompWrap<CLine2d>
{
public:
	typedef TObject2dCompWrap<CLine2d> BaseClass;

	I_BEGIN_COMPONENT(CLine2dComp);
		I_REGISTER_INTERFACE(CLine2d);
		I_ASSIGN(m_x1AttrPtr, "X1", "X-Position of start line point", true, 0);
		I_ASSIGN(m_y1AttrPtr, "Y1", "Y-Position of start line point", true, 0);
		I_ASSIGN(m_x2AttrPtr, "X2", "X-Position of end line point", true, 0);
		I_ASSIGN(m_y2AttrPtr, "Y2", "Y-Position of end line point", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_x1AttrPtr);
	I_ATTR(double, m_y1AttrPtr);
	I_ATTR(double, m_x2AttrPtr);
	I_ATTR(double, m_y2AttrPtr);
};


} // namespace i2d


#endif // !i2d_CLine2dComp_included


