/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#ifndef icmpstr_CPackagesLoaderExtComp_included
#define icmpstr_CPackagesLoaderExtComp_included


// Qt includes
#include <QtCore/QMap>
#include <QtCore/QDir>

// ACF includes
#include "icmpstr/IExternalMetaInfoManager.h"
#include "ipackage/CPackagesLoaderComp.h"


namespace icmpstr
{


class CPackagesLoaderExtComp:
			public ipackage::CPackagesLoaderComp,
			virtual public IExternalMetaInfoManager
{
public:
	typedef ipackage::CPackagesLoaderComp BaseClass;

	I_BEGIN_COMPONENT(CPackagesLoaderComp);
		I_REGISTER_INTERFACE(IExternalMetaInfoManager);
	I_END_COMPONENT;

	// reimplemented (iqt::CPackagesLoaderComp)
	virtual bool RegisterPackagesDir(const QString& subDir);

	// reimplemented (icmpstr::IExternalMetaInfoManager)
	virtual QString GetPackageInfoPath(const QByteArray& packageId) const;
	virtual QString GetComponentInfoPath(const icomp::CComponentAddress& address) const;

private:
	typedef QMap<QByteArray, QDir> PackageInfosMap;
	PackageInfosMap m_packageInfosMap;
};


} // namespace icmpstr


#endif // !icmpstr_CPackagesLoaderExtComp_included


