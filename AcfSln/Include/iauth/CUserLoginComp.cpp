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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iauth/CUserLoginComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iauth
{


// reimplemented (iauth::IUserLogin)

CUser* CUserLoginComp::GetLoggedUser() const
{
	if (m_usersManagerIfPtr.IsValid()){
		int userIndex = m_usersManagerIfPtr->FindUserIndex(m_loggedUserName);
		if (userIndex >= 0){
			return &m_usersManagerIfPtr->GetUserRef(userIndex);
		}
	}

	return NULL;
}


// reimplemented (iauth::ILogin)

bool CUserLoginComp::IsUserLogged() const
{
	return (!m_loggedUserName.isEmpty());
}


bool CUserLoginComp::Login(const QString& userName, const QString& password)
{
	if (m_usersManagerIfPtr.IsValid()){
		int userIndex = m_usersManagerIfPtr->FindUserIndex(userName);
		if (userIndex >= 0){
			CUser& user = m_usersManagerIfPtr->GetUserRef(userIndex);
			if (user.CheckPassword(password)){
				if (m_passwordChangerIfPtr.IsValid() && password.isEmpty()){
					if (!m_passwordChangerIfPtr->TryChangePassword(user)){
						return false;
					}
				}

				istd::TChangeNotifier<IRightsProvider> updatePtr(this);

				m_loggedUserName = userName;

				return true;
			}
		}
	}

	return false;
}


bool CUserLoginComp::Logout()
{
	if (m_usersManagerIfPtr.IsValid()){
		if (!m_loggedUserName.isEmpty()){
			istd::TChangeNotifier<IRightsProvider> updatePtr(this);

			m_loggedUserName.clear();

			return true;
		}
	}
	return false;
}


// reimplemented (iauth::IRightsProvider)

bool CUserLoginComp::HasRight(const std::string& operationId,	bool beQuiet) const
{
	int levelId = 0;
	if (!m_loggedUserName.isEmpty() && m_usersManagerIfPtr.IsValid()){
		int userIndex = m_usersManagerIfPtr->FindUserIndex(m_loggedUserName);
		if (userIndex >= 0){
			const CUser& user = m_usersManagerIfPtr->GetUser(userIndex);
			levelId = user.GetUserGroup();
		}
	}

	if (m_userLevelsIfPtr.IsValid()){
		IRightsProvider* groupRightsPtr = NULL;

		if (levelId < m_userLevelsIfPtr.GetCount()){
			groupRightsPtr = m_userLevelsIfPtr[levelId];
		}
		else if (m_userLevelsIfPtr.GetCount() > 0){
			groupRightsPtr = m_userLevelsIfPtr[0];
		}

		if (groupRightsPtr != NULL){
			return groupRightsPtr->HasRight(operationId, beQuiet);
		}
	}

	return false;
}


} // namespace iauth


