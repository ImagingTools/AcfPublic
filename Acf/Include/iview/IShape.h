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


#ifndef iview_IShape_included
#define iview_IShape_included


// ACF includes
#include "imod/IModel.h"
#include "imod/IObserver.h"

#include "i2d/CRect.h"

#include "iview/IVisualizable.h"
#include "iview/ITouchable.h"


namespace iview
{


class IColorShema;


/**
	Common interface for all display console shapes.
	Shapes are a representants of model objects in display console.
*/
class IShape:
			virtual public imod::IObserver,
			virtual public IVisualizable,
			virtual public ITouchable
{
public:
	enum ChangeFlags
	{
		CF_CALIB = 1 << 20
	};

	/**
		Get layer type of this shape object.
		\sa IViewLayer::LayerType
	*/
	virtual int GetLayerType() const = 0;

	/**	
		Return bounding box in client window coordinates.
		You can store this bounding box for optimisation,
		because about every change of transformation you will be informed
		by calling OnDisplayChange(int) method.
	*/
	virtual i2d::CRect GetBoundingBox() const = 0;

	/**
		Set color shema to draw shape.
	*/
	virtual void SetUserColorShema(const IColorShema* shemaPtr) = 0;
 
	/**
		Get color shema from view or user defined.
	*/
	virtual const iview::IColorShema* GetUserColorShema() const = 0;
};


} // namespace iview


#endif // !iview_IShape_included


