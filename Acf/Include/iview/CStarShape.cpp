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


#include <iview/CStarShape.h>


// ACF includes
#include <imod/IModel.h>
#include <iview/IColorSchema.h>
#include <iview/CScreenTransform.h>


namespace iview
{



// reimplemented (iview::IVisualizable)

void CStarShape::Draw(QPainter& drawContext) const
{
	Q_ASSERT(IsDisplayConnected());

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetObservedModel());
	if (pinPtr != NULL){
		istd::CIndex2d sp = GetScreenPosition(pinPtr->GetPosition()).ToIndex2d();

		drawContext.setPen(QPen(Qt::green, 3));

		drawContext.drawLine(sp.GetX() - 5, sp.GetY() - 5, sp.GetX() + 5, sp.GetY() + 5);
		drawContext.drawLine(sp.GetX() + 5, sp.GetY() - 5, sp.GetX() - 5, sp.GetY() + 5);
	}
}



// protected methods

// reimplemented (iview::CShapeBase)

i2d::CRect CStarShape::CalcBoundingBox() const
{
	Q_ASSERT(IsDisplayConnected());

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetObservedModel());
	if (pinPtr != NULL){
		istd::CIndex2d sp = GetScreenPosition(pinPtr->GetPosition()).ToIndex2d();

		return i2d::CRect(sp.GetX() - 5, sp.GetY() - 5, sp.GetX() + 5, sp.GetY() + 5);
	}

	return i2d::CRect::GetEmpty();
}


} // namespace iview



