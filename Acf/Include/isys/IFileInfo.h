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


#ifndef isys_IFileInfo_included
#define isys_IFileInfo_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/IChangeable.h"
#include "istd/CString.h"

#include "isys/IDateTime.h"


namespace isys
{


/**
	Provide info about a file

	\ingroup Persistence
*/
class IFileInfo: virtual public iser::ISerializable
{
public:
	/**
		Get file path.
	*/
	virtual istd::CString GetFilePath() const = 0;

	/**
		Get the file permissions.
	*/
	virtual int GetPermissions() const = 0;
	
	/**
		Get the last modification time.
	*/
	virtual const isys::IDateTime& GetModificationTime() const = 0;
};


} // namespace isys


#endif // !isys_IFileInfo_included


