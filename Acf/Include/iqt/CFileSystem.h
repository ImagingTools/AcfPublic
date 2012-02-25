/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
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
	virtual QString GetNormalizedPath(const QString& path) const;
	virtual QString GetFileName(const QString& filePath) const;
	virtual QString GetBaseFileName(const QString& filePath) const;
	virtual QString GetDirPath(const QString& filePath) const;
	virtual bool HasExtension(const QString& filePath, const QString& extension) const;
	virtual bool IsPresent(const QString& filePath) const;
	virtual bool CreateFileCopy(const QString& inputFile, const QString& outputFile, bool overwriteExisting = false) const;
	virtual bool RemoveFile(const QString& filePath) const;
	virtual bool RemoveFolder(const QString& directoryPath, bool ignoreNonEmpty = false) const;
	virtual bool CreateFolder(const QString& directoryPath) const;

	// static members
	static QString FindVariableValue(const QString& varName);
	static QString GetEnrolledPath(const QString& path);
};


} // namespace iqt


#endif // !iqt_CFileSystem_included


