/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iinsp_CInspectionTaskComp_included
#define iinsp_CInspectionTaskComp_included


// ACF includes
#include "imod/IModel.h"
#include "imod/CMultiModelBridgeBase.h"
#include "ibase/TLoggerCompWrap.h"

#include "iinsp/IInspectionTask.h"


namespace iinsp
{


/**
	Standard component implementation of interface iinsp::IInspectionTask.
*/
class CInspectionTaskComp:
			public ibase::CLoggerComponentBase,
			virtual public IInspectionTask,
			protected imod::CMultiModelBridgeBase
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	enum MessageId
	{
		MI_BAD_PARAMS_COUNT = 0x5af30,
		MI_NO_SUBTASK
	};

	I_BEGIN_COMPONENT(CInspectionTaskComp);
		I_REGISTER_INTERFACE(IInspectionTask);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN_MULTI_0(m_subtasksCompPtr, "Subtasks", "List of subtasks (suppliers)", true);
		I_ASSIGN_MULTI_0(m_subtaskModelsCompPtr, "Subtasks", "List of subtasks (suppliers)", false);
		I_ASSIGN(m_serialzeSuppliersAttrPtr, "SerializeSuppliers", "If it is true, parameters of suppliers will be serialized", true, true);
		I_ASSIGN(m_generalParamsCompPtr, "GeneralParams", "Optional general parameter set, it will be always serialized", false, "GeneralParams");
	I_END_COMPONENT;

	// reimplemented (iinsp::IInspectionTask)
	virtual int GetSubtasksCount() const;
	virtual iproc::ISupplier* GetSubtask(int subtaskIndex) const;
	virtual iprm::IParamsSet* GetTaskParams() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_MULTIREF(iproc::ISupplier, m_subtasksCompPtr);
	I_MULTIREF(imod::IModel, m_subtaskModelsCompPtr);
	I_ATTR(bool, m_serialzeSuppliersAttrPtr);
	I_REF(iprm::IParamsSet, m_generalParamsCompPtr);
};


} // namespace iinsp


#endif // !iinsp_CInspectionTaskComp_included


