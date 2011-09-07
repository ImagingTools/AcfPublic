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


#ifndef iqt2d_CAnnulusShape_included
#define iqt2d_CAnnulusShape_included


#include "i2d/CAnnulus.h"

#include "iqt2d/TObjectShapeBase.h"
#include "iqt2d/CGripShape.h"


namespace iqt2d
{


class CAnnulusShape: public TObjectShapeBase<QGraphicsPathItem, i2d::CAnnulus>
{
	Q_OBJECT

public:
	typedef TObjectShapeBase<QGraphicsPathItem, i2d::CAnnulus> BaseClass;

	CAnnulusShape(bool isEditable = false, const ISceneProvider* providerPtr = NULL);

protected Q_SLOTS:
	virtual void OnInnerGripPositionChanged(const i2d::CVector2d& point);
	virtual void OnOuterGripPositionChanged(const i2d::CVector2d& point);

protected:
	virtual void CalcVisualization(const i2d::CAnnulus& annulus);

	// reimplemented (iqt2d::TObjectShapeBase)
	void UpdateGraphicsItem(const i2d::CAnnulus& annulus);

private:
	CGripShape m_leftInnerGrip;
	CGripShape m_rightInnerGrip;
	CGripShape m_topInnerGrip;
	CGripShape m_bottomInnerGrip;
	CGripShape m_leftOuterGrip;
	CGripShape m_rightOuterGrip;
	CGripShape m_topOuterGrip;
	CGripShape m_bottomOuterGrip;
};


} // namespace iqt2d


#endif // !iqt2d_CAnnulusShape_included


