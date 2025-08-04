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


#ifndef icomp_CEnvironmentManagerBase_included
#define icomp_CEnvironmentManagerBase_included


// ACF includes
#include <icomp/CPackageStaticInfo.h>
#include <icomp/IComponentEnvironmentManager.h>


namespace icomp
{


class CEnvironmentManagerBase:
			public CPackageStaticInfo,
			virtual public IComponentEnvironmentManager
{
public:
	// reimplemented (icomp::IComponentEnvironmentManager)
	virtual QString GetConfigFilePath() const override;

	// reimplemented (icomp::IPackagesManager)
	virtual bool LoadPackages(const QString& configFilePath = QString()) override;
	virtual int GetPackageType(const QByteArray& packageId) const override;
	virtual QString GetPackagePath(const QByteArray& packageId) const override;
	virtual QString GetRegistryPath(const CComponentAddress& address) const override;

	// reimplemented (icomp::IRegistriesManager)
	virtual const IRegistry* GetRegistry(const CComponentAddress& address, const IRegistry* contextRegistryPtr = NULL) const override;

	// reimplemented (icomp::IComponentListProvider)
	virtual ComponentAddresses GetComponentAddresses(int typeFlag = CTF_ALL) const override;

	// reimplemented (icomp::IMetaInfoManager)
	virtual const IComponentStaticInfo* GetComponentMetaInfo(const CComponentAddress& address) const override;
	virtual const IComponentStaticInfo* GetPackageMetaInfo(const QByteArray& packageId) const override;
};


} // namespace icomp


#endif // !icomp_CEnvironmentManagerBase_included


