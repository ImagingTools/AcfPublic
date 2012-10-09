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


#ifndef _qcam_CCameraDelegatorBase_included
#define _qcam_CCameraDelegatorBase_included


// ACF includes
#include "ibase/TLoggerCompWrap.h"

// ACF-Solutions includes
#include "icam/IBitmapAcquisition.h"


namespace icam
{


/**
	Implementation of bitmap acquisition delegating all calls to some slave object.
	It is used to provide cascades of camera implementations.
*/
class CCameraDelegatorComp:
			public ibase::CLoggerComponentBase,
			public IBitmapAcquisition
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CCameraDelegatorComp);
		I_REGISTER_INTERFACE(IBitmapAcquisition);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_ASSIGN(m_slaveCameraCompPtr, "SlaveCamera", "Slave camera object", true, "SlaveCamera");
	I_END_COMPONENT;

	// reimplemented (iipr::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;

	// reimplemented (iproc::IProcessor)
	virtual int GetProcessorState(const iprm::IParamsSet* paramsPtr) const;
	virtual bool AreParamsAccepted(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				const istd::IChangeable* outputPtr) const;
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);
	virtual int BeginTask(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);
	virtual int WaitTaskFinished(
					int taskId = -1,
					double timeoutTime = -1,
					bool killOnTimeout = true);
	virtual void CancelTask(int taskId = -1);
	virtual int GetReadyTask();
	virtual int GetTaskState(int taskId = -1) const;
	virtual void InitProcessor(const iprm::IParamsSet* paramsPtr);

protected:
	I_REF(IBitmapAcquisition, m_slaveCameraCompPtr);
};


} // namespace icam


#endif // !_qcam_CCameraDelegatorBase_included


