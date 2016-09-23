/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef _qqtauth_CLoginBarGuiComp_included
#define _qqtauth_CLoginBarGuiComp_included


// Qt includes
#include <QtCore/QTimer>

// ACF includes
#include <iqtgui/TDesignerGuiCompBase.h>

// ACF-Solutions includes
#include <iauth/ILogin.h>

#include <GeneratedFiles/iqtauth/ui_CLoginBarGuiComp.h>


namespace iqtauth
{


class CLoginBarGuiComp: public iqtgui::TDesignerGuiCompBase<Ui::CLoginBarGuiComp>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CLoginBarGuiComp> BaseClass;

	I_BEGIN_COMPONENT(CLoginBarGuiComp);
		I_ASSIGN(m_loginIfPtr, "Login", "Login logic component", true, "Login");
		I_ASSIGN(m_autoLogoutMinutesAttrPtr, "AutoLogoutMinutes", "Time intervall for the automatic logout", false, 60);
	I_END_COMPONENT;

	CLoginBarGuiComp();

protected:
	void UpdateButtonsState();

	// reimplemented (QWidget)
	virtual bool eventFilter(QObject *obj, QEvent *event);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

protected Q_SLOTS:
	virtual void on_LoginButton_clicked();
	virtual void on_LogoutButton_clicked();

private:
	QTimer m_autoLogoutTimer;
	int m_autoLogoutMilisec;

	I_REF(iauth::ILogin, m_loginIfPtr);
	I_ATTR(int, m_autoLogoutMinutesAttrPtr);
};


} // namespace iqtauth


#endif // !_qqtauth_CLoginBarGuiComp_included



