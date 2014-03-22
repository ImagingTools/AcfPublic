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


#ifndef iproc_CIterativeProcessorComp_included
#define iproc_CIterativeProcessorComp_included


// Qt includes
#include <QtCore/QString>
#include <QtCore/QVector>

// ACF includes
#include "ilog/TLoggerCompWrap.h"

#include "iprm/IOptionsList.h"

#include "iproc/TSyncProcessorWrap.h"


namespace iproc
{
	

/**
	Processor wrapper for multiple executing of a slave processor.
	Input at k-iteration for the slave operator is processor output at (k-1)-iteration.
*/
class CIterativeProcessorComp:
			public ilog::CLoggerComponentBase,
			public iproc::CSyncProcessorBase,
			virtual public iprm::IOptionsList
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;
	typedef iproc::CSyncProcessorBase BaseClass2;

	enum MessageId
	{
		MI_BAD_BUFFER = 0x6b30
	};

	I_BEGIN_COMPONENT(CIterativeProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_REGISTER_INTERFACE(iprm::IOptionsList);
		I_ASSIGN(m_paramsIdAttrPtr, "IterationParamId", "ID of parameter defining number of iterations (type iprm::ISelectionParam)", true, "ParamsId");
		I_ASSIGN(m_maxIterationsCountAttrPtr, "MaxIterations", "Maximal number of iterations", true, 10);
		I_ASSIGN(m_bufferObjectCompPtr, "BufferObject", "Object used as buffer between single processing steps", true, "BufferObject");
		I_ASSIGN(m_slaveProcessorCompPtr, "SlaveProcessor", "Slave image processor", true, "SlaveProcessor");
	I_END_COMPONENT;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (iprm::IOptionsList)
	virtual int GetOptionsFlags() const;
	virtual int GetOptionsCount() const;
	virtual QString GetOptionName(int index) const;
	virtual QString GetOptionDescription(int index) const;
	virtual QByteArray GetOptionId(int index) const;
	virtual bool IsOptionEnabled(int index) const;

protected:
	int ProcessSlave(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(QByteArray, m_paramsIdAttrPtr);
	I_ATTR(int, m_maxIterationsCountAttrPtr);
	I_REF(istd::IChangeable, m_bufferObjectCompPtr);
	I_REF(iproc::IProcessor, m_slaveProcessorCompPtr);

	QVector<QString> m_iterationNames;
};


} // namespace iproc


#endif // !iproc_CIterativeProcessorComp_included


