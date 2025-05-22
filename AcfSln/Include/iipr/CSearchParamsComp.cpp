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


#include <iipr/CSearchParamsComp.h>


namespace iipr
{


// public methods

// reimplemented (iipr::ISearchParams)

const ISearchConstraints* CSearchParamsComp::GetSearchConstraints() const
{
	return m_searchConstraintsCompPtr.IsValid() ? m_searchConstraintsCompPtr.GetPtr() : nullptr;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CSearchParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	SetNominalModelsCount(*m_defaultModelOccuranceAttrPtr);

	if (!m_defaultMinRotationAngleAttrPtr.IsValid() || !m_defaultMaxRotationAngleAttrPtr.IsValid())
		return;

	auto searchConstraints = GetSearchConstraints();
	const double minAngle = searchConstraints
		? std::max(*m_defaultMinRotationAngleAttrPtr, searchConstraints->GetRotationRangeConstraints().GetMinValue())
		: *m_defaultMinRotationAngleAttrPtr;
	const double maxAngle = searchConstraints
		? std::min(*m_defaultMaxRotationAngleAttrPtr, searchConstraints->GetRotationRangeConstraints().GetMaxValue())
		: *m_defaultMaxRotationAngleAttrPtr;

	SetRotationRange(istd::CRange{ minAngle, maxAngle });
}


} // namespace iipr


