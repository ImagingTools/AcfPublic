/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <imeas/CNumericParamsComp.h>


// ACF includes
#include <imath/CDoubleManip.h>


namespace imeas
{


// public methods

// reimplemented (imeas::INumericValue)

const INumericConstraints* CNumericParamsComp::GetNumericConstraints() const
{
	if (m_constraintsCompPtr.IsValid()){
		return m_constraintsCompPtr.GetPtr();
	}

	return NULL;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CNumericParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	int count = 0;
	int defaultValuesCount = m_defaultValuesAttrPtr.GetCount();

	const INumericConstraints* constraintsPtr = GetNumericConstraints();
	if (constraintsPtr != NULL){
		count = constraintsPtr->GetNumericValuesCount();
	}
	else{
		count = defaultValuesCount;
	}

	m_values.SetElementsCount(count);

	double lastValue = 0;
	for (int i = 0; i < count; ++i){
		if (i < defaultValuesCount){
			lastValue = m_defaultValuesAttrPtr[i];
		}

		if (constraintsPtr != NULL){
			// correct the value according to the constraints
			const imath::IUnitInfo* unitInfoPtr = constraintsPtr->GetNumericValueUnitInfo(i);
			if ((unitInfoPtr != NULL) && unitInfoPtr->GetValueRange().IsValid()){
				m_values[i] = unitInfoPtr->GetValueRange().GetClipped(lastValue);
			}
			else{
				m_values[i] = lastValue;
			}
		}
		else{
			m_values[i] = lastValue;
		}
	}
}


} // namespace imeas


