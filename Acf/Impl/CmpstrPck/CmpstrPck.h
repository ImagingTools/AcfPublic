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


#ifndef CmpstrPck_included
#define CmpstrPck_included


#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "icmpstr/CAttributeEditorComp.h"
#include "icmpstr/CPackageOverviewComp.h"
#include "icmpstr/CRegistryLoaderComp.h"
#include "icmpstr/CRegistryPreviewComp.h"
#include "icmpstr/CComponentHelpFileProviderComp.h"
#include "icmpstr/CVisualRegistryComp.h"
#include "icmpstr/CVisualRegistryScenographerComp.h"
#include "icmpstr/CRegistryConsistInfoComp.h"
#include "icmpstr/CRegistryPropEditorComp.h"
#include "icmpstr/CQuickHelpGuiComp.h"
#include "icmpstr/CPackagesLoaderExtComp.h"


/**
	Component manipulation package.
	This package is used to contruct Compositor tool.
*/
namespace CmpstrPck
{


typedef icmpstr::CAttributeEditorComp AttributeEditor;
typedef icmpstr::CPackageOverviewComp PackageOverview;
typedef icmpstr::CRegistryLoaderComp RegistryLoader;
typedef icmpstr::CRegistryPreviewComp RegistryPreview;
typedef icmpstr::CComponentHelpFileProviderComp ComponentHelpFileProvider;
typedef icomp::TModelCompWrap<icmpstr::CVisualRegistryComp> VisualRegistry;
typedef icomp::TModelCompWrap<icmpstr::CVisualRegistryScenographerComp> VisualRegistryScenographer;
typedef icomp::TMakeComponentWrap<
			imod::TModelWrap<icomp::CRegistry>,
			icomp::IRegistry,
			iser::ISerializable,
			istd::IChangeable,
			imod::IModel> Registry;
typedef icmpstr::CRegistryConsistInfoComp RegistryConsistInfo;
typedef icmpstr::CRegistryPropEditorComp RegistryPropEditor;
typedef icmpstr::CQuickHelpGuiComp QuickHelpGui;
typedef icomp::TModelCompWrap<icmpstr::CPackagesLoaderExtComp> PackagesLoaderExt;


} // namespace CmpstrPck


#endif // !CmpstrPck_included


