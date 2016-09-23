/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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


#include <MePck/CChannelAddressParamComp.h>


namespace imebase
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CChannelAddressParamComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_mailhausAccessCompPtr.IsValid()){
		m_mailhausAccessCompPtr->CreateSelectionTree(*this);
	}
}

	
void CChannelAddressParamComp::OnComponentDestroyed()
{
	ResetNodes();

	BaseClass::OnComponentDestroyed();
}


} // namespace imebase


