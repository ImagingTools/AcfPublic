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


#ifndef iqt_included
#define iqt_included


// Qt includes
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QSize>
#include <QtCore/QPoint>
#include <QtCore/QPointF>
#include <QtCore/QRectF>
#include <QtCore/QLine>
#include <QtCore/QLineF>
#include <QtCore/QFileInfo>
#include <QtCore/QDateTime>

// ACF includes
#include "istd/CIndex2d.h"

#include "i2d/CVector2d.h"
#include "i2d/CRectangle.h"
#include "i2d/CLine2d.h"
#include "i2d/CRect.h"


/**
	This namespace contains standard classes based on Qt.
*/
namespace iqt
{


extern QSize GetQSize(const istd::CIndex2d& size);
extern istd::CIndex2d GetCIndex2d(const QSize& size);
extern QPoint GetQPoint(const istd::CIndex2d& position);
extern istd::CIndex2d GetCIndex2d(const QPoint& position);
extern QRectF GetQRectF(const i2d::CRectangle& rect);
extern i2d::CRectangle GetCRectangle(const QRectF& rect);
extern i2d::CLine2d GetCLine2d(const QLine& line);
extern QLine GetQLine(const i2d::CLine2d& line);
extern i2d::CLine2d GetCLine2d(const QLineF& line);
extern QLineF GetQLineF(const i2d::CLine2d& line);
extern QRect GetQRect(const i2d::CRect& rect);
extern i2d::CRect GetCRect(const QRect& rect);


} // namespace iqt


#endif // !iqt_included


