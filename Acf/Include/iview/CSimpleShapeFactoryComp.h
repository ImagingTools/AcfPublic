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


#ifndef iview_CSimpleShapeFactoryComp_included
#define iview_CSimpleShapeFactoryComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iview/IShapeFactory.h"


namespace iview
{


/**
	Simple shape factory for common 2D-objects
*/
class CSimpleShapeFactoryComp:
			public icomp::CComponentBase,
			virtual public IShapeFactory
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSimpleShapeFactoryComp);
		I_REGISTER_INTERFACE(IShapeFactory);
		I_ASSIGN(m_useInteractiveShapesAttrPtr, "UseInteractiveShapes", "If true, the created shapes will be editable", true, true);
	I_END_COMPONENT;

	// reimplemented (IShapeFactory)
	virtual IShape* CreateShape(const i2d::IObject2d& object, bool connectToModel = false) const;

protected:
	IShape* CreateShapeInstance(const i2d::IObject2d& object) const;

private:
	I_ATTR(bool, m_useInteractiveShapesAttrPtr);
};


} // namespace iview


#endif // !iview_CSimpleShapeFactoryComp_included


