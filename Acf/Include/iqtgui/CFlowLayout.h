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


#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H


#include <QtCore/QRect>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidgetItem>
#include <QtWidgets/QStyle>
#else
#include <QtGui/QLayout>
#include <QtGui/QWidgetItem>
#include <QtGui/QStyle>
#endif


namespace iqtgui
{


class CFlowLayout : public QLayout
{
public:
	CFlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);
	CFlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
	~CFlowLayout();

	void addItem(QLayoutItem *item);
	int horizontalSpacing() const;
	int verticalSpacing() const;
	Qt::Orientations expandingDirections() const;
	bool hasHeightForWidth() const;
	int heightForWidth(int) const;
	int count() const;
	QLayoutItem *itemAt(int index) const;
	QSize minimumSize() const;
	void setGeometry(const QRect &rect);
	QSize sizeHint() const;
	QLayoutItem *takeAt(int index);

private:
	int doLayout(const QRect &rect, bool testOnly) const;
	int smartSpacing(QStyle::PixelMetric pm) const;

	QList<QLayoutItem *> itemList;
	int m_hSpace;
	int m_vSpace;
};


}


#endif
