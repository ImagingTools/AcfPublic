/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iproc/CModelBasedProcessingTriggerComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "imod/IModel.h"


namespace iproc
{


// public methods

CModelBasedProcessingTriggerComp::CModelBasedProcessingTriggerComp()
	:m_paramsObserver(*this)
{
}

// reimplemented (icomp::CComponentBase)

void CModelBasedProcessingTriggerComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_paramsSetCompPtr.IsValid() && m_triggerOnParamsChangeAttrPtr.IsValid() && *m_triggerOnParamsChangeAttrPtr){
		imod::IModel* paramsModelPtr = dynamic_cast<imod::IModel*>(m_paramsSetCompPtr.GetPtr());
		if (paramsModelPtr != NULL){
			paramsModelPtr->AttachObserver(&m_paramsObserver);
		}
	}
}


void CModelBasedProcessingTriggerComp::OnComponentDestroyed()
{
	if (m_paramsSetCompPtr.IsValid() && m_triggerOnParamsChangeAttrPtr.IsValid() && *m_triggerOnParamsChangeAttrPtr){
		imod::IModel* paramsModelPtr = dynamic_cast<imod::IModel*>(m_paramsSetCompPtr.GetPtr());
		if (paramsModelPtr != NULL && paramsModelPtr->IsAttached(&m_paramsObserver)){
			paramsModelPtr->DetachObserver(&m_paramsObserver);
		}
	}

	BaseClass::OnComponentDestroyed();
}


// protected methods
	
// reimplemented (imod::CSingleModelObserverBase)

void CModelBasedProcessingTriggerComp::OnUpdate(int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	DoProcessing();
}


// private methods

void CModelBasedProcessingTriggerComp::DoProcessing()
{
	if (!m_processorCompPtr.IsValid()){
		SendErrorMessage(0, "Processor not set");

		return;
	}

	if (!m_outputDataCompPtr.IsValid()){
		SendErrorMessage(0, "Output data object not set");

		return;
	}

	istd::CChangeNotifier changePtr(m_outputDataCompPtr.GetPtr());

	istd::IChangeable* inputDataPtr = dynamic_cast<istd::IChangeable*>(GetModelPtr());

	int retVal = m_processorCompPtr->DoProcessing(
				m_paramsSetCompPtr.GetPtr(),
				inputDataPtr,
				m_outputDataCompPtr.GetPtr(),
				m_progressManagerCompPtr.GetPtr());
	if (retVal != iproc::IProcessor::TS_OK){
		SendErrorMessage(0, "Processing failed");
	}
}


// public methods of the embedded class ParamsObserver

CModelBasedProcessingTriggerComp::ParamsObserver::ParamsObserver(CModelBasedProcessingTriggerComp& parent)
	:m_parent(parent)
{
}


// reimplemented (imod::CSingleModelObserverBase)

void CModelBasedProcessingTriggerComp::ParamsObserver::OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr)
{
	m_parent.DoProcessing();
}


} // namespace iproc


