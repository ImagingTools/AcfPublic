/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iwidgets/CMiniWidgetPage.h>


// Qt includes
#include <QtWidgets/QGraphicsEffect>


namespace iwidgets
{


// public methods

CMiniWidgetPage::CMiniWidgetPage(QWidget* parentPtr)
	:BaseClass(parentPtr),
	m_pageWidgetPtr(NULL),
	m_iconSize(32, 32)
{
	setupUi(this);

	PageIconToolButton->setHidden(true);
}


void CMiniWidgetPage::SetTitle(const QString& text)
{
	PageLabel->setText(text);
}


void CMiniWidgetPage::SetWidget(QWidget* pageWidgetPtr)
{
	PageFrame->layout()->addWidget(pageWidgetPtr);

	m_pageWidgetPtr = pageWidgetPtr;
}


void CMiniWidgetPage::SetIconSize(const QSize& size)
{
	PageIconToolButton->setMinimumSize(size);
	PageIconToolButton->setMaximumSize(size);

	m_iconSize = size;

	PageIconToolButton->setIconSize(m_iconSize);
	PageIconToolButton->setIcon(m_icon);
}


void CMiniWidgetPage::SetIcon(const QIcon& icon)
{
	m_icon = icon;

	PageIconToolButton->setVisible(!m_icon.isNull());

	PageIconToolButton->setIcon(m_icon);
}


// private slots

void CMiniWidgetPage::SetPageVisible(bool visible)
{
	PageFrame->setVisible(visible);

	if (visible){
		setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	}
	else{
		setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
	}
}


} // namespace iwidgets


