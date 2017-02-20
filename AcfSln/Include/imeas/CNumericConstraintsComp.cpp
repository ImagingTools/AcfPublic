/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#include <imeas/CNumericConstraintsComp.h>


namespace imeas
{


// reimplemented (imeas::INumericConstraints)

int CNumericConstraintsComp::GetNumericValuesCount() const
{
	return *m_dimensionsCountAttrPtr;
}


QString CNumericConstraintsComp::GetNumericValueName(int index) const
{
	if (index < m_namesAttrPtr.GetCount()){
		return m_namesAttrPtr[index];
	}
		
	return QString();
}


QString CNumericConstraintsComp::GetNumericValueDescription(int index) const
{
	if (index < m_descriptionsAttrPtr.GetCount()){
		return m_descriptionsAttrPtr[index];
	}

	return QString();
}


const imath::IUnitInfo* CNumericConstraintsComp::GetNumericValueUnitInfo(int /*index*/) const
{
	return this;
}


// protected methods

// reimplemented (imath::IUnitInfo)

int CNumericConstraintsComp::GetUnitType() const
{
	return *m_unitTypeAttrPtr;
}


QString CNumericConstraintsComp::GetUnitName() const
{
	return *m_unitNameAttrPtr;
}


double CNumericConstraintsComp::GetDisplayMultiplicationFactor() const
{
	return *m_displayMultFactorAttrPtr;
}


istd::CRange CNumericConstraintsComp::GetValueRange() const
{
	return istd::CRange(*m_minValueAttrPtr, *m_maxValueAttrPtr);
}


const imath::IDoubleManip& CNumericConstraintsComp::GetValueManip() const
{
	return *this;
}


// reimplemented (imath::IDoubleManip)

int CNumericConstraintsComp::GetPrecision() const
{
	return m_precision;
}


// reimplemented (ibase::CComponentBase)

void CNumericConstraintsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_precision = qMax(0, *m_precisionAttrPtr);
}


} // namespace imeas

