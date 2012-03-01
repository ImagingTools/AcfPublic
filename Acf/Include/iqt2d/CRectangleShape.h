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


#ifndef iqt2d_CRectangleShape_included
#define iqt2d_CRectangleShape_included


// Qt includes
#include <QtGui/QGraphicsRectItem>

// ACF includes
#include "i2d/CRectangle.h"

#include "iqt2d/TObjectShapeBase.h"
#include "iqt2d/CGripShape.h"


namespace iqt2d
{


class CRectangleShape: public TObjectShapeBase<QGraphicsPathItem, i2d::CRectangle>
{
	Q_OBJECT

public:
	typedef TObjectShapeBase<QGraphicsPathItem, i2d::CRectangle> BaseClass;

	CRectangleShape(bool isEditable = false, const ISceneProvider* providerPtr = NULL);

protected Q_SLOTS:
	virtual void OnTopLeftChanged(const i2d::CVector2d& point);
	virtual void OnTopRightChanged(const i2d::CVector2d& point);
	virtual void OnBottomLeftChanged(const i2d::CVector2d& point);
	virtual void OnBottomRightChanged(const i2d::CVector2d& point);

protected:
	// reimplemented (iqt2d::TObjectShapeBase)
	void UpdateGraphicsItem(const i2d::CRectangle& rect);

private:
	CGripShape m_topLeftGrip;
	CGripShape m_topRightGrip;
	CGripShape m_bottomLeftGrip;
	CGripShape m_bottomRightGrip;
};


} // namespace iqt2d


#endif // !iqt2d_CRectangleShape_included


