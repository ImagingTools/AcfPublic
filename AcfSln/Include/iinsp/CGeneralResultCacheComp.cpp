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


#include "iinsp/CGeneralResultCacheComp.h"


namespace iinsp
{


CGeneralResultCacheComp::CGeneralResultCacheComp()
:	m_result(istd::IInformation::IC_CRITICAL)
{
}


// reimplemented (iinsp::IGeneralResultProvider)

istd::IInformation::InformationCategory CGeneralResultCacheComp::GetGeneralResult() const
{
	return m_result;
}


// reimplemented (istd::IChangeable)

bool CGeneralResultCacheComp::CopyFrom(const IChangeable& object)
{
	const IGeneralResultProvider* providerPtr = dynamic_cast<const IGeneralResultProvider*>(&object);
	if (providerPtr != NULL){
		m_result = providerPtr->GetGeneralResult();

		return true;
	}

	return false;
}


} // namespace iinsp


