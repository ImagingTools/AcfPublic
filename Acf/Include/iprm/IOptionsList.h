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


#ifndef iprm_IOptionsList_included
#define iprm_IOptionsList_included


// Qt includes
#include <QtCore/QString>


// ACF includes
#include "istd/IChangeable.h"

#include "iprm/iprm.h"


namespace iprm
{


/**
	Constraints of selection from set of possibilities.
*/
class IOptionsList: virtual public istd::IChangeable
{
public:
	/**
		Flags for changes related to this interface.
	*/
	enum ChangeFlags
	{
		/**
			Option list updated.
		*/
		CF_OPTIONS_CHANGED = 1 << 18,

		/**
			One or more options were renamed.
		*/
		CF_OPTION_RENAMED = 1 << 19
	};

	/**
		Flags for control constraints behavior.
	*/
	enum OptionsFlags
	{
		SCF_NONE = 0,

		/**
			If set, every option must have an unique ID.
		*/
		SCF_SUPPORT_UNIQUE_ID = 256,

		/**
			If set, some options can be disabled.
		*/
		SFC_DISABLE_ALLOWED = 32
	};

	/**
		Get constraints flags. The flags describes how the constraints object mantainance
	*/
	virtual int GetOptionsFlags() const = 0;

	/**
		Get number of managed options.
	*/
	virtual int GetOptionsCount() const = 0;

	/**
		Get name of specified option.
	*/
	virtual QString GetOptionName(int index) const = 0;

	/**
		Get human readable description for a option with the index \c index.
	*/
	virtual QString GetOptionDescription(int index) const = 0;

	/**
		Get option ID. The option ID must be unique, if flag SCF_SUPPORT_UNIQUE_ID is set.
		\sa OptionsFlags
	*/
	virtual QByteArray GetOptionId(int index) const = 0;

	/**
		Return \c true if the option is enabled and can be selected.
	*/
	virtual bool IsOptionEnabled(int index) const = 0;
};


} // namespace iprm


#endif // !iprm_IOptionsList_included


