/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_CCircleShape_included
#define iqt2d_CCircleShape_included


#include "i2d/CCircle.h"

#include "iqt2d/TObjectShapeBase.h"
#include "iqt2d/CGripShape.h"


namespace iqt2d
{


class CCircleShape: public TObjectShapeBase<QGraphicsEllipseItem, i2d::CCircle>
{
	Q_OBJECT

public:
	typedef TObjectShapeBase<QGraphicsEllipseItem, i2d::CCircle> BaseClass;

	CCircleShape(bool isEditable = false, const ISceneProvider* providerPtr = NULL);

protected slots:
	virtual void OnGripPositionChanged(const i2d::CVector2d& point);

private:
	// reimplemented (iqt2d::TObjectShapeBase)
	void UpdateGraphicsItem(const i2d::CCircle& circle);

private:
	CGripShape m_leftGrip;
	CGripShape m_rightGrip;
	CGripShape m_topGrip;
	CGripShape m_bottomGrip;
};


} // namespace iqt2d


#endif // !iqt2d_CCircleShape_included


