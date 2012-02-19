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


#ifndef iview_CInteractiveSplineShape_included
#define iview_CInteractiveSplineShape_included



#include "iview/CInteractivePolylineShape.h"



namespace iview{



class CInteractiveSplineShape: public CInteractivePolylineShape
{
public:
	typedef CInteractivePolylineShape BaseClass;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

	// reimplemented (iview::CInteractiveShapeBase)
	virtual void CalcBoundingBox(i2d::CRect& result) const;

protected:
	virtual void DrawPolyBezier(QPainter& drawContext, const istd::CIndex2d* pointsPtr, int pointsCount) const;

	// reimplemented (iview::CInteractivePolygonShape)
	virtual i2d::CVector2d GetSegmentMiddle(int index) const;
	virtual void DrawCurve(QPainter& drawContext) const;
	virtual bool IsCurveTouched(istd::CIndex2d position) const;
};



} // namespace iview



#endif // !iview_CInteractiveSplineShape_included



