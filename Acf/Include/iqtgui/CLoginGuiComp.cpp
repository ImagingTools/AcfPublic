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


#include "iqtgui/CLoginGuiComp.h"


// Qt includes
#include <QMessageBox>


namespace iqtgui
{


// protected methods

void CLoginGuiComp::UpdateGui()
{
	if (m_userLoginCompPtr.IsValid()){
		std::string loggedUser = m_userLoginCompPtr->GetLoggedUser();
		if (!loggedUser.empty()){
			UserNameEdit->setText(loggedUser.c_str());
			UserNameEdit->setEnabled(false);
			PasswordFrame->setVisible(false);
			LogoutButton->setVisible(true);
			LoginButton->setVisible(false);
		}
		else{
			UserNameEdit->setEnabled(true);
			PasswordFrame->setVisible(true);
			LogoutButton->setVisible(false);
			LoginButton->setVisible(true);
		}

		LoginFrame->setVisible(true);
	}
	else{
		LoginFrame->setVisible(false);
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CLoginGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	UpdateGui();
}


// protected slots

void CLoginGuiComp::on_LoginButton_clicked()
{
	if (m_userLoginCompPtr.IsValid()){
		if (!m_userLoginCompPtr->LoginUser(UserNameEdit->text().toStdString(), iqt::GetCString(PasswordEdit->text()))){
			PasswordEdit->setText("");
			QMessageBox::warning(GetWidget(), tr("Login Error") , tr("Wrong password or user name"));
		}

		UpdateGui();
	}
}


void CLoginGuiComp::on_LogoutButton_clicked()
{
	if (m_userLoginCompPtr.IsValid()){
		m_userLoginCompPtr->LogoutUser();

		UpdateGui();
	}
}


} // namespace iqtgui

