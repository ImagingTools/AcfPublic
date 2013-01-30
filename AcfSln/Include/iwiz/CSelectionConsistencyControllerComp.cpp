/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iwiz/CSelectionConsistencyControllerComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iprm/IOptionsList.h"


namespace iwiz
{


// reimplemented (iproc::IStateController)

bool CSelectionConsistencyControllerComp::IsStateEnabled() const
{
	return true;
}


bool CSelectionConsistencyControllerComp::IsStateActive() const
{
	return m_isStateActive;
}


bool CSelectionConsistencyControllerComp::IsEnterAllowed(bool /*isActionAllowed*/, const IStateController* /*prevStatePtr*/) const
{
	EnsureCacheValid();

	return m_isEnterAllowed;
}


bool CSelectionConsistencyControllerComp::IsLeaveAllowed(bool /*isActionAllowed*/, const IStateController* /*nextStatePtr*/) const
{
	EnsureCacheValid();

	return m_isLeaveAllowed;
}


bool CSelectionConsistencyControllerComp::TryEnterState(bool /*isActionAllowed*/, const IStateController* /*prevStatePtr*/)
{
	if (IsEnterAllowed()){
		if (!m_isStateActive){
			istd::CChangeNotifier notifier(this);
			m_isStateActive = true;
		}

		return true;
	}

	return false;
}


bool CSelectionConsistencyControllerComp::TryLeaveState(bool /*isActionAllowed*/, const IStateController* /*nextStatePtr*/)
{
	if (IsLeaveAllowed()){
		if (m_isStateActive){
			istd::CChangeNotifier notifier(this);
			m_isStateActive = false;
		}

		return true;
	}

	return false;
}


bool CSelectionConsistencyControllerComp::IsResetAllowed() const
{
	return true;
}


// reimplemented (icomp::CComponentBase)

void CSelectionConsistencyControllerComp::OnComponentCreated()
{
	m_isStateActive = false;

	m_isCacheValid = false;

	m_isEnterAllowed = false;
	m_isLeaveAllowed = false;

	BaseClass::OnComponentCreated();

	int enterCondParamModelsCount = m_enterDependenciesModelCompPtr.GetCount();
	for (int i = 0; i < enterCondParamModelsCount; ++i){
		imod::IModel* modelPtr = m_enterDependenciesModelCompPtr[i];
		if ((modelPtr != NULL) && !modelPtr->IsAttached(this)){
			modelPtr->AttachObserver(this);
		}
	}

	int leaveCondParamModelsCount = m_leaveCondParamModelsCompPtr.GetCount();
	for (int i = 0; i < leaveCondParamModelsCount; ++i){
		imod::IModel* modelPtr = m_leaveCondParamModelsCompPtr[i];
		if ((modelPtr != NULL) && !modelPtr->IsAttached(this)){
			modelPtr->AttachObserver(this);
		}
	}

	int leaveCondParamsCount = m_leaveCondParamsCompPtr.GetCount();
	for (int i = 0; i < leaveCondParamsCount; ++i){
		const iprm::ISelectionParam* paramPtr = m_leaveCondParamsCompPtr[i];
		if (paramPtr != NULL){
			imod::IModel* contraintsModelPtr =
						const_cast<imod::IModel*>(dynamic_cast<const imod::IModel*>(paramPtr->GetSelectionConstraints()));
			if ((contraintsModelPtr != NULL) && !contraintsModelPtr->IsAttached(this)){
				contraintsModelPtr->AttachObserver(this);
			}
		}
	}
}


void CSelectionConsistencyControllerComp::OnComponentDestroyed()
{
	EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


// protected methods

void CSelectionConsistencyControllerComp::EnsureCacheValid() const
{
	if (!m_isCacheValid){
		m_isEnterAllowed = true;
		m_isLeaveAllowed = true;

		int enterCondParamsCount = m_enterDependenciesCompPtr.GetCount();
		for (int i = 0; i < enterCondParamsCount; ++i){
			const iproc::IStateController* controllerPtr = m_enterDependenciesCompPtr[i];
			if ((controllerPtr != NULL) && !controllerPtr->IsLeaveAllowed()){
				m_isEnterAllowed = false;
				m_isLeaveAllowed = false;
				break;
			}
		}

		int leaveCondParamsCount = m_leaveCondParamsCompPtr.GetCount();
		for (int i = 0; i < leaveCondParamsCount; ++i){
			const iprm::ISelectionParam* paramPtr = m_leaveCondParamsCompPtr[i];
			if ((paramPtr != NULL) && !CheckParamConsistency(*paramPtr)){
				m_isLeaveAllowed = false;
				break;
			}
		}

		m_isCacheValid = true;
	}
}


bool CSelectionConsistencyControllerComp::CheckParamConsistency(const iprm::ISelectionParam& param) const
{
	int index = param.GetSelectedOptionIndex();

	if (index < 0){
		return false;
	}

	const iprm::IOptionsList* constraintsPtr = param.GetSelectionConstraints();
	if (constraintsPtr != NULL){
		if (index >= constraintsPtr->GetOptionsCount()){
			return false;
		}
	}

	return true;
}


// reimplemented (imod::IObserver)

void CSelectionConsistencyControllerComp::BeforeUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	m_isCacheValid = false;
}


void CSelectionConsistencyControllerComp::AfterUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	m_isCacheValid = false;
}


} // namespace iwiz


