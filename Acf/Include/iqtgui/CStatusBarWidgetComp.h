/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_CStatusBarWidgetGuiComp_included
#define iqtgui_CStatusBarWidgetGuiComp_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QStatusBar>
#else
#include <QtGui/QStatusBar>
#endif

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
		I_ASSIGN_MULTI_0(m_statusBarWidgetsCompPtr, "StatusBarWidgets", "Widgets to place into the status bar of the application", true);
		I_ASSIGN(m_isSizeGripEnabledAttrPtr, "EnableSizeGrip", "if enabled, the size grip will be created", true, true);
		I_ASSIGN(m_suppressWidgetFrameAttrPtr, "SuppressWidgetFrame", "if enabled, the frame around status bar widgets will be hidden", true, false);
	I_END_COMPONENT;

	// reimplemented (iqtgui::IMainWindowComponent)
	virtual bool AddToMainWindow(QMainWindow& mainWindow);
	virtual bool RemoveFromMainWindow(QMainWindow& mainWindow);
	virtual QString GetTitle() const;
	virtual int GetFlags() const;

private:
	I_MULTIREF(iqtgui::IGuiObject, m_statusBarWidgetsCompPtr);
	I_ATTR(bool, m_isSizeGripEnabledAttrPtr);
	I_ATTR(bool, m_suppressWidgetFrameAttrPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CStatusBarWidgetGuiComp_included


