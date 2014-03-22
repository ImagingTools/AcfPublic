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


#ifndef i2d_CRectangleComp_included
#define i2d_CRectangleComp_included


// ACF includes
#include "i2d/TObject2dCompWrap.h"
#include "i2d/CRectangle.h"


namespace i2d
{


/**
	Implementation of a rectangle as a component.
	It gives the possibility to define a rectangle model via component attributes.
*/
class CRectangleComp: public TObject2dCompWrap<CRectangle>
{
public:
	typedef TObject2dCompWrap<CRectangle> BaseClass;

	I_BEGIN_COMPONENT(CRectangleComp);
		I_REGISTER_INTERFACE(CRectangle);
		I_REGISTER_INTERFACE(IObject2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_leftAttrPtr, "X", "X-Position of the rectangle", true, 0);
		I_ASSIGN(m_topAttrPtr, "Y", "Y-Position of the rectangle", true, 0);
		I_ASSIGN(m_widthAttrPtr, "Width", "Width of the rectangle", true, 0);
		I_ASSIGN(m_heightAttrPtr, "Height", "Height of the rectangle", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(double, m_leftAttrPtr);
	I_ATTR(double, m_topAttrPtr);
	I_ATTR(double, m_widthAttrPtr);
	I_ATTR(double, m_heightAttrPtr);
};


} // namespace i2d


#endif // !i2d_CRectangleComp_included


