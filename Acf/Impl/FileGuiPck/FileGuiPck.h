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


#ifndef FileGuiPck_included
#define FileGuiPck_included


#include <ifilegui/CFileTreeViewGuiComp.h>
#include <ifilegui/CFileSystemExplorerGuiComp.h>
#include <ifilegui/CFilePersistenceGuiComp.h>
#include <ifilegui/CFileDialogLoaderComp.h>
#include <ifilegui/CFilePreviewGuiComp.h>
#include <ifilegui/CFileListProviderGuiComp.h>
#include <ifilegui/CSimpleFilePathParamGuiComp.h>


/**
	File UI package.
*/
namespace FileGuiPck
{


typedef ifilegui::CFileTreeViewGuiComp FileTreeViewGui;
typedef ifilegui::CFileSystemExplorerGuiComp FileSystemExplorerGui;
typedef ifilegui::CFilePersistenceGuiComp FilePersistenceGui;
typedef ifilegui::CFileDialogLoaderComp FileDialogLoader;
typedef ifilegui::CFilePreviewGuiComp FilePreviewGui;
typedef ifilegui::CFileListProviderGuiComp FileListProviderGui;
typedef ifilegui::CSimpleFilePathParamGuiComp SimpleFilePathParamGui;


} // namespace FileGuiPck


#endif // !FileGuiPck_included


