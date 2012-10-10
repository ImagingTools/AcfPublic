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


#ifndef i2d_CPolylineComp_included
#define i2d_CPolylineComp_included


// ACF includes
#include "i2d/CPolyline.h"

#include "icomp/CComponentBase.h"


namespace i2d
{


/**
	Implementation of a poly-line as a component.
	It gives the possibility to define a list of polyline points via component attributes.
*/
class CPolylineComp: public icomp::CComponentBase, public CPolyline
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CPolyline BaseClass2;

	I_BEGIN_COMPONENT(CPolylineComp);
		I_REGISTER_INTERFACE(CPolyline);
		I_REGISTER_INTERFACE(IObject2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN_MULTI_0(m_xAttrPtr, "X", "X-Positions of the poly-line points", true);
		I_ASSIGN_MULTI_0(m_yAttrPtr, "Y", "Y-Positions of the poly-line points", true);
		I_ASSIGN(m_isClosedAttrPtr, "IsClosed", "Indicate if poly-line should be initially closed", true, true);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_MULTIATTR(double, m_xAttrPtr);
	I_MULTIATTR(double, m_yAttrPtr);
	I_ATTR(bool, m_isClosedAttrPtr);
};


} // namespace i2d


#endif // !i2d_CPolylineComp_included
