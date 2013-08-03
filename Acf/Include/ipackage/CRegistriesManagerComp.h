/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ipackage_CRegistriesManagerComp_included
#define ipackage_CRegistriesManagerComp_included


// Qt includes
#include <QtCore/QMap>
#include <QtCore/QDir>

// ACF includes
#include "istd/TDelPtr.h"
#include "icomp/IExtPackagesManager.h"
#include "icomp/IRegistriesManager.h"
#include "icomp/IRegistryLoader.h"
#include "icomp/CComponentBase.h"
#include "ilog/TLoggerCompWrap.h"
#include "ifile/IFilePersistence.h"
#include "ifile/IFileNameParam.h"


namespace ipackage
{


/**
	Loads component packages from dynamic link libraries.
*/
class CRegistriesManagerComp:
			public ilog::CLoggerComponentBase,
			virtual public icomp::IExtPackagesManager,
			virtual public icomp::IRegistriesManager,
			virtual public icomp::IRegistryLoader
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;

	enum MessageId
	{
		MI_CANNOT_REGISTER = 650,
		MI_CANNOT_CREATE_ELEMENT
	};

	I_BEGIN_COMPONENT(CRegistriesManagerComp);
		I_REGISTER_INTERFACE(icomp::IExtPackagesManager);
		I_REGISTER_INTERFACE(icomp::IPackagesManager);
		I_REGISTER_INTERFACE(icomp::IRegistriesManager);
		I_REGISTER_INTERFACE(icomp::IRegistryLoader);
		I_ASSIGN(m_registryLoaderCompPtr, "RegistryLoader", "Loader used to read registry", true, "RegistryLoader");
		I_ASSIGN(m_configFilePathCompPtr, "ConfigFilePath", "Path of packages configuration file will be loaded, if enabled", false, "ConfigFilePath");
	I_END_COMPONENT;

	// reimplemented (icomp::IPackagesManager)
	virtual bool LoadPackages(const QString& configFilePath = QString());
	virtual int GetPackageType(const QByteArray& packageId) const;
	virtual QString GetPackagePath(const QByteArray& packageId) const;

	// reimplemented (icomp::IExtRegistriesManager)
	virtual PathList GetConfigurationPathList(PathType pathType) const;

	// reimplemented (icomp::IRegistriesManager)
	virtual const icomp::IRegistry* GetRegistry(const icomp::CComponentAddress& address, const icomp::IRegistry* contextRegistryPtr = NULL) const;

	// reimplemented (icomp::IRegistryLoader)
	virtual const icomp::IRegistry* GetRegistryFromFile(const QString& path) const;

protected:
	void RegisterPackageFile(const QString& file);
	void RegisterPackagesDir(const QString& subDir);
	bool LoadConfigFile(const QString& configFile);

	bool CheckAndMarkPath(PathList& pathList, const QDir& directory, const QString& path, QString& resultPath) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	/**
		Map package ID to package file path.
	*/
	typedef QMap<QByteArray, QString> RealPackagesMap;
	RealPackagesMap m_realPackagesMap;

	/**
		Map package ID to directory.
	*/
	typedef QMap<QByteArray, QDir> CompositePackagesMap;
	CompositePackagesMap m_compositePackagesMap;

	typedef istd::TDelPtr<icomp::IRegistry> RegistryPtr;
	typedef QMap<QString, RegistryPtr> RegistriesMap;

	mutable RegistriesMap m_registriesMap;

	mutable PathList m_usedConfigFilesList;
	mutable PathList m_usedPackageDirsList;
	mutable PathList m_usedPackageFilesList;
	mutable PathList m_usedRegistryFilesList;

	I_REF(ifile::IFilePersistence, m_registryLoaderCompPtr);
	I_REF(ifile::IFileNameParam, m_configFilePathCompPtr);
};


} // namespace ipackage


#endif // !ipackage_CRegistriesManagerComp_included


