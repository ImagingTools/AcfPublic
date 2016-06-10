/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef ifile_CFileNameParam_included
#define ifile_CFileNameParam_included


// ACF includes
#include "iser/ISerializable.h"
#include "ifile/IFileNameParam.h"


namespace ifile
{


/**
	Basic implementation of interface ifile::IFileNameParam.
*/
class CFileNameParam: virtual public IFileNameParam
{
public:

	// reimplemented (ifile::IFileNameParam)
	virtual int GetPathType() const;
	virtual const QString& GetPath() const;
	virtual void SetPath(const QString& path);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	QString m_path;
};


} // namespace ifile


#endif // !ifile_CFileNameParam_included


