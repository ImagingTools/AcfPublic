/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqtgui/CDockWidgetGuiComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QAction>
#else
#include <QtGui/QMainWindow>
#include <QtGui/QVBoxLayout>
#include <QtGui/QAction>
#endif


namespace iqtgui
{


// public methods

// reimplemented (iqtgui::IMainWindowComponent)

bool CDockWidgetGuiComp::AddToMainWindow(QMainWindow& mainWindow)
{
	if (IsGuiCreated()){
		return false;
	}

	if (!CreateGui(NULL)){
		return false;
	}

	Qt::DockWidgetArea area = Qt::LeftDockWidgetArea;
	Qt::Orientation orientation = Qt::Vertical;
	if (m_dockAreaAttrPtr.IsValid()){
		switch (m_dockAreaAttrPtr->GetValue()){
			case 0:
				area = Qt::LeftDockWidgetArea;
				orientation = Qt::Vertical;
				break;

			case 1:
				area = Qt::RightDockWidgetArea;
				orientation = Qt::Vertical;
				break;

			case 2:
				area = Qt::TopDockWidgetArea;
				orientation = Qt::Horizontal;
				break;

			case 3:
				area = Qt::BottomDockWidgetArea;
				orientation = Qt::Horizontal;
				break;
		}
	}

	QDockWidget* dockWidgetPtr = GetQtWidget();
	Q_ASSERT(dockWidgetPtr != NULL);
	if (dockWidgetPtr != NULL){
		mainWindow.addDockWidget(area, dockWidgetPtr, orientation);

		return true;
	}

	return false;
}


bool CDockWidgetGuiComp::RemoveFromMainWindow(QMainWindow& /*mainWindow*/)
{
	return DestroyGui();
}


QString CDockWidgetGuiComp::GetTitle() const
{
	static QString emptyTitle;

	if (m_dockTitleAttrPtr.IsValid()){
		return *m_dockTitleAttrPtr;
	}

	return emptyTitle;
}


int CDockWidgetGuiComp::GetFlags() const
{
	return *m_dockFeaturesAttrPtr & (WCF_CLOSABLE | WCF_MOVEABLE | WCF_FLOATABLE);
}


// protected methods

// reimplemented (CGuiComponentBase)

void CDockWidgetGuiComp::OnGuiCreated()
{
	BaseClass::OnGuiCreated();

	QDockWidget* dockWidgetPtr = GetQtWidget();
	Q_ASSERT(dockWidgetPtr != NULL);

	QAction* toggleViewAction = dockWidgetPtr->toggleViewAction();
	if (toggleViewAction != NULL){
		toggleViewAction->setVisible(false);
	}

	if (m_dockTitleAttrPtr.IsValid()){
		dockWidgetPtr->setWindowTitle(*m_dockTitleAttrPtr);
		dockWidgetPtr->setObjectName(*m_dockTitleAttrPtr);
	}
	else{
		dockWidgetPtr->setTitleBarWidget(new QWidget(dockWidgetPtr));
	}

	istd::TDelPtr<QWidget> containerWidgetPtr(new QWidget(NULL));
	QVBoxLayout* layoutPtr = new QVBoxLayout(containerWidgetPtr.GetPtr());
	layoutPtr->setMargin(1);
	containerWidgetPtr->setLayout(layoutPtr);

	if (m_slaveGuiCompPtr.IsValid() && m_slaveGuiCompPtr->CreateGui(containerWidgetPtr.GetPtr())){
		dockWidgetPtr->setWidget(containerWidgetPtr.PopPtr());
	}

	if (m_dockFeaturesAttrPtr.IsValid()){
		dockWidgetPtr->setFeatures(QDockWidget::DockWidgetFeature(*m_dockFeaturesAttrPtr));
	}
	else{
		dockWidgetPtr->setFeatures(
					QDockWidget::DockWidgetMovable |
					QDockWidget::DockWidgetFloatable |
					QDockWidget::DockWidgetClosable);
	}

	if (m_allowedDockAreasAttrPtr.IsValid()){
		dockWidgetPtr->setAllowedAreas(Qt::DockWidgetAreas(*m_allowedDockAreasAttrPtr));
	}
}


void CDockWidgetGuiComp::OnGuiDestroyed()
{
	if (m_slaveGuiCompPtr.IsValid() && m_slaveGuiCompPtr->IsGuiCreated()){
		m_slaveGuiCompPtr->DestroyGui();
	}

	BaseClass::OnGuiDestroyed();
}


void CDockWidgetGuiComp::OnGuiRetranslate()
{
	BaseClass::OnGuiRetranslate();

	QDockWidget* dockWidgetPtr = GetQtWidget();
	Q_ASSERT(dockWidgetPtr != NULL);

	if (m_dockTitleAttrPtr.IsValid()){
		dockWidgetPtr->setWindowTitle(*m_dockTitleAttrPtr);
	}
}


} // namespace iqtgui


