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


#ifndef iqtgui_CCommandTools_included
#define iqtgui_CCommandTools_included


// Qt includes
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBar>
#include <QtGui/QAction>
#include <QtGui/QActionGroup>

// ACF includes
#include "ibase/ICommandsProvider.h"

#include "iqtgui/CHierarchicalCommand.h"


namespace iqtgui
{


/**
	Helper class to manage menu and toolbar using CHierarchicalCommand.
*/
class CCommandTools
{
public:
	template <class MenuType>
	static void CreateMenu(const iqtgui::CHierarchicalCommand& command, MenuType& result);

	static int SetupToolbar(const iqtgui::CHierarchicalCommand& command, QToolBar& result, int prevGroupId = ibase::ICommand::GI_NONE);
};


// protected template methods

template <class MenuType>
void CCommandTools::CreateMenu(const iqtgui::CHierarchicalCommand& command, MenuType& result)
{
	int prevGroupId = ibase::ICommand::GI_NONE;

	int childsCount = command.GetChildsCount();

	QMap<int, QActionGroup*> groups;

	for (int i = 0; i < childsCount; ++i){
		QString text = command.text();
		iqtgui::CHierarchicalCommand* hierarchicalPtr = const_cast<iqtgui::CHierarchicalCommand*>(
					dynamic_cast<const iqtgui::CHierarchicalCommand*>(command.GetChild(i)));

		if (hierarchicalPtr != NULL){
			QString text2 = hierarchicalPtr->text();
			int groupId = hierarchicalPtr->GetGroupId();
			int flags = hierarchicalPtr->GetStaticFlags();

			if ((groupId != prevGroupId) && (prevGroupId != ibase::ICommand::GI_NONE)){
				result.addSeparator();
			}

			if (groupId != ibase::ICommand::GI_NONE){
				prevGroupId = groupId;
			}

			if (hierarchicalPtr->GetChildsCount() > 0){
				QMenu* newMenuPtr = new QMenu(&result);
				newMenuPtr->setTitle(hierarchicalPtr->GetName());

				CreateMenu<QMenu>(*hierarchicalPtr, *newMenuPtr);

				result.addMenu(newMenuPtr);
			}
			else if ((flags & ibase::ICommand::CF_GLOBAL_MENU) != 0){
				if ((flags & ibase::ICommand::CF_EXCLUSIVE) != 0){
					QActionGroup*& groupPtr = groups[hierarchicalPtr->GetGroupId()];
					if (groupPtr == NULL){
						groupPtr = new QActionGroup(&result);
						groupPtr->setExclusive(true);
					}

					groupPtr->addAction(hierarchicalPtr);
					hierarchicalPtr->setCheckable(true);
				}

				result.addAction(hierarchicalPtr);
			}
		}
	}
}


} // namespace iqtgui


#endif // !iqtgui_CCommandTools_included


