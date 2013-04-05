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


#ifndef iqtgui_CSettingsContainerGuiComp_included
#define iqtgui_CSettingsContainerGuiComp_included


// Qt includes
#include <QtGui/QStackedWidget>
#include <QtGui/QListWidget>

// ACF includes
#include "iqtgui/CContainerGuiBase.h"


namespace iqtgui
{


/**
	GUI container providing vertical menu for selection between the child UIs.
	Typically used for building the settings dialogs.
*/
class CSettingsContainerGuiComp:
				public iqtgui::TContainerGuiBase<QWidget>
{
	Q_OBJECT
public:
	typedef iqtgui::TContainerGuiBase<QWidget> BaseClass;

	I_BEGIN_COMPONENT(CSettingsContainerGuiComp);
		I_ASSIGN(m_fixedWidthAttrPtr, "FixedWidth", "Fixed width of the buttons", false, 100);
		I_ASSIGN(m_alternateColorsAttrPtr, "AlternateColors", "Alternate colors for each button", true, true);
		I_ASSIGN(m_menuPositionAttrPtr, "SelectorPosition", "0 - Left\n1 - Right", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (CContainerGuiBase)
	virtual bool CreateMainGui(QSize iconSize);
	virtual int CreatePageGui(const QString& name, QSize iconSize, iqtgui::IGuiObject* guiPtr);
	virtual void UpdateItem(int index, const QIcon& icon, const QString& toolTip);
	virtual bool SetSelectedIndex(int index);
	virtual bool SetEnabled(int index, bool isEnabled);

private:
	I_ATTR(int, m_fixedWidthAttrPtr);
	I_ATTR(bool, m_alternateColorsAttrPtr);
	I_ATTR(int, m_menuPositionAttrPtr);

	QStackedWidget* m_stackedWidgetPtr;
	QListWidget* m_menuListPtr;
};


} // namespace iqtgui


#endif // !iqtgui_CSettingsContainerGuiComp_included
