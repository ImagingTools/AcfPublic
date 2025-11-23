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


#include <ipackage/CComponentAccessor.h>


// ACF includes
#include <icomp/IComponentEnvironmentManager.h>
#include <icomp/IRegistryLoader.h>
#include <icomp/TSimComponentWrap.h>
#include <icomp/CCompositeComponentContext.h>
#include <icomp/CRegistryElement.h>
#include <ifile/TFileSerializerComp.h>
#include <ifile/CSimpleXmlFileReadArchive.h>
#include <ifile/CSimpleXmlFileWriteArchive.h>
#include <ifile/CComposedFilePersistenceComp.h>
#include <ifile/CCompactXmlFileReadArchive.h>
#include <ifile/CCompactXmlFileWriteArchive.h>
#include <ilog/CConsoleLogComp.h>
#include <ipackage/CPackagesLoaderComp.h>


namespace
{


typedef ifile::TFileSerializerComp<ifile::CSimpleXmlFileReadArchive, ifile::CSimpleXmlFileWriteArchive> SimpleXmlSerializer;
typedef ifile::TFileSerializerComp<ifile::CCompactXmlFileReadArchive, ifile::CCompactXmlFileWriteArchive> CompactXmlSerializer;


struct Loader
{
	icomp::TSimSharedComponentPtr<SimpleXmlSerializer> oldRegistrySerializerComp;
	icomp::TSimSharedComponentPtr<CompactXmlSerializer> registrySerializerComp;
	icomp::TSimSharedComponentPtr<ifile::CComposedFilePersistenceComp> composedSerializerComp;
	icomp::TSimSharedComponentPtr<ipackage::CPackagesLoaderComp> packagesLoaderComp;
	icomp::TSimSharedComponentPtr<ilog::CConsoleLogComp> log;

	explicit Loader(bool isDiagnosticEnabled)
	{
		log->SetBoolAttr("UseCategory", false);
		log->SetBoolAttr("UseCode", false);
		log->InitComponent();

		oldRegistrySerializerComp->InsertMultiAttr("FileExtensions", QString("arx"));
		oldRegistrySerializerComp->InitComponent();

		registrySerializerComp->InsertMultiAttr("FileExtensions", QString("acc"));
		if (isDiagnosticEnabled){
			registrySerializerComp->SetRef("Log", log);
			registrySerializerComp->SetBoolAttr("EnableVerbose", true);
		}
		registrySerializerComp->InitComponent();

		composedSerializerComp->InsertMultiRef("SlaveLoaders", oldRegistrySerializerComp);
		composedSerializerComp->InsertMultiRef("SlaveLoaders", registrySerializerComp);
		composedSerializerComp->InitComponent();

		packagesLoaderComp->SetRef("RegistryLoader", composedSerializerComp);

		if (isDiagnosticEnabled){
			packagesLoaderComp->SetRef("Log", log);
			packagesLoaderComp->SetBoolAttr("EnableVerbose", true);
		}

		packagesLoaderComp->InitComponent();
	}
};


}


namespace ipackage
{


CComponentAccessor::CComponentAccessor(
			const QString& registryFile,
			const QString& configFile,
			bool isDiagnosticEnabled,
			bool manualAutoInit)
:	m_mainComponent(manualAutoInit)
{
	static Loader loader(isDiagnosticEnabled);
	loader.packagesLoaderComp->LoadPackages(configFile);

	QString usedRegistryFile = registryFile.isEmpty()? QString("default.acc"): registryFile;
	const icomp::IRegistry* registryPtr = loader.packagesLoaderComp->GetRegistryFromFile(usedRegistryFile);
	if (registryPtr != NULL){
		static icomp::CRegistryElement dummyElement;

		m_mainComponentStaticInfoPtr.SetPtr(new icomp::CCompositeComponentStaticInfo(
					*registryPtr,
					*loader.packagesLoaderComp,
					NULL));

		m_mainComponentContextPtr.reset(new icomp::CCompositeComponentContext(
					&dummyElement,
					m_mainComponentStaticInfoPtr.GetPtr(),
					registryPtr,
					&(*loader.packagesLoaderComp),
					NULL,
					""));
		m_mainComponent.SetComponentContext(m_mainComponentContextPtr, NULL, false);
	}
}


bool CComponentAccessor::EnsureAutoInitComponentsCreated() const
{
	return m_mainComponent.EnsureAutoInitComponentsCreated();
}


} // namespace ipackage


