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


#ifndef iview_CPolygonCalibrationShape_included
#define iview_CPolygonCalibrationShape_included


// STL includes
#include <vector>


// ACF includes  
#include "i2d/CVector2d.h"

#include "iview/CTransformableRectangleCalibrationShape.h"


namespace iview
{


// TODO: Redesign it to ACF transformation concept.
class CPolygonCalibrationShape: public CTransformableRectangleCalibrationShape
{
public:
	typedef CTransformableRectangleCalibrationShape BaseClass;

	CPolygonCalibrationShape();

	virtual bool IsFirstVisible() const;
	virtual void SetFirstVisible(bool state = true);

	/**
		Check if in all edit modes this shape is able to be draged.
		Normally it is possible to drag this object only in EM_NONE mode.
	*/
	virtual bool IsAlwaysMovable() const;
	
	/**
		Set flag if in all edit modes is this shape draggable.
		\sa IsAlwaysMovable()
	*/
	virtual void SetAlwaysMovable(bool state = true);

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::IDraggable)
	virtual bool IsDraggable() const;

protected:
	virtual i2d::CVector2d GetSegmentMiddle(int index) const;
	virtual void DrawCurve(QPainter& drawContext) const;
	virtual void DrawArea(QPainter& drawContext) const;
	virtual void DrawSelectionElements(QPainter& drawContext) const;
	virtual bool IsTickerTouched(istd::CIndex2d position) const;
	virtual bool IsCurveTouched(istd::CIndex2d position) const;

	// reimplemented (iview::CInteractiveTransformableRectangle)
	virtual void EnsureValidNodes() const;

	// reimplemented (iview::CInteractiveShapeBase)
	virtual void CalcBoundingBox(i2d::CRect& result) const;
	virtual void BeginLogDrag(const i2d::CVector2d& reference);
	virtual void SetLogDragPosition(const i2d::CVector2d& position);

	i2d::CVector2d m_referencePosition;
	int m_referenceIndex;
	std::vector<i2d::CVector2d> m_references;

	i2d::CVector2d m_castAxis;
	mutable i2d::CAffine2d m_castTransform;

private:
	bool m_isFirstVisible;
	bool m_isAlwaysDraggable;

	mutable QPolygon m_screenPoints;
};


// inline methods

inline bool CPolygonCalibrationShape::IsFirstVisible() const
{
	return m_isFirstVisible;
}


inline void CPolygonCalibrationShape::SetFirstVisible(bool state)
{
	m_isFirstVisible = state;
}


inline bool CPolygonCalibrationShape::IsAlwaysMovable() const
{
	return m_isAlwaysDraggable;
}


inline void CPolygonCalibrationShape::SetAlwaysMovable(bool state)
{
	m_isAlwaysDraggable = state;
}


} // namespace iview


#endif // !iview_CPolygonCalibrationShape_included


