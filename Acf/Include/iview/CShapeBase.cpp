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


#include "iview/CShapeBase.h"


namespace iview
{


CShapeBase::CShapeBase()
{
	m_modelPtr = NULL;
}


CShapeBase::CShapeBase(const CShapeBase& I_IF_DEBUG(shape))
{
	I_ASSERT(shape.m_modelPtr == NULL);		// Copy constructor not allowed for shapes connected to model 
	m_modelPtr = NULL;
}


CShapeBase::~CShapeBase()
{
	DisconnectDisplay();

	if (m_modelPtr != NULL){
		m_modelPtr->DetachObserver(this);
	}
}


// reimplemented (imod::IObserver)

bool CShapeBase::OnAttached(imod::IModel* modelPtr)
{
	bool retVal = BaseClass::OnAttached(modelPtr);

	Invalidate(CS_CONSOLE);

	return retVal;
}


bool CShapeBase::OnDetached(imod::IModel* modelPtr)
{
	bool retVal = BaseClass::OnDetached(modelPtr);

	Invalidate(CS_CONSOLE);

	return retVal;
}


} // namespace iview


