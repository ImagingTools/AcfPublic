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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iser_IFileLoaderInfo_included
#define iser_IFileLoaderInfo_included


// Qt includes
#include <QtCore/QString>


// ACF includes
#include "istd/IPolymorphic.h"


namespace iser
{


/**
	Provide some information about file loader state.

	\ingroup Persistence
*/
class IFileLoaderInfo: virtual public istd::IPolymorphic
{
public:
	enum OperationType
	{
		OT_UNKNOWN,
		OT_LOAD,
		OT_SAVE
	};

	enum PathType
	{
		PT_COMPLETE,
		OT_FILENAME,
		OT_DIR
	};

	/**
		Returns the last opened file name.
	*/
	virtual QString GetLastFilePath(OperationType operationType = OT_UNKNOWN, PathType pathType = PT_COMPLETE) const = 0;
};


} // namespace iser


#endif // !iser_IFileLoaderInfo_included


