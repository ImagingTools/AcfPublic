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


#include <iipr/CFeatureToImageMapperProcessorComp.h>

#include <imeas/INumericValue.h>


namespace iipr
{


// reimplemented (iipr::IFeatureToFeatureProcessor)

int CFeatureToImageMapperProcessorComp::DoConvertFeatures(
			const iprm::IParamsSet* paramsPtr,
			const imeas::INumericValueProvider& container,
			IFeaturesConsumer& results)
{
	if (!m_featuresMapperCompPtr.IsValid()){
		return TS_INVALID;
	}

	int featuresCount = container.GetValuesCount();

	for (int featureIndex = 0; featureIndex < featuresCount; featureIndex++){
		const imeas::INumericValue& feature = container.GetNumericValue(featureIndex);

		i2d::CVector2d position;
		if (m_featuresMapperCompPtr->GetImagePosition(feature, paramsPtr, position)){
			double weight = 1.0;

			if (feature.IsValueTypeSupported(imeas::INumericValue::VTI_WEIGHT)){
				weight = feature.GetComponentValue(imeas::INumericValue::VTI_WEIGHT).GetElement(0);
			}

			PositionFeature* positionFeaturePtr = new PositionFeature(weight);
			positionFeaturePtr->SetPosition(position);

			bool isFull = false;
			results.AddFeature(positionFeaturePtr, &isFull);

			if (isFull){
				break;
			}
		}
		else if (!*m_ignoreNotMappableAttrPtr){
			return TS_INVALID;
		}
	}

	return TS_OK;
}


// reimplemented (iproc::IProcessor)

int CFeatureToImageMapperProcessorComp::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* /*progressManagerPtr*/)
{
	if (outputPtr == NULL){
		return TS_OK;
	}

	const imeas::INumericValueProvider* containerPtr = dynamic_cast<const imeas::INumericValueProvider*>(inputPtr);
	IFeaturesConsumer* consumerPtr = dynamic_cast<IFeaturesConsumer*>(outputPtr);

	if (		(containerPtr == NULL) ||
				(consumerPtr == NULL)){
		return TS_INVALID;
	}

	return DoConvertFeatures(paramsPtr, *containerPtr, *consumerPtr);
}


} // namespace iipr


