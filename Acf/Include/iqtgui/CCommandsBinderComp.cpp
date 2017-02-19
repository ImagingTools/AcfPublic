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


#include <iqtgui/CCommandsBinderComp.h>

// ACF includes
#include <istd/CChangeNotifier.h>


namespace iqtgui
{


// public methods

CCommandsBinderComp::CCommandsBinderComp()
	:m_isUpdateLocked(false)
{
}


// reimplemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CCommandsBinderComp::GetCommands() const
{
	return &m_commands;
}


// protected methods

// reimplemented (imod::CMultiModelDispatcherBase)

void CCommandsBinderComp::OnModelChanged(int /*modelId*/, const istd::IChangeable::ChangeSet& changeSet)
{
	if (m_isUpdateLocked){
		return;
	}

	UnregisterAllModels();

	istd::CChangeNotifier notifier(this, &changeSet);
	Q_UNUSED(notifier);

	m_commands.ResetChilds();

	CreateCommands();
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
	m_isUpdateLocked = true;

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
				static const istd::IChangeable::ChangeSet commandsChangeSet(ibase::ICommandsProvider::CF_COMMANDS);
				RegisterModel(commandsProviderModelPtr, index, commandsChangeSet);
			}
		}
	}

	m_isUpdateLocked = false;
}


} // namespace iqtgui


