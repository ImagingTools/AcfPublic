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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "isec/CComposedAuthorizationVerifierComp.h"


namespace isec
{


// reimplemented (isec::IAuthorizationVerifier)

bool CComposedAuthorizationVerifierComp::IsAuthorized(const std::string& featureId) const
{
	int slavesCount = m_slaveVerifiersCompPtr.GetCount();
	for (int i = 0; i < slavesCount; ++i){
		const IAuthorizationVerifier* verifierPtr = m_slaveVerifiersCompPtr[i];
		if (verifierPtr != NULL){
			if (verifierPtr->IsAuthorized(featureId)){
				return true;
			}
		}
	}

	return false;
}


IAuthorizationVerifier::Ids CComposedAuthorizationVerifierComp::GetKnownFeatureIds() const
{
	Ids retVal;

	int slavesCount = m_slaveVerifiersCompPtr.GetCount();
	for (int i = 0; i < slavesCount; ++i){
		const IAuthorizationVerifier* verifierPtr = m_slaveVerifiersCompPtr[i];
		if (verifierPtr != NULL){
			Ids ids = verifierPtr->GetKnownFeatureIds();
			retVal.insert(ids.begin(), ids.end());
		}
	}

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CComposedAuthorizationVerifierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	int modelsCount = m_slaveVerifiersModelCompPtr.GetCount();

	for (int i = 0; i < modelsCount; ++i){
		imod::IModel* modelPtr = m_slaveVerifiersModelCompPtr[i];
		if (modelPtr != NULL){
			modelPtr->AttachObserver(this);
		}
	}
}


void CComposedAuthorizationVerifierComp::OnComponentDestroyed()
{
	int modelsCount = m_slaveVerifiersModelCompPtr.GetCount();

	for (int i = 0; i < modelsCount; ++i){
		imod::IModel* modelPtr = m_slaveVerifiersModelCompPtr[i];
		if ((modelPtr != NULL) && modelPtr->IsAttached(this)){
			modelPtr->DetachObserver(this);
		}
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace isec


