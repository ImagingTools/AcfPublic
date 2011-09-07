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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icomp/CEnvironmentManagerBase.h"


#include "icomp/IRegistry.h"


namespace icomp
{


// reimplemented (icomp::IRegistryLoader)

const IRegistry* CEnvironmentManagerBase::GetRegistryFromFile(const istd::CString& /*path*/) const
{
	return NULL;
}


// reimplemented (icomp::IComponentEnvironmentManager)

bool CEnvironmentManagerBase::ConfigureEnvironment(const istd::CString& /*configFilePath*/)
{
	return false;
}


istd::CString CEnvironmentManagerBase::GetConfigFilePath() const
{
	return istd::CString::GetEmpty();
}


// reimplemented (icomp::IRegistriesManager)

const IRegistry* CEnvironmentManagerBase::GetRegistry(const CComponentAddress& address, const IRegistry* contextRegistryPtr) const
{
	if ((contextRegistryPtr != NULL) && address.GetPackageId().empty()){
		return contextRegistryPtr->GetEmbeddedRegistry(address.GetComponentId());
	}

	return NULL;
}


istd::CString CEnvironmentManagerBase::GetPackageDirPath(const std::string& /*packageId*/) const
{
	return istd::CString::GetEmpty();
}


// reimplemented (icomp::IMetaInfoManager)

CEnvironmentManagerBase::ComponentAddresses CEnvironmentManagerBase::GetComponentAddresses(int typeFlag) const
{
	ComponentAddresses retVal;

	Ids packageIds = GetMetaIds(MGI_EMBEDDED_COMPONENTS);
	for (		Ids::const_iterator packageIter = packageIds.begin();
				packageIter != packageIds.end();
				++packageIter){
		const std::string packageName = *packageIter;

		const IComponentStaticInfo* packageInfoPtr = GetEmbeddedComponentInfo(packageName);
		if (packageInfoPtr != NULL){
			Ids componentIds = packageInfoPtr->GetMetaIds(MGI_EMBEDDED_COMPONENTS);

			icomp::CComponentAddress address;
			address.SetPackageId(packageName);

			for (		Ids::const_iterator componentIter = componentIds.begin();
						componentIter != componentIds.end();
						++componentIter){
				const std::string componentName = *componentIter;

				const IComponentStaticInfo* componentInfoPtr = GetEmbeddedComponentInfo(componentName);
				if (componentInfoPtr != NULL){
					int componentType = componentInfoPtr->GetComponentType();

					if ((typeFlag & (1 << componentType)) != 0){
						address.SetComponentId(*componentIter);
					}

					retVal.insert(address);
				}
			}
		}
	}

	return retVal;
}


const IComponentStaticInfo* CEnvironmentManagerBase::GetComponentMetaInfo(const CComponentAddress& address) const
{
	const icomp::IComponentStaticInfo* packageInfoPtr = GetEmbeddedComponentInfo(address.GetPackageId());
	if (packageInfoPtr != NULL){
		return packageInfoPtr->GetEmbeddedComponentInfo(address.GetComponentId());
	}

	return NULL;
}


const IComponentStaticInfo* CEnvironmentManagerBase::GetPackageMetaInfo(const std::string& packageId) const
{
	return GetEmbeddedComponentInfo(packageId);
}



} // namespace icomp


