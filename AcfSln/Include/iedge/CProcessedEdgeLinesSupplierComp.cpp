/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include "iedge/CProcessedEdgeLinesSupplierComp.h"


namespace iedge
{


// reimplemented (iedge::IEdgeLinesProvider)

const CEdgeLineContainer* CProcessedEdgeLinesSupplierComp::GetEdgesContainer() const
{
	return GetWorkProduct();
}


// protected methods

// reimplemented (iinsp::TSupplierCompWrap)

int CProcessedEdgeLinesSupplierComp::ProduceObject(CEdgeLineContainer& result) const
{
	if (!m_edgeLinesProviderCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component architecture, 'EdgeLinesProvider' component reference is not set");

		return WS_CRITICAL;
	}

	if (!m_edgesProcessorCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component architecture, 'EdgesProcessor' component reference is not set");

		return WS_CRITICAL;
	}

	const CEdgeLineContainer* containerPtr = m_edgeLinesProviderCompPtr->GetEdgesContainer();
	if (containerPtr != NULL){
		Timer performanceTimer(this, "Edge processing");
		Q_UNUSED(performanceTimer);

		if (m_edgesProcessorCompPtr->DoLinesProcessing(GetModelParametersSet(), *containerPtr, result)){
			istd::TDelPtr<i2d::ICalibration2d> newCalibration;

			// copy calibration from original
			const i2d::ICalibration2d* calibrationPtr = containerPtr->GetCalibration();
			if (calibrationPtr != NULL){
				newCalibration.SetCastedOrRemove(calibrationPtr->CloneMe());
			}

			result.SetCalibration(newCalibration.PopPtr(), true);

			return WS_OK;
		}
	}

	return WS_ERROR;
}


// reimplemented (icomp::CComponentBase)

void CProcessedEdgeLinesSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_edgeLinesProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_edgeLinesProviderModelCompPtr.GetPtr(), m_edgeLinesSupplierCompPtr.GetPtr());
	}

	// Force components initialization
	m_edgeLinesProviderCompPtr.EnsureInitialized();
	m_edgesProcessorCompPtr.EnsureInitialized();
}


} // namespace iedge


