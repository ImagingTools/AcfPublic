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


#ifndef iqt_CDefaultRegistryLoaderProvider_included
#define iqt_CDefaultRegistryLoaderProvider_included


#include "iser/CXmlFileReadArchive.h"
#include "iser/CXmlFileWriteArchive.h"

#include "ibase/TFileSerializerComp.h"

#include "icomp/IRegistryLoaderProvider.h"
#include "icomp/TSimComponentWrap.h"

#include "iqt/CPackagesLoaderComp.h"


namespace iqt
{


/**
	Loads component packages from dynamic link libraries.
*/
class CDefaultRegistryLoaderProvider: virtual public icomp::IRegistryLoaderProvider
{
public:
	CDefaultRegistryLoaderProvider();

	// reimplemented (icomp::IRegistryLoaderProvider)
	virtual icomp::IComponentEnvironmentManager* GetEnvironmentManager() const;
	virtual icomp::IRegistryLoader* GetRegistryLoader() const;
	
private:
	typedef ibase::TFileSerializerComp<iser::CXmlFileReadArchive, iser::CXmlFileWriteArchive> XmlFileSerializer;
	
	icomp::TSimComponentWrap<XmlFileSerializer> m_registryLoaderComp;
	mutable icomp::TSimComponentWrap<iqt::CPackagesLoaderComp> m_packagesLoaderComp;
};


// public inline methods

inline icomp::IComponentEnvironmentManager* CDefaultRegistryLoaderProvider::GetEnvironmentManager() const
{
	return &m_packagesLoaderComp;
}


inline icomp::IRegistryLoader* CDefaultRegistryLoaderProvider::GetRegistryLoader() const
{
	return &m_packagesLoaderComp;
}


} // namespace iqt


#endif // !iqt_CDefaultRegistryLoaderProvider_included


