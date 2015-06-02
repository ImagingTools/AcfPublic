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


#include "iedge/CExtractedEdgeLinesSupplierComp.h"


namespace iedge
{


// reimplemented (iedge::IEdgeLinesProvider)

const CEdgeLineContainer* CExtractedEdgeLinesSupplierComp::GetEdgesContainer() const
{
	return GetWorkProduct();
}


// protected methods

// reimplemented (iinsp::TSupplierCompWrap)

int CExtractedEdgeLinesSupplierComp::ProduceObject(CEdgeLineContainer& result) const
{
	result.Reset();

	if (!m_bitmapProviderCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component architecture, 'BitmapProvider' component reference is not set");

		return WS_CRITICAL;
	}

	if (!m_edgesExtractorCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component architecture, 'EdgesExtractor' component reference is not set");

		return WS_CRITICAL;
	}

	const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
	if (bitmapPtr != NULL){
		Timer performanceTimer(this, "Edge extraction");
		Q_UNUSED(performanceTimer);

		if (m_edgesExtractorCompPtr->DoContourExtraction(GetModelParametersSet(), *bitmapPtr, result)){
			const i2d::ICalibration2d* bitmapCalibrationPtr = bitmapPtr->GetCalibration();
			if (bitmapCalibrationPtr != NULL){
				result.Transform(*bitmapCalibrationPtr);	// move to global coordinates
			}

			if (m_calibrationProviderCompPtr.IsValid()){
				const i2d::ICalibration2d* calibrationPtr = m_calibrationProviderCompPtr->GetCalibration();

				if (calibrationPtr != NULL){
					istd::TDelPtr<i2d::ICalibration2d> calibCopyPtr;
					calibCopyPtr.SetCastedOrRemove(calibrationPtr->CloneMe());

					if (calibCopyPtr.IsValid()){
						result.InvTransform(*calibrationPtr);
						result.SetCalibration(calibCopyPtr.PopPtr(), true);
					}
				}
			}

			return WS_OK;
		}
	}

	return WS_ERROR;
}


// reimplemented (icomp::CComponentBase)

void CExtractedEdgeLinesSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr(), m_bitmapSupplierCompPtr.GetPtr());
	}

	if (m_calibrationProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_calibrationProviderModelCompPtr.GetPtr(), m_calibrationSupplierCompPtr.GetPtr());
	}

	// Force components initialization
	m_bitmapProviderCompPtr.EnsureInitialized();
	m_edgesExtractorCompPtr.EnsureInitialized();
}


} // namespace iedge


