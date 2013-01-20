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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef i2d_CPolygonComp_included
#define i2d_CPolygonComp_included


// ACF includes
#include "i2d/TObject2dCompWrap.h"
#include "i2d/CPolygon.h"


namespace i2d
{


/**
	Implementation of a polygon as a component.
	It gives the possibility to define a polygonal model via component attributes.
*/
class CPolygonComp: public TObject2dCompWrap<CPolygon>
{
public:
	typedef TObject2dCompWrap<CPolygon> BaseClass;

	I_BEGIN_COMPONENT(CPolygonComp);
		I_REGISTER_INTERFACE(CPolygon);
		I_ASSIGN_MULTI_0(m_xAttrPtr, "X", "X-Positions of the polygon points", true);
		I_ASSIGN_MULTI_0(m_yAttrPtr, "Y", "Y-Positions of the polygon points", true);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_MULTIATTR(double, m_xAttrPtr);
	I_MULTIATTR(double, m_yAttrPtr);
};


} // namespace i2d


#endif // !i2d_CPolygonComp_included


