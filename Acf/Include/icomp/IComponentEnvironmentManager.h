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


#ifndef icomp_IComponentEnvironmentManager_included
#define icomp_IComponentEnvironmentManager_included


#include <icomp/IPackagesManager.h>
#include <icomp/IRegistriesManager.h>
#include <icomp/IMetaInfoManager.h>


namespace icomp
{


class IComponentEnvironmentManager:
			virtual public IPackagesManager,
			virtual public IRegistriesManager,
			virtual public IMetaInfoManager
{
public:
	/**
		Get file path of real used config file.
		If no config file was used, it returns empty string.
	*/
	virtual QString GetConfigFilePath() const = 0;
};


} // namespace icomp


#endif // !icomp_IComponentEnvironmentManager_included


