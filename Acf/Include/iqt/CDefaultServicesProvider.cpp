/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CDefaultServicesProvider.h"


// ACF includes
#include "istd/TSingleFactory.h"
#include "istd/CStaticServicesProvider.h"

#include "iqt/CTimer.h"
#include "iqt/CApplicationEnvironment.h"
#include "iqt/CCriticalSection.h"
#include "iqt/CFileSystem.h"
#include "iqt/CDefaultRegistryLoaderProvider.h"
#include "iqt/CSystemEnvironment.h"


namespace iqt
{


void CDefaultServicesProvider::RegisterServices()
{
	static iqt::CApplicationEnvironment applicationEnvironment;
	istd::CStaticServicesProvider::RegisterService<isys::IApplicationEnvironment>(&applicationEnvironment);

	static iqt::CCriticalSection criticalSection;
	istd::CStaticServicesProvider::RegisterService<isys::ICriticalSection>(&criticalSection);

	static iqt::CFileSystem fileSystem;
	istd::CStaticServicesProvider::RegisterService<isys::IFileSystem>(&fileSystem);

	static iqt::CDefaultRegistryLoaderProvider registryLoaderProvider;
	istd::CStaticServicesProvider::RegisterService<icomp::IRegistryLoaderProvider>(&registryLoaderProvider);

	static iqt::CSystemEnvironment systemEnvironment;
	istd::CStaticServicesProvider::RegisterService<isys::ISystemEnvironment>(&systemEnvironment);

	static istd::TSingleFactory<isys::ITimer, iqt::CTimer> timerFactory("");
	istd::CStaticServicesProvider::RegisterFactory(&timerFactory);

	static istd::TSingleFactory<isys::ICriticalSection, iqt::CCriticalSection> criticalSectionFactory("");
	istd::CStaticServicesProvider::RegisterFactory(&criticalSectionFactory);
}


} // namespace iqt


