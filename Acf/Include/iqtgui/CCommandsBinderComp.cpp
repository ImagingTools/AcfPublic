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


#include "iqtgui/CCommandsBinderComp.h"

// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqtgui
{


// reimplemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CCommandsBinderComp::GetCommands() const
{
	return &m_commands;
}


// protected methods

// reimplemented (imod::CMultiModelDispatcherBase)

void CCommandsBinderComp::OnModelChanged(int /*modelId*/, int changeFlags, istd::IPolymorphic* updateParamsPtr)
{
	UnregisterAllModels();

	m_commands.ResetChilds();

	CreateCommands();

	istd::CChangeNotifier changePtr(this, changeFlags, updateParamsPtr);
}


// reimplemented (icomp::CComponentBase)

void CCommandsBinderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	CreateCommands();
}


// private methods

void CCommandsBinderComp::CreateCommands()
{
	if (m_commandProvidersCompPtr.IsValid()){
		for (int index = 0; index < m_commandProvidersCompPtr.GetCount(); index++){
			ibase::ICommandsProvider* commandsProviderPtr = m_commandProvidersCompPtr[index];
			if (commandsProviderPtr != NULL){
				const ibase::IHierarchicalCommand* commandPtr = commandsProviderPtr->GetCommands();
				if (commandPtr != NULL){
					m_commands.JoinLinkFrom(commandPtr);
				}
			}

			imod::IModel* commandsProviderModelPtr = dynamic_cast<imod::IModel*>(commandsProviderPtr);
			if (commandsProviderModelPtr != NULL){
				RegisterModel(commandsProviderModelPtr, index, ibase::ICommandsProvider::CF_COMMANDS);
			}
		}
	}
}


} // namespace iqtgui


