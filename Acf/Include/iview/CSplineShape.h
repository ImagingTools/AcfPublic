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


#ifndef iview_CSplineShape_included
#define iview_CSplineShape_included


// ACF includes
#include <i2d/CVector2d.h>
#include <iview/CPolylineShape.h>


namespace iview{


class CSplineShape: public CPolylineShape
{
public:
	typedef CPolylineShape BaseClass;

	// reimplemented (imod::IObserver)
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask) override;

protected:
	virtual void DrawPolyBezier(QPainter& drawContext, const i2d::CVector2d* pointsPtr, int pointsCount) const;

	// reimplemented (iview::CPolygonShape)
	virtual i2d::CVector2d GetSegmentMiddle(int index) const override;
	virtual void DrawCurve(QPainter& drawContext) const override;

	// reimplemented (iview::CRectControlledShapeBase)
	virtual bool IsCurveTouched(istd::CIndex2d position) const override;

	// reimplemented (iview::CShapeBase)
	virtual i2d::CRect CalcBoundingBox() const override;
};


} // namespace iview


#endif // !iview_CSplineShape_included


