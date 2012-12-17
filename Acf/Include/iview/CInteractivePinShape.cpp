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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iview/CInteractivePinShape.h"


// ACF includes
#include "imod/IModel.h"

#include "i2d/CPosition2d.h"

#include "iview/IColorSchema.h"
#include "iview/CScreenTransform.h"


namespace iview
{


// constructors

CInteractivePinShape::CInteractivePinShape()
{
}


// reimplemented (iview::ITouchable)

ITouchable::TouchState CInteractivePinShape::IsTouched(istd::CIndex2d position) const
{
	i2d::CRect boundingBox = CInteractivePinShape::CalcBoundingBox();
	if (boundingBox.IsInside(position)){
		if (IsEditablePosition()){
			return TS_TICKER;
		}
		else{
			return TS_INACTIVE;
		}
	}

	return TS_NONE;
}


// reimplemented (imod::IObserver)

bool CInteractivePinShape::OnAttached(imod::IModel* modelPtr)
{
	I_ASSERT(dynamic_cast<i2d::CPosition2d*>(modelPtr) != NULL);

	return BaseClass::OnAttached(modelPtr);
}


// reimplemented (iview::IVisualizable)

void CInteractivePinShape::Draw(QPainter& drawContext) const
{
	I_ASSERT(IsDisplayConnected());

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetModelPtr());
	if (pinPtr != NULL){
		const iview::CScreenTransform& transform = GetLogToScreenTransform();
		const IColorSchema& colorSchema = GetColorSchema();

		istd::CIndex2d sp = transform.GetScreenPosition(pinPtr->GetPosition());

		if (IsSelected()){
			if (IsEditablePosition()){
				colorSchema.DrawTicker(drawContext, sp, IColorSchema::TT_MOVE);
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

bool CInteractivePinShape::OnMouseButton(istd::CIndex2d position, Qt::MouseButton /*buttonType*/, bool downFlag)
{
	I_ASSERT(IsDisplayConnected());

	if (!IsEditablePosition()){
		EndModelChanges();
		return false;
	}

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetModelPtr());
	if (IsDisplayConnected() && (pinPtr != NULL)){
		if (downFlag){
			const IColorSchema& colorSchema = GetColorSchema();
			const iview::CScreenTransform& transform = GetLogToScreenTransform();

			const i2d::CVector2d& cp = pinPtr->GetPosition();
			istd::CIndex2d sp = transform.GetScreenPosition(cp);
			const i2d::CRect& tickerBox = colorSchema.GetTickerBox(IColorSchema::TT_MOVE);
			if (tickerBox.IsInside(position - sp)){
				m_referencePosition = cp - transform.GetClientPosition(position);
				BeginModelChanges();
				return true;
			}
		}
	}

	EndModelChanges();

	return false;
}


bool CInteractivePinShape::OnMouseMove(istd::CIndex2d position)
{
	if (!IsEditablePosition()){
		return false;
	}

	imod::IModel* modelPtr = GetModelPtr();
	if (modelPtr != NULL){
		i2d::CPosition2d& pin = *dynamic_cast<i2d::CPosition2d*>(modelPtr);
		I_ASSERT(&pin != NULL);

		const iview::CScreenTransform& transform = GetLogToScreenTransform();
		
		pin.SetPosition(m_referencePosition + transform.GetClientPosition(position));

		UpdateModelChanges();

		return true;
	}

	return false;
}



// protected methods

// reimplemented (iview::CShapeBase)

i2d::CRect CInteractivePinShape::CalcBoundingBox() const
{
	I_ASSERT(IsDisplayConnected());

	const i2d::CPosition2d* pinPtr = dynamic_cast<const i2d::CPosition2d*>(GetModelPtr());
	if (pinPtr != NULL){
		const iview::CScreenTransform& transform = GetLogToScreenTransform();
		const IColorSchema& colorSchema = GetColorSchema();

		istd::CIndex2d sp = transform.GetScreenPosition(pinPtr->GetPosition());

		IColorSchema::TickerType tickerType;
		if (IsSelected()){
			if (IsEditablePosition()){
				tickerType = IColorSchema::TT_MOVE;
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


// reimplemented (iview::CInteractiveShapeBase)

void CInteractivePinShape::BeginLogDrag(const i2d::CVector2d& reference)
{
	const imod::IModel* modelPtr = GetModelPtr();
	if (modelPtr != NULL){
		const i2d::CPosition2d& pin = *dynamic_cast<const i2d::CPosition2d*>(modelPtr);
		I_ASSERT(&pin != NULL);

		m_referencePosition = pin.GetPosition() - reference;
	}
}


void CInteractivePinShape::SetLogDragPosition(const i2d::CVector2d& position)
{
	if (IsEditablePosition()){
		imod::IModel* modelPtr = GetModelPtr();
		if (modelPtr != NULL){
			BeginModelChanges();

			i2d::CPosition2d& pin = *dynamic_cast<i2d::CPosition2d*>(modelPtr);
			I_ASSERT(&pin != NULL);

			pin.SetPosition(m_referencePosition + position);

			EndModelChanges();
		}
	}
}


} // namespace iview



