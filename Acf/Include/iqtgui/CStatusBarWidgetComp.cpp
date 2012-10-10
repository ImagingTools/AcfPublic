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


#include "iqtgui/CStatusBarWidgetComp.h"


// Qt includes
#include <QtGui/QMainWindow>


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::IMainWindowComponent)

bool CStatusBarWidgetComp::AddToMainWindow(QMainWindow& mainWindow)
{
	if (m_statusBarWidgetsCompPtr.IsValid()){
		QStatusBar* statusBar = mainWindow.statusBar();
		I_ASSERT(statusBar != NULL);

		int widgetsCount = m_statusBarWidgetsCompPtr.GetCount();

		for (int widgetIndex = 0; widgetIndex < widgetsCount; widgetIndex++){
			iqtgui::IGuiObject* guiPtr = m_statusBarWidgetsCompPtr[widgetIndex];
			if (guiPtr != NULL){
				if (!guiPtr->IsGuiCreated()){
					if (guiPtr->CreateGui(statusBar)){
						statusBar->addPermanentWidget(guiPtr->GetWidget());
					}
					else{
						return false;
					}
				}
				else{
					I_CRITICAL();

					return false;
				}
			}
			else{
				I_CRITICAL();

				return false;
			}
		}
	}

	return false;
}


bool CStatusBarWidgetComp::RemoveFromMainWindow(QMainWindow& /*mainWindow*/)
{
	int widgetsCount = m_statusBarWidgetsCompPtr.GetCount();

	bool retVal = true;

	if (m_statusBarWidgetsCompPtr.IsValid()){
		for (int widgetIndex = 0; widgetIndex < widgetsCount; widgetIndex++){
			iqtgui::IGuiObject* guiPtr = m_statusBarWidgetsCompPtr[widgetIndex];
			if (guiPtr != NULL && guiPtr->IsGuiCreated()){
				retVal = guiPtr->DestroyGui() && retVal;
			}
		}
	}
	else{
		return false;
	}

	return retVal;
}


} // namespace iqtgui


