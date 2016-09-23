/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <imod/CMultiModelDispatcherBase.h>


// ACF includes
#include <imod/IModel.h>


namespace imod
{


bool CMultiModelDispatcherBase::RegisterModel(IModel* modelPtr, int modelId, const istd::IChangeable::ChangeSet& relevantFlags)
{
	ObserverProxyPtr& proxyPtr = m_modelMap[modelId];
	if (!proxyPtr.IsValid()){
		proxyPtr.SetPtr(new ObserverProxy(this, modelId, relevantFlags));
	}

	if (!modelPtr->AttachObserver(proxyPtr.GetPtr())){
		m_modelMap.remove(modelId);

		return false;
	}

	return true;
}


void CMultiModelDispatcherBase::UnregisterModel(int modelId)
{
	m_modelMap.remove(modelId);
}


void CMultiModelDispatcherBase::UnregisterAllModels()
{
	m_modelMap.clear();
}


// protected methods of the embedded class ObserverProxy

CMultiModelDispatcherBase::ObserverProxy::ObserverProxy(CMultiModelDispatcherBase* parentPtr, int modelId, const istd::IChangeable::ChangeSet& relevantFlags)
:	m_parent(*parentPtr),
	m_modelId(modelId)
{
	Q_ASSERT(parentPtr != NULL);

	SetObservedIds(relevantFlags);
}


// reimplemented (imod::CMultiModelObserverBase)

void CMultiModelDispatcherBase::ObserverProxy::OnUpdate(const istd::IChangeable::ChangeSet& changeSet)
{
	m_parent.OnModelChanged(m_modelId, changeSet);
}


} // namespace imod


