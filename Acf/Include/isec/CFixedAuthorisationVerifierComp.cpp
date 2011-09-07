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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "isec/CFixedAuthorisationVerifierComp.h"


namespace isec
{


// reimplemented (isec::IAuthorizationVerifier)

bool CFixedAuthorisationVerifierComp::IsAuthorized(const std::string& featureId) const
{
	if (m_enabledFeatureIds.find(featureId) != m_enabledFeatureIds.end()){
		return true;
	}

	if (m_disabledFeatureIds.find(featureId) != m_disabledFeatureIds.end()){
		return false;
	}

	if (m_slaveVerifierCompPtr.IsValid()){
		return m_slaveVerifierCompPtr->IsAuthorized(featureId);
	}

	if (m_defaultRightCompPtr.IsValid()){
		return *m_defaultRightCompPtr;
	}

	return false;
}


isec::IAuthorizationVerifier::Ids CFixedAuthorisationVerifierComp::GetKnownFeatureIds() const
{
	Ids retVal = m_enabledFeatureIds;
	retVal.insert(m_disabledFeatureIds.begin(), m_disabledFeatureIds.end());

	if (m_slaveVerifierCompPtr.IsValid()){
		Ids slaveIds = m_slaveVerifierCompPtr->GetKnownFeatureIds();

		retVal.insert(slaveIds.begin(), slaveIds.end());
	}

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CFixedAuthorisationVerifierComp::OnComponentCreated()
{
	m_enabledFeatureIds.clear();

	int enabledCount = m_enabledFeaturesCompPtr.GetCount();
	for (int enabledIndex = 0; enabledIndex < enabledCount; ++enabledIndex){
		const istd::CString& id = m_enabledFeaturesCompPtr[enabledIndex];

		m_enabledFeatureIds.insert(id.ToString());
	}

	m_disabledFeatureIds.clear();

	int disabledCount = m_disabledFeaturesCompPtr.GetCount();
	for (int disabledIndex = 0; disabledIndex < disabledCount; ++disabledIndex){
		const istd::CString& id = m_disabledFeaturesCompPtr[disabledIndex];

		m_disabledFeatureIds.insert(id.ToString());
	}
}


} // namespace isec


