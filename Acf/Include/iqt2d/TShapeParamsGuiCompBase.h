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


#ifndef iqt2d_TShapeParamsGuiCompBase_included
#define iqt2d_TShapeParamsGuiCompBase_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"
#include "iview/IColorSchema.h"
#include "iview/CShapeControl.h"
#include "iqt2d/TViewExtenderCompBase.h"


namespace iqt2d
{


template <class Ui, class Shape, class ShapeModel>
class TShapeParamsGuiCompBase:
			public iqt2d::TViewExtenderCompBase<
						iqtgui::TDesignerGuiObserverCompBase<Ui, ShapeModel> >
{
public:
	typedef iqt2d::TViewExtenderCompBase<iqtgui::TDesignerGuiObserverCompBase<Ui, ShapeModel> > BaseClass;

	I_BEGIN_COMPONENT(TShapeParamsGuiCompBase);
		I_ASSIGN(m_unitNameAttrPtr, "UnitName", "Name of geometric units e.g. mm", false, "mm");
		I_ASSIGN(m_colorSchemaCompPtr, "ShapeColorSchema", "Color schema used by displayed shape", false, "ShapeColorSchema");
	I_END_COMPONENT;

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);

protected:
	typedef typename BaseClass::Shapes Shapes;
	typedef typename BaseClass::ShapesMap ShapesMap;

	virtual Shape* CreateShape() const;

	// reimplemented (iqt2d::TViewExtenderCompBase)
	virtual void CreateShapes(int sceneId, Shapes& result);

	I_ATTR(QString, m_unitNameAttrPtr);
	I_REF(iview::IColorSchema, m_colorSchemaCompPtr);
};


// public methods

// reimplemented (imod::IObserver)

template <class Ui, class Shape, class ShapeModel>
bool TShapeParamsGuiCompBase<Ui, Shape, ShapeModel>::OnAttached(imod::IModel* modelPtr)
{
	if (BaseClass::OnAttached(modelPtr)){
		const ShapesMap& shapesMap = BaseClass::GetShapesMap();
		for (		typename ShapesMap::const_iterator iter = shapesMap.begin();
					iter != shapesMap.end();
					++iter){
			const Shapes& shapes = iter.value();
			int shapesCount = shapes.GetCount();
			for (int shapeIndex = 0; shapeIndex < shapesCount; ++shapeIndex){
				Shape* shapePtr = dynamic_cast<Shape*>(shapes.GetAt(shapeIndex));
				if (shapePtr != NULL){
					if (modelPtr->AttachObserver(shapePtr)){
						shapePtr->SetVisible(true);
					}
				}
			}
		}

		return true;
	}
	else{
		return false;
	}
}


template <class Ui, class Shape, class ShapeModel>
bool TShapeParamsGuiCompBase<Ui, Shape, ShapeModel>::OnDetached(imod::IModel* modelPtr)
{
	if (BaseClass::OnDetached(modelPtr)){
		const ShapesMap& shapesMap = BaseClass::GetShapesMap();
		for (		typename ShapesMap::const_iterator iter = shapesMap.begin();
					iter != shapesMap.end();
					++iter){
			const Shapes& shapes = iter.value();
			int shapesCount = shapes.GetCount();
			for (int shapeIndex = 0; shapeIndex < shapesCount; ++shapeIndex){
				Shape* shapePtr = dynamic_cast<Shape*>(shapes.GetAt(shapeIndex));
				if (shapePtr != NULL){
					if (modelPtr->IsAttached(shapePtr)){
						modelPtr->DetachObserver(shapePtr);
					}

					shapePtr->SetVisible(false);
				}
			}
		}

		return true;
	}
	else{
		return false;
	}
}


// protected methods

template <class Ui, class Shape, class ShapeModel>
Shape* TShapeParamsGuiCompBase<Ui, Shape, ShapeModel>::CreateShape() const
{
	return new Shape();
}


// reimplemented (iqt2d::TViewExtenderCompBase)

template <class Ui, class Shape, class ShapeModel>
void TShapeParamsGuiCompBase<Ui, Shape, ShapeModel>::CreateShapes(int /*sceneId*/, Shapes& result)
{
	Shape* shapePtr = CreateShape();
	if (shapePtr != NULL){
		if (m_colorSchemaCompPtr.IsValid()){
			shapePtr->SetUserColorSchema(m_colorSchemaCompPtr.GetPtr());
		}

		result.PushBack(shapePtr);

		imod::IModel* modelPtr = BaseClass::GetModelPtr();
		if (modelPtr != NULL){
			if (modelPtr->AttachObserver(shapePtr)){
				shapePtr->SetVisible(true);
			}
		}
	}
}


} // namespace iview


#endif // !iview_TShapeParamsGuiCompBase_included


