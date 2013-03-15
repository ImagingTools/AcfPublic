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


#ifndef iprm_IOptionsManager_included
#define iprm_IOptionsManager_included


// ACF includes
#include "iprm/IOptionsList.h"


namespace iprm
{


/**
	Common interface for the management of the dynamic selection constraints.
*/
class IOptionsManager: virtual public IOptionsList
{
public:
	enum ChangeFlags
	{
		CF_OPTION_ADDED = 1 << 7,
		CF_OPTION_REMOVED = 1 << 8
	};

	/**
		Enables a given option. Only enabled options can be selected.
		\sa GetOptionEnabled
	*/
	virtual void SetOptionEnabled(int index, bool isEnabled = true) = 0;

	/**
		Remove an option at the given index.
		Returns \c true if the operation was successful.
	*/
	virtual bool RemoveOption(int index) = 0;

	/**
		Insert an option at some position.
		\param optionName	Name of the option
		\param optionId		ID of the option, according to data model constraints needs to be unique
		\param optionDescription	Description of the option
		\param index	Position in the list, where the new option will be inserted. Negative value means that the option will be added to the end of the list.	
		Returns \c true if the operation was successful.
	*/
	virtual bool InsertOption(
				const QString& optionName,
				const QByteArray& optionId,
				const QString& optionDescription = QString(),
				int index = -1) = 0;

	/**
		Swap two options.
	*/
	virtual bool SwapOptions(int index1, int index2) = 0;

	/**
		Set a new name for the option at the given index \c optionIndex
	*/
	virtual bool SetOptionName(int optionIndex, const QString& optionName) = 0;

	/**
		Set a new description for the option at the given index \c optionIndex
	*/
	virtual bool SetOptionDescription(int optionIndex, const QString& optionDescription) = 0;
};


} // namespace iprm


#endif // !iprm_IOptionsManager_included


