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


#ifndef iview_IShapeObserver_included
#define iview_IShapeObserver_included


#include <istd/IPolymorphic.h>


namespace iview
{


class IShape;


/**
	Common interface for all objects informed about shapes state changes.
	Each shape has a pointer to one IShapeObserver object.
*/
class IShapeObserver: virtual public istd::IPolymorphic
{
public:
	/**
		Invalidate a shape.
		When you call Update, all invalidated shapes will be repainted.
		\return	true, if it was possible to invalidate this shape.
	*/
	virtual void OnChangeShape(IShape* shapePtr) = 0;

	/**
		Disconnect shape object from view.
		This shape had to be connected using ConnectShape.
		\return	true, if it was possible to disconnect this shape.
	*/
	virtual bool DisconnectShape(IShape* shapePtr) = 0;
};


} // namespace iview


#endif // !iview_IShapeObserver_included


