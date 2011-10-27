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


#include "CompositorPck.h"


#include "icomp/export.h"

#include "iqt/CDefaultServicesProvider.h"


static struct StaticInit
{
	StaticInit()
	{
		Q_INIT_RESOURCE(iqtgui);
		Q_INIT_RESOURCE(icmpstr);
	}

} instance;


namespace CompositorPck
{


I_EXPORT_SERVICES_PROVIDER(iqt::CDefaultServicesProvider);

I_EXPORT_PACKAGE(
			"Cmpstr",
			"Compositor package",
			IM_PROJECT("ACF") IM_TAG("Compositor Qt") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			AttributeEditor,
			"GUI used to edit attributes",
			"Observer Attributes Qt" IM_TAG("GUI Editor"));

I_EXPORT_COMPONENT(
			PackageOverview,
			"GUI showing all packages",
			"Observer Packages" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			RegistryLoader,
			"Loader for registries including component layout in *.alx files",
			"Registry Loader Serializer Layout Components" IM_TAG("Loader"));

I_EXPORT_COMPONENT(
			RegistryPreview,
			"Preview of registry object in separated application context",
			"Registry Preview Application" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			ComponentHelpFileProvider,
			"Provide file path of html help for component using its address",
			"Help File Provider Component Address" IM_TAG("Help"));

I_EXPORT_COMPONENT(
			VisualRegistry,
			"Model of ACF registry with additional visual elements designed for Compositor", 
			"Components ARX Registry Visual" IM_TAG("Model"));

I_EXPORT_COMPONENT(
			VisualRegistryScenographer,
			"Visual registry editor",
			"Components Registry Visual Observer" IM_TAG("GUI Editor"));

I_EXPORT_COMPONENT(
			RegistryConsistInfo,
			"Provides additional information about registries, its elements and attributes",
			"Registry Element Attribute Consistency Check");

I_EXPORT_COMPONENT(
			RegistryPropEditor,
			"Allows to edit global registry properties",
			"Registry Description Keywords" IM_TAG("GUI Editor"));

I_EXPORT_COMPONENT(
			QuickHelpGui,
			"Show short description and allow to show technical documentation",
			"Quick Help Technical Documentation" IM_TAG("GUI Help"));

I_EXPORT_COMPONENT(
			PackagesLoaderExt,
			"Load, cache packages from files and supports additional meta information needed for compositor",
			"Component Registry Cache Package Load File Configuration Components" IM_TAG("Loader"));


} // namespace CompositorPck


