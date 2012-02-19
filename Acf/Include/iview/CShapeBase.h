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


#ifndef iview_CShapeBase_included
#define iview_CShapeBase_included


// ACF includes
#include "imod/IModel.h"


#include "iview/IShape.h"
#include "iview/TShapeBase.h"


namespace iview
{


class CShapeBase: public TShapeBase<IShape>
{
public:
	typedef TShapeBase<IShape> BaseClass;

	CShapeBase();
	CShapeBase(const CShapeBase& shape);
	virtual ~CShapeBase();

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);
	virtual bool OnDetached(imod::IModel* modelPtr);

private:
	imod::IModel* m_modelPtr;
};


} // namespace iview


#endif // !iview_CShapeBase_included


