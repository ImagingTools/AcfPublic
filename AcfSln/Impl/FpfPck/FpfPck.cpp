/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "icomp/export.h"

#include "FpfPck.h"


namespace FpfPck
{


I_EXPORT_DEFAULT_SERVICES

I_EXPORT_PACKAGE(
			"Fpf",
			"Acf-Solutions File-To-File Processing Framework package",
			"File Processing Hotfolder Workflow" IM_TAG("Hotfolder") IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			DirectoryMonitorParams,
			"Parameter for the directory monitoring",
			"Processing Parameter Directory Monitoring" IM_TAG("File Model"));

I_EXPORT_COMPONENT(
			HotfolderLoader,
			"Hotfolder loader",
			"File Processing Parameter Directory Hotfolder" IM_TAG("Loader"));

I_EXPORT_COMPONENT(
			HotfolderProcessingInfo,
			"Hotfolder's state",
			"File Processing Hotfolder" IM_TAG("Model"));

I_EXPORT_COMPONENT(
			MonitoringSessionsManager,
			"Monitoring sessions",
			"File Processing Hotfolder Session");

I_EXPORT_COMPONENT(
			HotfolderStatistics,
			"Simple hotfolder statistics",
			"File Processing Hotfolder Statistics");

I_EXPORT_COMPONENT(
			AttributedDirectoryMonitorParams,
			"Default parameter for directory monitoring",
			"File Processing Hotfolder Directory Monitoring");

I_EXPORT_COMPONENT(
			HotfolderWorkflow,
			"Hotfolder workflow",
			"File Processing Hotfolder Workflow");

I_EXPORT_COMPONENT(
			VisualHotfolderWorkflow,
			"Visualization model of a hotfolder workflow",
			"File Processing Hotfolder Workflow");

I_EXPORT_COMPONENT(
			FileNamingParams,
			"Parmeter for file (re)naming",
			"File Processing Hotfolder Parameter");

I_EXPORT_COMPONENT(
			FileSystemChangeStorage,
			"File storage component",
			"File Processing Hotfolder Parameter");

} // namespace FpfPck


