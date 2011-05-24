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


#ifndef isys_CFileInfo_included
#define isys_CFileInfo_included


// ACF includes
#include "isys/IFileInfo.h"

#include "isys/CSimpleDateTime.h"


namespace isys
{


/**
	Simple implementation of the file info

	\ingroup File System
*/
class CFileInfo: virtual public isys::IFileInfo
{
public:
	CFileInfo(
				const istd::CString& filePath = istd::CString(),
				int filePermissions = 0,
				const isys::CSimpleDateTime& modificationTime = isys::CSimpleDateTime::GetCurrent());

	bool operator== (const CFileInfo& fileInfo) const;
	bool operator!= (const CFileInfo& fileInfo) const;

	virtual void SetPermissions(int filePermissions);
	virtual void SetModificationTime(const isys::IDateTime& modificationTime);

	// reimplemented (isys::IFileInfo)
	virtual istd::CString GetFilePath() const;
	virtual int GetPermissions() const;
	virtual const isys::IDateTime& GetModificationTime() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	istd::CString m_filePath;

	int m_filePermissions;

	isys::CSimpleDateTime m_modificationTime;
};


} // namespace isys


#endif // !isys_CFileInfo_included


