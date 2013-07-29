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


#include "iinsp/CComposedInformationProviderComp.h"


namespace iinsp
{


// public methods

// reimplemented (iinsp::IInformationProvider)

QDateTime CComposedInformationProviderComp::GetInformationTimeStamp() const
{
	QDateTime retVal;

	for (int index = 0; index < m_slaveInformationProvidersCompPtr.GetCount(); ++index){
		const istd::IInformationProvider* infoProviderPtr = m_slaveInformationProvidersCompPtr[index];
		if (infoProviderPtr != NULL){
			QDateTime timeStamp = infoProviderPtr->GetInformationTimeStamp();

			if (!retVal.isValid()){
				retVal = timeStamp; 
			}
			else if(retVal < timeStamp){
				retVal = timeStamp;
			}
		}
	}

	return retVal;
}


istd::IInformationProvider::InformationCategory CComposedInformationProviderComp::GetInformationCategory() const
{
	InformationCategory retVal = IC_NONE;

	for (int index = 0; index < m_slaveInformationProvidersCompPtr.GetCount(); ++index){
		const istd::IInformationProvider* infoProviderPtr = m_slaveInformationProvidersCompPtr[index];
		if (infoProviderPtr != NULL){
			InformationCategory informationCategory = infoProviderPtr->GetInformationCategory();
			if (informationCategory > retVal){
				retVal = informationCategory;
			}
		}
	}

	return retVal;
}


int CComposedInformationProviderComp::GetInformationId() const
{
	return -1;
}


QString CComposedInformationProviderComp::GetInformationDescription() const
{
	return *m_defaultDescriptionAttrPtr;
}


QString CComposedInformationProviderComp::GetInformationSource() const
{
	return *m_defaultSourceAttrPtr;
}


int CComposedInformationProviderComp::GetInformationFlags() const
{
	return 0;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CComposedInformationProviderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	int providerModelsCount = m_slaveInformationProviderModelsCompPtr.GetCount();

	for (int index = 0; index < providerModelsCount; ++index){
		imod::IModel* infoProviderModelPtr = m_slaveInformationProviderModelsCompPtr[index];
		if (infoProviderModelPtr != NULL){
			infoProviderModelPtr->AttachObserver(this);
		}
	}
}


void CComposedInformationProviderComp::OnComponentDestroyed()
{
	EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}




} // namespace iinsp


