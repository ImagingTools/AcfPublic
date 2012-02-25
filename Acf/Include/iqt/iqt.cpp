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


#include "iqt/iqt.h"


// Qt includes
#include <QStringList>
#include <QDateTime>


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


QPointF GetQPointF(const i2d::CVector2d& position)
{
	return QPointF(position.GetX(), position.GetY());
}


i2d::CVector2d GetCVector2d(const QPointF& position)
{
	return i2d::CVector2d(position.x(), position.y());
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


isys::CFileInfo GetCFileInfo(const QFileInfo& fileInfo)
{
	isys::CSimpleDateTime modificationTime;

	modificationTime.FromCTime(fileInfo.lastModified().toTime_t());

	return isys::CFileInfo(
				fileInfo.absoluteFilePath(),
				fileInfo.permissions(),
				modificationTime);
}


QFileInfo GetQFileInfo(const isys::CFileInfo& fileInfo)
{
	return QFileInfo(fileInfo.GetFilePath());
}


QDateTime GetQDateTime(const isys::IDateTime& dateTime)
{
	QDateTime qtDateTime;

	QDate date(dateTime.GetComponent(isys::IDateTime::TC_YEAR),
				dateTime.GetComponent(isys::IDateTime::TC_MONTH),
				dateTime.GetComponent(isys::IDateTime::TC_DAY));

	QTime time(dateTime.GetComponent(isys::IDateTime::TC_HOUR),
				dateTime.GetComponent(isys::IDateTime::TC_MINUTE),
				dateTime.GetComponent(isys::IDateTime::TC_SECOND),
				dateTime.GetComponent(isys::IDateTime::TC_MILLISECOND));
	
	qtDateTime.setDate(date);
	qtDateTime.setTime(time);

	return qtDateTime;
}


isys::CSimpleDateTime GetCSimpleDateTime(const QDateTime& dateTime)
{
	isys::CSimpleDateTime simpleDateTime;

	simpleDateTime.FromCTime(dateTime.toTime_t());

	return simpleDateTime;
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

