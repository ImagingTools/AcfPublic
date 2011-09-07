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


#ifndef iqt2d_CAnnulusSegmentShape_included
#define iqt2d_CAnnulusSegmentShape_included


#include "iqt2d/CAnnulusShape.h"
#include "iqt2d/CGripShape.h"


namespace iqt2d
{


class CAnnulusSegmentShape: public CAnnulusShape
{
	Q_OBJECT

public:
	typedef CAnnulusShape BaseClass;

	CAnnulusSegmentShape(bool isEditable = false, const ISceneProvider* providerPtr = NULL);

protected Q_SLOTS:
	virtual void OnAngleGripPositionChanged(const i2d::CVector2d& point);

protected:
	// reimplemented (iqt2d::CAnnulusShape)
	virtual void CalcVisualization(const i2d::CAnnulus& annulus);

	// reimplemented (iqt2d::TObjectShapeBase)
	void UpdateGraphicsItem(const i2d::CAnnulus& circle);

private:
	CGripShape m_beginAngleGrip;
	CGripShape m_endAngleGrip;
};


} // namespace iqt2d


#endif // !iqt2d_CAnnulusSegmentShape_included


