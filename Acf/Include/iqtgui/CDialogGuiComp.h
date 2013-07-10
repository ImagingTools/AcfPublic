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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_CDialogGuiComp_included
#define iqtgui_CDialogGuiComp_included


// ACF includes
#include "ibase/ICommandsProvider.h"

#include "iqtgui/IDialog.h"
#include "iqtgui/CGuiComponentDialog.h"
#include "iqtgui/CHierarchicalCommand.h"


namespace iqtgui
{


/**
	Dialog based representation of any UI-Component.
	This component provides also a menu command and can be integrated into a consumer of ibase::ICommandsProvider interface.
*/
class CDialogGuiComp:
			public QObject,
			public icomp::CComponentBase,
			virtual public iqtgui::IDialog,
			virtual public ibase::ICommandsProvider
{
	Q_OBJECT
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CDialogGuiComp);
		I_REGISTER_INTERFACE(iqtgui::IDialog);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_ASSIGN(m_guiCompPtr, "Gui", "UI to show in the dialog", true, "Gui");
		I_ASSIGN(m_dialogTitleAttrPtr, "DialogTitle", "Title for the dialog", false, "DialogTitle");
		I_ASSIGN(m_dialogIconPathAttrPtr, "DialogIconPath", "Icon path for the dialog", false, "IconPath");
		I_ASSIGN(m_menuNameAttrPtr, "MenuName", "Name of the menu for the action group", true, "MenuName");
		I_ASSIGN(m_menuDescriptionAttrPtr, "MenuDescription", "Description for the action group", true, "MenuDescription");
		I_ASSIGN(m_rootMenuNameAttrPtr, "RootMenu", "Name of the root command", true, "RootMenu");
		I_ASSIGN(m_initialDialogSizeAttrPtr, "DialogSize", "Initial size of the dialog. The value is proportion of dialog size to desktop size", false, 0.5);
		I_ASSIGN(m_isModalAttrPtr, "IsModal", "Modality of the dialog", true, true);
	I_END_COMPONENT;

	// reimplemented (iqtgui::IDialog)
	virtual int ExecuteDialog(IGuiObject* parentPtr);

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const;

protected:
	virtual iqtgui::CGuiComponentDialog* CreateComponentDialog(int buttons, IGuiObject* parentPtr) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

protected Q_SLOTS:
	void OnCommandActivated();

private:
	void SetInitialDialogSize(QDialog& dialog) const;

private:
	I_REF(iqtgui::IGuiObject, m_guiCompPtr);
	I_ATTR(QString, m_dialogTitleAttrPtr);
	I_ATTR(QString, m_dialogIconPathAttrPtr);
	I_ATTR(QString, m_menuNameAttrPtr);
	I_ATTR(QString, m_menuDescriptionAttrPtr);
	I_ATTR(QString, m_rootMenuNameAttrPtr);
	I_ATTR(double, m_initialDialogSizeAttrPtr);
	I_ATTR(bool, m_isModalAttrPtr);

	iqtgui::CHierarchicalCommand m_rootCommand;
	iqtgui::CHierarchicalCommand m_rootMenuCommand;
	iqtgui::CHierarchicalCommand m_dialogCommand;
};


} // namespace iqtgui


#endif // !iqtgui_CDialogGuiComp_included

