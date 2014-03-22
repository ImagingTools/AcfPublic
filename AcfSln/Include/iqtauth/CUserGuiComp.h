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


#ifndef _qqtauth_CUserGuiComp_included
#define _qqtauth_CUserGuiComp_included


// ACF includes
#include "imod/CMultiModelDispatcherBase.h"
#include "ilog/TLoggerCompWrap.h"
#include "iqtgui/TDesignerGuiObserverCompBase.h"

// ACF-Solutions includes
#include "iauth/IRightsProvider.h"
#include "iauth/ILogin.h"
#include "iauth/IUsersManager.h"
#include "iauth/IPasswordChanger.h"

#include "GeneratedFiles/iqtauth/ui_CUserGuiComp.h"


namespace iqtauth
{


class CUserGuiComp:
			public ilog::TLoggerCompWrap<
						iqtgui::TDesignerGuiObserverCompBase<
									Ui::CUserGuiComp, iauth::IUsersManager> >,
			protected imod::CMultiModelDispatcherBase,
			virtual public iauth::IPasswordChanger
{
	Q_OBJECT

public:
	typedef ilog::TLoggerCompWrap<
				iqtgui::TDesignerGuiObserverCompBase<
							Ui::CUserGuiComp, iauth::IUsersManager> > BaseClass;

	I_BEGIN_COMPONENT(CUserGuiComp);
		I_REGISTER_INTERFACE(iauth::IPasswordChanger);
		I_ASSIGN(m_rightsProviderIfPtr, "RightsProvider", "RightsProvider", false, "RightsProvider");
		I_ASSIGN(m_rightsModelIfPtr, "RightsProvider", "RightsProvider", true, "RightsProvider");
		I_ASSIGN(m_userLoginIfPtr, "RightsProvider", "RightsProvider", true, "RightsProvider");
		I_ASSIGN(m_usersManagerRightIdAttrPtr, "UsersManagerRightId", "Right ID for user manager", false, "");
		I_ASSIGN(m_changePasswordRightIdAttrPtr, "ChangePasswordRightsId", "Right ID for changing password", false, "");
	I_END_COMPONENT;

	// reimplemented (iauth::IPasswordChanger)
	virtual bool TryChangePassword(iauth::CUser& user) const;

protected:
	void UpdateButtonsState();

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiShown();

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

	// reimplemented (imod::CMultiModelDispatcherBase)
	virtual void OnModelChanged(int modelId, int changeFlags, istd::IPolymorphic* updateParamsPtr);

protected Q_SLOTS:
	virtual void on_PushChangePassword_clicked();
	virtual void on_PushOpenUserManager_clicked();

private:
	I_REF(iauth::IRightsProvider, m_rightsProviderIfPtr);
	I_REF(imod::IModel, m_rightsModelIfPtr);
	I_REF(iauth::ILogin, m_userLoginIfPtr);

	I_ATTR(QByteArray, m_usersManagerRightIdAttrPtr);
	I_ATTR(QByteArray, m_changePasswordRightIdAttrPtr);
};

} // namespace iqtauth


#endif	// !_qqtauth_CUserGuiComp_included


