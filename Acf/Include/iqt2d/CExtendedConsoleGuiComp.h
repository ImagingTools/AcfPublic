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


#ifndef iqt2d_CExtendedConsoleGuiComp_included
#define iqt2d_CExtendedConsoleGuiComp_included


// ACF includes
#include "ibase/ICommandsProvider.h"

#include "iqtgui/TDesignerGuiCompBase.h"

#include "iqt2d/Generated/ui_CExtendedConsoleGuiComp.h"


namespace iqt2d
{


class CExtendedConsoleGuiComp: public iqtgui::TDesignerGuiCompBase<Ui::CExtendedConsoleGuiComp>
{
public:
	typedef iqtgui::TDesignerGuiCompBase<Ui::CExtendedConsoleGuiComp> BaseClass;
	
	I_BEGIN_COMPONENT(CExtendedConsoleGuiComp);
		I_ASSIGN(m_viewProviderGuiCompPtr, "ViewProvider", "Provider of the 2D-View", true, "ViewProvider");
		I_ASSIGN(m_toolBarCompPtr, "ToolBar", "Tool bar showing the commands of the view provider", true, "ToolBar");
		I_ASSIGN(m_statusInfoGuiCompPtr, "StatusInfoGui", "UI for status information of the 2D-console", true, "StatusInfoGui");
	I_END_COMPONENT;

protected:
	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	I_REF(iqtgui::IGuiObject, m_viewProviderGuiCompPtr);
	I_REF(iqtgui::IGuiObject, m_toolBarCompPtr);
	I_REF(iqtgui::IGuiObject, m_statusInfoGuiCompPtr);
};


} // namespace iqt2d


#endif // !iqt2d_CExtendedConsoleGuiComp_included


