/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iwiz_CSelectionConsistencyController_included
#define iwiz_CSelectionConsistencyController_included


// ACF includes
#include "imod/CMultiModelObserverBase.h"

#include "icomp/CComponentBase.h"

#include "iprm/ISelectionParam.h"

#include "iproc/IStateController.h"


namespace iwiz
{


/**
	Component implementation of a wizard controller.
*/
class CSelectionConsistencyControllerComp:
			public icomp::CComponentBase,
			virtual public iproc::IStateController,
			protected imod::CMultiModelObserverBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSelectionConsistencyControllerComp);
		I_REGISTER_INTERFACE(iproc::IStateController);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN_MULTI_0(m_enterDependenciesCompPtr, "Dependencies", "List of states must be valid before this state can be entered", false);
		I_ASSIGN_TO(m_enterDependenciesModelCompPtr, m_enterDependenciesCompPtr, false);
		I_ASSIGN_MULTI_0(m_leaveCondParamsCompPtr, "LeaveConditionParams", "List of selection parameters, needed to be consistent to allow state leaving", false);
		I_ASSIGN_TO(m_leaveCondParamModelsCompPtr, m_leaveCondParamsCompPtr, false);
	I_END_COMPONENT;

	// reimplemented (iproc::IStateController)
	virtual bool IsStateEnabled() const;
	virtual bool IsStateActive() const;
	virtual bool IsEnterAllowed(bool isActionAllowed = true, const IStateController* prevStatePtr = NULL) const;
	virtual bool IsLeaveAllowed(bool isActionAllowed = true, const IStateController* nextStatePtr = NULL) const;
	virtual bool TryEnterState(bool isActionAllowed = true, const IStateController* prevStatePtr = NULL);
	virtual bool TryLeaveState(bool isActionAllowed = true, const IStateController* nextStatePtr = NULL);
	virtual bool IsResetAllowed() const;

protected:
	void EnsureCacheValid() const;

	bool CheckParamConsistency(const iprm::ISelectionParam& param) const;

	// reimplemented (icomp::CComponentBase)
	void OnComponentCreated();
	void OnComponentDestroyed();

	// reimplemented (imod::IObserver)
	virtual void BeforeUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, int updateFlags, istd::IPolymorphic* updateParamsPtr);

private:
	I_MULTIREF(iproc::IStateController, m_enterDependenciesCompPtr);
	I_MULTIREF(imod::IModel, m_enterDependenciesModelCompPtr);
	I_MULTIREF(iprm::ISelectionParam, m_leaveCondParamsCompPtr);
	I_MULTIREF(imod::IModel, m_leaveCondParamModelsCompPtr);

	bool m_isStateActive;

	mutable bool m_isCacheValid;

	// cached values
	mutable bool m_isEnterAllowed;
	mutable bool m_isLeaveAllowed;
};


} // namespace iwiz


#endif // !iwiz_CSelectionConsistencyController_included


