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


#ifndef FileProcessingPck_included
#define FileProcessingPck_included


#include <icomp/TModelCompWrap.h>
#include <icomp/TMakeComponentWrap.h>

#include <ifileproc/CFileNamingComp.h>
#include <ifileproc/CFileNamingParamsComp.h>
#include <ifileproc/CFileListConverterComp.h>
#include <ifileproc/CFilePathesContainer.h>
#include <ifileproc/CSelectableFileConverterComp.h>
#include <ifileproc/CFileConvertOverProcessorComp.h>
#include <ifileproc/CExternalFileConverterComp.h>
#include <ifileproc/CCopyFilesTreeComp.h>
#include <ifileproc/CComposedCopyFilesComp.h>
#include <ifileproc/CProcessingResultsReviewComp.h>
#include <ifileproc/CFileInfoCopyComp.h>
#include <ifileproc/CFileCopyOverLoaderComp.h>
#include <ifileproc/CCopyAppComp.h>
#include <ifileproc/CRenderedObjectFileLoaderComp.h>
#include <ifileproc/CBitmapPreviewGeneratorComp.h>


/**
	System-undependent package for File Processing Framework.
*/
namespace FileProcessingPck
{


typedef ifileproc::CFileNamingComp FileNaming;

typedef icomp::TModelCompWrap<ifileproc::CFileNamingParamsComp> FileNamingParams;

typedef ifileproc::CFileListConverterComp FileListConverter;

typedef icomp::TMakeComponentWrap<
			ifileproc::CFilePathesContainer, ifile::IFileListProvider, istd::IChangeable> FilesContainer;

typedef ifileproc::CExternalFileConverterComp ExternalFileConverter;
typedef icomp::TModelCompWrap<ifileproc::CSelectableFileConverterComp> SelectableFileConverter;
typedef ifileproc::CFileConvertOverProcessorComp FileConvertOverProcessor;
typedef ifileproc::CCopyFilesTreeComp CopyFilesTree;
typedef ifileproc::CComposedCopyFilesComp ComposedCopyFiles;

typedef ifileproc::CProcessingResultsReviewComp ProcessingResultsReview;

typedef ifileproc::CFileInfoCopyComp FileInfoCopy;
typedef ifileproc::CFileCopyOverLoaderComp FileCopyOverLoader;
typedef ifileproc::CCopyAppComp CopyApp;
typedef ifileproc::CRenderedObjectFileLoaderComp RenderedObjectFileLoader;
typedef ifileproc::CBitmapPreviewGeneratorComp BitmapPreviewGenerator;


} // namespace FileProcessingPck


#endif // !FileProcessingPck_included


