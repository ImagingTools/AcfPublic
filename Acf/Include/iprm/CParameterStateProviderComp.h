/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iprm_CParameterStateProviderComp_included
#define iprm_CParameterStateProviderComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <iprm/IParameterStateProvider.h>


namespace iprm
{


/**
	Component implementation of iprm::IParameterStateProvider interface.
*/
class CParameterStateProviderComp:
			public icomp::CComponentBase,
			virtual public iprm::IParameterStateProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CParameterStateProviderComp);
		I_REGISTER_INTERFACE(iprm::IParameterStateProvider);
		I_ASSIGN(m_slaveStateProviderCompPtr, "SlaveStateProvider", "Slave state provider", false, "SlaveStateProvider");
		I_ASSIGN(m_editActivationIdAttrPtr, "EditActivatorId", "ID of the edit activation parameter in the parameter set", true, "");
		I_ASSIGN_MULTI_0(m_controlledIdsAttrPtr, "ControlledIds", "IDs of related (affected) parameters in the parameter set", true);
	I_END_COMPONENT;

	// reimplemented (iprm::IParameterStateProvider)
	virtual ParameterState GetState(
				const iprm::IParamsSet& paramSet,
				const QByteArray& parameterId,
				StateType stateType) const;

private:
	I_ATTR(QByteArray, m_editActivationIdAttrPtr);
	I_MULTIATTR(QByteArray, m_controlledIdsAttrPtr);
	I_REF(iprm::IParameterStateProvider, m_slaveStateProviderCompPtr);
};


} // namespace iprm


#endif // !iprm_CParameterStateProviderComp_included


