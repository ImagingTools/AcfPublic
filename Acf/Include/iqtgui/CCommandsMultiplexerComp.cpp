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


#include <iqtgui/CCommandsMultiplexerComp.h>


namespace iqtgui
{


CCommandsMultiplexerComp::CCommandsMultiplexerComp()
:	BaseClass2(this)
{
}


// reimpemented (ibase::ICommandsProvider)

const ibase::IHierarchicalCommand* CCommandsMultiplexerComp::GetCommands() const
{
	int selectedIndex = -1;

	if (m_commandSelectionCompPtr.IsValid()){
		selectedIndex = m_commandSelectionCompPtr->GetSelectedOptionIndex();
	}

	if ((selectedIndex >= 0) && (selectedIndex < m_commandProvidersCompPtr.GetCount())){
		ibase::ICommandsProvider* commandsProviderPtr = m_commandProvidersCompPtr[selectedIndex];
		if (commandsProviderPtr != NULL){
			return commandsProviderPtr->GetCommands();
		}
	}

	return NULL;
}


// protected methods

// reimplemented (imod::IObserver)

void CCommandsMultiplexerComp::BeforeUpdate(imod::IModel* I_IF_DEBUG(modelPtr))
{
	I_IF_DEBUG(Q_ASSERT(IsModelAttached(modelPtr)));

	ChangeSet changeSet(CF_DELEGATED, ibase::ICommandsProvider::CF_COMMANDS);

	BeginChanges(changeSet);
}


void CCommandsMultiplexerComp::AfterUpdate(imod::IModel* I_IF_DEBUG(modelPtr), const istd::IChangeable::ChangeSet& changeSet)
{
	I_IF_DEBUG(Q_ASSERT(IsModelAttached(modelPtr)));

	ChangeSet composedChangeSet = changeSet;

	composedChangeSet += CF_DELEGATED;

	EndChanges(composedChangeSet);
}


// reimpemented (icomp::CComponentBase)

void CCommandsMultiplexerComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_commandSelectionModelCompPtr.IsValid()){
		m_commandSelectionModelCompPtr->AttachObserver(this);
	}

	for(int i = 0; i < m_commandProviderModelsCompPtr.GetCount(); ++i){
		imod::IModel* modelPtr = m_commandProviderModelsCompPtr[i];
		if (modelPtr != NULL){
			modelPtr->AttachObserver(this);
		}
	}
}


void CCommandsMultiplexerComp::OnComponentDestroyed()
{
	EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace iqtgui


