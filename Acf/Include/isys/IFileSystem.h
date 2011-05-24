/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef isys_IFileSystem_included
#define isys_IFileSystem_included


#include "istd/IPolymorphic.h"
#include "istd/CString.h"

#include "isys/isys.h"


namespace isys
{


/**
	Defines some file system dependent operations.

	\ingroup System
*/
class IFileSystem: virtual public istd::IPolymorphic
{
public:
	/**
		Get normalized file path.
		For any path to the same file this function should return the same path.
		For example for "C:\Test\..\Test\blah.txt" it should return "C:\Test\blah.txt".
	*/
	virtual istd::CString GetNormalizedPath(const istd::CString& path) const = 0;

	/**
		Get file name of specified file path.
		For example for "C:\Test\blah.txt" it should return "blah.txt".
	*/
	virtual istd::CString GetFileName(const istd::CString& filePath) const = 0;

	/**
		Get base file name (also without extension) of specified file path.
		For example for "C:\Test\blah.txt.gz" it should return "blah".		
	*/
	virtual istd::CString GetBaseFileName(const istd::CString& filePath) const = 0;

	/**
		Get directory path of specified file path.
		For example for "C:\Test\blah.txt" it should return "C:\Test".
	*/
	virtual istd::CString GetDirPath(const istd::CString& filePath) const = 0;

	/**
		Check if file path has specified extension.
	*/
	virtual bool HasExtension(const istd::CString& filePath, const istd::CString& extension) const = 0;

	/**
		Check if some file is present.
	*/
	virtual bool IsPresent(const istd::CString& filePath) const = 0;

	/**
		Copy any file to another. If the \c overwriteExisting is set on, the existing file will be overwritten.
	*/
	virtual bool CopyFile(const istd::CString& inputFile, const istd::CString& outputFile, bool overwriteExisting = false) const = 0;
};


} // namespace isys


#endif // !isys_IFileSystem_included


