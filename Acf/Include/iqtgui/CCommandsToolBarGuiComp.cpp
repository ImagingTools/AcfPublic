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


#include "iqtgui/CCommandsToolBarGuiComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

// ACF includes
#include "iqtgui/CCommandTools.h"


namespace iqtgui
{


// protected methods

// reimplemented (CGuiComponentBase)

void CCommandsToolBarGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QToolBar* toolBarPtr = GetQtWidget();
	Q_ASSERT(toolBarPtr != NULL);
	if (toolBarPtr == NULL){
		return;
	}

	if (m_commandsProviderCompPtr.IsValid()){
		const ibase::IHierarchicalCommand* commandsPtr = m_commandsProviderCompPtr->GetCommands();
		if (commandsPtr != NULL){
			m_toolBarCommands.JoinLinkFrom(commandsPtr);
		}

		CCommandTools::SetupToolbar(m_toolBarCommands, *toolBarPtr);
	}
}


void CCommandsToolBarGuiComp::OnGuiDestroyed()
{
	m_toolBarCommands.ResetChilds();

	BaseClass::OnGuiDestroyed();
}


} // namespace iqtgui


