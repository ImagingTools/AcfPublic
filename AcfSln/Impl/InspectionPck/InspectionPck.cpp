/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include "InspectionPck.h"


#include <icomp/export.h>


namespace InspectionPck
{


I_EXPORT_PACKAGE(
			"AcfSln/InspectionPck",
			"General, system-independent inspection package",
			"Standard Base Imaging Tools" IM_PROJECT("ACF-Solutions") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools"));

I_EXPORT_COMPONENT(
			InspectionTask,
			"Groups set of suppliers into single inspection task",
			"Task Model Supplier Product Process Cascade" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model") IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			InformationProviderCache,
			"General information provider cache object used to manage threading barrier for object supplier chain",
			"Provider Cache Results" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model") IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			IdProviderCache,
			"ID provider cache object used to manage threading barrier for object supplier chain",
			"Provider Cache ID" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model") IM_AUTHOR("\"Witold Gantzke\""));

I_EXPORT_COMPONENT(
			ComposedInformationProvider,
			"Provider of the combined information state based on the list of underlaying information providers",
			"Provider Results Composition State Information" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model") IM_AUTHOR("\"Kirill Lepskiy\""));


} // namespace InspectionPck


