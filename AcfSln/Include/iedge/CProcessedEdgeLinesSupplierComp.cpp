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


#include "iedge/CProcessedEdgeLinesSupplierComp.h"


namespace iedge
{


// reimplemented (iedge::IEdgeLinesProvider)

const CEdgeLine::Container* CProcessedEdgeLinesSupplierComp::GetEdgesContainer() const
{
	return GetWorkProduct();
}


// protected methods

// reimplemented (iproc::TSupplierCompWrap)

int CProcessedEdgeLinesSupplierComp::ProduceObject(CEdgeLine::Container& result) const
{
	if (m_edgeLinesProviderCompPtr.IsValid() && m_edgesProcessorCompPtr.IsValid()){
		const CEdgeLine::Container* containerPtr = m_edgeLinesProviderCompPtr->GetEdgesContainer();

		if (containerPtr != NULL){
			Timer performanceTimer(this, "Edge processing");

			if (m_edgesProcessorCompPtr->DoLinesProcessing(GetModelParametersSet(), *containerPtr, result)){
				return WS_OK;
			}
		}

		return WS_ERROR;
	}
	else{
		return WS_CRITICAL;
	}
}


// reimplemented (icomp::CComponentBase)

void CProcessedEdgeLinesSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_edgeLinesProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_edgeLinesProviderModelCompPtr.GetPtr(), m_edgeLinesSupplierCompPtr.GetPtr());
	}
}


} // namespace iedge


