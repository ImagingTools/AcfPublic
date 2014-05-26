/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ifile_IFileSystemInfoProvider_included
#define ifile_IFileSystemInfoProvider_included


// ACF includes
#include "istd/IChangeable.h"
#include "istd/CSystem.h"
#include "iprm/IOptionsList.h"


namespace ifile
{


/**
	Provider of file system related informations.
*/
class IFileSystemInfoProvider: virtual public istd::IChangeable
{
public:
	/**
		Get the list of drives available on the local machine.
	*/
	virtual const iprm::IOptionsList& GetDriveList() const = 0;

	/**
		Get info about a given file drive.
		\param driveIndex	Index of the file drive specified as index of the element inside of the list returned by GetDriveList.
							Negative values mean that information about all available file drives will be cummulated.
	*/
	virtual const istd::CSystem::FileDriveInfo* GetFileDriveInfo(int driveIndex = -1) const = 0;
};


} // namespace ifile


#endif // !ifile_IFileSystemInfoProvider_included


