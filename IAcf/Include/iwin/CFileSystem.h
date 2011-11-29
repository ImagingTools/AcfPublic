/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef iwin_CFileSystem_included
#define iwin_CFileSystem_included


// ACF includes
#include "isys/CFileSystemBase.h"

#include "iwin/iwin.h"


namespace iwin
{


/**
	Implementation of file system information service for the windows plattform.
*/
class CFileSystem: virtual public isys::CFileSystemBase
{
public:
	// reimplemented (isys::IFileSystem)
	virtual bool IsPresent(const istd::CString& filePath) const;
	virtual bool CreateFileCopy(const istd::CString& inputFile, const istd::CString& outputFile, bool overwriteExisting = false) const;
	virtual bool RemoveFile(const istd::CString& filePath) const;
	virtual bool RemoveFolder(const istd::CString& directoryPath, bool ignoreNonEmpty = false) const;
	virtual bool CreateFolder(const istd::CString& directoryPath) const;
};


} // namespace iwin


#endif // !iwin_CFileSystem_included


