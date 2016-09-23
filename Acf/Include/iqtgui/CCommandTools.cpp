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


#include <iqtgui/CCommandTools.h>


namespace iqtgui
{


// public static methods

int CCommandTools::SetupToolbar(const iqtgui::CHierarchicalCommand& command, QToolBar& result, int prevGroupId)
{
	int childsCount = command.GetChildsCount();

	QMap<int, QActionGroup*> groups;

	for (int i = 0; i < childsCount; ++i){
		iqtgui::CHierarchicalCommand* hierarchicalPtr = const_cast<iqtgui::CHierarchicalCommand*>(
					dynamic_cast<const iqtgui::CHierarchicalCommand*>(command.GetChild(i)));

		if (hierarchicalPtr != NULL){
			int groupId = hierarchicalPtr->GetGroupId();
			int flags = hierarchicalPtr->GetStaticFlags();

			if ((flags & ibase::ICommand::CF_TOOLBAR) != 0){
				if (hierarchicalPtr->GetChildsCount() > 0){
					QMenu* newMenuPtr = new QMenu(&result);
					if (newMenuPtr != NULL){
						newMenuPtr->setTitle(hierarchicalPtr->GetName());

						CreateMenu<QMenu>(*hierarchicalPtr, *newMenuPtr);

						newMenuPtr->setIcon(hierarchicalPtr->icon());
						result.addAction(newMenuPtr->menuAction());
					}
				}
				else{
					if ((groupId != prevGroupId) && (prevGroupId != ibase::ICommand::GI_NONE)){
						result.addSeparator();
					}

					QString actionName = hierarchicalPtr->GetName();

					result.addAction(hierarchicalPtr);

					if ((flags & ibase::ICommand::CF_EXCLUSIVE) != 0){
						QActionGroup*& groupPtr = groups[hierarchicalPtr->GetGroupId()];
						if (groupPtr == NULL){
							groupPtr = new QActionGroup(&result);
							groupPtr->setExclusive(true);
						}

						groupPtr->addAction(hierarchicalPtr);
						hierarchicalPtr->setCheckable(true);
					}
				}

				if (groupId != ibase::ICommand::GI_NONE){
					prevGroupId = groupId;
				}
			}
			else if (hierarchicalPtr->GetChildsCount() > 0){
				prevGroupId = SetupToolbar(*hierarchicalPtr, result, prevGroupId);
			}
		}
	}

	return prevGroupId;
}


} // namespace iqtgui


