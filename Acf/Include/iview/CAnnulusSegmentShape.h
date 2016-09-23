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


#ifndef iview_CAnnulusSegmentShape_included
#define iview_CAnnulusSegmentShape_included


#include <iview/CAnnulusShape.h>


namespace iview
{

	
class CAnnulusSegmentShape: public CAnnulusShape
{
public:
	typedef CAnnulusShape BaseClass;
	typedef CInteractiveShapeBase ShapeBaseClass;

	CAnnulusSegmentShape();

	virtual bool IsEditableAngles() const;
	virtual void SetEditableAngles(bool editable = true);

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
	virtual void DrawArea(
				QPainter& painter,
				i2d::CVector2d realCenter,
				i2d::CVector2d center,
				double realMinRadius,
				double realMaxRadius,
				int minRadius,
				int maxRadius,
				double startAngle,
				double stopAngle,
				bool fillFlag = true) const;

	double GetDegreeAndleOfPoint(const i2d::CVector2d& center, const QPointF& point) const;

	bool m_editableAngle;

	enum EditMode
	{
		EM_ANGLE1 = EM_OUTER_RADIUS + 1,
		EM_ANGLE2
	};
};


inline bool CAnnulusSegmentShape::IsEditableAngles() const
{
	return m_editableAngle;
}


} // namespace iview


#endif // !iview_CAnnulusSegmentShape_included

