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


#ifndef iwidgets_CSimpleGuiContainerDelegate_included
#define iwidgets_CSimpleGuiContainerDelegate_included


// ACF includes
#include <iwidgets/IMultiPageWidgetDelegate.h>


namespace iwidgets
{


/**
	Implementation of the IMultiPageWidgetDelegate interface for a simple container of widgets.
*/
class CSimpleGuiContainerDelegate: virtual public IMultiPageWidgetDelegate
{
public:
	CSimpleGuiContainerDelegate();

	// reimplemented (iwidgets::IMultiPageWidgetDelegate)
	virtual QWidget* CreateContainerWidget(
				QWidget* parentWidgetPtr,
				int containerGuiFlags = CGF_NONE,
				int orientation = Qt::Horizontal);
	virtual bool ConnectPageIndexListener(
				QWidget& containerWidget,
				QObject* receiverPtr,
				const char* receiverSlotName);
	virtual bool SetPageHeaderPosition(QWidget& containerWidget, PageHeaderPosition pageHeaderPosition);
	virtual int InsertPage(
				QWidget& containerWidget,
				QWidget* pageWidgetPtr,
				const QString& pageTitle,
				int pageIndex = -1);
	virtual void RemovePage(QWidget& containerWidget, int pageIndex);
	virtual void ResetPages(QWidget& containerWidget);
	virtual int GetPagesCount(const QWidget& containerWidget) const; 
	virtual QWidget* GetPageWidgetPtr(const QWidget& containerWidget, int pageIndex) const; 
	virtual int GetCurrentPage(const QWidget& containerWidget) const;
	virtual bool SetCurrentPage(QWidget& containerWidget, int pageIndex);
	virtual QString GetPageTitle(const QWidget& containerWidget, int pageIndex) const;
	virtual void SetPageTitle(QWidget& containerWidget, int pageIndex, const QString& pageTitle);
	virtual QIcon GetPageIcon(const QWidget& containerWidget, int pageIndex) const;
	virtual void SetPageIcon(QWidget& containerWidget, int pageIndex, const QIcon& pageIcon);
	virtual QString GetPageToolTip(const QWidget& containerWidget, int pageIndex) const;
	virtual void SetPageToolTip(QWidget& containerWidget, int pageIndex, const QString& pageToolTip);
	virtual bool IsPageEnabled(const QWidget& containerWidget, int pageIndex) const;
	virtual bool SetPageEnabled(QWidget& containerWidget, int pageIndex, bool isPageEnabled = true);
	virtual bool IsPageVisible(const QWidget& containerWidget, int pageIndex) const;
	virtual bool SetPageVisible(QWidget& containerWidget, int pageIndex, bool isPageVisible = true);
	virtual QSize GetPageIconSize(const QWidget& containerWidget) const;
	virtual bool SetPageIconSize(QWidget& containerWidget, const QSize& pageIconSize);

private:
	QSize m_iconSize;
	int m_containerGuiFlags;
	int m_orientation;
};


} // namespace iwidgets


#endif // !iwidgets_CSimpleGuiContainerDelegate_included


