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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iview_CConsoleWidget_included
#define iview_CConsoleWidget_included


// Qt includes
#include <QtGui/QPainter>
#include <QtGui/QWidget>
#include <QtGui/QCursor>
#include <QtGui/QPainter>


// ACF includes
#include "iview/TViewImpl.h"
#include "iview/CDrawBuffer.h"
#include "iview/CColorShema.h"
#include "iview/CCalibratedViewBase.h"


namespace iview
{


class CConsoleWidget:
			public QWidget,
			public iview::TViewImpl<iview::CCalibratedViewBase>
{
public:
	typedef iview::TViewImpl<iview::CCalibratedViewBase> BaseClass;
	typedef QWidget BaseClass2;

	CConsoleWidget(QWidget* parent = NULL);

	// reimplemented (iview::IShapeView)
	virtual i2d::CRect GetClientRect() const;

protected:
	// reimplemented (QWidget)
	virtual void paintEvent(QPaintEvent* event);
	virtual void resizeEvent (QResizeEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);

	// reimplemented (iview::CViewBase)
	virtual void SetMousePointer(MousePointerMode mode);
	void UpdateRectArea(const i2d::CRect& rect);

	// static methods
	int GetKeysState(const QMouseEvent& event);

private:
	QCursor m_mousePointerModes[MPM_LAST + 1];
};


} // namespace iview


#endif // !iview_CConsoleWidget_included


