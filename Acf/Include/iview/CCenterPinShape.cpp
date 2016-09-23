/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <iview/CCenterPinShape.h>


// ACF includes
#include <imod/IModel.h>

#include <i2d/CPosition2d.h>

#include <iview/IColorSchema.h>
#include <iview/CScreenTransform.h>


namespace iview
{


CCenterPinShape::CCenterPinShape()
	:m_referencePosition(0.0, 0.0)

{
}


// reimplemented (iview::IVisualizable)

void CCenterPinShape::Draw(QPainter& drawContext) const
{
	Q_ASSERT(IsDisplayConnected());

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetObservedModel());
	if (pinPtr != NULL){
		const IColorSchema& colorSchema = GetColorSchema();

		istd::CIndex2d sp = GetScreenPosition(pinPtr->GetPosition()).ToIndex2d();

		if (IsSelected()){
			if (IsEditablePosition()){
				colorSchema.DrawTicker(drawContext, sp, IColorSchema::TT_MOVE_CENTER);
			}
			else{
				colorSchema.DrawTicker(drawContext, sp, IColorSchema::TT_SELECTED_INACTIVE);
			}
		}
		else{
			colorSchema.DrawTicker(drawContext, sp, IColorSchema::TT_INACTIVE);
		}
	}
}


// reimplemented (iview::IMouseActionObserver)

bool CCenterPinShape::OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag)
{
	Q_ASSERT(IsDisplayConnected());

	ShapeBaseClass::OnMouseButton(position, buttonType, downFlag);

	if (!IsEditablePosition()){
		EndTickerDrag();

		return false;
	}

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetObservedModel());
	if (IsDisplayConnected() && (pinPtr != NULL)){
		if (downFlag){
			const IColorSchema& colorSchema = GetColorSchema();

			const i2d::CVector2d& cp = pinPtr->GetPosition();
			istd::CIndex2d sp = GetScreenPosition(cp).ToIndex2d();
			const i2d::CRect& tickerBox = colorSchema.GetTickerBox(IColorSchema::TT_MOVE_CENTER);
			if (tickerBox.IsInside(position - sp)){
				m_referencePosition = cp - GetLogPosition(position);

				BeginTickerDrag();

				return true;
			}
		}
	}

	EndTickerDrag();

	return false;
}


bool CCenterPinShape::OnMouseMove(istd::CIndex2d position)
{
	if (!IsEditablePosition()){
		return false;
	}

	imod::IModel* modelPtr = GetObservedModel();
	if (modelPtr != NULL){
		i2d::CPosition2d& pin = *dynamic_cast<i2d::CPosition2d*>(modelPtr);
		Q_ASSERT(&pin != NULL);

		pin.SetPosition(m_referencePosition + GetLogPosition(position));

		UpdateModelChanges();

		return true;
	}

	return false;
}


// protected methods

// reimplemented (iview::CShapeBase)

i2d::CRect CCenterPinShape::CalcBoundingBox() const
{
	Q_ASSERT(IsDisplayConnected());

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetObservedModel());
	if (pinPtr != NULL){
		const IColorSchema& colorSchema = GetColorSchema();

		istd::CIndex2d sp = GetScreenPosition(pinPtr->GetPosition()).ToIndex2d();

		IColorSchema::TickerType tickerType;
		if (IsSelected()){
			if (IsEditablePosition()){
				tickerType = IColorSchema::TT_MOVE_CENTER;
			}
			else{
				tickerType = IColorSchema::TT_SELECTED_INACTIVE;
			}
		}
		else{
			tickerType = IColorSchema::TT_INACTIVE;
		}

		const i2d::CRect& tickerBox = colorSchema.GetTickerBox(tickerType);

		return tickerBox.GetTranslated(sp);
	}

	return i2d::CRect::GetEmpty();
}


} // namespace iview



