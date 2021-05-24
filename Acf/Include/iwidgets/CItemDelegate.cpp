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


#include <iwidgets/CItemDelegate.h>


// Qt includes
#include <QtGui/QPainter>


namespace iwidgets
{


// public methods

CItemDelegate::CItemDelegate(int itemHeight, QObject* parent)
	:BaseClass(parent),
	m_itemHeight(itemHeight)
{
}


void CItemDelegate::SetItemHeight(int itemHeight)
{
	m_itemHeight = itemHeight;
}


int CItemDelegate::GetItemHeight() const
{
	return m_itemHeight;
}


// reimplemented (QItemDelegate)

QSize CItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index ) const
{
	QSize size = QItemDelegate::sizeHint(option, index);

	QFontMetrics fontMetrics(option.font);

	int height = qMax(fontMetrics.height(), m_itemHeight);

	size.setHeight(height);

	return size;
}


void CItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QItemDelegate::paint(painter, option, index);

	QRect rect = option.rect;
	painter->setPen(QPen(Qt::darkGray, 0, Qt::SolidLine));
	if (index.column() != 3){
		painter->drawLine(rect.topRight(), rect.bottomRight());
	}

	painter->drawLine(rect.bottomLeft(), rect.bottomRight());
}


} // namespace iwidgets


