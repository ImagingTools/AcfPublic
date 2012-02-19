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


#ifndef iview_CInteractiveAnnulusSegmentShape_included
#define iview_CInteractiveAnnulusSegmentShape_included


#include "iview/CInteractiveAnnulusShape.h"


namespace iview
{

	
class CInteractiveAnnulusSegmentShape: public CInteractiveAnnulusShape
{
public:
	typedef CInteractiveAnnulusShape BaseClass;

	CInteractiveAnnulusSegmentShape();

	virtual bool IsEditableAngles() const;
	virtual void SetEditableAngles(bool editable = true);

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

	// reimplemented (iview::ITouchable)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

	// reimplemented (iview::CInteractiveShapeBase)
	virtual void CalcBoundingBox(i2d::CRect& result) const;

protected:
	virtual void DrawAnnulusSegment(
				QPainter& painter,
				istd::CIndex2d center,
				int minRadius,
				int maxRadius,
				double startAngle,
				double stopAngle,
				bool fillFlag = true) const;

	bool m_editRadius2Mode;

	bool m_editableAngle;
	bool m_editAngle1Mode;
	bool m_editAngle2Mode;
};


inline bool CInteractiveAnnulusSegmentShape::IsEditableAngles() const
{
	return m_editableAngle;
}


} // namespace iview


#endif // !iview_CInteractiveAnnulusSegmentShape_included

