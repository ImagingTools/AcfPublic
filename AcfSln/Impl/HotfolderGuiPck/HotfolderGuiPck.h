/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef HotfolderGuiPck_included
#define HotfolderGuiPck_included


#include "icomp/TModelCompWrap.h"

#include "ihotfgui/CHotfolderProcessingComp.h"
#include "ihotfgui/CDirectoryMonitorComp.h"
#include "ihotfgui/CDirectoryMonitorParamsGui.h"
#include "ihotfgui/CHotfolderGuiComp.h"
#include "ihotfgui/CProcessingItemPreviewGuiComp.h"
#include "ihotfgui/CDirectoryItemGuiComp.h"
#include "ihotfgui/CHotfolderContainerGuiComp.h"
#include "ihotfgui/CHotfolderTaskManagerComp.h"


/**
	Qt based package for Flie Processing Framework.
*/
namespace HotfolderGuiPck
{


typedef ihotfgui::CHotfolderProcessingComp HotfolderProcessor;
typedef ihotfgui::CDirectoryMonitorComp DirectoryMonitor;
typedef ihotfgui::CDirectoryMonitorParamsGui DirectoryMonitorParamsGui;
typedef ihotfgui::CHotfolderGuiComp HotfolderGui;
typedef ihotfgui::CProcessingItemPreviewGuiComp ProcessingItemPreviewGui;
typedef ihotfgui::CDirectoryItemGuiComp DirectoryItemGui;
typedef ihotfgui::CHotfolderContainerGuiComp HotfolderContainerGui;
typedef ihotfgui::CHotfolderTaskManagerComp HotfolderTaskManager;


} // namespace HotfolderGuiPck


#endif // !HotfolderGuiPck_included


