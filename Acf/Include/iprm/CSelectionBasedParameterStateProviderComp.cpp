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


#include <iprm/CSelectionBasedParameterStateProviderComp.h>


// ACF includes
#include <iprm/IParamsSet.h>
#include <iprm/ISelectionParam.h>
#include <iprm/TParamsPtr.h>


namespace iprm
{


// public methods

// reimplemented (iprm::IParameterStateProvider)

iprm::IParameterStateProvider::ParameterState CSelectionBasedParameterStateProviderComp::GetState(
			const iprm::IParamsSet& paramSet,
			const QByteArray& parameterId,
			StateType stateType) const
{
	if (stateType == ST_EDIT){
		int index = m_controlledIdsAttrPtr.FindValue(parameterId);
		if (index >= 0){
			const iprm::ISelectionParam* selectorPtr = dynamic_cast<const iprm::ISelectionParam*>(paramSet.GetParameter(*m_editSelectorIdAttrPtr));
			if (selectorPtr != NULL){
				int selectedIndex = selectorPtr->GetSelectedOptionIndex();

				return m_editActiveIndexesAttrPtr.FindValue(selectedIndex) >= 0 ? PS_ON : PS_OFF;
			}
		}
	}

	if (m_slaveStateProviderCompPtr.IsValid()){
		return m_slaveStateProviderCompPtr->GetState(paramSet, parameterId, stateType);
	}

	return PS_UNKNOWN;
}


} // namespace iprm


