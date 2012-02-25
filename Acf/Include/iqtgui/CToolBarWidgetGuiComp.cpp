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


#include "iqtgui/CToolBarWidgetGuiComp.h"


// Qt includes
#include <QHBoxLayout>
#include <QComboBox>
#include <QMainWindow>


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::IMainWindowComponent)

bool CToolBarWidgetGuiComp::AddToMainWindow(QMainWindow& mainWindow)
{
	if (IsGuiCreated()){
		return false;
	}
		
	if (!CreateGui(NULL)){
		return false;
	}

	Qt::ToolBarArea area = Qt::AllToolBarAreas;
	int dockArea = Qt::TopToolBarArea;

	if (m_dockAreaAttrPtr.IsValid()){
		dockArea = *m_dockAreaAttrPtr;
	}

	switch (dockArea){
		case 0:
			area = Qt::LeftToolBarArea;
			break;

		case 1:
			area = Qt::RightToolBarArea;
			break;
		case 2:
			area = Qt::TopToolBarArea;
			break;

		case 3:
			area = Qt::BottomToolBarArea;
			break;
	}

	QToolBar* toolBarPtr = GetQtWidget();
	I_ASSERT(toolBarPtr != NULL); 
	if (toolBarPtr != NULL){
		toolBarPtr->setIconSize(mainWindow.iconSize());
		mainWindow.addToolBar(area, toolBarPtr);

		return true;
	}

	return false;
}


bool CToolBarWidgetGuiComp::RemoveFromMainWindow(QMainWindow& /*mainWindow*/)
{
	return DestroyGui();
}


// protected methods

// reimplemented (CGuiComponentBase)

void CToolBarWidgetGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QToolBar* widgetPtr = GetQtWidget();
	I_ASSERT(widgetPtr != NULL);
	if (widgetPtr == NULL){
		return;
	}

	if (m_titleAttrPtr.IsValid()){
		widgetPtr->setWindowTitle(m_titleAttrPtr->GetValue());
		widgetPtr->setObjectName(m_titleAttrPtr->GetValue());
	}

	if (m_toolbarWidgetCompPtr.IsValid()){
		iqtgui::IGuiObject* guiPtr = m_toolbarWidgetCompPtr.GetPtr();
		if (guiPtr != NULL){
			I_ASSERT(!guiPtr->IsGuiCreated());

			if (guiPtr->CreateGui(NULL)){
				widgetPtr->addWidget(guiPtr->GetWidget());
			}
		}
	}
}


void CToolBarWidgetGuiComp::OnGuiDestroyed()
{
	if (m_toolbarWidgetCompPtr.IsValid()){
		iqtgui::IGuiObject* guiPtr = m_toolbarWidgetCompPtr.GetPtr();
		if (guiPtr != NULL){
			guiPtr->DestroyGui();
		}
	}

	BaseClass::OnGuiDestroyed();
}


} // namespace iqtgui


