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


#include "iqtauth/CUserGuiComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "iser/CMemoryReadArchive.h"

// ACF-Solutions includes
#include "iqtauth/CChangePasswordDialog.h"
#include "iqtauth/CUserManagerDialog.h"


namespace iqtauth
{


// reimplemented (iauth::IPasswordChanger)

bool CUserGuiComp::TryChangePassword(iauth::CUser& user) const
{
	istd::TChangeNotifier<iauth::IUsersManager> managerPtr(GetObjectPtr());
	if (managerPtr.IsValid()){
		CChangePasswordDialog dialog(*managerPtr, user);
		dialog.exec();

		return true;
	}

	return false;
}


// protected methods

void CUserGuiComp::UpdateButtonsState()
{
	if (!IsGuiCreated()){
		return;
	}

	bool isUserLogged = m_userLoginIfPtr.IsValid() && (m_userLoginIfPtr->GetLoggedUser() != NULL);
	bool isUsersManagerAllowed = isUserLogged;
	bool isChangePasswordAllowed = isUserLogged;

	if (isUserLogged && m_rightsProviderIfPtr.IsValid()){
		if (m_usersManagerRightIdAttrPtr.IsValid()){
			isUsersManagerAllowed = m_rightsProviderIfPtr->HasRight((*m_usersManagerRightIdAttrPtr).ToString(), false);
		}

		if (m_changePasswordRightIdAttrPtr.IsValid()){
			isChangePasswordAllowed = m_rightsProviderIfPtr->HasRight((*m_changePasswordRightIdAttrPtr).ToString(), false);
		}
	}

	PushOpenUserManager->setEnabled(isUsersManagerAllowed);
	PushChangePassword->setEnabled(isChangePasswordAllowed);
}


// reimplemented (iqtgui::CGuiComponentBase)

void CUserGuiComp::OnGuiShown()
{
	UpdateButtonsState();
}


// reimplemented (icomp::CComponentBase)

void CUserGuiComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_rightsProviderIfPtr.IsValid()){
		RegisterModel(m_rightsModelIfPtr.GetPtr());
	}
}


void CUserGuiComp::OnComponentDestroyed()
{
	UnregisterModel();

	BaseClass::OnComponentDestroyed();
}


// reimplemented (imod::CMultiModelDispatcherBase)

void CUserGuiComp::OnModelChanged(int /*modelId*/, int /*changeFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	UpdateButtonsState();
}


// protected slots

void CUserGuiComp::on_PushChangePassword_clicked()
{
	if (m_userLoginIfPtr.IsValid()){
		iauth::CUser* loggedUserPtr = m_userLoginIfPtr->GetLoggedUser();
		if (loggedUserPtr != NULL){
			TryChangePassword(*loggedUserPtr);
		}
	}
}


void CUserGuiComp::on_PushOpenUserManager_clicked()
{

	if (m_userLoginIfPtr.IsValid()){
		istd::TChangeNotifier<iauth::IUsersManager> managerPtr(GetObjectPtr());
		if (managerPtr.IsValid()){
			CUserManagerDialog dialog(*m_userLoginIfPtr, *managerPtr);

			dialog.exec();
		}
	}
}


} // namespace iqtauth


