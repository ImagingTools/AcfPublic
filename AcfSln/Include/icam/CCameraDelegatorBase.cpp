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


#include "icam/CCameraDelegatorBase.h"


// ACF includes
#include "istd/CIndex2d.h"


namespace icam
{


// reimplemented (iipr::IBitmapAcquisition)

istd::CIndex2d CCameraDelegatorBase::GetBitmapSize(const iprm::IParamsSet* paramsPtr) const
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->GetBitmapSize(paramsPtr);
	}

	return istd::CIndex2d(0, 0);
}


// reimplemented (iproc::IProcessor)

int CCameraDelegatorBase::GetProcessorState(const iprm::IParamsSet* paramsPtr) const
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->GetProcessorState(paramsPtr);
	}

	return PS_UNKNOWN;
}


bool CCameraDelegatorBase::AreParamsAccepted(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			const istd::IChangeable* outputPtr) const
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->AreParamsAccepted(paramsPtr, inputPtr, outputPtr);
	}

	return false;
}


int CCameraDelegatorBase::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			iproc::IProgressManager* progressManagerPtr)
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->DoProcessing(paramsPtr, inputPtr, outputPtr, progressManagerPtr);
	}

	return TS_INVALID;
}


int CCameraDelegatorBase::BeginTask(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			iproc::IProgressManager* progressManagerPtr)
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->BeginTask(paramsPtr, inputPtr, outputPtr, progressManagerPtr);
	}

	return -1;
}


int CCameraDelegatorBase::WaitTaskFinished(
				int taskId,
				double timeoutTime,
				bool killOnTimeout)
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->WaitTaskFinished(taskId, timeoutTime, killOnTimeout);
	}

	return TS_INVALID;
}


void CCameraDelegatorBase::CancelTask(int taskId)
{
	if (m_slaveCameraCompPtr.IsValid()){
		m_slaveCameraCompPtr->CancelTask(taskId);
	}
}


int CCameraDelegatorBase::GetReadyTask()
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->GetReadyTask();
	}

	return -1;
}


int CCameraDelegatorBase::GetTaskState(int taskId) const
{
	if (m_slaveCameraCompPtr.IsValid()){
		return m_slaveCameraCompPtr->GetTaskState(taskId);
	}

	return TS_INVALID;
}


void CCameraDelegatorBase::InitProcessor(const iprm::IParamsSet* paramsPtr)
{
	if (m_slaveCameraCompPtr.IsValid()){
		m_slaveCameraCompPtr->InitProcessor(paramsPtr);
	}
}


} // namespace icam


