/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#pragma once


// ACF includes
#include <i2d/TObject2dCompWrap.h>


// RTVision includes
#include <i2d/CParallelogram.h>


namespace i2d
{


/**
	Implementation of a parallelogram as a component.
	It gives the possibility to define a parallelogram model via component attributes.
*/
class CParallelogramComp: public i2d::TObject2dCompWrap<i2d::CParallelogram>
{
public:
	typedef i2d::TObject2dCompWrap<i2d::CParallelogram> BaseClass;

	I_BEGIN_COMPONENT(CParallelogramComp);
		I_REGISTER_INTERFACE(CParallelogram);
		I_REGISTER_INTERFACE(IObject2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_xAttrPtr, "X", "X-Position of the parallelogramm", true, 0);
		I_ASSIGN(m_yAttrPtr, "Y", "Y-Position of the parallelogramm", true, 0);
		I_ASSIGN(m_widthAttrPtr, "Width", "Width of the parallelogramm", true, 200);
		I_ASSIGN(m_heightAttrPtr, "Height", "Height of the parallelogramm", true, 200);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

private:
	I_ATTR(double, m_xAttrPtr);
	I_ATTR(double, m_yAttrPtr);
	I_ATTR(double, m_widthAttrPtr);
	I_ATTR(double, m_heightAttrPtr);
};


} // namespace i2d


