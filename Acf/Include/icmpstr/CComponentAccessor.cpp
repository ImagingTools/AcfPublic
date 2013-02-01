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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icmpstr/CComponentAccessor.h"


// ACF includes
#include "iser/CXmlFileReadArchive.h"
#include "iser/CXmlFileWriteArchive.h"
#include "icomp/IComponentEnvironmentManager.h"
#include "icomp/IRegistryLoader.h"
#include "icomp/TSimComponentWrap.h"
#include "icomp/CCompositeComponentContext.h"
#include "icomp/CRegistryElement.h"
#include "ibase/TFileSerializerComp.h"
#include "icmpstr/CPackagesLoaderComp.h"


namespace
{

	
struct Loader
{
	icomp::TSimComponentWrap< ibase::TFileSerializerComp<iser::CXmlFileReadArchive, iser::CXmlFileWriteArchive> > registryLoaderComp;
	icomp::TSimComponentWrap<icmpstr::CPackagesLoaderComp> packagesLoaderComp;

	Loader()
	{
		registryLoaderComp.InitComponent();

		packagesLoaderComp.SetRef("RegistryLoader", &registryLoaderComp);
		packagesLoaderComp.InitComponent();
	}
};


}


namespace icmpstr
{


CComponentAccessor::CComponentAccessor(
			const QString& registryFile,
			const QString& configFile)
:	m_isAutoInitBlocked(false)
{
	static Loader loader;
	loader.packagesLoaderComp.LoadPackages(configFile);

	QString usedRegistryFile = registryFile.isEmpty()? QString("default.arx"): registryFile;
	const icomp::IRegistry* registryPtr = loader.packagesLoaderComp.GetRegistryFromFile(usedRegistryFile);
	if (registryPtr != NULL){
		static icomp::CRegistryElement dummyElement;

		m_isAutoInitBlocked = true;

		m_mainComponentStaticInfoPtr.SetPtr(new icomp::CCompositeComponentStaticInfo(
					*registryPtr,
					loader.packagesLoaderComp,
					NULL));

		m_mainComponentContextPtr.SetPtr(new icomp::CCompositeComponentContext(
					&dummyElement,
					m_mainComponentStaticInfoPtr.GetPtr(),
					registryPtr,
					&loader.packagesLoaderComp,
					NULL,
					""));
		m_mainComponent.SetComponentContext(m_mainComponentContextPtr.GetPtr(), NULL, false);
	}
}


} // namespace icmpstr


