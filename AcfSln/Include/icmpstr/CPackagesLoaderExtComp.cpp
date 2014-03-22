/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "icmpstr/CPackagesLoaderExtComp.h"


namespace icmpstr
{


// reimplemented (iqt::CPackagesLoaderComp)

bool CPackagesLoaderExtComp::RegisterPackagesDir(const QString& path)
{
	bool retVal = BaseClass::RegisterPackagesDir(path);

	QDir packagesDir(path);

	QStringList infoFilters;
	infoFilters.append("*.arp.info");
	QStringList infoFilesInfo = packagesDir.entryList(infoFilters, QDir::Dirs | QDir::NoDotAndDotDot);
	for (		QStringList::iterator iter = infoFilesInfo.begin();
				iter != infoFilesInfo.end();
				++iter){
		QFileInfo fileInfo(*iter);

		QByteArray packageName(fileInfo.baseName().toLocal8Bit());

		QDir componentInfoDir = packagesDir;
		componentInfoDir.cd(*iter);

		m_packageInfosMap[packageName] = componentInfoDir;
	}

	return retVal;
}


// reimplemented (icmpstr::IExternalMetaInfoManager)

QString CPackagesLoaderExtComp::GetPackageInfoPath(const QByteArray& packageId) const
{
	PackageInfosMap::ConstIterator foundPackageIter = m_packageInfosMap.constFind(packageId);
	if (foundPackageIter != m_packageInfosMap.constEnd()){
		return foundPackageIter.value().absolutePath();
	}

	return "";
}


QString CPackagesLoaderExtComp::GetComponentInfoPath(const icomp::CComponentAddress& address) const
{
	PackageInfosMap::ConstIterator foundPackageIter = m_packageInfosMap.constFind(address.GetPackageId());
	if (foundPackageIter != m_packageInfosMap.constEnd()){
		return foundPackageIter.value().filePath(address.GetComponentId());
	}

	return "";
}


} // namespace icmpstr


