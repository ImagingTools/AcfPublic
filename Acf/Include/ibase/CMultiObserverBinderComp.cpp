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


#include <ibase/CMultiObserverBinderComp.h>


namespace ibase
{


CMultiObserverBinderComp::CMultiObserverBinderComp()
	:m_attachedModelPtr(NULL)
{
}



// public methods

bool CMultiObserverBinderComp::IsModelAttached(const imod::IModel* modelPtr) const
{
	return (modelPtr == m_attachedModelPtr);
}


bool CMultiObserverBinderComp::OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask)
{
	Q_ASSERT(m_attachedModelPtr == NULL);

	bool retVal = false;

	int count = m_observersCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IObserver* observerPtr = m_observersCompPtr[i];
		if (observerPtr != NULL){
			if (modelPtr->AttachObserver(observerPtr)){
				retVal = true;
			}
		}
	}

	if (retVal){
		changeMask = istd::IChangeable::GetAllChanges();
		m_attachedModelPtr = modelPtr;
	}

	return retVal;
}


bool CMultiObserverBinderComp::OnModelDetached(imod::IModel* modelPtr)
{
	Q_ASSERT(m_attachedModelPtr == modelPtr);

	int count = m_observersCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IObserver* observerPtr = m_observersCompPtr[i];
		if ((observerPtr != NULL) && observerPtr->IsModelAttached(modelPtr)){
			modelPtr->DetachObserver(observerPtr);
		}
	}

	m_attachedModelPtr = NULL;

	return true;
}


void CMultiObserverBinderComp::BeforeUpdate(imod::IModel* /*modelPtr*/)
{
}


void CMultiObserverBinderComp::AfterUpdate(imod::IModel* /*modelPtr*/, const istd::IChangeable::ChangeSet& /*changeSet*/)
{
}


void CMultiObserverBinderComp::UpdateEditor(const istd::IChangeable::ChangeSet& changeSet)
{
	int count = m_modelEditorsCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IModelEditor* editorPtr = m_modelEditorsCompPtr[i];
		if (editorPtr != NULL){
			editorPtr->UpdateEditor(changeSet);
		}
	}
}


void CMultiObserverBinderComp::UpdateModel() const
{
	int count = m_modelEditorsCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IModelEditor* editorPtr = m_modelEditorsCompPtr[i];
		if (editorPtr != NULL){
			editorPtr->UpdateModel();
		}
	}
}


bool CMultiObserverBinderComp::IsReadOnly() const
{
	int count = m_modelEditorsCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IModelEditor* editorPtr = m_modelEditorsCompPtr[i];
		if (editorPtr != NULL){
			if (!editorPtr->IsReadOnly()){
				return false;
			}
		}
	}

	return true;
}


void CMultiObserverBinderComp::SetReadOnly(bool state)
{
	int count = m_modelEditorsCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IModelEditor* editorPtr = m_modelEditorsCompPtr[i];
		if (editorPtr != NULL){
			editorPtr->SetReadOnly(state);
		}
	}
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CMultiObserverBinderComp::OnComponentDestroyed()
{
	EnsureModelDetached();

	BaseClass::OnComponentDestroyed();
}


// private methods

void CMultiObserverBinderComp::EnsureModelDetached()
{
	if ((m_attachedModelPtr != NULL) && m_attachedModelPtr->IsAttached(this)){
		m_attachedModelPtr->DetachObserver(this);
	}
}


} // namespace ibase



