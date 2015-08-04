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


#ifndef iview_TVisualObjects_included
#define iview_TVisualObjects_included


// ACF includes
#include "imod/TModelWrap.h"

#include "i2d/CCircle.h"

#include "iview/CCircleShape.h"
#include "iview/CImageShape.h"


namespace iview
{


// helper template for circle shapes

template<class Object = i2d::CCircle, class Shape = iview::CCircleShape>
struct TCircleVisualObject
{
	TCircleVisualObject(bool editable = false);

	typedef imod::TModelWrap<Object> PositionModel;

	istd::TDelPtr<PositionModel> model;
	istd::TDelPtr<Shape> shape;
};


template<class Object, class Shape>
TCircleVisualObject<Object, Shape>::TCircleVisualObject(bool editable)
{
	model.SetPtr(new PositionModel);

	shape.SetPtr(new Shape);
	shape->SetEditablePosition(editable);
	shape->SetEditableRadius(editable);

	model->AttachObserver(shape.GetPtr());
}


// helper template for image shapes

template<class Object, class BitmapShape = iview::CImageShape>
struct TBitmapVisualObject
{
	TBitmapVisualObject(const Object* imagePtr = NULL);

	typedef imod::TModelWrap<Object> ImageModel;

	istd::TDelPtr<ImageModel> model;
	istd::TDelPtr<BitmapShape> shape;
};


template<class Object, class BitmapShape>
TBitmapVisualObject<Object, BitmapShape>::TBitmapVisualObject(const Object* imagePtr)
{
	model.SetPtr(new ImageModel);
	if (imagePtr != NULL){
		model->SetBaseObject(*imagePtr);
	}
	
	shape.SetPtr(new BitmapShape);

	model->AttachObserver(shape.GetPtr());
}


} // namespace iview


#endif // !iview_TVisualObjects_included
