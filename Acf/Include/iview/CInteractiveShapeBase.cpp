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


#include "iview/CInteractiveShapeBase.h"


// Qt includes
#include <QtGui/QPainter>


// ACF includes
#include "istd/IChangeable.h"
#include "istd/TChangeNotifier.h"
#include "iqt/iqt.h"

#include "iview/ISelectable.h"


namespace iview
{


CInteractiveShapeBase::CInteractiveShapeBase()
{
	m_isSelected = false;
	m_isEditablePosition = true;
}


CInteractiveShapeBase::CInteractiveShapeBase(const CInteractiveShapeBase& /*shape*/)
{
}


CInteractiveShapeBase::~CInteractiveShapeBase()
{
	DisconnectDisplay();

	DisconnectFromModel();
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

bool CInteractiveShapeBase::OnMouseButton(istd::CIndex2d /*position*/, Qt::MouseButton /*buttonType*/, bool /*downFlag*/)
{
	return false;
}


bool CInteractiveShapeBase::OnMouseMove(istd::CIndex2d)
{
	return false;
}


// reimplemented (imod::IObserver)

bool CInteractiveShapeBase::OnAttached(imod::IModel* modelPtr)
{
	if (BaseClass3::OnAttached(modelPtr)){
		Invalidate(CS_CONSOLE);

		return true;
	}

	return false;
}


bool CInteractiveShapeBase::OnDetached(imod::IModel* modelPtr)
{
	Invalidate(CS_CONSOLE);

	return BaseClass3::OnDetached(modelPtr);
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
	istd::IChangeable* objectPtr = dynamic_cast<istd::IChangeable*>(GetShapeModelPtr());

	istd::CChangeNotifier changePtr(objectPtr, istd::IChangeable::CF_MODEL);
}


void CInteractiveShapeBase::DrawText(QPainter& drawContext, istd::CIndex2d point, const QString& text) const
{
	QFontMetrics metrics(drawContext.font());

	QString qText = text;

	QRect textRect(iqt::GetQPoint(point), metrics.size(0, qText));

	drawContext.drawText(textRect, Qt::AlignLeft | Qt::AlignBottom, qText);
}


} // namespace iview


