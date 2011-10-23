/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqt/CComponentAccessor.h"


#include "istd/CStaticServicesProvider.h"

#include "icomp/IRegistryLoaderProvider.h"
#include "icomp/IComponentEnvironmentManager.h"
#include "icomp/IRegistryLoader.h"
#include "icomp/CCompositeComponentContext.h"
#include "icomp/CRegistryElement.h"

#include "iqt/CDefaultRegistryLoaderProvider.h"


namespace iqt
{


CComponentAccessor::CComponentAccessor(
			const istd::CString& registryFile,
			const istd::CString& configFile)
:	m_registryFile(registryFile),
	m_isAutoInitBlocked(false)
{
	if (m_registryFile.IsEmpty()){
		m_registryFile = "default.arx";
	}

	static iqt::CDefaultRegistryLoaderProvider registryProvider;

	icomp::IComponentEnvironmentManager* managerPtr = registryProvider.GetEnvironmentManager();
	if (managerPtr != NULL){
		managerPtr->LoadPackages(configFile);

		const icomp::IComponentStaticInfo* staticInfoPtr = dynamic_cast<const icomp::IComponentStaticInfo*>(managerPtr);
		const icomp::IRegistryLoader* registryLoaderPtr = registryProvider.GetRegistryLoader();
		if ((registryLoaderPtr != NULL) && (staticInfoPtr != NULL)){
			const icomp::IRegistry* registryPtr = registryLoaderPtr->GetRegistryFromFile(m_registryFile.c_str());
			if (registryPtr != NULL){
				static icomp::CRegistryElement dummyElement;

				m_composite.BeginAutoInitBlock();
				m_isAutoInitBlocked = true;

				static icomp::CCompositeComponentContext compositeContext(
					&dummyElement,
					staticInfoPtr,
					registryPtr,
					managerPtr,
					NULL);
				m_composite.SetComponentContext(&compositeContext, NULL, false);
			}
		}
	}
}


} // namespace iqt


