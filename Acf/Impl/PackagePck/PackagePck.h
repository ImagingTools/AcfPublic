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


#ifndef PackagePck_included
#define PackagePck_included


#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"
#include "icomp/CXpcModel.h"

#include "ipackage/CPackagesLoaderComp.h"
#include "ipackage/CRegistriesManagerComp.h"
#include "ipackage/CRegistryCodeSaverComp.h"


/**
	Component, packages and registries manipulation package.
*/
namespace PackagePck
{


typedef icomp::TMakeComponentWrap<
			imod::TModelWrap<icomp::CRegistry>,
			icomp::IRegistry,
			iser::ISerializable,
			istd::IChangeable,
			imod::IModel> Registry;
typedef icomp::TMakeComponentWrap<
			imod::TModelWrap<icomp::CXpcModel>,
			icomp::CXpcModel,
			iser::ISerializable,
			istd::IChangeable,
			imod::IModel> XpcModel;
typedef ipackage::CPackagesLoaderComp PackagesLoader;
typedef ipackage::CRegistriesManagerComp RegistriesManager;
typedef ipackage::CRegistryCodeSaverComp RegistryCodeSaver;


} // namespace PackagePck


#endif // !PackagePck_included


