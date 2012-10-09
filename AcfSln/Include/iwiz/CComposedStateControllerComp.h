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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iwiz_CComposedStateControllerComp_included
#define iwiz_CComposedStateControllerComp_included


#include "imod/CMultiModelDispatcherBase.h"

#include "iprm/CComposedParamsSetComp.h"

#include "iproc/IStateController.h"
#include "iproc/IProcessor.h"


namespace iwiz
{


/**
	Component implementation of a wizard page.
*/
class CComposedStateControllerComp:
			public iprm::CComposedParamsSetComp,
			protected imod::CMultiModelDispatcherBase,
			virtual public iproc::IStateController
{
public:
	typedef iprm::CComposedParamsSetComp BaseClass;
	typedef imod::CMultiModelDispatcherBase BaseClass2;

	I_BEGIN_COMPONENT(CComposedStateControllerComp);
		I_REGISTER_INTERFACE(iproc::IStateController);
		I_ASSIGN_MULTI_0(m_slaveControllersCompPtr, "SlaveControllers", "State controllers used to calculation general page state", false);
		I_ASSIGN_TO(m_slaveControllerModelsCompPtr, m_slaveControllersCompPtr, false);
		I_ASSIGN(m_processOnEnterCompPtr, "EnterProcessor", "Processor called on enter", false, "EnterProcessor");
		I_ASSIGN(m_processOnLeaveCompPtr, "LeaveProcessor", "Processor called on exit", false, "LeaveProcessor");
	I_END_COMPONENT;

	CComposedStateControllerComp();

	// reimplemented (iproc::IStateController)
	virtual bool IsStateEnabled() const;
	virtual bool IsStateActive() const;
	virtual bool IsEnterAllowed(bool isActionAllowed = true, const IStateController* prevStatePtr = NULL) const;
	virtual bool IsLeaveAllowed(bool isActionAllowed = true, const IStateController* nextStatePtr = NULL) const;
	virtual bool TryEnterState(bool isActionAllowed = true, const IStateController* prevStatePtr = NULL);
	virtual bool TryLeaveState(bool isActionAllowed = true, const IStateController* nextStatePtr = NULL);

protected:
	void UpdateAllMembers();

	// reimplemented (imod::CMultiModelDispatcherBase)
	virtual void OnModelChanged(int modelId, int changeFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	bool m_isStateEnabled;
	bool m_isStateActive;

	I_MULTIREF(iproc::IStateController, m_slaveControllersCompPtr);
	I_MULTIREF(imod::IModel, m_slaveControllerModelsCompPtr);
	I_REF(iproc::IProcessor, m_processOnEnterCompPtr);
	I_REF(iproc::IProcessor, m_processOnLeaveCompPtr);
};


} // namespace iwiz


#endif // !iwiz_CComposedStateControllerComp_included


