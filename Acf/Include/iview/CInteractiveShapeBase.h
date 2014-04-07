/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iview_CInteractiveShapeBase_included
#define iview_CInteractiveShapeBase_included


// ACF includes
#include "istd/TChangeNotifier.h"

#include "imod/IModel.h"

#include "iview/IInteractiveShape.h"
#include "iview/IDraggable.h"
#include "iview/ISelectable.h"
#include "iview/CShapeBase.h"

// Qt includes
#include <QtGui/QPen>


namespace iview
{


class CInteractiveShapeBase:
			public CShapeBase,
			virtual public IInteractiveShape,
			virtual public IDraggable
{
public:
	typedef CShapeBase BaseClass;

	CInteractiveShapeBase();
	CInteractiveShapeBase(const CInteractiveShapeBase& shape);

	virtual ~CInteractiveShapeBase();

	virtual bool IsEditablePosition() const;
	virtual void SetEditablePosition(bool state = true);

	// reimplemented (iview::IInteractiveShape)
	virtual bool IsSelected() const;
	virtual void SetSelected(bool selectFlag = true);
	virtual bool IsActionAvailable(ShapeAction action) const;
	virtual bool ExecuteAction(ShapeAction action);

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::IDraggable)
	virtual bool IsDraggable() const;
	virtual void BeginDrag(const istd::CIndex2d& position);
	virtual void SetDragPosition(const istd::CIndex2d& position);
	virtual void EndDrag();

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);

protected:
	void BeginTickerDrag();
	void EndTickerDrag();
	void UpdateModelChanges();

	/**
		Get actual keys state.
		Note, that display must be connected to use this method.
	*/
	int GetKeysState() const;

	/**
		Get actual edit mode.
		Note, that display must be connected to use this method.
	*/
	int GetEditMode() const;

	/**
		Draw text on a given position.
	*/
	void DrawText(QPainter& drawContext, istd::CIndex2d point, const QString& text) const;

	// reimplemented (iview::CShapeBase)
	virtual int GetDisplayChangesMask();

	// abstract methods
	virtual void BeginLogDrag(const i2d::CVector2d& reference) = 0;
	virtual void SetLogDragPosition(const i2d::CVector2d& position) = 0;

private:
	bool m_isSelected;
	bool m_isEditablePosition;

	istd::TChangeNotifier<istd::IChangeable> m_changeNotifier;
};


// inline methods

inline bool CInteractiveShapeBase::IsEditablePosition() const
{
	return m_isEditablePosition;
}


inline void CInteractiveShapeBase::SetEditablePosition(bool state)
{
	m_isEditablePosition = state;
}


// protected methods

inline int CInteractiveShapeBase::GetKeysState() const
{
	ISelectable* selectablePtr = dynamic_cast<ISelectable*>(GetDisplayPtr());
	if (selectablePtr != NULL){
		return selectablePtr->GetKeysState();
	}
	else{
		return 0;
	}
}


inline int CInteractiveShapeBase::GetEditMode() const
{
	ISelectable* selectablePtr = dynamic_cast<ISelectable*>(GetDisplayPtr());
	if (selectablePtr != NULL){
		return selectablePtr->GetEditMode();
	}
	else{
		return ISelectable::EM_NONE;
	}
}


// reimplemented (iview::IInteractiveShape)

inline bool CInteractiveShapeBase::IsActionAvailable(IInteractiveShape::ShapeAction /*action*/) const
{
	return false;
}


inline bool CInteractiveShapeBase::ExecuteAction(IInteractiveShape::ShapeAction /*action*/)
{
	return false;
}


// reimplemented (iview::CShapeBase)

inline int CInteractiveShapeBase::GetDisplayChangesMask()
{
	return BaseClass::GetDisplayChangesMask() | CF_EDIT_MODE;
}


} // namespace iview


#endif // !iview_CInteractiveShapeBase_included


