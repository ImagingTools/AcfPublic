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


#include "iipr/CSingleFeatureConsumer.h"


// ACF-Solutions includes
#include "imeas/INumericValue.h"


namespace iipr
{


// public methods
	
CSingleFeatureConsumer::CSingleFeatureConsumer(int featurePolicy)
	:m_featurePolicy(featurePolicy)
{
}


int CSingleFeatureConsumer::GetFeaturePolicy() const
{
	return m_featurePolicy;
}


void CSingleFeatureConsumer::SetFeaturePolicy(int featurePolicy)
{
	ResetFeatures();

	m_featurePolicy = featurePolicy;
}


// reimplemented (iipr::IFeaturesConsumer)

void CSingleFeatureConsumer::ResetFeatures()
{
	m_featurePtr.Reset();
}


bool CSingleFeatureConsumer::AddFeature(const imeas::INumericValue* featurePtr, bool* isFullPtr)
{
	Q_ASSERT(featurePtr != NULL);
	if (!m_featurePtr.IsValid() || m_featurePolicy == FP_LAST){
		m_featurePtr.SetPtr(featurePtr);
	}
	else{
		switch (m_featurePolicy){
			case FP_FIRST:
				delete featurePtr;
				break;

			case FP_HEAVIEST:
				if (		m_featurePtr.IsValid() &&
							featurePtr->IsValueTypeSupported(imeas::INumericValue::VTI_WEIGHT) && 
							m_featurePtr->IsValueTypeSupported(imeas::INumericValue::VTI_WEIGHT)){
				
					double featureWeight = featurePtr->GetComponentValue(imeas::INumericValue::VTI_WEIGHT).GetElement(0);
					double currentWeight = m_featurePtr->GetComponentValue(imeas::INumericValue::VTI_WEIGHT).GetElement(0);
				
					if (featureWeight > currentWeight){
						m_featurePtr.SetPtr(featurePtr);
						break;
					}
				}

				delete featurePtr;
				break;

			default:
				delete featurePtr;
				break;
		}
	}

	if (isFullPtr != NULL){
		*isFullPtr = false;
	}

	return true;
}


// reimplemented (imeas::INumericValueProvider)

int CSingleFeatureConsumer::GetValuesCount() const
{
	return m_featurePtr.IsValid() ? 1 : 0;
}


const imeas::INumericValue& CSingleFeatureConsumer::GetNumericValue(int I_IF_DEBUG(index)) const
{
	Q_ASSERT(m_featurePtr.IsValid());
	I_IF_DEBUG(Q_ASSERT(index == 0));

	return *m_featurePtr.GetPtr();
}


} // namespace iipr


