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


#include "iqt2d/CRectangleShape.h"


// ACF includes
#include "istd/TChangeNotifier.h"


namespace iqt2d
{


// public methods

CRectangleShape::CRectangleShape(bool isEditable, const ISceneProvider* providerPtr)
:	BaseClass(isEditable, providerPtr),
	m_topLeftGrip(this, providerPtr),
	m_topRightGrip(this, providerPtr),
	m_bottomLeftGrip(this, providerPtr),
	m_bottomRightGrip(this, providerPtr)
{
	connect(&m_topLeftGrip, SIGNAL(PositionChanged(const i2d::CVector2d&)), this, SLOT(OnTopLeftChanged(const i2d::CVector2d&)));
	connect(&m_topRightGrip, SIGNAL(PositionChanged(const i2d::CVector2d&)), this, SLOT(OnTopRightChanged(const i2d::CVector2d&)));
	connect(&m_bottomLeftGrip, SIGNAL(PositionChanged(const i2d::CVector2d&)), this, SLOT(OnBottomLeftChanged(const i2d::CVector2d&)));
	connect(&m_bottomRightGrip, SIGNAL(PositionChanged(const i2d::CVector2d&)), this, SLOT(OnBottomRightChanged(const i2d::CVector2d&)));
	
	m_bottomLeftGrip.SetLabelPosition(CGripShape::LabelBottom);
	m_bottomRightGrip.SetLabelPosition(CGripShape::LabelBottom);

	if (!isEditable){
		m_topLeftGrip.setParentItem(NULL);
		m_topRightGrip.setParentItem(NULL);
		m_bottomLeftGrip.setParentItem(NULL);
		m_bottomRightGrip.setParentItem(NULL);
	}
}


// protected slots

void CRectangleShape::OnTopLeftChanged(const i2d::CVector2d& point)
{
	i2d::CRectangle* rectPtr = GetObjectPtr();
	if (rectPtr != NULL){
		rectPtr->SetTopLeft(point);
	}

}


void CRectangleShape::OnTopRightChanged(const i2d::CVector2d& point)
{
	i2d::CRectangle* rectPtr = GetObjectPtr();
	if (rectPtr != NULL){
		rectPtr->SetTopRight(point);
	}
}


void CRectangleShape::OnBottomLeftChanged(const i2d::CVector2d& point)
{
	i2d::CRectangle* rectPtr = GetObjectPtr();
	if (rectPtr != NULL){
		rectPtr->SetBottomLeft(point);
	}
}


void CRectangleShape::OnBottomRightChanged(const i2d::CVector2d& point)
{
	i2d::CRectangle* rectPtr = GetObjectPtr();
	if (rectPtr != NULL){
		rectPtr->SetBottomRight(point);
	}
}


// protected methods

// reimplemented (iqt2d::TObjectShapeBase)

void CRectangleShape::UpdateGraphicsItem(const i2d::CRectangle& rect)
{
	m_topLeftGrip.SetPosition(rect.GetTopLeft());
	m_topRightGrip.SetPosition(rect.GetTopRight());
	m_bottomLeftGrip.SetPosition(rect.GetBottomLeft());
	m_bottomRightGrip.SetPosition(rect.GetBottomRight());

	QPainterPath path;

	path.moveTo(GetLocalFromPos(rect.GetTopLeft()));
	path.lineTo(GetLocalFromPos(rect.GetTopRight()));
	path.lineTo(GetLocalFromPos(rect.GetBottomRight()));
	path.lineTo(GetLocalFromPos(rect.GetBottomLeft()));
	path.lineTo(GetLocalFromPos(rect.GetTopLeft()));

	setPath(path);
}


} // namespace iqt2d


