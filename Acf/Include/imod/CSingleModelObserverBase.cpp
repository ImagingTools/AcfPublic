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


#include <imod/CSingleModelObserverBase.h>


// ACF includes
#include <istd/IChangeable.h>
#include <imod/IModel.h>


namespace imod
{


const istd::IChangeable::ChangeSet CSingleModelObserverBase::s_undoChanges(istd::IChangeable::CF_NO_UNDO);


CSingleModelObserverBase::CSingleModelObserverBase()
:	m_modelPtr(NULL)
{
	m_observedIds = istd::IChangeable::GetAllChanges();
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


void CSingleModelObserverBase::SetObservedIds(const istd::IChangeable::ChangeSet& changeMask)
{
	m_observedIds = changeMask;
}


// reimplemented (imod::IObserver)

bool CSingleModelObserverBase::OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask)
{
	Q_ASSERT(modelPtr != NULL);
	Q_ASSERT(m_modelPtr == NULL);

	BeforeUpdate(NULL);

	m_modelPtr = modelPtr;

	changeMask = m_observedIds;

	AfterUpdate(m_modelPtr, s_undoChanges);

	return true;
}


bool CSingleModelObserverBase::OnModelDetached(imod::IModel* modelPtr)
{
	Q_ASSERT(modelPtr != NULL);
	Q_ASSERT(m_modelPtr == modelPtr);

	if (m_modelPtr == modelPtr){		
		m_modelPtr = NULL;

		return true;
	}

	return false;
}


void CSingleModelObserverBase::BeforeUpdate(imod::IModel* I_IF_DEBUG(modelPtr))
{
	I_IF_DEBUG(Q_ASSERT(m_modelPtr == modelPtr));
}


void CSingleModelObserverBase::AfterUpdate(imod::IModel* I_IF_DEBUG(modelPtr), const istd::IChangeable::ChangeSet& changeSet)
{
	I_IF_DEBUG(Q_ASSERT(m_modelPtr == modelPtr));

	if (!changeSet.IsEmpty()){
		OnUpdate(changeSet);
	}
}


// protected methods

void CSingleModelObserverBase::OnUpdate(const istd::IChangeable::ChangeSet& /*changeSet*/)
{
}


} // namespace imod


