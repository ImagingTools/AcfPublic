/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "ibase/CMultiObserverBinderComp.h"


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


bool CMultiObserverBinderComp::OnAttached(imod::IModel* modelPtr)
{
	Q_ASSERT(m_attachedModelPtr == NULL);

	bool retVal = true;

	int count = m_observersCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IObserver* observerPtr = m_observersCompPtr[i];
		if (observerPtr != NULL){
			retVal = modelPtr->AttachObserver(observerPtr) || retVal;
		}
	}

	if (retVal){
		m_attachedModelPtr = modelPtr;
	}

	return retVal;
}


bool CMultiObserverBinderComp::OnDetached(imod::IModel* modelPtr)
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


void CMultiObserverBinderComp::BeforeUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
}


void CMultiObserverBinderComp::AfterUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
}


void CMultiObserverBinderComp::UpdateEditor(int updateFlags)
{
	int count = m_modelEditorsCompPtr.GetCount();
	for (int i = 0; i < count; ++i){
		imod::IModelEditor* editorPtr = m_modelEditorsCompPtr[i];
		if (editorPtr != NULL){
			editorPtr->UpdateEditor(updateFlags);
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



