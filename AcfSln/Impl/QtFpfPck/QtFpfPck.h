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


#ifndef QtFpfPck_included
#define QtFpfPck_included


#include "icomp/TModelCompWrap.h"

#include "iqtfpf/CHotfolderProcessingComp.h"
#include "iqtfpf/CDirectoryMonitorComp.h"
#include "iqtfpf/CDirectoryMonitorParamsGui.h"
#include "iqtfpf/CHotfolderGuiComp.h"
#include "iqtfpf/CFileNamingComp.h"
#include "iqtfpf/CProcessingItemPreviewGuiComp.h"
#include "iqtfpf/CDirectoryItemGuiComp.h"
#include "iqtfpf/CHotfolderContainerGuiComp.h"
#include "iqtfpf/CHotfolderTaskManagerComp.h"


/**
	Qt based package for Flie Processing Framework.
*/
namespace QtFpfPck
{


typedef iqtfpf::CHotfolderProcessingComp HotfolderProcessor;
typedef iqtfpf::CDirectoryMonitorComp DirectoryMonitor;
typedef iqtfpf::CDirectoryMonitorParamsGui DirectoryMonitorParamsGui;
typedef iqtfpf::CHotfolderGuiComp HotfolderGui;
typedef iqtfpf::CFileNamingComp FileNaming;
typedef iqtfpf::CProcessingItemPreviewGuiComp ProcessingItemPreviewGui;
typedef iqtfpf::CDirectoryItemGuiComp DirectoryItemGui;
typedef iqtfpf::CHotfolderContainerGuiComp HotfolderContainerGui;
typedef iqtfpf::CHotfolderTaskManagerComp HotfolderTaskManager;


} // namespace QtFpfPck


#endif // !QtFpfPck_included


