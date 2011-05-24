/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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


#ifndef isec_CComposedAuthorizationVerifierComp_included
#define isec_CComposedAuthorizationVerifierComp_included


#include "imod/CMultiModelBridgeBase.h"

#include "icomp/CComponentBase.h"

#include "isec/IAuthorizationVerifier.h"


namespace isec
{


/**
	Allows to connect many authorisation versifiers into one.
*/
class CComposedAuthorizationVerifierComp:
			public icomp::CComponentBase,
			virtual public IAuthorizationVerifier,
			protected imod::CMultiModelBridgeBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CComposedAuthorizationVerifierComp);
		I_REGISTER_INTERFACE(IAuthorizationVerifier);
		I_ASSIGN_MULTI_0(m_slaveVerifiersCompPtr, "SlaveVerifiers", "List of slave verifiers", true);
		I_ASSIGN_MULTI_0(m_slaveVerifiersModelCompPtr, "SlaveVerifiers", "List of slave verifiers", true);
	I_END_COMPONENT;

	// reimplemented (isec::IAuthorizationVerifier)
	virtual bool IsAuthorized(const std::string& featureId) const;
	virtual Ids GetKnownFeatureIds() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_MULTIREF(IAuthorizationVerifier, m_slaveVerifiersCompPtr);
	I_MULTIREF(imod::IModel, m_slaveVerifiersModelCompPtr);
};


} // namespace isec


#endif // !isec_CComposedAuthorizationVerifierComp_included


