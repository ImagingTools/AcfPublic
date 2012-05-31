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


#ifndef iqtgui_CCommandsToolBarGuiComp_included
#define iqtgui_CCommandsToolBarGuiComp_included


// ACF includes
#include "ibase/ICommandsProvider.h"

#include "iqtgui/CToolBarGuiCompBase.h"
#include "iqtgui/CHierarchicalCommand.h"


namespace iqtgui
{


/**
	Component for construction of a tool bar for a given commands provider.
*/
class CCommandsToolBarGuiComp: 
			public CToolBarGuiCompBase
{
public:
	typedef CToolBarGuiCompBase BaseClass; 
	
	I_BEGIN_COMPONENT(CCommandsToolBarGuiComp);
		I_REGISTER_INTERFACE(iqtgui::IMainWindowComponent);
		I_ASSIGN(m_commandsProviderCompPtr, "CommandsProvider", "Commands for the tool bar", true, "CommandsProvider");
	I_END_COMPONENT;

protected:
	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	I_REF(ibase::ICommandsProvider, m_commandsProviderCompPtr);

	iqtgui::CHierarchicalCommand m_toolBarCommands;
};


} // namespace iqtgui


#endif // !iqtgui_CCommandsToolBarGuiComp_included


