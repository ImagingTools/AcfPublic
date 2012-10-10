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


#ifndef iview_CNoneCalibrationShape_included
#define iview_CNoneCalibrationShape_included


#include "iview/CCalibrationShapeBase.h"


namespace iview
{


// TODO: Redesign it to ACF transformation concept.

/**
	Shape object for none calibration.
	You need this shape to visualize grid without calibration on the shape view.
*/
class CNoneCalibrationShape: public CCalibrationShapeBase
{
public:
	typedef iview::CCalibrationShapeBase BaseClass;

	// reimplemented (iview::IVisualizable)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (iview::IInteractiveShape)
	virtual TouchState IsTouched(istd::CIndex2d position) const;

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);
	virtual bool OnMouseMove(istd::CIndex2d position);

protected:
	/**
		Get access to calibration.
	*/
	virtual const i2d::ITransformation2d* GetCalibrationPtr() const;

	// reimplemented (iview::CInteractiveShapeBase)
	virtual void BeginLogDrag(const i2d::CVector2d& reference);
	virtual void SetLogDragPosition(const i2d::CVector2d& position);

	// reimplemented (iview::CShapeBase)
	virtual i2d::CRect CalcBoundingBox() const;
};


} // namespace iview


#endif // !iview_CNoneCalibrationShape_included


