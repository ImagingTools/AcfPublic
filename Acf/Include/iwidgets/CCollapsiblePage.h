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


#ifndef iwidgets_CCollapsiblePage_included
#define iwidgets_CCollapsiblePage_included


// ACF includes
#include "GeneratedFiles/iwidgets/ui_CCollapsiblePage.h"


namespace iwidgets
{


class CCollapsiblePage: public QWidget, public Ui::CCollapsiblePage
{
	Q_OBJECT
public:
	typedef QWidget BaseClass;

	CCollapsiblePage(QWidget* parentPtr = NULL);

	void SetTitle(const QString& text);
	void SetWidget(QWidget* pageWidgetPtr);
	void SetIconSize(const QSize& size);
	void SetIcon(const QIcon& icon);

private Q_SLOTS:
	void SetPageVisible(bool visible);

private:
	QIcon m_icon;
	QWidget* m_pageWidgetPtr;
};

} // namespace iwidgets


#endif // !iwidgets_CCollapsiblePage_included


