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


#ifndef iser_CFileArchiveInfo_included
#define iser_CFileArchiveInfo_included


#include "iser/IFileArchiveInfo.h"


namespace iser
{


/**
	Basic implementation of interface iser::IFileArchiveInfo.
*/
class CFileArchiveInfo: virtual public IFileArchiveInfo
{
public:
	CFileArchiveInfo(const istd::CString& filePath);

	// reimplemented (iser::IFileArchiveInfo)
	virtual const istd::CString& GetCurrentFilePath() const;

protected:
	istd::CString m_filePath;
};


} // namespace iser


#endif // !iser_CFileArchiveInfo_included


