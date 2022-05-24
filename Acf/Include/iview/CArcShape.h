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


#ifndef iview_CArcShape_included
#define iview_CArcShape_included


// ACF includes
#include <iview/CPinShape.h>


namespace iview
{


class CArcShape: public CPinShape
{

public:
	typedef CPinShape BaseClass;
	typedef CInteractiveShapeBase ShapeBaseClass;

	CArcShape();

	virtual bool IsEditableRadius() const;
	virtual void SetEditableRadius(bool editable = true);
	virtual bool IsEditableStartAngle() const;
	virtual void SetEditableStartAngle(bool editable = true);
	virtual bool IsEditableAngleWidth() const;
	virtual void SetEditableAngleWidth(bool editable = true);
	virtual bool IsCenterVisible() const;
	virtual void SetCenterVisible(bool state = true);

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (imod::IObserver)
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask);

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

protected:
	// reimplemented (iview::CShapeBase)
	virtual i2d::CRect CalcBoundingBox() const;

	bool m_isEditableRadius;
	bool m_isCenterVisible;
	bool m_isEditableStartAngle;
	bool m_isEditableAngleWidth;

	enum EditMode
	{
		EM_NONE,
		EM_RADIUS,
		EM_STARTANGLE,
		EM_ANGLEWIDTH
	};

	int m_editMode;
};


} // namespace iview


#endif // !iview_CArcShape_included
