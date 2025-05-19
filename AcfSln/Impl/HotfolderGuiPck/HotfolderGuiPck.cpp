/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#include "HotfolderGuiPck.h"


#include <icomp/export.h>


I_REGISTER_QT_RESOURCE(iqtgui);
I_REGISTER_QT_RESOURCE(ihotfgui);


namespace HotfolderGuiPck
{


I_EXPORT_PACKAGE(
			"AcfSln/Hotfolder/Gui",
			"Qt based package for File Processsing Framework",
			"File Processing" IM_TAG("Qt Hotfolder") IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			DirectoryMonitor,
			"This component observes changes in a given file folder",
			"File Dir Filter Observer");

I_EXPORT_COMPONENT(
			DirectoryMonitorParamsGui,
			"Editor for directory monitor parameters",
			"File Dir Filter Observer Editor Monitor" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			FileNamingParamsGui,
			"Editor for file naming parameters",
			"File Dir Name" IM_TAG("GUI"));


} // namespace HotfolderGuiPck


