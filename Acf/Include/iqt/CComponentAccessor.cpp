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


#include "icomp/IRegistryLoaderProvider.h"
#include "icomp/IComponentEnvironmentManager.h"
#include "icomp/IRegistryLoader.h"
#include "icomp/CCompositeComponentContext.h"
#include "icomp/CRegistryElement.h"

#include "iqt/CDefaultRegistryLoaderProvider.h"


namespace iqt
{


CComponentAccessor::CComponentAccessor(
		const QString& registryFile,
		const QString& configFile)
: m_registryFile(registryFile),
m_isAutoInitBlocked(false),
m_packageStaticInfo(NULL)
{
	if (m_registryFile.isEmpty()){
		m_registryFile = "default.arx";
	}

	static iqt::CDefaultRegistryLoaderProvider registryProvider;

	icomp::IComponentEnvironmentManager* managerPtr = registryProvider.GetEnvironmentManager();
	if (managerPtr == NULL){
		return;
	}

	managerPtr->LoadPackages(configFile);

	const icomp::IComponentStaticInfo* staticInfoPtr = dynamic_cast<const icomp::IComponentStaticInfo*>(managerPtr);
	if (staticInfoPtr == NULL){
		return;
	}

	const icomp::IRegistryLoader* registryLoaderPtr = registryProvider.GetRegistryLoader();
	if (registryLoaderPtr == NULL){
		return;
	}

	const icomp::IRegistry* registryPtr = registryLoaderPtr->GetRegistryFromFile(m_registryFile);
	if (registryPtr == NULL){
		return;
	}

	static icomp::CRegistryElement dummyElement;

	m_composite.BeginAutoInitBlock();
	m_isAutoInitBlocked = true;

	static icomp::CCompositeComponentContext compositeContext(
			&dummyElement,
			staticInfoPtr,
			registryPtr,
			managerPtr,
			NULL,
			"");
	m_composite.SetComponentContext(&compositeContext, NULL, false);

	// remove constness in order to register embedded static info
	m_packageStaticInfo = const_cast<icomp::CPackageStaticInfo*>(
			dynamic_cast<const icomp::CPackageStaticInfo*>(staticInfoPtr));

	// create and register static info for embedded compositions
	icomp::IRegistry::Ids embeddedRegistryIds = registryPtr->GetEmbeddedRegistryIds();
	for (icomp::IRegistry::Ids::const_iterator iter = embeddedRegistryIds.begin();
			iter != embeddedRegistryIds.end();
			iter++){
		icomp::IRegistry* embeddedRegistry = registryPtr->GetEmbeddedRegistry(*iter);
		Q_ASSERT(embeddedRegistry != NULL);
		icomp::CCompositeComponentStaticInfo* newInfo;
		newInfo = new icomp::CCompositeComponentStaticInfo(*embeddedRegistry, *managerPtr, staticInfoPtr);
		m_packageStaticInfo->RegisterEmbeddedComponentInfo(*iter, newInfo);
	}
}


CComponentAccessor::~CComponentAccessor()
{
	// unregister embedded registry info
	if (m_packageStaticInfo != NULL){
		m_packageStaticInfo->Reset();
	}
}

} // namespace iqt


