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


#include "imeas/CDataSequenceJoinerSupplierComp.h"

namespace imeas
{


// public methods

// reimplemented (imeas::IDataSequenceProvider)

const imeas::IDataSequence* CDataSequenceJoinerSupplierComp::GetDataSequence() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr;
	}

	return NULL;
}


// reimplemented (iproc::TSupplierCompWrap)

int CDataSequenceJoinerSupplierComp::ProduceObject(ProductType& result) const
{
	if (!m_dataSequenceProviderCompPtr.IsValid() && !m_multiDataSequenceProviderCompPtr.IsValid()){
		return WS_CRITICAL;
	}

	if (!m_dataSequenceSupplierCompPtr.IsValid() && !m_multiDataSequenceSupplierCompPtr.IsValid()){
		return WS_CRITICAL;
	}

	istd::CChangeNotifier updater(&result);

	result.ResetSequence();

	if (m_dataSequenceProviderCompPtr.IsValid()){
		int providerCount = m_dataSequenceProviderCompPtr.GetCount();
		int endSamplesCount = 0;
		int endChannelsCount = 0;
		for (int providerIndex = 0; providerIndex < providerCount; ++providerIndex){
			imeas::IDataSequenceProvider* provider = m_dataSequenceProviderCompPtr[providerIndex];
			if ((provider != NULL)){
				const imeas::IDataSequence* sequence = provider->GetDataSequence();
				if (sequence != NULL){
					int samplesCount = sequence->GetSamplesCount();
					int channelsCount = sequence->GetChannelsCount();
					if (endSamplesCount < samplesCount){
						endSamplesCount = samplesCount;
					}
					endChannelsCount += channelsCount;
				}
			}
		}

		result.CreateSequence(endSamplesCount, endChannelsCount);

		int actChannel = 0;

		for (int providerIndex = 0; providerIndex < providerCount; ++providerIndex){
			imeas::IDataSequenceProvider* provider = m_dataSequenceProviderCompPtr[providerIndex];
			if (provider != NULL){
				const imeas::IDataSequence* sequence = provider->GetDataSequence();
				if (sequence != NULL){
					int channelsCount = sequence->GetChannelsCount();
					for (int channelsIndex = 0; channelsIndex < channelsCount; ++channelsIndex){
						int samplesCount = sequence->GetSamplesCount();
						for (int samplesIndex = 0; samplesIndex < samplesCount; ++samplesIndex){
							result.SetSample(samplesIndex, actChannel, sequence->GetSample(samplesIndex, channelsIndex));
						}
						actChannel++;
					}
				}
			}
		}
	}
	else if(m_multiDataSequenceProviderCompPtr.IsValid()){
		int multiProviderCount = m_multiDataSequenceProviderCompPtr.GetCount();
		for (int multiProviderIndex = 0; multiProviderIndex < multiProviderCount; ++multiProviderIndex){
			imeas::IMultiDataSequenceProvider* provider = m_multiDataSequenceProviderCompPtr[multiProviderIndex];
			if (provider != NULL){
				int sequenceCount = provider->GetSequencesCount();
				for (int sequenceIndex = 0; sequenceIndex < sequenceCount; ++sequenceIndex){
					const imeas::IDataSequence* sequence = provider->GetDataSequence(sequenceIndex);
					if (sequence != NULL){
						int channelsCount = sequence->GetChannelsCount();
						for (int channelsIndex = 0; channelsIndex < channelsCount; ++channelsIndex){
							int newChannelIndex = result.GetChannelsCount();
							int samplesCount = sequence->GetSamplesCount();
							for (int samplesIndex = 0; samplesIndex < samplesCount; ++samplesIndex){
								result.SetSample(samplesIndex, newChannelIndex, sequence->GetSample(samplesIndex, channelsIndex));
							}
						}
					}
				}
			}
		}
	}

	return WS_OK;
}


// reimplemented (icomp::CComponentBase)

void CDataSequenceJoinerSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	/*if (m_dataSequenceProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_dataSequenceProviderModelCompPtr, m_dataSequenceSupplierCompPtr);
	}
	if (m_multiDataSequenceProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_multiDataSequenceProviderModelCompPtr, m_multiDataSequenceSupplierCompPtr);
	}*/
}


} // namespace imeas


