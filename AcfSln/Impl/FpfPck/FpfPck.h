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


#ifndef FpfPck_included
#define FpfPck_included


#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "ifpf/CDirectoryMonitorParams.h"
#include "ifpf/CHotfolderProcessingInfo.h"
#include "ifpf/CMonitoringSessionsManager.h"
#include "ifpf/CHotfolderStatistics.h"
#include "ifpf/CHotfolderLoaderComp.h"
#include "ifpf/CDirectoryMonitorParamsComp.h"
#include "ifpf/CHotfolderWorkflowComp.h"
#include "ifpf/CVisualHotfolderWorkflowComp.h"
#include "ifpf/CFileSystemChangeStorage.h"
#include "ifpf/CFileNamingParamsComp.h"
#include "ifpf/CFileListConverterComp.h"
#include "ifpf/CFilePathesContainer.h"


/**
	System-undependent package for File Processing Framework.
*/
namespace FpfPck
{


typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ifpf::CDirectoryMonitorParams, iser::ISerializable, ifpf::IDirectoryMonitorParams> > DirectoryMonitorParams;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ifpf::CHotfolderProcessingInfo, iser::ISerializable, ifpf::IHotfolderProcessingInfo> > HotfolderProcessingInfo;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ifpf::CMonitoringSessionsManager, iser::ISerializable, ifpf::IMonitoringSessionManager> > MonitoringSessionsManager;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ifpf::CHotfolderStatistics, iser::ISerializable, imod::IObserver, ifpf::IHotfolderStatistics> > HotfolderStatistics;
typedef ifpf::CHotfolderLoaderComp HotfolderLoader;

typedef icomp::TModelCompWrap<ifpf::CDirectoryMonitorParamsComp> AttributedDirectoryMonitorParams;

typedef icomp::TModelCompWrap<ifpf::CHotfolderWorkflowComp> HotfolderWorkflow;

typedef icomp::TModelCompWrap<ifpf::CVisualHotfolderWorkflowComp> VisualHotfolderWorkflow;

typedef icomp::TModelCompWrap<ifpf::CFileNamingParamsComp> FileNamingParams;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ifpf::CFileSystemChangeStorage, ifpf::IFileSystemChangeStorage> > FileSystemChangeStorage;

typedef ifpf::CFileListConverterComp FileListConverter;

typedef icomp::TMakeComponentWrap<
			ifpf::CFilePathesContainer, ibase::IFileListProvider, istd::IChangeable> FilesContainer;


} // namespace FpfPck


#endif // !FpfPck_included


