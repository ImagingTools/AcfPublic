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


#include <iqtgui/CSimpleGuiContainerDelegate.h>


// Qt includes
#include <QtCore/QVariant>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QIcon>
#include <QtGui/QGroupBox>


namespace iqtgui
{


// public methods

QWidget* CSimpleGuiContainerDelegate::CreateContainerWidget(QWidget* parentWidgetPtr, int orientation)
{	
	QWidget* containerPtr = new QWidget(parentWidgetPtr);

	switch (orientation){
		case Qt::Vertical:
			new QVBoxLayout(containerPtr);
			break;
		case Qt::Horizontal:
			new QHBoxLayout(containerPtr);
			break;
	}

	return containerPtr;
}


bool CSimpleGuiContainerDelegate::SetPageHeaderPosition(QWidget& /*containerWidget*/, PageHeaderPosition /*pageHeaderPosition*/)
{
	return false;
}


int CSimpleGuiContainerDelegate::InsertPage(
		QWidget& containerWidget,
		QWidget* pageWidgetPtr,
		const QString& pageTitle,
		int pageIndex)
{
	QLayout* containerLayoutPtr = containerWidget.layout();
	Q_ASSERT(containerLayoutPtr != NULL);

	QWidget* panelPtr = pageTitle.isEmpty() ? new QWidget(&containerWidget) : new QGroupBox(pageTitle, &containerWidget);
	panelPtr->setObjectName(QString("Page %1").arg(pageIndex));
	QLayout* panelLayoutPtr = new QVBoxLayout(panelPtr);
	panelLayoutPtr->setMargin(0);
	panelLayoutPtr->addWidget(pageWidgetPtr);

	containerLayoutPtr->addWidget(panelPtr);

	return containerLayoutPtr->count() - 1;
}


void CSimpleGuiContainerDelegate::RemovePage(QWidget& containerWidget, int pageIndex)
{
	QLayout* containerLayoutPtr = containerWidget.layout();
	Q_ASSERT(containerLayoutPtr != NULL);

	delete containerLayoutPtr->takeAt(pageIndex);
}


int CSimpleGuiContainerDelegate::GetPagesCount(const QWidget& containerWidget) const
{
	QLayout* containerLayoutPtr = containerWidget.layout();
	Q_ASSERT(containerLayoutPtr != NULL);

	return containerLayoutPtr->count();
}


QWidget* CSimpleGuiContainerDelegate::GetPageWidgetPtr(const QWidget& containerWidget, int pageIndex) const
{
	Q_ASSERT(pageIndex >= 0);
	Q_ASSERT(pageIndex < GetPagesCount(containerWidget));

	QLayout* containerLayoutPtr = containerWidget.layout();
	Q_ASSERT(containerLayoutPtr != NULL);

	return containerLayoutPtr->itemAt(pageIndex)->widget();
}


int CSimpleGuiContainerDelegate::GetCurrentPage(const QWidget& /*containerWidget*/) const
{
	return -1;
}


bool CSimpleGuiContainerDelegate::SetCurrentPage(QWidget& /*containerWidget*/, int /*pageIndex*/)
{
	return false;
}


QString CSimpleGuiContainerDelegate::GetPageTitle(const QWidget& /*containerWidget*/, int /*pageIndex*/) const
{
	return QString();
}


void CSimpleGuiContainerDelegate::SetPageTitle(QWidget& /*containerWidget*/, int /*pageIndex*/, const QString& /*pageTitle*/)
{
}


QIcon CSimpleGuiContainerDelegate::GetPageIcon(const QWidget& containerWidget, int pageIndex) const
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		pageWidgetPtr->windowIcon();
	}

	return QIcon();
}


void CSimpleGuiContainerDelegate::SetPageIcon(QWidget& containerWidget, int pageIndex, const QIcon& pageIcon)
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		QIcon usedIcon = pageIcon;

		if (!m_iconSize.isNull()){
			usedIcon = pageIcon.pixmap(m_iconSize);
		}

		return pageWidgetPtr->setWindowIcon(usedIcon);
	}
}


QString CSimpleGuiContainerDelegate::GetPageToolTip(const QWidget& containerWidget, int pageIndex) const
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		return pageWidgetPtr->toolTip();
	}

	return QString();
}


void CSimpleGuiContainerDelegate::SetPageToolTip(QWidget& containerWidget, int pageIndex, const QString& pageToolTip)
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		pageWidgetPtr->setToolTip(pageToolTip);
	}
}


bool CSimpleGuiContainerDelegate::IsPageEnabled(const QWidget& containerWidget, int pageIndex) const
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		return pageWidgetPtr->isEnabled();
	}

	return false;
}


bool CSimpleGuiContainerDelegate::SetPageEnabled(QWidget& containerWidget, int pageIndex, bool isPageEnabled)
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		pageWidgetPtr->setEnabled(isPageEnabled);

		return true;
	}

	return false;
}


bool CSimpleGuiContainerDelegate::IsPageVisible(const QWidget& containerWidget, int pageIndex) const
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		return pageWidgetPtr->isVisible();
	}

	return false;
}


bool CSimpleGuiContainerDelegate::SetPageVisible(QWidget& containerWidget, int pageIndex, bool isPageVisible)
{
	QWidget* pageWidgetPtr = GetPageWidgetPtr(containerWidget, pageIndex);
	if (pageWidgetPtr != NULL){
		pageWidgetPtr->setVisible(isPageVisible);
	}

	return false;
}


QSize CSimpleGuiContainerDelegate::GetPageIconSize(const QWidget& /*containerWidget*/) const
{
	return m_iconSize;
}


bool CSimpleGuiContainerDelegate::SetPageIconSize(QWidget& /*containerWidget*/, const QSize& pageIconSize)
{
	m_iconSize = pageIconSize;

	return true;
}


} // namespace iqtgui


