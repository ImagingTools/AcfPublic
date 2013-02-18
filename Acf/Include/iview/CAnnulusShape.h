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


#ifndef iview_CAnnulusShape_included
#define iview_CAnnulusShape_included


#include "iview/CPinShape.h"


namespace iview
{


class CAnnulusShape: public CPinShape
{
public:
	typedef CPinShape BaseClass;

	CAnnulusShape();

	virtual bool IsEditableRadiusInner() const;
	virtual void SetEditableRadiusInner(bool editable = true);
	virtual bool IsEditableRadiusOuter() const;
	virtual void SetEditableRadiusOuter(bool editable = true);

	virtual bool IsEditableRadius() const;
	virtual void SetEditableRadius(bool editable = true);

	virtual bool IsCenterVisible() const;
	virtual void SetCenterVisible(bool state = true);

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

protected:
	virtual void DrawAnnulus(QPainter& painter, istd::CIndex2d center, int minRadius1, int maxRadius1, bool fillFlag = true) const;

	// reimplemented (iview::CShapeBase)
	virtual i2d::CRect CalcBoundingBox() const;

	bool m_isCenterVisible;

	bool m_editRadiusMode;
	bool m_isEditableRadius;

	// true when the outer radius is being edited
	bool m_editRadius2Mode;
	// true when the outer radius is editable
	bool m_isEditableRadius2;
};


} // namespace iview


#endif // !iview_CAnnulusShape_included



