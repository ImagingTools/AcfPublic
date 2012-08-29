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


#ifndef iqtgui_CToolBarGuiCompBase_included
#define iqtgui_CToolBarGuiCompBase_included


// Qt includes
#include <QtCore/QMap>
#include <QtGui/QToolBar>

// ACF includes
#include "iqtgui/IMainWindowComponent.h"
#include "iqtgui/TGuiComponentBase.h"


namespace iqtgui
{


/**
	Basic implementation of a tool bar component.
*/
class CToolBarGuiCompBase: 
			public iqtgui::TGuiComponentBase<QToolBar>, 
			virtual public iqtgui::IMainWindowComponent
{
public:
	typedef iqtgui::TGuiComponentBase<QToolBar> BaseClass; 
	
	I_BEGIN_COMPONENT(CToolBarGuiCompBase);
		I_REGISTER_INTERFACE(iqtgui::IMainWindowComponent);
		I_ASSIGN(m_dockAreaAttrPtr, "ToolBarArea", "Specify the area for this toolbar\n 0 - left\n 1 - right\n 2 - top\n 3 - bottom", false, 0);
		I_ASSIGN(m_titleAttrPtr, "Title", "Tool bar title", false, "");
		I_ASSIGN(m_iconSizeAttrPtr, "IconSize", "Size of the icon used in the tool bar", false, 32);
	I_END_COMPONENT;

	// reimplemented (iqtgui::IMainWindowComponent)
	virtual bool AddToMainWindow(QMainWindow& mainWindow);
	virtual bool RemoveFromMainWindow(QMainWindow& mainWindow);

protected:
	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	I_ATTR(int, m_dockAreaAttrPtr);
	I_ATTR(QString, m_titleAttrPtr);
	I_ATTR(int, m_iconSizeAttrPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CToolBarGuiCompBase_included


