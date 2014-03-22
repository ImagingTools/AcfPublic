/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iqt/iqt.h"


// Qt includes
#include <QtCore/QStringList>
#include <QtCore/QDateTime>


namespace iqt
{


QSize GetQSize(const istd::CIndex2d& size)
{
	return QSize(size.GetX(), size.GetY());
}


istd::CIndex2d GetCIndex2d(const QSize& size)
{
	return istd::CIndex2d(size.width(), size.height());
}


QPoint GetQPoint(const istd::CIndex2d& position)
{
	return QPoint(position.GetX(), position.GetY());
}


istd::CIndex2d GetCIndex2d(const QPoint& position)
{
	return istd::CIndex2d(position.x(), position.y());
}


QRectF GetQRectF(const i2d::CRectangle& rect)
{
	return QRectF(rect.GetLeft(), rect.GetTop(), rect.GetWidth(), rect.GetHeight());
}


i2d::CRectangle GetCRectangle(const QRectF& rect)
{
	return i2d::CRectangle(rect.left(), rect.top(), rect.width(), rect.height());
}


i2d::CLine2d GetCLine2d(const QLine& line)
{
	return i2d::CLine2d(line.x1(), line.y1(), line.x2(), line.y2());
}


QLine GetQLine(const i2d::CLine2d& line)
{
	return QLine(
				int(line.GetPoint1().GetX()),
				int(line.GetPoint1().GetY()),
				int(line.GetPoint2().GetX()),
				int(line.GetPoint2().GetY()));
}


i2d::CLine2d GetCLine2d(const QLineF& line)
{
	return i2d::CLine2d(line.x1(), line.y1(), line.x2(), line.y2());
}


QLineF GetQLineF(const i2d::CLine2d& line)
{
	return QLineF(line.GetPoint1().GetX(), line.GetPoint1().GetY(), line.GetPoint2().GetX(), line.GetPoint2().GetY());
}


QRect GetQRect(const i2d::CRect& rect)
{
	return QRect(rect.GetLeft(), rect.GetTop(), rect.GetWidth(), rect.GetHeight());
}


i2d::CRect GetCRect(const QRect& rect)
{
	return i2d::CRect(rect.left(), rect.top(), rect.right() + 1, rect.bottom() + 1);
}


} // namespace iqt

