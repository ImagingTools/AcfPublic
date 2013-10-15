/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "iview/CInteractiveShapeBase.h"


// Qt includes
#include <QtGui/QPainter>


// ACF includes
#include "istd/IChangeable.h"
#include "iqt/iqt.h"

#include "iview/ISelectable.h"
#include "iview/IViewLayer.h"


namespace iview
{


CInteractiveShapeBase::CInteractiveShapeBase()
{
	m_isSelected = false;
	m_isEditablePosition = true;

	AssignToLayer(IViewLayer::LT_ACTIVE);
}


CInteractiveShapeBase::CInteractiveShapeBase(const CInteractiveShapeBase& shape)
	:BaseClass(shape)
{
}


CInteractiveShapeBase::~CInteractiveShapeBase()
{
	DisconnectDisplay();
}


// reimplemented (iview::IInteractiveShape)

bool CInteractiveShapeBase::IsSelected() const
{
	return m_isSelected;
}


void CInteractiveShapeBase::SetSelected(bool selectFlag)
{
	if (m_isSelected != selectFlag){
		m_isSelected = selectFlag;

		InvalidateBoundingBox();

		ISelectable* observerPtr = dynamic_cast<ISelectable*>(GetDisplayPtr());
		if (observerPtr != NULL){
			observerPtr->OnShapeSelected(*this, selectFlag);
		}
	}
}


// reimplemented (iview::IMouseActionObserver)

bool CInteractiveShapeBase::OnMouseButton(istd::CIndex2d /*position*/, Qt::MouseButton buttonType, bool downFlag)
{
	if (buttonType == Qt::LeftButton){
		if (downFlag){
			istd::IChangeable* objectPtr = dynamic_cast<istd::IChangeable*>(GetModelPtr());
			m_changeNotifier.SetPtr(objectPtr);
		}
		else{
			m_changeNotifier.Reset();
		}
	}

	return false;
}


bool CInteractiveShapeBase::OnMouseMove(istd::CIndex2d)
{
	return false;
}


// reimplemented (imod::IObserver)

bool CInteractiveShapeBase::OnAttached(imod::IModel* modelPtr)
{
	if (BaseClass::OnAttached(modelPtr)){
		Invalidate(CS_CONSOLE);

		return true;
	}

	return false;
}


bool CInteractiveShapeBase::OnDetached(imod::IModel* modelPtr)
{
	Invalidate(CS_CONSOLE);

	return BaseClass::OnDetached(modelPtr);
}


// reimplemented (iview::IDraggable)

bool CInteractiveShapeBase::IsDraggable() const
{
	return m_isEditablePosition;
}


void CInteractiveShapeBase::BeginDrag(const istd::CIndex2d& position)
{
	BeginLogDrag(GetLogPosition(position));
}


void CInteractiveShapeBase::SetDragPosition(const istd::CIndex2d& position)
{
	istd::IChangeable* objectPtr = dynamic_cast<istd::IChangeable*>(GetModelPtr());
	m_changeNotifier.SetPtr(objectPtr);

	SetLogDragPosition(GetLogPosition(position));

	Invalidate(CS_CONSOLE);
}


void CInteractiveShapeBase::EndDrag()
{
	m_changeNotifier.Reset();
}


// protected methods

void CInteractiveShapeBase::BeginModelChanges()
{
	ISelectable* controllerPtr = dynamic_cast<ISelectable*>(GetDisplayPtr());
	if (controllerPtr != NULL){
		controllerPtr->OnShapeFocused(this);
	}
}


void CInteractiveShapeBase::EndModelChanges()
{
	UpdateModelChanges();

	ISelectable* controllerPtr = dynamic_cast<ISelectable*>(GetDisplayPtr());
	if (controllerPtr != NULL){
		controllerPtr->OnShapeDefocused(this);
	}
}


void CInteractiveShapeBase::UpdateModelChanges()
{
	istd::IChangeable* objectPtr = dynamic_cast<istd::IChangeable*>(GetModelPtr());

	istd::CChangeNotifier changePtr(objectPtr, istd::IChangeable::CF_MODEL);

	Invalidate(CS_CONSOLE);
}


void CInteractiveShapeBase::DrawText(QPainter& drawContext, istd::CIndex2d point, const QString& text) const
{
	QFontMetrics metrics(drawContext.font());

	QRect textRect(iqt::GetQPoint(point), metrics.size(0, text));

	drawContext.drawText(textRect, Qt::AlignLeft | Qt::AlignBottom, text);
}


} // namespace iview


