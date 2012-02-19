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


#ifndef iview_CInteractivePerspectiveCalibrationShape_included
#define iview_CInteractivePerspectiveCalibrationShape_included


#include "iview/CCalibrationShapeBase.h"


namespace iview
{


// TODO: Redesign it to ACF transformation concept.

/**
	This shape object, is used to tune bounds of iview::CPerpectiveCalib using user interface.
*/
class CInteractivePerspectiveCalibrationShape: public iview::CCalibrationShapeBase
{
public:
	// reimplemented (iview::IInteractiveShape)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

protected:
	// reimplemented (iview::CInteractiveShapeBase)
	virtual void CalcBoundingBox(i2d::CRect& result) const;
	virtual void BeginLogDrag(const i2d::CVector2d& reference);
	virtual void SetLogDragPosition(const i2d::CVector2d& position);

private:
	enum EditBound
	{
		EB_LEFT,
		EB_RIGHT,
		EB_TOP,
		EB_BOTTOM
	} m_editBound;
};


} // namespace iview


#endif // !iview_CInteractivePerspectiveCalibrationShape_included


