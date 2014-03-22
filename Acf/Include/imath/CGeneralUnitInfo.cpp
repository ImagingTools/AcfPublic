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


#include "imath/CGeneralUnitInfo.h"


// ACF includes
#include "imath/CDoubleManip.h"


namespace imath
{


CGeneralUnitInfo::CGeneralUnitInfo(
			int type,
			const QString& name,
			double displayMultFactor,
			const istd::CRange& range)
:	m_type(type),
	m_name(name),
	m_displayMultFactor(displayMultFactor),
	m_range(range)
{
}


void CGeneralUnitInfo::SetUnitType(int type)
{
	m_type = type;
}


void CGeneralUnitInfo::SetUnitName(const QString& name)
{
	m_name = name;
}


void CGeneralUnitInfo::SetDisplayMultiplicationFactor(double factor)
{
	m_displayMultFactor = factor;
}


void CGeneralUnitInfo::SetValueRange(const istd::CRange& range)
{
	m_range = range;
}


//	reimplemented (imath::IUnitInfo)

int CGeneralUnitInfo::GetUnitType() const
{
	return m_type;
}


QString CGeneralUnitInfo::GetUnitName() const
{
	return m_name;
}


double CGeneralUnitInfo::GetDisplayMultiplicationFactor() const
{
	return m_displayMultFactor;
}


istd::CRange CGeneralUnitInfo::GetValueRange() const
{
	return m_range;
}


const imath::IDoubleManip& CGeneralUnitInfo::GetValueManip() const
{
	static imath::CDoubleManip manip;

	return manip;
}


} // namespace imath


