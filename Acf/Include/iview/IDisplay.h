/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iview_IDisplay_included
#define iview_IDisplay_included


#include "i2d/CRect.h"

#include "iview/IShapeObserver.h"


namespace iview
{


class CScreenTransform;
class IColorSchema;


class IDisplay: public IShapeObserver
{
public:
	/**
		Get parent object of this display.
		If this display is root, it returns NULL.
	*/
	virtual IDisplay* GetParentDisplayPtr() const = 0;

	/**
		Return a screen transformation.
		This transformation converts view units to screen units.
	*/
	virtual const iview::CScreenTransform& GetTransform() const = 0;

	/**
		Get bounding box of all object in this display.
	*/
	virtual i2d::CRect GetBoundingBox() const = 0;
	
	/**
		Get bounding box of client area.
	*/
	virtual i2d::CRect GetClientRect() const = 0;

	/**
		Get color schema.
   */
	virtual const IColorSchema& GetColorSchema() const = 0;
	
	/**
		Invalidate display area.
		\param	prevArea	previous area used to display object.
		\param	newArea		new area used to display object.
	*/
	virtual void OnAreaInvalidated(const i2d::CRect& prevArea, const i2d::CRect& newArea) = 0;
};


} // namespace iview


#endif // !iview_IDisplay_included


