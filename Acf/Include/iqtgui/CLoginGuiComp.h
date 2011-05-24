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


#ifndef iqtgui_CLoginGuiComp_included
#define iqtgui_CLoginGuiComp_included


// ACF includes
#include "isec/IUserLogin.h"

#include "iqtgui/TDesignerGuiCompBase.h"

#include "iqtgui/Generated/ui_CLoginGuiComp.h"


namespace iqtgui
{


class CLoginGuiComp: public TDesignerGuiCompBase<Ui::CLoginGuiComp, QWidget>
{
	Q_OBJECT

public:
	typedef TDesignerGuiCompBase<Ui::CLoginGuiComp, QWidget> BaseClass;

	I_BEGIN_COMPONENT(CLoginGuiComp);
		I_ASSIGN(m_userLoginCompPtr, "UserLogin", "User login object", true, "UserLogin");
	I_END_COMPONENT;

protected:
	void UpdateGui();

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

	I_REF(isec::IUserLogin, m_userLoginCompPtr);

protected slots:
	void on_LoginButton_clicked();
	void on_LogoutButton_clicked();
};


} // namespace iqtgui


#endif // !iqtgui_CLoginGuiComp_included

