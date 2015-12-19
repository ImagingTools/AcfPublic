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


#include "HotfolderPck.h"


#include "icomp/export.h"


namespace HotfolderPck
{


I_EXPORT_PACKAGE(
			"AcfSln/Hotfolder",
			"Acf-Solutions File-To-File Processing Framework package",
			"File Processing Hotfolder Workflow" IM_TAG("Hotfolder") IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			DirectoryMonitorParams,
			"Parameter for the directory monitoring",
			"Processing Parameter Directory Monitoring" IM_TAG("File Model"));

I_EXPORT_COMPONENT(
			MonitoringSessionsManager,
			"Monitoring sessions",
			"File Processing Hotfolder Session");

I_EXPORT_COMPONENT(
			FileSystemChangeStorage,
			"File storage component",
			"File Processing Hotfolder Parameter");


} // namespace HotfolderPck


