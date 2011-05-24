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


#ifndef icomp_CEnvironmentManagerBase_included
#define icomp_CEnvironmentManagerBase_included


#include "icomp/CPackageStaticInfo.h"
#include "icomp/IComponentEnvironmentManager.h"


namespace icomp
{


class CEnvironmentManagerBase:
			public CPackageStaticInfo,
			virtual public IComponentEnvironmentManager
{
public:
	// reimplemented (icomp::IRegistryLoader)
	virtual const IRegistry* GetRegistryFromFile(const istd::CString& path) const;

	// reimplemented (icomp::IComponentEnvironmentManager)
	virtual bool ConfigureEnvironment(const istd::CString& configFilePath = istd::CString());
	virtual istd::CString GetConfigFilePath() const;

	// reimplemented (icomp::IRegistriesManager)
	virtual const IRegistry* GetRegistry(const CComponentAddress& address, const IRegistry* contextRegistryPtr = NULL) const;
	virtual istd::CString GetPackageDirPath(const std::string& packageId) const;

	// reimplemented (icomp::IMetaInfoManager)
	virtual ComponentAddresses GetComponentAddresses(int typeFlag = CTF_ALL) const;
	virtual const IComponentStaticInfo* GetComponentMetaInfo(const CComponentAddress& address) const;
	virtual const IComponentStaticInfo* GetPackageMetaInfo(const std::string& packageId) const;
};


} // namespace icomp


#endif // !icomp_CEnvironmentManagerBase_included


