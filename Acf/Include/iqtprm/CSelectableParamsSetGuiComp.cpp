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


#include "iqtprm/CSelectableParamsSetGuiComp.h"


// ACF includes
#include "iprm/ISelectionConstraints.h"
#include "iprm/IParamsSet.h"


namespace iqtprm
{


// public methods

CSelectableParamsSetGuiComp::CSelectableParamsSetGuiComp()
	:m_currentParamsSetIndex(-1)
{
}


// reimplemented (imod::CSingleModelObserverBase)

void CSelectableParamsSetGuiComp::BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	if ((updateFlags & iprm::ISelectionParam::CF_SELECTION_CHANGED) != 0){
		EnsureDetachLastEditor();
	}

	BaseClass::BeforeUpdate(modelPtr, updateFlags, updateParamsPtr);
}

void CSelectableParamsSetGuiComp::AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	if ((updateFlags & iprm::ISelectionParam::CF_SELECTION_CHANGED) != 0){
		ConnectCurrentEditor();
	}

	BaseClass::AfterUpdate(modelPtr, updateFlags, updateParamsPtr);
}


// protected methods

// reimplemented (iqtgui::TModelObserverWrap)

void CSelectableParamsSetGuiComp::OnGuiModelAttached()
{
	ConnectCurrentEditor();

	BaseClass::OnGuiModelAttached();
}


void CSelectableParamsSetGuiComp::OnGuiModelDetached()
{
	EnsureDetachLastEditor();

	BaseClass::OnGuiModelDetached();
}


// private methods

void CSelectableParamsSetGuiComp::EnsureDetachLastEditor()
{
	int observersCount = m_slaveObserversCompPtr.GetCount();

	int observerIndex = qMin(m_currentParamsSetIndex, observersCount - 1);

	iprm::IParamsSet* paramsSetPtr = dynamic_cast<iprm::IParamsSet*>(GetObjectPtr());
	if (paramsSetPtr != NULL && observerIndex >= 0){
		imod::IObserver* observerPtr = m_slaveObserversCompPtr[observerIndex];
		imod::IModel* paramsSetModelPtr = dynamic_cast<imod::IModel*>(paramsSetPtr);
		if (		(paramsSetModelPtr != NULL) &&
					(observerPtr != NULL) &&
					paramsSetModelPtr->IsAttached(observerPtr)){
			paramsSetModelPtr->DetachObserver(observerPtr);
		}
	}

	m_currentParamsSetIndex = -1;
}


void CSelectableParamsSetGuiComp::ConnectCurrentEditor()
{
	iprm::ISelectionParam* selectionPtr = GetObjectPtr();
	if (selectionPtr != NULL){
		int selectedIndex = selectionPtr->GetSelectedOptionIndex();

		if (selectedIndex != m_currentParamsSetIndex){
			EnsureDetachLastEditor();
	
			m_currentParamsSetIndex = selectedIndex;
			
			if (m_slaveObserversCompPtr.IsValid()){	
				int observersCount = m_slaveObserversCompPtr.GetCount();

				int observerIndex = qMin(m_currentParamsSetIndex, observersCount - 1);

				iprm::IParamsSet* paramsSetPtr = dynamic_cast<iprm::IParamsSet*>(selectionPtr);
				if (paramsSetPtr != NULL && observerIndex >= 0){
					imod::IObserver* observerPtr = m_slaveObserversCompPtr[observerIndex];
					imod::IModel* paramsSetModelPtr = dynamic_cast<imod::IModel*>(paramsSetPtr);
					if (paramsSetModelPtr != NULL && observerPtr != NULL){
						paramsSetModelPtr->AttachObserver(observerPtr);
					}
				}	
			}
		}
	}
}


} // namespace iqtprm


