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


#ifndef iview_IShape_included
#define iview_IShape_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <imod/IModel.h>
#include <imod/IObserver.h>
#include <i2d/CRect.h>
#include <iview/IVisualizable.h>
#include <iview/ITouchable.h>


namespace iview
{


class IColorSchema;


/**
	Common interface for all display console shapes.
	Shapes are representants of model objects in display console.
*/
class IShape:
			virtual public imod::IObserver,
			virtual public IVisualizable,
			virtual public ITouchable
{
public:
	/**
		Data model change notification flags.
	*/
	enum ChangeFlags
	{
		CF_CALIB = 0x3663adf
	};

	/**
		Get layer type of this shape object.
		\sa IViewLayer::LayerType
	*/
	virtual int GetLayerType() const = 0;

	/**	
		Return bounding box in client window coordinates.
		You can store this bounding box for optimization,
		because about every change of transformation you will be informed
		by calling OnDisplayChange(int) method.
	*/
	virtual i2d::CRect GetBoundingBox() const = 0;

	/**
		Make shape to be visible or not.
	*/
	virtual void SetVisible(bool state = true) = 0;

	/**
		Get color schema from view or user defined.
	*/
	virtual const iview::IColorSchema* GetUserColorSchema() const = 0;
	/**
		Set color schema to draw shape.
	*/
	virtual void SetUserColorSchema(const IColorSchema* schemaPtr) = 0;

	/**
		Set default description will be used to display on console.
	*/
	virtual void SetDefaultDescription(const QString& description) = 0;
};


} // namespace iview


#endif // !iview_IShape_included


