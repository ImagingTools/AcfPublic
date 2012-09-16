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


#include "iipr/CTubeProjectionLinesProviderComp.h"


// ACF includes
#include "iprm/TParamsPtr.h"
#include "imeas/INumericValue.h"
#include "i2d/CTubeProjectionsGenerator.h"


namespace iipr
{


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
		
		return i2d::CTubeProjectionsGenerator::GeneratorProjections(*tubeRegionPtr, projectionsCount, result) ? WS_OK : WS_ERROR;
	}

	return WS_CRITICAL;
}


} // namespace iipr


