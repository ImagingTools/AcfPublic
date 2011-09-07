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


#ifndef isec_CStaticUserLoginComp_included
#define isec_CStaticUserLoginComp_included


#include "icomp/CComponentBase.h"

#include "isec/IAuthorizationVerifier.h"
#include "isec/IUserLogin.h"


namespace isec
{


/**
	Authorization verifier delegating authorisation request depent on logged user.
	List of user and passwords is defined statically.
*/
class CStaticUserLoginComp:
			public icomp::CComponentBase,
			virtual public IAuthorizationVerifier,
			virtual public IUserLogin
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CStaticUserLoginComp);
		I_REGISTER_INTERFACE(IUserLogin);
		I_REGISTER_INTERFACE(IAuthorizationVerifier);
		I_ASSIGN_MULTI_0(m_userIdsCompPtr, "UserIds", "List of user ID's", true);
		I_ASSIGN_MULTI_0(m_userPasswordsCompPtr, "UserPasswords", "List of user passwords", true);
		I_ASSIGN_MULTI_0(m_verifiersCompPtr, "Verifiers", "List of user authorization verifiers", true);
		I_ASSIGN(m_defaultVerifierCompPtr, "DefaultVerifier", "Authorization verifier used if no user is logged", true, "DefaultVerifier");
	I_END_COMPONENT;

	CStaticUserLoginComp();

	// reimplemented (isec::IAuthorizationVerifier)
	virtual bool IsAuthorized(const std::string& featureId) const;
	virtual Ids GetKnownFeatureIds() const;

	// reimplemented (isec::IUserLogin)
	virtual bool LoginUser(const std::string& userId, const istd::CString& password);
	virtual bool LogoutUser();
	virtual std::string GetLoggedUser() const;

private:
	I_MULTIATTR(istd::CString, m_userIdsCompPtr);
	I_MULTIATTR(istd::CString, m_userPasswordsCompPtr);
	I_MULTIREF(IAuthorizationVerifier, m_verifiersCompPtr);
	I_REF(IAuthorizationVerifier, m_defaultVerifierCompPtr);

	int m_loggedUserIndex;
};


} // namespace isec


#endif // !isec_CStaticUserLoginComp_included


