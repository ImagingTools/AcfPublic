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


#include "iipr/CImageRegionProcessorCompBase.h"


// Qt includes
#include <QtCore/QStringList>

 // ACF includes
#include "istd/TChangeNotifier.h"
#include "ibase/CSize.h"
#include "i2d/IObject2d.h"
#include "i2d/ICalibrationProvider.h"
#include "iimg/IBitmap.h"
#include "iprm/TParamsPtr.h"

// IACF includes
#include "iipr/TImagePixelInterpolator.h"


namespace iipr
{


// public methods

// reimplemented (iproc::IProcessor)

int CImageRegionProcessorCompBase::DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* /*progressManagerPtr*/)
{
	const iimg::IBitmap* inputBitmapPtr = dynamic_cast<const iimg::IBitmap*>(inputPtr);
	if (inputBitmapPtr == NULL){
		SendErrorMessage(0, "Processor input is not a bitmap");

		return TS_INVALID;
	}

	i2d::CRectangle inputImageArea(inputBitmapPtr->GetImageSize());

	iprm::TParamsPtr<i2d::IObject2d> aoiPtr(paramsPtr, *m_aoiParamIdAttrPtr);

	istd::TDelPtr<i2d::IObject2d> transformedRegionPtr;

	if (aoiPtr.IsValid()){
		const i2d::ITransformation2d* logToPhysicalTransformPtr = NULL;
		if (m_regionCalibrationProviderCompPtr.IsValid()){
			logToPhysicalTransformPtr = m_regionCalibrationProviderCompPtr->GetCalibration();
		}

		if (logToPhysicalTransformPtr != NULL){
			transformedRegionPtr.SetCastedOrRemove<istd::IChangeable>(aoiPtr->CloneMe());

			if (transformedRegionPtr.IsValid()){
				if (!transformedRegionPtr->Transform(*logToPhysicalTransformPtr)){
					SendErrorMessage(0, "2D-transformation of the processing region failed");

					return TS_INVALID;
				}

				aoiPtr.SetPtr(transformedRegionPtr.GetPtr());
			}
		}
	}
	else{
		if (*m_allowEmptyRegionAttrPtr){
			aoiPtr.SetPtr(&inputImageArea);			
		}
	}

	return ProcessImageRegion(*inputBitmapPtr, paramsPtr, aoiPtr.GetPtr(), outputPtr) ? TS_OK : TS_INVALID;
}


} // namespace iipr


