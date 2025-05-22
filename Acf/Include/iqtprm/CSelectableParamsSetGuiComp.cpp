/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include <iqtprm/CSelectableParamsSetGuiComp.h>


// ACF includes
#include <iprm/IParamsManager.h>


namespace iqtprm
{


// public methods

CSelectableParamsSetGuiComp::CSelectableParamsSetGuiComp()
	:m_currentParamsSetIndex(-1)
{
	static const istd::IChangeable::ChangeSet changeMask(iprm::ISelectionParam::CF_SELECTION_CHANGED);
	SetObservedIds(changeMask);
}


// reimplemented (imod::CSingleModelObserverBase)

void CSelectableParamsSetGuiComp::BeforeUpdate(imod::IModel* modelPtr)
{
	EnsureDetachLastEditor();

	BaseClass::BeforeUpdate(modelPtr);
}


void CSelectableParamsSetGuiComp::AfterUpdate(imod::IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet)
{
	BaseClass::AfterUpdate(modelPtr, changeSet);

	ConnectCurrentEditor();
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

	iprm::IParamsSet* paramsSetPtr = ExtractParamsSetPtr(GetObservedModel());

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
	iprm::ISelectionParam* selectionPtr = GetObservedObject();
	if (selectionPtr != NULL){
		int selectedIndex = selectionPtr->GetSelectedOptionIndex();

		if (selectedIndex != m_currentParamsSetIndex){
			EnsureDetachLastEditor();
	
			m_currentParamsSetIndex = selectedIndex;
			
			if (m_slaveObserversCompPtr.IsValid()){	
				int observersCount = m_slaveObserversCompPtr.GetCount();

				int observerIndex = qMin(m_currentParamsSetIndex, observersCount - 1);

				iprm::IParamsSet* paramsSetPtr = ExtractParamsSetPtr(GetObservedModel());
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


// private methods

iprm::IParamsSet* CSelectableParamsSetGuiComp::ExtractParamsSetPtr(imod::IModel* modelPtr) const
{
	iprm::IParamsManager* paramsManagerPtr = dynamic_cast<iprm::IParamsManager*>(modelPtr);
	if ((paramsManagerPtr != NULL) && (m_currentParamsSetIndex >= 0)){
		return paramsManagerPtr->GetParamsSet(m_currentParamsSetIndex);
	}

	return NULL;
}


} // namespace iqtprm


