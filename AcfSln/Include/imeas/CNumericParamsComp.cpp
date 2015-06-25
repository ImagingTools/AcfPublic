/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "imeas/CNumericParamsComp.h"


#include "istd/CChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"

#include "imath/CDoubleManip.h"


namespace imeas
{


CNumericParamsComp::CNumericParamsComp()
:	imod::CMultiModelBridgeBase(this)
{
}


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

	const INumericConstraints* constraintsPtr = GetNumericConstraints();
	Q_ASSERT(constraintsPtr != NULL);

	int count = constraintsPtr->GetNumericValuesCount();
	m_values.SetElementsCount(count);

	int defaultValuesCount = m_defaultValuesAttrPtr.GetCount();

	double lastValue = 0;
	for (int i = 0; i < count; ++i){
		if (i < defaultValuesCount){
			lastValue = m_defaultValuesAttrPtr[i];
		}

		// correct the value according to the constraints
		const imath::IUnitInfo& unitInfo = constraintsPtr->GetNumericValueUnitInfo(i);
		if (unitInfo.GetValueRange().IsValid()){
			m_values[i] = unitInfo.GetValueRange().GetClipped(lastValue);
		} else {
			m_values[i] = lastValue;
		}
	}

	if (m_constraintsModelCompPtr.IsValid()){
		m_constraintsModelCompPtr->AttachObserver(this);
	}
}


void CNumericParamsComp::OnComponentDestroyed()
{
	EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace imeas


