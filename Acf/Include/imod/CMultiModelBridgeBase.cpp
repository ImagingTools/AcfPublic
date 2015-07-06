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


#include "imod/CMultiModelBridgeBase.h"


namespace imod
{


// public methods

CMultiModelBridgeBase::CMultiModelBridgeBase(istd::IChangeable* changeablePtr)
:	m_changeablePtr(changeablePtr)
{
}


CMultiModelBridgeBase::~CMultiModelBridgeBase()
{
	EnsureModelsDetached();
}


IModel* CMultiModelBridgeBase::GetModelPtr(int modelIndex) const
{
	Q_ASSERT(modelIndex >= 0);
	Q_ASSERT(modelIndex < GetModelCount());

	return m_models.at(modelIndex);
}


int CMultiModelBridgeBase::GetModelCount() const
{
	return int(m_models.size());
}


void CMultiModelBridgeBase::EnsureModelsDetached()
{
	while (!m_models.isEmpty()){
		imod::IModel* modelPtr = m_models.front();
		Q_ASSERT(modelPtr != NULL);

		modelPtr->DetachObserver(this);
	}
}


// reimplemented (imod::IObserver)

bool CMultiModelBridgeBase::IsModelAttached(const imod::IModel* modelPtr) const
{
	if (modelPtr == NULL){
		return !m_models.isEmpty();
	}

	Models::const_iterator foundIter = qFind(m_models.begin(), m_models.end(), modelPtr);

	return (foundIter != m_models.end());
}


bool CMultiModelBridgeBase::OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask)
{
	Q_ASSERT(modelPtr != NULL);

	if (IsModelAttached(modelPtr)){
		return false;
	}

	m_models.push_back(modelPtr);

	changeMask = istd::IChangeable::GetAllChanges();

	return true;
}


bool CMultiModelBridgeBase::OnModelDetached(IModel* modelPtr)
{
	Models::iterator iter = qFind(m_models.begin(), m_models.end(), modelPtr);
	if (iter != m_models.end()){
		m_models.erase(iter);
		
		return true;
	}

	return false;
}


void CMultiModelBridgeBase::BeforeUpdate(IModel* I_IF_DEBUG(modelPtr))
{
	I_IF_DEBUG(Q_ASSERT(IsModelAttached(modelPtr)));

	m_changeablePtr->BeginChanges(istd::IChangeable::GetDelegatedChanges());
}


void CMultiModelBridgeBase::AfterUpdate(IModel* I_IF_DEBUG(modelPtr), const istd::IChangeable::ChangeSet& /*changeSet*/)
{
	I_IF_DEBUG(Q_ASSERT(IsModelAttached(modelPtr)));

	m_changeablePtr->EndChanges(istd::IChangeable::GetDelegatedChanges());
}


} // namespace imod

