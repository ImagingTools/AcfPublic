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


#ifndef ibase_ICommandsProvider_included
#define ibase_ICommandsProvider_included


// ACF includes
#include "istd/IChangeable.h"

#include "ibase/ICommand.h"


namespace ibase
{


class ICommandsProvider: virtual public istd::IChangeable
{
public:
	enum ChangeFlags
	{
		CF_COMMANDS = 1 << 14
	};

	/**
		Get list of menu commands.
		This commands will be integrated in global menu system undependent of actual selected view.
		For support of normal pull down menu, depth of this tree structure should be at least 3.
	*/
	virtual const IHierarchicalCommand* GetCommands() const;
};


inline const IHierarchicalCommand* ICommandsProvider::GetCommands() const
{
	return NULL;
}


} // namespace ibase


#endif // !ibase_ICommandsProvider_included


