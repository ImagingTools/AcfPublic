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


#include "ibase/CModelProxyComp.h"


namespace ibase
{


CModelProxyComp::CModelProxyComp()
	:m_modelSelectionListener(*this)
{
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CModelProxyComp::OnComponentCreated()
{
	if (m_modelSelectionCompPtr.IsValid() && m_selectionModelCompPtr.IsValid()){
		m_selectionModelCompPtr->AttachObserver(&m_modelSelectionListener);
	}
}


void CModelProxyComp::OnComponentDestroyed()
{
	if (m_modelSelectionCompPtr.IsValid() && m_selectionModelCompPtr.IsValid()){
		m_selectionModelCompPtr->DetachObserver(&m_modelSelectionListener);
	}
}


// public methods of embedded class ModelSelectionListener

CModelProxyComp::ModelSelectionListener::ModelSelectionListener(CModelProxyComp& parent)
	:m_parent(parent)
{
}


// reimplemented (imod::CSingleModelObserverBase)

void CModelProxyComp::ModelSelectionListener::AfterUpdate(imod::IModel* /*modelPtr*/, int/* updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	imod::IModelSelection* selectionPtr = GetObjectPtr();
	if (selectionPtr != NULL){
		m_parent.SetModelPtr(selectionPtr->GetSelectedModel());
	}
}


} // namespace ibase


