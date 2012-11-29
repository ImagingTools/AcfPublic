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
#include "iprm/ISelectionConstraints.h"


namespace iprm
{


/**
	Common interface for the management of the dynamic selection constraints.
*/
class IOptionsManager: virtual public ISelectionConstraints
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
		Returns \c true if the operation was successull.
	*/
	virtual bool RemoveOption(int index) = 0;

	/**
		Insert an option with the at the given option name and ID.
		Returns \c true if the operation was successull.
	*/
	virtual bool InsertOption(
				QString& optionName,
				const QByteArray& optionId,
				const QString& optionDescription = QString(),
				int index = -1) = 0;
};


} // namespace iprm


#endif // !iprm_IOptionsManager_included


