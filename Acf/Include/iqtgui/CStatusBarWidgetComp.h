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


#ifndef iqtgui_CStatusBarWidgetGuiComp_included
#define iqtgui_CStatusBarWidgetGuiComp_included


// Qt includes
#include <QtGui/QStatusBar>

// ACF includes
#include "icomp/CComponentBase.h"

#include "iqtgui/IMainWindowComponent.h"
#include "iqtgui/IGuiObject.h"


namespace iqtgui
{


/**
	Component for inserting of a widget into a status bar of the application.
*/
class CStatusBarWidgetComp:
			public icomp::CComponentBase,
			virtual public iqtgui::IMainWindowComponent
{
public:
	typedef icomp::CComponentBase BaseClass; 
	
	I_BEGIN_COMPONENT(CStatusBarWidgetComp);
		I_REGISTER_INTERFACE(iqtgui::IMainWindowComponent);
		I_ASSIGN(m_statusBarWidgetCompPtr, "StatusBarWidget", "Widget to place into the status bar of the application", true, "StatusBarWidget");
	I_END_COMPONENT;

	// reimplemented (iqtgui::IMainWindowComponent)
	virtual bool AddToMainWindow(QMainWindow& mainWindow);
	virtual bool RemoveFromMainWindow(QMainWindow& mainWindow);

private:
	I_REF(iqtgui::IGuiObject, m_statusBarWidgetCompPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CStatusBarWidgetGuiComp_included


