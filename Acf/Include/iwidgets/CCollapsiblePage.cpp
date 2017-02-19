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


#include <iwidgets/CCollapsiblePage.h>


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#include <QtGui/QScreen>
#endif


namespace iwidgets
{


// public methods

CCollapsiblePage::CCollapsiblePage(QWidget* parentPtr)
	:BaseClass(parentPtr),
	m_pageWidgetPtr(NULL),
	m_iconSize(32, 32)
{
	setupUi(this);

	CollapsiblePageIconToolButton->setHidden(true);

	connect(CollapseButton, SIGNAL(toggled(bool)), this, SLOT(SetPageVisible(bool)));
}


void CCollapsiblePage::SetTitle(const QString& text)
{
	CollapseButton->setText(text);
}


void CCollapsiblePage::SetWidget(QWidget* pageWidgetPtr)
{
	CollapsiblePageFrame->layout()->addWidget(pageWidgetPtr);

	m_pageWidgetPtr = pageWidgetPtr;
}


void CCollapsiblePage::SetIconSize(const QSize& size)
{
	CollapsiblePageIconToolButton->setMinimumSize(size);
	CollapsiblePageIconToolButton->setMaximumSize(size);

	m_iconSize = size;

	CollapsiblePageIconToolButton->setIconSize(m_iconSize);
	CollapsiblePageIconToolButton->setIcon(m_icon);
}


void CCollapsiblePage::SetIcon(const QIcon& icon)
{
	m_icon = icon;

	CollapsiblePageIconToolButton->setVisible(!m_icon.isNull());

	CollapsiblePageIconToolButton->setIcon(m_icon);
}


// private slots

void CCollapsiblePage::SetPageVisible(bool visible)
{
	CollapsiblePageFrame->setVisible(visible);

	if (visible){
		setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	}
	else{
		setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
	}
}


} // namespace iwidgets


