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


#include "iipr/CTubeProjectionLinesProviderComp.h"


// ACF includes
#include "iprm/TParamsPtr.h"
#include "imeas/INumericValue.h"
#include "iipr/CTubeProjectionsGenerator.h"


namespace iipr
{


// reimplemented (i2d::ICalibrationProvider)

const i2d::ITransformation2d* CTubeProjectionLinesProviderComp::GetCalibration() const
{
	if (m_calibrationProviderCompPtr.IsValid()){
		return m_calibrationProviderCompPtr->GetCalibration();
	}

	return NULL;
}


// reimplemented (iipr::CMultiLineSupplierCompBase)

int CTubeProjectionLinesProviderComp::ProduceObject(ProductType& result) const
{
	result.clear();

	iprm::IParamsSet* paramsPtr = GetModelParametersSet();
	if (paramsPtr == NULL){
		return WS_CRITICAL;
	}

	iprm::TParamsPtr<i2d::CTubePolyline> tubeRegionPtr(paramsPtr, *m_tubeParamsIdAttrPtr);
	if (tubeRegionPtr.IsValid()){
		int projectionsCount = 2;
		iprm::TParamsPtr<imeas::INumericValue> linesCountPtr(paramsPtr, *m_linesCountParamsIdAttrPtr);
		if (linesCountPtr.IsValid()){
			const imath::CVarVector values = linesCountPtr->GetValues();
			if (values.GetElementsCount() > 0){
				projectionsCount = qMax<int>(2, (int)values.GetElement(0));
			}
		}

		Timer performanceTimer(this, "Tube generating");

		if (iipr::CTubeProjectionsGenerator::GenerateProjections(*tubeRegionPtr, projectionsCount, result)){
			if (m_calibrationProviderCompPtr.IsValid()){
				const i2d::ITransformation2d* transformPtr = m_calibrationProviderCompPtr->GetCalibration();
				if (transformPtr != NULL){
					for (int lineIndex = 0; lineIndex < result.count(); lineIndex++){
						i2d::CLine2d& line = result[lineIndex];

						if (!line.Transform(*transformPtr)){
							result.clear();

							return WS_ERROR;
						}
					}
				}
			}

			return WS_OK;
		}
	
		return WS_ERROR;
	}

	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

// reimplemented (icomp::CComponentBase)

void CTubeProjectionLinesProviderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_calibrationSupplierModelCompPtr.IsValid()){
		RegisterSupplierInput(m_calibrationSupplierModelCompPtr.GetPtr(), m_calibrationSupplierCompPtr.GetPtr());
	}
}


void CTubeProjectionLinesProviderComp::OnComponentDestroyed()
{
	BaseClass::OnComponentDestroyed();

	if (m_calibrationSupplierModelCompPtr.IsValid()){
		UnregisterSupplierInput(m_calibrationSupplierModelCompPtr.GetPtr());
	}
}


} // namespace iipr


