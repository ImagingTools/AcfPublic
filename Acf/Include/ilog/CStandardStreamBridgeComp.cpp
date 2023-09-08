/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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


#include <ilog/CStandardStreamBridgeComp.h>


namespace ilog
{


// protected methods

// reimplemented (icomp::CComponentBase)

void CStandardStreamBridgeComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_slaveMessageConsumerCompPtr.IsValid()){
		m_coutBridgePtr.SetPtr(new CStandardStreamBridge(std::cout, *m_slaveMessageConsumerCompPtr, istd::IInformationProvider::IC_INFO));

		m_cerrBridgePtr.SetPtr(new CStandardStreamBridge(std::cerr, *m_slaveMessageConsumerCompPtr, istd::IInformationProvider::IC_ERROR));
	}
}

void CStandardStreamBridgeComp::OnComponentDestroyed()
{
	m_coutBridgePtr.Reset();
	m_cerrBridgePtr.Reset();

	BaseClass::OnComponentDestroyed();
}


} // namespace ilog


