/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "iqtgui/CToolBarGuiCompBase.h"


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QHBoxLayout>
#include <QtGui/QComboBox>
#include <QtGui/QMainWindow>
#include <QtGui/QAction>
#endif


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::IMainWindowComponent)

bool CToolBarGuiCompBase::AddToMainWindow(QMainWindow& mainWindow)
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
	Q_ASSERT(toolBarPtr != NULL);
	if (toolBarPtr != NULL){
		toolBarPtr->setIconSize(mainWindow.iconSize());
		mainWindow.addToolBar(area, toolBarPtr);

		return true;
	}

	return false;
}


bool CToolBarGuiCompBase::RemoveFromMainWindow(QMainWindow& /*mainWindow*/)
{
	return DestroyGui();
}


QByteArray CToolBarGuiCompBase::GetAssociatedDocumentTypeId() const
{
	static QByteArray emptyId;

	if (m_associatedDocumentTypeId.IsValid()){
		return *m_associatedDocumentTypeId;
	}

	return emptyId;
}


QString CToolBarGuiCompBase::GetTitle() const
{
	static QString emptyTitle;

	if (m_titleAttrPtr.IsValid()){
		return *m_titleAttrPtr;
	}

	return emptyTitle;
}


// protected methods

// reimplemented (CGuiComponentBase)

void CToolBarGuiCompBase::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QToolBar* widgetPtr = GetQtWidget();
	Q_ASSERT(widgetPtr != NULL);
	if (widgetPtr == NULL){
		return;
	}

	QAction* toggleViewAction = widgetPtr->toggleViewAction();
	if (toggleViewAction != NULL){
		toggleViewAction->setVisible(false);
	}

	if (m_titleAttrPtr.IsValid()){
		widgetPtr->setWindowTitle(m_titleAttrPtr->GetValue());
		widgetPtr->setObjectName(m_titleAttrPtr->GetValue());
	}

	if (m_iconSizeAttrPtr.IsValid()){
		widgetPtr->setIconSize(QSize(*m_iconSizeAttrPtr, *m_iconSizeAttrPtr));
	}
}


} // namespace iqtgui


