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


#ifndef ibase_ICommand_included
#define ibase_ICommand_included


// ACF includes
#include "istd/TIHierarchical.h"

#include "iprm/INameParam.h"
#include "iprm/IEnableableParam.h"


namespace ibase
{


/**
	Provides single command for interaction with user.
*/
class ICommand:
			virtual public iprm::INameParam, 
			virtual public iprm::IEnableableParam
{
public:
	enum StaticFlags
	{
		/**
			If this is enabled command will be permanent accessible, even if context is not active.
			For example if view command is permanent, this command will be also accessible if other view is active.
		*/
		CF_PERMANENT = 0x0001,
		/**
			Enable to use this command in global application menu.
		*/
		CF_GLOBAL_MENU = 0x0010,
		/**
			Enable to use this command in context menu.
		*/
		CF_CONTEXT_MENU = 0x0020,
		/**
			Enable to use this command in application toolbar.
		*/
		CF_TOOLBAR = 0x0040,
		/**
			Enable to use this command in separated toolbox.
		*/
		CF_TOOLBOX = 0x0080,
		/**
			Inform that this command can be turned on or off (checkable).
		*/
		CF_ONOFF = 0x0100,
		/**
			Enable exclusive selection of this command with other commands in the same node with the same group ID.
		*/
		CF_EXCLUSIVE = 0x0200
	};

	enum GroupId
	{
		GI_NONE = -1,
		GI_NORMAL = 0,
		GI_USER = 0x1000
	};

	/**
		Get priority in the same group.
	*/
	virtual int GetPriority() const = 0;

	/**
		Get group ID used to decide if separator should be used.
		\sa	GroupId.
		\return	group ID or negative value, if no group is assigned.
	*/
	virtual int GetGroupId() const = 0;

	/**
		Get static flags of this command.
		This flags should not change its values during application run and they don't belong to data model.
	*/
	virtual int GetStaticFlags() const = 0;

	/**
		Execute this command.
		\param	contextPtr	implementation specific context parameter.
		\return	true if this command was consumed.
	*/
	virtual bool Execute(istd::IPolymorphic* contextPtr) = 0;
};


/**
	Hierarchical command structure used to create dynamic menu structures.
*/
typedef istd::TIHierarchical<ICommand> IHierarchicalCommand;


} // namespace ibase


#endif // !ibase_ICommand_included


