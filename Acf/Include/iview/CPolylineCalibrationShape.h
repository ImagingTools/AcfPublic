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


#ifndef iview_CPolylineCalibrationShape_included
#define iview_CPolylineCalibrationShape_included


#include "iview/CPolygonCalibrationShape.h"


namespace iview
{


// TODO: Redesign it to ACF transformation concept.
class CPolylineCalibrationShape: public CPolygonCalibrationShape
{
public:
	typedef CPolygonCalibrationShape BaseClass;

	CPolylineCalibrationShape();

	bool IsOrientationVisible() const;
	void SetOrientationVisible(bool state = true);

    // reimplemented (iview::CPolygonCalibrationShape)
	virtual bool IsTickerTouched(istd::CIndex2d position) const;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

	// reimplemented (iview::IMouseActionObserver)
	virtual bool OnMouseButton(istd::CIndex2d position, Qt::MouseButton buttonType, bool downFlag);

protected:
	virtual void DrawCurve(QPainter& drawContext) const;
	virtual void DrawArea(QPainter& drawContext) const;
	virtual void DrawSelectionElements(QPainter& drawContext) const;
	virtual bool IsCurveTouched(istd::CIndex2d position) const;

private:
	bool m_isOrientationVisible;
};


inline bool CPolylineCalibrationShape::IsOrientationVisible() const
{
	return m_isOrientationVisible;
}


inline void CPolylineCalibrationShape::SetOrientationVisible(bool state)
{
	m_isOrientationVisible = state;
}


} // namespace iview


#endif // !iview_CPolylineCalibrationShape_included


