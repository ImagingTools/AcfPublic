/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef icomp_IExtPackagesManager_included
#define icomp_IExtPackagesManager_included


// Qt includes
#include <QtCore/QString>
#include <QtCore/QSet>

// ACF includes
#include <icomp/IPackagesManager.h>


namespace icomp
{


class IExtPackagesManager: virtual public IPackagesManager
{
public:
	enum PathType
	{
		PT_ALL,
		/**
		*/
		PT_CONFIG,
		/**
		*/
		PT_PACKAGES_DIR,
		/**
		*/
		PT_PACKAGE,
		/**
		*/
		PT_REGISTRY
	};

	/**
		List of pathes.
	*/
	typedef QSet<QString> PathList;

	/**
		Get list of files used for configuration.
	*/
	virtual PathList GetConfigurationPathList(PathType pathType) const = 0;
	/**
		Get level of package definition in configuration.
		The packages defined direct in loaded configuration file returns 0, the packages in the derrived configuration 1 etc.
		It returns negative value if the definition level cannot be calculated.
	*/
	virtual int GetPackageDefinitionLevel(const QByteArray& packageId) const = 0;
};


} // namespace icomp


#endif // !icomp_IExtPackagesManager_included


