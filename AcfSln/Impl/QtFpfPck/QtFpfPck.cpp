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


#include "QtFpfPck.h"


#include "icomp/export.h"


namespace QtFpfPck
{


I_REGISTER_QT_RESOURCE(iqtgui);
I_REGISTER_QT_RESOURCE(iqtfpf);

I_EXPORT_PACKAGE(
			"AcfSln/Fpf/Gui",
			"Qt based package for File Processsing Framework",
			"File Processing" IM_TAG("Qt Hotfolder") IM_PROJECT("ACF-Solutions") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			HotfolderProcessor,
			"Implementation of the hotfolder processor",
			"File" IM_TAG("Processing"));

I_EXPORT_COMPONENT(
			DirectoryMonitor,
			"This component observes changes in a given file folder",
			"File Dir Filter Observer");

I_EXPORT_COMPONENT(
			DirectoryMonitorParamsGui,
			"Editor for directory monitor parameters",
			"File Dir Filter Observer Editor Monitor" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			HotfolderGui,
			"Hotfolder view",
			"File Observer Editor View" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			FileNaming,
			"Component for file (re)nameing",
			"File Renaming Directory");

I_EXPORT_COMPONENT(
			ProcessingItemPreviewGui,
			"GUI for the graphical preview of a hotfolder processing item",
			"File Processing Editor View Item" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			DirectoryItemGui,
			"View sub-component for a hotfolder directory item",
			"File Processing Editor View GUI Item");

I_EXPORT_COMPONENT(
			HotfolderContainerGui,
			"Hotfolder container UI",
			"Hotfolder File Procesing Observer" IM_TAG("GUI"));

I_EXPORT_COMPONENT(
			HotfolderTaskManager,
			"Hotfolder task manager",
			"File Procesing" IM_TAG("Hotfolder"));


} // namespace QtFpfPck


