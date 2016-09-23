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


#include "PackagePck.h"


#include <icomp/export.h>


namespace PackagePck
{


I_EXPORT_PACKAGE(
			"Acf/PackagePck",
			"Compositor package",
			IM_PROJECT("ACF") IM_TAG("Compositor Qt") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			Registry,
			"Model of ACF registry (ARX)",
			"Registry Components Data Connection Diagram ARP ARX" IM_TAG("Model"));

I_EXPORT_COMPONENT(
			XpcModel,
			"Model of ACF configuration (XPC)",
			"Registry Components Configuration Packages ARP ARX XPC AWC Data Connection" IM_TAG("Model"));

I_EXPORT_COMPONENT(
			PackagesLoader,
			"Load and cache packages from files",
			"Component Registry Cache Package Load File Configuration Components" IM_TAG("Loader"));

I_EXPORT_COMPONENT(
			RegistriesManager,
			"Load and cache registries from files",
			"Registry Manager Load File Configuration Components");

I_EXPORT_COMPONENT(
			RegistryCodeSaver,
			"Stores registry as C++ code",
			"Code C++ File Store Save Registry Compile" IM_CATEGORY(I_DATA_PERSISTENCE) IM_TAG("Loader"));


} // namespace PackagePck


