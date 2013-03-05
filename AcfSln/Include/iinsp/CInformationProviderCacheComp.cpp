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


#include "iinsp/CInformationProviderCacheComp.h"


namespace iinsp
{


CInformationProviderCacheComp::CInformationProviderCacheComp()
:	m_category(istd::IInformationProvider::IC_NONE)
{
}


// reimplemented (iinsp::IInformationProvider)

QDateTime CInformationProviderCacheComp::GetInformationTimeStamp() const
{
	return m_timeStamp;
}


istd::IInformationProvider::InformationCategory CInformationProviderCacheComp::GetInformationCategory() const
{
	return m_category;
}


int CInformationProviderCacheComp::GetInformationId() const
{
	return m_id;
}


QString CInformationProviderCacheComp::GetInformationDescription() const
{
	return m_description;
}


QString CInformationProviderCacheComp::GetInformationSource() const
{
	return m_source;
}


int CInformationProviderCacheComp::GetInformationFlags() const
{
	return m_flags;
}


// reimplemented (istd::IChangeable)

bool CInformationProviderCacheComp::CopyFrom(const IChangeable& object, CompatibilityMode /*mode*/)
{
	const istd::IInformationProvider* providerPtr = dynamic_cast<const IInformationProvider*>(&object);
	if (providerPtr != NULL){
		m_timeStamp = providerPtr->GetInformationTimeStamp();
		m_category = providerPtr->GetInformationCategory();
		m_id = providerPtr->GetInformationId();
		m_description = providerPtr->GetInformationDescription();
		m_source = providerPtr->GetInformationSource();
		m_flags = providerPtr->GetInformationFlags();

		return true;
	}

	return false;
}


} // namespace iinsp


