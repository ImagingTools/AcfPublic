/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "FilePck.h"


#include "icomp/export.h"


namespace FilePck
{


I_EXPORT_PACKAGE(
			"Acf/File",
			"Package for file system primitives management",
			IM_PROJECT("ACF") IM_TAG("File") IM_COMPANY("ImagingTools") IM_AUTHOR("\"Witold Gantzke\" \"Kirill Lepskiy\""));

I_EXPORT_COMPONENT(
			FileNameParam,
			"Parameters for file/directory selection",
			"Name Directory Parameters URL" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Model Parameter"));

I_EXPORT_COMPONENT(
			RelativeFileNameParam,
			"Provide file name relative to some other optional directory",
			"Name Relative Directory Parameters URL" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Model Parameter"));

I_EXPORT_COMPONENT(
			SystemLocation,
			"System locations provider",
			"System Path File Location Temp Documents Media Cache" IM_TAG("Model"));

I_EXPORT_COMPONENT(
			GeneratedFileNameParam,
			"Provide auto generated file or directory name",
			"Name Relative Directory Parameters URL" IM_CATEGORY(I_DATA_MODEL) IM_TAG("Model Parameter"));

I_EXPORT_COMPONENT(
			FileListProvider,
			"Provides list of file synchronized with some directory",
			"List Provider Directory");

I_EXPORT_COMPONENT(
			AutoPersistence,
			"Allows object persistence using files",
			"Free Create Store Restore Load Save" IM_CATEGORY(I_DATA_PERSISTENCE) IM_TAG("Persistence File"));

I_EXPORT_COMPONENT(
			FileSystemInfoProvider,
			"Allows access to information about the local file system",
			"Free System Info" IM_CATEGORY(I_DATA_PERSISTENCE) IM_TAG("File System"));


} // namespace FilePck


