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


#ifndef iview_CTubePolylineShape_included
#define iview_CTubePolylineShape_included


#include "iview/CPolylineShape.h"


namespace iview
{


/**
	Graphical representation of tube region.
*/
class CTubePolylineShape: public iview::CPolylineShape
{
public:
	typedef iview::CPolylineShape BaseClass;

	CTubePolylineShape();

	/**
		Check if orientation of polyline is visible.
		Orientation is shown as small arrow at the end of polyline.
	*/
	virtual bool IsOrientationVisible() const;
	
	/**
		Set the orientation to be visible or not.
		@param	state	if true, orientation will be visible.
	*/
	virtual void SetOrientationVisible(bool state = true);

	/**
		Check if in all edit modes is this shape draggable.
		Normally it is possible to drag this object only in EM_NONE mode.
	*/
	virtual bool IsAlwaysMovable() const;

	/**
		Set flag if in all edit modes is this shape draggable.
		\sa IsAlwaysMovable()
	 */
	virtual void SetAlwaysMovable(bool state = true);

	// reimplemented (iview::CShapeBase)
	virtual i2d::CRect CalcBoundingBox() const;

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

protected:
	// reimplemented (iview::CPolygonShape)
	virtual void DrawCurve(QPainter& drawContext) const;
	virtual void DrawSelectionElements(QPainter& drawContext) const;

private:
	enum TickerType{
		TT_NONE,
		TT_BASIC,
		TT_LEFT,
		TT_RIGHT
	};

	bool m_isAlwaysDraggable;
	bool m_isOrientationVisible;

	int m_draggedTickerType;
	int m_draggedTickerIndex;
};


// inline methods

inline bool CTubePolylineShape::IsOrientationVisible() const
{
	return m_isOrientationVisible;
}


inline void CTubePolylineShape::SetOrientationVisible(bool state)
{
	if (m_isOrientationVisible != state){
		m_isOrientationVisible = state;
		Invalidate(iview::CS_CONSOLE);
	}
}


inline bool CTubePolylineShape::IsAlwaysMovable() const
{
	return m_isAlwaysDraggable;
}


inline void CTubePolylineShape::SetAlwaysMovable(bool state)
{
	m_isAlwaysDraggable = state;
}


} // namespace qto


#endif // !iview_CTubePolylineShape_included



