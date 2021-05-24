/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iproc_CCascadedProcessorComp_included
#define iproc_CCascadedProcessorComp_included


#include <istd/IChangeable.h>

#include <icomp/CComponentBase.h>

#include <iproc/TSyncProcessorWrap.h>


namespace iproc
{
	

/**
	Processor starting sequence of cascaded processors to processing input object to the output one.
	To realize this task external objects are needed to store temporary results.
*/
class CCascadedProcessorComp:
			public icomp::CComponentBase,
			public CSyncProcessorBase
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CSyncProcessorBase BaseClass2;

	I_BEGIN_COMPONENT(CCascadedProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_ASSIGN_MULTI_0(m_processorsCompPtr, "Processors", "List of processors", true);
		I_ASSIGN_MULTI_0(m_buffersCompPtr, "Buffers", "List of buffers storing data between processors", false);
		I_ASSIGN_MULTI_0(m_progressIdsAttrPtr, "ProgressIds", "List of progress ID's used for progress manager for each processor", false);
		I_ASSIGN_MULTI_0(m_progressDescriptionsAttrPtr, "ProgressDescriptions", "List of progress descriptions used for progress manager for each processor", false);
	I_END_COMPONENT;

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
	virtual void InitProcessor(const iprm::IParamsSet* paramsPtr);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_MULTIREF(iproc::IProcessor, m_processorsCompPtr);
	I_MULTIREF(istd::IChangeable, m_buffersCompPtr);
	I_MULTIATTR(QByteArray, m_progressIdsAttrPtr);
	I_MULTITEXTATTR(m_progressDescriptionsAttrPtr);
};


} // namespace iproc


#endif // !iproc_CCascadedProcessorComp_included

