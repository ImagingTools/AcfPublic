/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef ifile_IFileNameParam_included
#define ifile_IFileNameParam_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <iser/ISerializable.h>
#include <ifile/ifile.h>


namespace ifile
{


/**
	Common interface for any file system item name (e.g directory, file or URL path)
*/
class IFileNameParam: virtual public iser::ISerializable
{
public:
	enum PathType
	{
		PT_UNKNOWN,
		PT_FILE,
		PT_DIRECTORY,
		PT_URL
	};

	/**
		Get intended type of the path.
		\sa PathType
	*/
	virtual int GetPathType() const = 0;

	/**
		Get path.
	*/
	virtual const QString& GetPath() const = 0;

	/**
		Set path.
	*/
	virtual void SetPath(const QString& path) = 0;
};


} // namespace ifile


#endif // !ifile_IFileNameParam_included


