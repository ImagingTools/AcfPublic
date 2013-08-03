/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef FilePck_included
#define FilePck_included


#include "icomp/TModelCompWrap.h"
#include "icomp/TMakeComponentWrap.h"

#include "ifile/CFileNameParamComp.h"
#include "ifile/CRelativeFileNameParamComp.h"
#include "ifile/CSystemLocationComp.h"
#include "ifile/CGeneratedFileNameParamComp.h"
#include "ifile/CFileListProviderComp.h"
#include "ifile/CAutoPersistenceComp.h"


/**
	Package for file system primitives management.
*/
namespace FilePck
{


typedef icomp::TModelCompWrap<ifile::CFileNameParamComp> FileNameParam;
typedef icomp::TModelCompWrap<ifile::CRelativeFileNameParamComp> RelativeFileNameParam;
typedef icomp::TModelCompWrap<ifile::CSystemLocationComp> SystemLocation;
typedef icomp::TModelCompWrap<ifile::CGeneratedFileNameParamComp> GeneratedFileNameParam;
typedef icomp::TModelCompWrap<ifile::CFileListProviderComp> FileListProvider;
typedef icomp::TModelCompWrap<ifile::CFileListProviderComp> FileListProvider;
typedef ifile::CAutoPersistenceComp AutoPersistence;


} // namespace FilePck


#endif // !FilePck_included


