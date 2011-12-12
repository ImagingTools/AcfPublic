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


#include "iqtauth/CLoginBarGuiComp.h"


// Qt includes
#include <QMessageBox>


namespace iqtauth
{


CLoginBarGuiComp::CLoginBarGuiComp()
:	m_autoLogoutMilisec(60*1000)
{
}


// protected methods

bool CLoginBarGuiComp::eventFilter(QObject *obj, QEvent *event)
{
	if (m_loginIfPtr.IsValid()){
		bool isLogged = m_loginIfPtr->IsUserLogged();

		if (isLogged && event->type() == QEvent::KeyRelease || event->type() == QEvent::MouseButtonRelease){
			// Auto log off functionality is activated
			if(m_autoLogoutMilisec > 0){
				m_autoLogoutTimer.start(m_autoLogoutMilisec);
			}
		}
	}

	// standard event processing
	return BaseClass::eventFilter(obj, event);
}


void CLoginBarGuiComp::UpdateButtonsState()
{
	if (m_loginIfPtr.IsValid()){
		bool isLogged = m_loginIfPtr->IsUserLogged();

		LoginButton->setVisible(!isLogged);
		LogoutButton->setVisible(isLogged);
		UserEdit->setEnabled(!isLogged);
		PasswordFrame->setVisible(!isLogged);
		if (!isLogged){
			m_autoLogoutTimer.stop();
			qApp->removeEventFilter(this);
			m_autoLogoutMilisec = 0;
		}
	}
}


// reimplemented (iqtgui::CGuiComponentBase)

void CLoginBarGuiComp::OnGuiCreated()
{
	connect(&m_autoLogoutTimer, SIGNAL(timeout()), this, SLOT(on_LogoutButton_clicked()));

	UpdateButtonsState();
}


// protected slots

void CLoginBarGuiComp::on_LoginButton_clicked()
{
	if (m_loginIfPtr.IsValid()){
		istd::CString userName = iqt::GetCString(UserEdit->text());
		istd::CString password = iqt::GetCString(PasswordEdit->text());
		if (m_loginIfPtr->Login(userName, password)){
			if (m_autoLogoutMinutesAttrPtr.IsValid()){
				I_ASSERT(*m_autoLogoutMinutesAttrPtr > 0);

				m_autoLogoutMilisec = *m_autoLogoutMinutesAttrPtr * 60 * 1000;
				m_autoLogoutTimer.start(m_autoLogoutMilisec);
				
				qApp->installEventFilter(this);
			}

			UpdateButtonsState();
		}
		else{
			QMessageBox::information(NULL, tr("Error"), tr("Wrong password"));
		}
	}

	PasswordEdit->setText("");
}


void CLoginBarGuiComp::on_LogoutButton_clicked()
{
	if (m_loginIfPtr.IsValid() && m_loginIfPtr->Logout()){
		UpdateButtonsState();
	}
}


} // namespace iqtauth


