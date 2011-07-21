/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef i2d_CQuadrangleComp_included
#define i2d_CQuadrangleComp_included


#include "i2d/CQuadrangle.h"

#include "icomp/CComponentBase.h"


namespace i2d
{		


/**
	Implementation of a quadrangle as a component.
	It gives the possibility to define a quadrangle model via component attributes.
*/
class CQuadrangleComp: public icomp::CComponentBase, public i2d::CQuadrangle
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CQuadrangleComp);
		I_REGISTER_INTERFACE(IObject2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_diag1X1AttrPtr, "Diag1X1", "X-Position of start line point of the first diagonal", true, 0);
		I_ASSIGN(m_diag1Y1AttrPtr, "Diag1Y1", "Y-Position of start line point of the first diagonal", true, 0);
		I_ASSIGN(m_diag1X2AttrPtr, "Diag1X2", "X-Position of end line point of the first diagonal", true, 0);
		I_ASSIGN(m_diag1Y2AttrPtr, "Diag1Y2", "Y-Position of end line point of the first diagonal", true, 0);
		I_ASSIGN(m_diag2X1AttrPtr, "Diag2X1", "X-Position of start line point of the second diagonal", true, 0);
		I_ASSIGN(m_diag2Y1AttrPtr, "Diag2Y1", "Y-Position of start line point of the second diagonal", true, 0);
		I_ASSIGN(m_diag2X2AttrPtr, "Diag2X2", "X-Position of end line point of the second diagonal", true, 0);
		I_ASSIGN(m_diag2Y2AttrPtr, "Diag2Y2", "Y-Position of end line point of the second diagonal", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_diag1X1AttrPtr);
	I_ATTR(double, m_diag1Y1AttrPtr);
	I_ATTR(double, m_diag1X2AttrPtr);
	I_ATTR(double, m_diag1Y2AttrPtr);
	I_ATTR(double, m_diag2X1AttrPtr);
	I_ATTR(double, m_diag2Y1AttrPtr);
	I_ATTR(double, m_diag2X2AttrPtr);
	I_ATTR(double, m_diag2Y2AttrPtr);
};


} // namespace i2d


#endif // !i2d_CQuadrangleComp_included


