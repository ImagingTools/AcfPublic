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


#ifndef iqtgui_CTabContainerGuiComp_included
#define iqtgui_CTabContainerGuiComp_included


// Qt includes
#include <QtGui/QTabWidget>

// ACF includes
#include "iqtgui/CContainerGuiBase.h"


namespace iqtgui
{


/**
	Component to create the tab widget, that shows the specified sub-UI-component in its tab page.
	You can control some settings of the tabs such icons, title, orientation or tab visualization.
	Optionally, you can specify the corner widget, which will be placed beside of the last tab.
*/
class CTabContainerGuiComp:
			public iqtgui::TContainerGuiBase<QTabWidget>
{
public:
	typedef iqtgui::TContainerGuiBase<QTabWidget> BaseClass;

	I_BEGIN_COMPONENT(CTabContainerGuiComp);
		I_ASSIGN(m_cornerGuiCompPtr, "CornerWidget", "Optional corner widget", false, "CornerWidget");
		I_ASSIGN(m_useTriangularTabsAttrPtr, "UseTriangularTabs", "Using triangular tab form", true, false);
		I_ASSIGN(m_tabOrientationAttrPtr, "TabBarOrientation", "Orientation of the tab bar\n 0 - North\n 1 - South\n 2 - West\n 3 - East", true, 0);
		I_ASSIGN(m_flatStyleAttrPtr, "FlatTabs", "Flat style of the tabs", true, false);
	I_END_COMPONENT;

protected:
	// reimplemented (CContainerGuiBase)
	virtual bool CreateMainGui(QSize iconSize);
	virtual int CreatePageGui(const QString& name, QSize iconSize, iqtgui::IGuiObject* guiPtr);
	virtual void UpdateItem(int index, const QIcon& icon, const QString& toolTip);
	virtual bool SetSelectedIndex(int index);
	virtual bool SetEnabled(int index, bool isEnabled);

private:
	I_REF(iqtgui::IGuiObject, m_cornerGuiCompPtr);
	I_ATTR(bool, m_useTriangularTabsAttrPtr);
	I_ATTR(int, m_tabOrientationAttrPtr);
	I_ATTR(bool, m_flatStyleAttrPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CTabContainerGuiComp_included

