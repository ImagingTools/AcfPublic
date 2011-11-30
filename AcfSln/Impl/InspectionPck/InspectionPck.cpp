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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "InspectionPck.h"


#include "icomp/export.h"


namespace InspectionPck
{


I_EXPORT_DEFAULT_SERVICES

I_EXPORT_PACKAGE(
			"InsopectionPck",
			"General, system-independent image processing package",
			"Standard Base Imaging Tools" IM_PROJECT("ACF-Solutions") IM_TAG("\"Image Processing\"") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));


I_EXPORT_COMPONENT(
			InspectionTask,
			"Group set of suppliers into single inspection task",
			"Task Model Supplier Product Process Cascade" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model"));

I_EXPORT_COMPONENT(
			Inspection,
			"Group set of inspection tasks into single one",
			"Task Model Supplier Product Composite Cascade" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model"));

I_EXPORT_COMPONENT(
			GeneralResultCache,
			"General inspection provider cache object",
			"Provider Cache Results" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model"));


I_EXPORT_COMPONENT(
			IdCache,
			"ID provider cache object",
			"Provider Cache ID" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Inspection Model"));


} // namespace InspectionPck


