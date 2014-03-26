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


#ifndef iview_IShapeFactory_included
#define iview_IShapeFactory_included


// ACF includes
#include "i2d/IObject2d.h"

#include "iview/IShape.h"


namespace iview
{


/**
	Interface for creation of visualization shapes of some geometrical object.
*/
class IShapeFactory: virtual public istd::IPolymorphic
{
public:
	/**
		Create a graphical representation of the given 2D-object \c object.
		If \connectModel is enabled, the created shape will be connected to the object's data model.
		If connection has failed, then no shape will be returned.
		The method returns \c NULL if the shape could not be created.
	*/
	virtual IShape* CreateShape(const i2d::IObject2d& object, bool connectToModel = false) const = 0;
};


} // namespace iview


#endif // !iview_IShapeFactory_included


