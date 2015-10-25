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


#include <iwidgets/CCollapsiblePage.h>


namespace iwidgets
{


// public methods
CCollapsiblePage::CCollapsiblePage(QWidget* parentPtr)
	:BaseClass(parentPtr),
	m_pageWidgetPtr(NULL)
{
	m_ui.setupUi(this);

	m_ui.IconLabel->setHidden(true);

	connect(m_ui.CollapseButton, SIGNAL(toggled(bool)), this, SLOT(SetPageVisible(bool)));
}


void CCollapsiblePage::SetTitle(const QString& text)
{
	m_ui.CollapseButton->setText(text);
}


void CCollapsiblePage::SetWidget(QWidget* pageWidgetPtr)
{
	m_ui.PageFrame->layout()->addWidget(pageWidgetPtr);

	m_pageWidgetPtr = pageWidgetPtr;
}


void CCollapsiblePage::SetIconSize(const QSize& size)
{
	m_ui.IconLabel->setMinimumSize(size);
	m_ui.IconLabel->setMaximumSize(size);

	m_ui.IconLabel->setPixmap(m_icon.pixmap(m_ui.IconLabel->minimumSize()));
}


void CCollapsiblePage::SetIcon(const QIcon& icon)
{
	m_icon = icon;

	m_ui.IconLabel->setVisible(!m_icon.isNull());

	m_ui.IconLabel->setPixmap(m_icon.pixmap(m_ui.IconLabel->minimumSize()));
}


// private slots

void CCollapsiblePage::SetPageVisible(bool visible)
{
	if (m_pageWidgetPtr != NULL){
		m_pageWidgetPtr->setVisible(visible);

		if (visible){
			setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		}
		else{
			setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
		}
	}
}


} // namespace iwidgets


