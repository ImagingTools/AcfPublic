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


#include "iqtgui/CSettingsContainerGuiComp.h"


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#else
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#endif


namespace iqtgui
{


// protected methods

// reimplemented (CContainerGuiBase)

bool CSettingsContainerGuiComp::CreateMainGui(QSize iconSize)
{
	QWidget* widgetPtr = GetQtWidget();
	if (widgetPtr == NULL){
		return false;
	}

	QHBoxLayout* mainLayoutPtr = new QHBoxLayout(widgetPtr);
	mainLayoutPtr->setContentsMargins(0, 0, 0, 0);

	m_menuListPtr = new QListWidget(widgetPtr);
	m_stackedWidgetPtr = new QStackedWidget(widgetPtr);

	if (*m_menuPositionAttrPtr == 0){
		mainLayoutPtr->addWidget(m_menuListPtr);
		mainLayoutPtr->addWidget(m_stackedWidgetPtr);
	}
	else{
		mainLayoutPtr->addWidget(m_stackedWidgetPtr);
		mainLayoutPtr->addWidget(m_menuListPtr);
	}

	m_menuListPtr->setIconSize(iconSize);
	m_menuListPtr->setUniformItemSizes(true);
	m_menuListPtr->setAlternatingRowColors(*m_alternateColorsAttrPtr);
	m_menuListPtr->setFrameStyle(QFrame::NoFrame);

	if (m_fixedWidthAttrPtr.IsValid()){
		int width = qMax(iconSize.width(), *m_fixedWidthAttrPtr);
		m_menuListPtr->setFixedWidth(width);
	}

	connect(m_menuListPtr, SIGNAL(currentRowChanged(int)), m_stackedWidgetPtr, SLOT(setCurrentIndex(int)));

	return true;
}


int CSettingsContainerGuiComp::CreatePageGui(const QString& name, QSize /*iconSize*/, iqtgui::IGuiObject* guiPtr)
{
	if (guiPtr == NULL || m_stackedWidgetPtr == NULL || m_menuListPtr == NULL){
		return -1;
	}

	if (!guiPtr->CreateGui(m_stackedWidgetPtr)){
		return -1;
	}

	m_menuListPtr->addItem(new QListWidgetItem(name));

	return m_stackedWidgetPtr->addWidget(guiPtr->GetWidget());
}


void CSettingsContainerGuiComp::UpdateItem(int index, const QIcon& icon, const QString& toolTip)
{
	Q_ASSERT(m_menuListPtr != NULL);

	QListWidgetItem* itemPtr = m_menuListPtr->item(index);
	if (itemPtr != NULL){
		itemPtr->setIcon(icon);
		itemPtr->setToolTip(toolTip);
	}
}


bool CSettingsContainerGuiComp::SetSelectedIndex(int index)
{
	Q_ASSERT(m_menuListPtr != NULL);
	Q_ASSERT(m_stackedWidgetPtr != NULL);

	if (m_menuListPtr != NULL){
		m_menuListPtr->setCurrentRow(index);

		return true;
	}

	return false;
}


bool CSettingsContainerGuiComp::SetEnabled(int /*index*/, bool /*isEnabled*/)
{
	// not implemented
	return true;
}


} // namespace iqtgui
