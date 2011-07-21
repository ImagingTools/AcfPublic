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


#ifndef iqt_CFileSystem_included
#define iqt_CFileSystem_included


#include "isys/IFileSystem.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	Implementation of file system information based on QT.
	This implementation is part of standard services if you use QT-based components.
*/
class CFileSystem: virtual public isys::IFileSystem
{
public:
	// reimplemented (isys::IFileSystem)
	virtual istd::CString GetNormalizedPath(const istd::CString& path) const;
	virtual istd::CString GetFileName(const istd::CString& filePath) const;
	virtual istd::CString GetBaseFileName(const istd::CString& filePath) const;
	virtual istd::CString GetDirPath(const istd::CString& filePath) const;
	virtual bool HasExtension(const istd::CString& filePath, const istd::CString& extension) const;
	virtual bool IsPresent(const istd::CString& filePath) const;
	virtual bool CreateFileCopy(const istd::CString& inputFile, const istd::CString& outputFile, bool overwriteExisting = false) const;
	virtual bool RemoveFile(const istd::CString& filePath) const;
	virtual bool RemoveFolder(const istd::CString& directoryPath, bool ignoreNonEmpty = false) const;
	virtual bool CreateFolder(const istd::CString& directoryPath) const;

	// static members
	static QString FindVariableValue(const QString& varName);
	static QString GetEnrolledPath(const QString& path);

protected:
	static const QStringList& GetEnvList();
};


} // namespace iqt


#endif // !iqt_CFileSystem_included


