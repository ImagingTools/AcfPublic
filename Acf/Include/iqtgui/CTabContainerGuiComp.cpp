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


#include "iqtgui/CTabContainerGuiComp.h"


// Qt includes
#include <QtGui/QGridLayout>
#include <QtGui/QFrame>


namespace iqtgui
{


// protected methods

// reimplemented (CContainerGuiBase)

bool CTabContainerGuiComp::CreateMainGui(QSize iconSize)
{
	QTabWidget* widgetPtr = GetQtWidget();
	Q_ASSERT(widgetPtr != NULL);
	if (widgetPtr == NULL){
		return false;
	}

	if (*m_useTriangularTabsAttrPtr){
		widgetPtr->setTabShape(QTabWidget::Triangular);
	}

	widgetPtr->setTabPosition(QTabWidget::TabPosition(*m_tabOrientationAttrPtr));
	widgetPtr->setIconSize(iconSize);

	bool isFlat = *m_flatStyleAttrPtr;
	if (isFlat){
		widgetPtr->setStyleSheet("QTabWidget::pane{border:0px none;}");
	}

	// setup the corner widget
	if (m_cornerGuiCompPtr.IsValid()){
		if (m_cornerGuiCompPtr->CreateGui(NULL)){
			widgetPtr->setCornerWidget(m_cornerGuiCompPtr->GetWidget());
		}
	}

	return true;
}


int CTabContainerGuiComp::CreatePageGui(const QString& name, QSize /*iconSize*/, iqtgui::IGuiObject* guiPtr)
{
	QTabWidget* widgetPtr = GetQtWidget();
	if (guiPtr == NULL || widgetPtr == NULL){
		return -1;
	}

	if (!guiPtr->CreateGui(widgetPtr)){
		return -1;
	}

	QWidget* pageWidget = new QWidget(widgetPtr);
	QVBoxLayout* pageLayout = new QVBoxLayout(pageWidget);

	pageLayout->addWidget(guiPtr->GetWidget());

	if (*m_flatStyleAttrPtr){
		pageLayout->setContentsMargins(0, 0, 0, 0);
	}

	return widgetPtr->addTab(pageWidget, name);
}


void CTabContainerGuiComp::UpdateItem(int index, const QIcon& icon, const QString& toolTip)
{
	QTabWidget* widgetPtr = GetQtWidget();
	Q_ASSERT(widgetPtr != NULL);

	if (widgetPtr != NULL){
		widgetPtr->setTabIcon(index, icon);
		widgetPtr->setTabToolTip(index, toolTip);
	}
}


bool CTabContainerGuiComp::SetSelectedIndex(int index)
{
	QTabWidget* widgetPtr = GetQtWidget();
	Q_ASSERT(widgetPtr != NULL);
	if (widgetPtr == NULL){
		return false;
	}

	widgetPtr->setCurrentIndex(index);

	return true;
}


bool CTabContainerGuiComp::SetEnabled(int index, bool isEnabled)
{
	QTabWidget* widgetPtr = GetQtWidget();
	Q_ASSERT(widgetPtr != NULL);
	if (widgetPtr == NULL){
		return false;
	}

	widgetPtr->setTabEnabled(index, isEnabled);

	return true;
}


} // namespace iqtgui


