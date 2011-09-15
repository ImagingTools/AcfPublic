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


#ifndef iqtgui_CCommandsBinderComp_included
#define iqtgui_CCommandsBinderComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "ibase/ICommandsProvider.h"

#include "iqtgui/CHierarchicalCommand.h"


namespace iqtgui
{


/**
	Component for binding of multiple command providers
*/
class CCommandsBinderComp: public icomp::CComponentBase, virtual public ibase::ICommandsProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CCommandsBinderComp);
		I_REGISTER_INTERFACE(ibase::ICommandsProvider);
		I_ASSIGN_MULTI_0(m_commandProvidersCompPtr, "CommandProviders", "List of command providers", true);
	I_END_COMPONENT;

	// reimplemented (ibase::ICommandsProvider)
	virtual const ibase::IHierarchicalCommand* GetCommands() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_MULTIREF(ibase::ICommandsProvider, m_commandProvidersCompPtr);

	mutable iqtgui::CHierarchicalCommand m_commands;
};


} // namespace iqtgui


#endif // !iqtgui_CCommandsBinderComp_included


