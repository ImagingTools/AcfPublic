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


#ifndef ifile_IFileArchiveInfo_included
#define ifile_IFileArchiveInfo_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <istd/IPolymorphic.h>


namespace ifile
{


/**
	Simple informative interface allowing to get access to current processed file by file archives.
	To check the file name from you \c Serialize methods simply cast your iser::IArchive to this interface.
	File-based archives should implement this interface.

	\ingroup Persistence
*/
class IFileArchiveInfo: virtual public istd::IPolymorphic
{
public:
	virtual const QString& GetCurrentFilePath() const = 0;
};


} // namespace ifile


#endif // !ifile_IFileArchiveInfo_included


