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


#include "imod/CSingleModelObserverBase.h"


// ACF includes
#include "imod/IModel.h"
#include "imod/IUndoManager.h"


namespace imod
{


CSingleModelObserverBase::CSingleModelObserverBase()
{
	m_modelPtr = NULL;
}


CSingleModelObserverBase::~CSingleModelObserverBase()
{
	EnsureModelDetached();
}


void CSingleModelObserverBase::EnsureModelDetached()
{
	if (m_modelPtr != NULL){
		m_modelPtr->DetachObserver(this);
	}

	m_modelPtr = NULL;
}


// reimplemented (IObserver)

bool CSingleModelObserverBase::OnAttached(imod::IModel* modelPtr)
{
	I_ASSERT(modelPtr != NULL);
	I_ASSERT(m_modelPtr == NULL);

	BeforeUpdate(NULL, IUndoManager::CF_NO_UNDO, NULL);

	m_modelPtr = modelPtr;

	AfterUpdate(m_modelPtr, IUndoManager::CF_NO_UNDO, NULL);

	return true;
}


bool CSingleModelObserverBase::OnDetached(imod::IModel* modelPtr)
{
	I_ASSERT(modelPtr != NULL);
	I_ASSERT(m_modelPtr == modelPtr);

	if (m_modelPtr == modelPtr){		
		m_modelPtr = NULL;

		return true;
	}

	return false;
}


void CSingleModelObserverBase::BeforeUpdate(
			imod::IModel* I_IF_DEBUG(modelPtr),
			int /*updateFlags*/,
			istd::IPolymorphic* /*updateParamsPtr*/)
{
	I_ASSERT(m_modelPtr == modelPtr);
}


void CSingleModelObserverBase::AfterUpdate(
			imod::IModel* I_IF_DEBUG(modelPtr),
			int updateFlags,
			istd::IPolymorphic* updateParamsPtr)
{
	I_ASSERT(m_modelPtr == modelPtr);

	OnUpdate(updateFlags, updateParamsPtr);
}


// protected methods

void CSingleModelObserverBase::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
}


} // namespace imod

