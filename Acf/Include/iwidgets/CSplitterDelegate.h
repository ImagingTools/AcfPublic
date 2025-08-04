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


#ifndef iwidgets_CSplitterDelegate_included
#define iwidgets_CSplitterDelegate_included


// ACF includes
#include <iwidgets/IMultiPageWidgetDelegate.h>


namespace iwidgets
{


/**
	Implementation of the IMultiPageWidgetDelegate interface for QSplitter.
*/
class CSplitterDelegate: virtual public IMultiPageWidgetDelegate
{
public:
	// reimplemented (iwidgets::IMultiPageWidgetDelegate)
	virtual QWidget* CreateContainerWidget(
				QWidget* parentWidgetPtr,
				int containerGuiFlags = CGF_NONE,
				int orientation = Qt::Horizontal) override;
	virtual bool ConnectPageIndexListener(
				QWidget& containerWidget,
				QObject* receiverPtr,
				const char* receiverSlotName) override;
	virtual bool SetPageHeaderPosition(QWidget& containerWidget, PageHeaderPosition pageHeaderPosition) override;
	virtual int InsertPage(
		QWidget& containerWidget,
		QWidget* pageWidgetPtr,
		const QString& pageTitle,
		int pageIndex = -1) override;
	virtual void RemovePage(QWidget& containerWidget, int pageIndex) override;
	virtual void ResetPages(QWidget& containerWidget) override;
	virtual int GetPagesCount(const QWidget& containerWidget) const override; 
	virtual QWidget* GetPageWidgetPtr(const QWidget& containerWidget, int pageIndex) const override; 
	virtual int GetCurrentPage(const QWidget& containerWidget) const override;
	virtual bool SetCurrentPage(QWidget& containerWidget, int pageIndex) override;
	virtual QString GetPageTitle(const QWidget& containerWidget, int pageIndex) const override;
	virtual void SetPageTitle(QWidget& containerWidget, int pageIndex, const QString& pageTitle) override;
	virtual QIcon GetPageIcon(const QWidget& containerWidget, int pageIndex) const override;
	virtual void SetPageIcon(QWidget& containerWidget, int pageIndex, const QIcon& pageIcon) override;
	virtual QString GetPageToolTip(const QWidget& containerWidget, int pageIndex) const override;
	virtual void SetPageToolTip(QWidget& containerWidget, int pageIndex, const QString& pageToolTip) override;
	virtual bool IsPageEnabled(const QWidget& containerWidget, int pageIndex) const override;
	virtual bool SetPageEnabled(QWidget& containerWidget, int pageIndex, bool isPageEnabled = true) override;
	virtual bool IsPageVisible(const QWidget& containerWidget, int pageIndex) const override;
	virtual bool SetPageVisible(QWidget& containerWidget, int pageIndex, bool isPageVisible = true) override;
	virtual QSize GetPageIconSize(const QWidget& containerWidget) const override;
	virtual bool SetPageIconSize(QWidget& containerWidget, const QSize& pageIconSize) override;

private:
	QSize m_iconSize;
};


} // namespace iwidgets


#endif // !iwidgets_CSplitterDelegate_included


