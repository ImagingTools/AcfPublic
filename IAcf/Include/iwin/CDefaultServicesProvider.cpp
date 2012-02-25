/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iwin/CDefaultServicesProvider.h"


#include "istd/TSingleFactory.h"
#include "istd/CStaticServicesProvider.h"

#include "isys/CSimpleDateTime.h"

#include "iwin/CTimer.h"
#include "iwin/CProcessEnvironment.h"
#include "iwin/CCriticalSection.h"
#include "iwin/CSystemEnvironment.h"
#include "iwin/CSystemInfo.h"


namespace iwin
{


void CDefaultServicesProvider::RegisterServices()
{
	static iwin::CProcessEnvironment applicationEnvironment;
	istd::CStaticServicesProvider::RegisterService<isys::IProcessEnvironment>(&applicationEnvironment);

	static iwin::CCriticalSection criticalSection;
	istd::CStaticServicesProvider::RegisterService<isys::ICriticalSection>(&criticalSection);

	static iwin::CSystemEnvironment systemEnvironment;
	istd::CStaticServicesProvider::RegisterService<isys::ISystemEnvironment>(&systemEnvironment);

	static istd::TSingleFactory<isys::ITimer, iwin::CTimer> timerFactory("");
	istd::CStaticServicesProvider::RegisterFactory(&timerFactory);

	static istd::TSingleFactory<isys::IDateTime, isys::CSimpleDateTime> dateTimeFactory("");
	istd::CStaticServicesProvider::RegisterFactory(&dateTimeFactory);

	static istd::TSingleFactory<isys::ISystemInfo, iwin::CSystemInfo> systemInfoFactory("");
	istd::CStaticServicesProvider::RegisterFactory(&systemInfoFactory);
}


} // namespace iwin


