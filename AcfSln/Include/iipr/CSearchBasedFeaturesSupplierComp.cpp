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


#include "iipr/CSearchBasedFeaturesSupplierComp.h"


namespace iipr
{


// reimplemented (iipr::IFeaturesProvider)

iipr::IFeaturesProvider::Features CSearchBasedFeaturesSupplierComp::GetFeatures() const
{
	const CFeaturesContainer* containerPtr = GetWorkProduct();
	if (containerPtr != NULL){
		return containerPtr->GetFeatures();
	}

	return iipr::IFeaturesProvider::Features();
}


// protected methods

// reimplemented (iproc::TSupplierCompWrap)

int CSearchBasedFeaturesSupplierComp::ProduceObject(CFeaturesContainer& result) const
{
	if (		m_bitmapProviderCompPtr.IsValid() &&
				m_searchProcessorCompPtr.IsValid()){
		const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
		if (bitmapPtr != NULL){
			iprm::IParamsSet* paramsSetPtr = GetModelParametersSet();

			int searchState = m_searchProcessorCompPtr->DoProcessing(
							paramsSetPtr,
							bitmapPtr,
							&result);

			if (searchState != iproc::IProcessor::TS_OK){
				return WS_ERROR;
			}

			return WS_OK;
		}
	}

	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CSearchBasedFeaturesSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr());
	}
}


} // namespace iipr


