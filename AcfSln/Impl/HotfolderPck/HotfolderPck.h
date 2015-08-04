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


#ifndef HotfolderPck_included
#define HotfolderPck_included


#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "ihotf/CDirectoryMonitorParams.h"
#include "ihotf/CHotfolderProcessingInfo.h"
#include "ihotf/CMonitoringSessionsManager.h"
#include "ihotf/CHotfolderStatistics.h"
#include "ihotf/CDirectoryMonitorParamsComp.h"
#include "ihotf/CFileSystemChangeStorage.h"


/**
	System-undependent package for File Processing Framework.
*/
namespace HotfolderPck
{


typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ihotf::CDirectoryMonitorParams, iser::ISerializable, ihotf::IDirectoryMonitorParams> > DirectoryMonitorParams;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ihotf::CHotfolderProcessingInfo, iser::ISerializable, ihotf::IHotfolderProcessingInfo> > HotfolderProcessingInfo;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ihotf::CMonitoringSessionsManager, iser::ISerializable, ihotf::IMonitoringSessionManager> > MonitoringSessionsManager;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ihotf::CHotfolderStatistics, iser::ISerializable, imod::IObserver, ihotf::IHotfolderStatistics> > HotfolderStatistics;

typedef icomp::TModelCompWrap<
			ihotf::CDirectoryMonitorParamsComp> AttributedDirectoryMonitorParams;

typedef icomp::TModelCompWrap<
			icomp::TMakeComponentWrap<
						ihotf::CFileSystemChangeStorage, ihotf::IFileSystemChangeStorage> > FileSystemChangeStorage;


} // namespace HotfolderPck


#endif // !HotfolderPck_included


