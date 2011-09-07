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


#ifndef iqt2d_CLine2dShape_included
#define iqt2d_CLine2dShape_included


#include "i2d/CLine2d.h"

#include "iqt2d/TObjectShapeBase.h"
#include "iqt2d/CGripShape.h"


namespace iqt2d
{


class CLine2dShape: public TObjectShapeBase<QGraphicsLineItem, i2d::CLine2d>
{
	Q_OBJECT
public:
	typedef TObjectShapeBase<QGraphicsLineItem, i2d::CLine2d> BaseClass;

	CLine2dShape(bool isEditable = false, const ISceneProvider* providerPtr = NULL);

protected Q_SLOTS:
	virtual void OnPosition1Changed(const i2d::CVector2d& point);
	virtual void OnPosition2Changed(const i2d::CVector2d& point);

protected:
	// reimplemented (iqt2d::TObjectShapeBase)
	void UpdateGraphicsItem(const i2d::CLine2d& line);

private:
	CGripShape m_pointGrip1;
	CGripShape m_pointGrip2;
};


} // namespace iqt2d


#endif // !iqt2d_CLine2dShape_included


