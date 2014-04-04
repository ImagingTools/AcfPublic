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


#include "imeas/CProcessedDataSequenceSupplierComp.h"


namespace imeas
{


// reimplemented (imeas::IDataSequenceProvider)

const imeas::IDataSequence* CProcessedDataSequenceSupplierComp::GetDataSequence() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr;
	}

	return NULL;
}


// reimplemented (iinsp::TSupplierCompWrap)

int CProcessedDataSequenceSupplierComp::ProduceObject(ProductType& result) const
{
	if (!m_dataSequenceProviderCompPtr.IsValid() || !m_dataSequenceProcessorCompPtr.IsValid() || !m_dataSequenceSupplierCompPtr.IsValid()){
		return WS_CRITICAL;
	}

	const imeas::IDataSequence* dataSequencePtr = m_dataSequenceProviderCompPtr->GetDataSequence();
	if (dataSequencePtr == NULL){
		return WS_ERROR;
	}

	Timer performanceTimer(this, "Data sequence processing");

	istd::CChangeNotifier updater(&result);

	m_dataSequenceProcessorCompPtr->InitProcessor(GetModelParametersSet());
	int status = m_dataSequenceProcessorCompPtr->DoProcessing(GetModelParametersSet(), dataSequencePtr, &result);
	switch (status){
	case iproc::IProcessor::TS_OK:
		return WS_OK;

	case iproc::IProcessor::TS_CANCELED:
		return WS_CANCELED;

	default:
		return WS_ERROR;
	}
}


// reimplemented (icomp::CComponentBase)

void CProcessedDataSequenceSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_dataSequenceProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_dataSequenceProviderModelCompPtr.GetPtr(), m_dataSequenceSupplierCompPtr.GetPtr());
	}
}


} // namespace iipr


