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


#include "FileGuiPck.h"


#include "icomp/export.h"


I_REGISTER_QT_RESOURCE(iqtgui);


namespace FileGuiPck
{


I_EXPORT_PACKAGE(
			"Acf/FileGui",
			"UI component packages for the file system access and visualization",
			IM_PROJECT("ACF") IM_TAG("Qt GUI File") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			FileTreeViewGui,
			"UI for showing a tree of files",
			"File Tree View");

I_EXPORT_COMPONENT(
			FileSystemExplorerGui,
			"Component for file system visualization",
			"File Path Directory Observer" IM_CATEGORY(I_GUI));

I_EXPORT_COMPONENT(
			FilePersistenceGui,
			"Show load and save button for specified object persistence",
			"Widget Layout Load Save Object Loader" IM_TAG("Persistence"));

I_EXPORT_COMPONENT(
			FileDialogLoader,
			"File dialog loader",
			"Serialization Serializer Dialog" IM_TAG("File Loader"));

I_EXPORT_COMPONENT(
			FilePreviewGui,
			"File preview",
			"Observer Display GUI Preview");

I_EXPORT_COMPONENT(
			FileListProviderGui,
			"UI for showing a list of files",
			"File List");


} // namespace FileGuiPck


