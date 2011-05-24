/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iwin/CFileSystem.h"


// Windows includes
#include <windows.h>


// Undef the microsoft macros, to avoid name conflicts
#ifdef CopyFile
	#undef CopyFile
#endif


namespace iwin
{


// public methods

// reimplemented (isys::IFileSystem)
	
bool CFileSystem::IsPresent(const istd::CString& filePath) const
{
	return (_waccess(filePath.c_str(), 0) == 0);
}


bool CFileSystem::CopyFile(const istd::CString& inputFile, const istd::CString& outputFile, bool overwriteExisting) const
{
	return ::CopyFileW(inputFile.c_str(), outputFile.c_str(), overwriteExisting? FALSE: TRUE) == TRUE;
}


} // namespace iwin


