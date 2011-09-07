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


#ifndef icmpstr_CPackagesLoaderExtComp_included
#define icmpstr_CPackagesLoaderExtComp_included


// STL includes
#include <map>

// Qt includes
#include <QDir>

#include "iqt/CPackagesLoaderComp.h"

#include "icmpstr/IExternalMetaInfoManager.h"


namespace icmpstr
{


class CPackagesLoaderExtComp:
			public iqt::CPackagesLoaderComp,
			virtual public IExternalMetaInfoManager
{
public:
	typedef iqt::CPackagesLoaderComp BaseClass;

	I_BEGIN_COMPONENT(CPackagesLoaderComp);
		I_REGISTER_INTERFACE(IExternalMetaInfoManager);
	I_END_COMPONENT;

	// reimplemented (iqt::CPackagesLoaderComp)
	virtual bool RegisterPackagesDir(const istd::CString& subDir);

	// reimplemented (icmpstr::IExternalMetaInfoManager)
	virtual istd::CString GetPackageInfoPath(const std::string& packageId) const;
	virtual istd::CString GetComponentInfoPath(const icomp::CComponentAddress& address) const;

private:
	typedef std::map<std::string, QDir> PackageInfosMap;
	PackageInfosMap m_packageInfosMap;
};


} // namespace icmpstr


#endif // !icmpstr_CPackagesLoaderExtComp_included


