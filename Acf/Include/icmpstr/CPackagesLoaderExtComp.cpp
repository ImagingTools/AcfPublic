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


#include "icmpstr/CPackagesLoaderExtComp.h"


namespace icmpstr
{


// reimplemented (iqt::CPackagesLoaderComp)

bool CPackagesLoaderExtComp::RegisterPackagesDir(const istd::CString& path)
{
	bool retVal = BaseClass::RegisterPackagesDir(path);

	QDir packagesDir(iqt::GetQString(path));

	QStringList infoFilters;
	infoFilters.append("*.arp.info");
	QStringList infoFilesInfo = packagesDir.entryList(infoFilters, QDir::Dirs | QDir::NoDotAndDotDot);
	for (		QStringList::iterator iter = infoFilesInfo.begin();
				iter != infoFilesInfo.end();
				++iter){
		QFileInfo fileInfo(*iter);

		std::string packageName(fileInfo.baseName().toStdString());

		QDir componentInfoDir = packagesDir;
		componentInfoDir.cd(*iter);

		m_packageInfosMap[packageName] = componentInfoDir;
	}

	return retVal;
}


// reimplemented (icmpstr::IExternalMetaInfoManager)

istd::CString CPackagesLoaderExtComp::GetPackageInfoPath(const std::string& packageId) const
{
	PackageInfosMap::const_iterator foundPackageIter = m_packageInfosMap.find(packageId);
	if (foundPackageIter != m_packageInfosMap.end()){
		return iqt::GetCString(foundPackageIter->second.absolutePath());
	}

	return "";
}


istd::CString CPackagesLoaderExtComp::GetComponentInfoPath(const icomp::CComponentAddress& address) const
{
	PackageInfosMap::const_iterator foundPackageIter = m_packageInfosMap.find(address.GetPackageId());
	if (foundPackageIter != m_packageInfosMap.end()){
		return iqt::GetCString(foundPackageIter->second.filePath(address.GetComponentId().c_str()));
	}

	return "";
}


} // namespace icmpstr


