/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_CToolBarWidgetGuiComp_included
#define iqtgui_CToolBarWidgetGuiComp_included


// ACF includes
#include <iqtgui/CToolBarGuiCompBase.h>


namespace iqtgui
{


/**
	Component for construction of a tool bar with an inserted widget.
*/
class CToolBarWidgetGuiComp: public CToolBarGuiCompBase
{
public:
	typedef CToolBarGuiCompBase BaseClass;

	
	I_BEGIN_COMPONENT(CToolBarWidgetGuiComp);
		I_REGISTER_INTERFACE(iqtgui::IMainWindowComponent);
		I_ASSIGN(m_toolbarWidgetCompPtr, "ToolBarWidget", "Widget to place into the tool bar", true, "ToolBarWidget");
	I_END_COMPONENT;

protected:
	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	I_REF(iqtgui::IGuiObject, m_toolbarWidgetCompPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CToolBarWidgetGuiComp_included

