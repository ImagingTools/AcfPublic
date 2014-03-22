/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef icomp_IPackagesManager_included
#define icomp_IPackagesManager_included


// Qt includes
#include <QtCore/QString>


// ACF includes
#include "istd/IChangeable.h"


namespace icomp
{


class IPackagesManager: virtual public istd::IChangeable
{
public:
	enum PackageType
	{
		PT_UNKNOWN,
		/**
			Real packages are stored as dynamic linked libraries in \c arp files.
		*/
		PT_REAL,
		/**
			Composed packages are stored in folders containing registry files (\c arx files).
		*/
		PT_COMPOSED
	};

	/**
		Configure environment for specified file path.
		If this file path is invalid or empty, standard configuration file will be used.
	*/
	virtual bool LoadPackages(const QString& configFilePath = QString()) = 0;

	/**
		Get type of package as defined in \c PackageType.
	*/
	virtual int GetPackageType(const QByteArray& packageId) const = 0;

	/**
		Get directory path of specified component package.
		\param	packageId	ID of component package.
		\return				package path or empty string if specified package is not registered.
	*/
	virtual QString GetPackagePath(const QByteArray& packageId) const = 0;
};


} // namespace icomp


#endif // !icomp_IPackagesManager_included


