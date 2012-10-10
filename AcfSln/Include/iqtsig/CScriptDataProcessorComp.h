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


#ifndef iqtsig_CScriptSampleAcquisitionComp_included
#define iqtsig_CScriptSampleAcquisitionComp_included


// Qt includes
#include <QtScript/QtScript>

// ACF includes
#include "icomp/CComponentBase.h"
#include "ibase/TLoggerCompWrap.h"
#include "iproc/TSyncProcessorWrap.h"

#include "iqtsig/iqtsig.h"


namespace iqtsig
{


/**
	Processor creating some data sequence (sample) using user defined script.
	The user script must define function named \c Calc.
	This function gets one parameter containing zero-based index of sample and it should return sample value.
	Additionally following global variables are defined and can be used from the calculation script:
	\li	frame		index of calculated frame, increased each time new calculation of complete sample was finished.
	\li	minValue	user defined minimal value.
	\li	maxValue	user defined minimal value.
*/
class CScriptDataProcessorComp:
			public ibase::CLoggerComponentBase,
			public iproc::CSyncProcessorBase
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CScriptDataProcessorComp);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_ASSIGN(m_minValueAttrPtr, "MinValue", "Minimal value of sample", true, 0.0);
		I_ASSIGN(m_maxValueAttrPtr, "MaxValue", "Maximal value of sample", true, 100.0);
		I_ASSIGN(m_samplesCountAttrPtr, "SamplesCount", "Number of samples processed in single step", false, 100);
		I_ASSIGN(m_channelsCountAttrPtr, "ChannelsCount", "Number of channels processed in single step", false, 100);
		I_ASSIGN(m_defaultScriptAttrPtr, "DefaultScript", "Default script used to calculate sample output in 'Calc' function", false, "minValue");
		I_ASSIGN(m_scriptParamIdAttrPtr, "ScriptParamId", "ID of script in parameter set (defined as ibase::ITextDocument)", false, "ScriptId");
	I_END_COMPONENT;

	CScriptDataProcessorComp();

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (isig::ISamplingConstraints)
	virtual istd::CRange GetIntervalRange() const;
	virtual bool IsSamplingModeSupported(int mode) const;
	virtual istd::CRange GetValueRange(bool forInput = true, bool forOutput = true, const iprm::IParamsSet* paramsSetPtr = 0) const;
	virtual int GetMaximalSamplesCount(bool forInput = true, bool forOutput = true, const iprm::IParamsSet* paramsSetPtr = 0) const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	QScriptEngine m_scriptEngine;
	int m_frameNumber;

	I_ATTR(double, m_minValueAttrPtr);
	I_ATTR(double, m_maxValueAttrPtr);
	I_ATTR(int, m_samplesCountAttrPtr);
	I_ATTR(int, m_channelsCountAttrPtr);
	I_ATTR(QString, m_defaultScriptAttrPtr);
	I_ATTR(QByteArray, m_scriptParamIdAttrPtr);
};


} // namespace iqtsig


#endif // !iqtsig_CScriptSampleAcquisitionComp_included


