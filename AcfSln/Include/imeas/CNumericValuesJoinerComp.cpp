/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#include "imeas/CNumericValuesJoinerComp.h"

#include "imeas/CSimpleNumericValue.h"


namespace imeas
{


// reimplemented (imeas::INumericValueProvider)

int CNumericValuesJoinerComp::GetValuesCount() const
{
	if (m_valueProvidersCompPtr.IsValid()){
		return m_valueProvidersCompPtr.GetCount();
	}

	return 0;
}


const imeas::INumericValue& CNumericValuesJoinerComp::GetNumericValue(int index) const
{
	if (m_valueProvidersCompPtr.IsValid()){
		int providerCount = m_valueProvidersCompPtr.GetCount();
		if (providerCount > 0 && index >= 0){
			int providerIndex = index % providerCount;
			int valueIndex = index / providerCount;
			if (m_valueProvidersCompPtr[providerIndex]->GetValuesCount() > valueIndex){
				return m_valueProvidersCompPtr[providerIndex]->GetNumericValue(valueIndex);
			}
		}
	}

	return *this;
}


// protected

// reimplemented (imeas::CSimpleNumericValue)

bool CNumericValuesJoinerComp::IsValueTypeSupported(imeas::INumericValue::ValueTypeId /*valueTypeId*/) const
{
	return false;
}


imath::CVarVector CNumericValuesJoinerComp::GetComponentValue(imeas::INumericValue::ValueTypeId /*valueTypeId*/) const
{
	return imath::CVarVector();
}


} // namespace imeas


