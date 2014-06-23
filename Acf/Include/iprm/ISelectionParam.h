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


#ifndef iprm_ISelectionParam_included
#define iprm_ISelectionParam_included


// Qt includes
#include <QtCore/QString>


// ACF includes
#include "iser/ISerializable.h"


namespace iprm
{


class IOptionsList;


/**
	Interface allowing to select single option from list of options.
*/
class ISelectionParam: virtual public iser::ISerializable
{
public:
	/**
		Data model change notification flags.
	*/
	enum ChangeFlags
	{
		CF_SELECTION_CHANGED = 0x67364be
	};

	enum 
	{
		NO_SELECTION = -1,
	};

	/**
		Get constraints of this parameter.
		Constraints describes some additional information about allowed parameter ranges and related informations.
	*/
	virtual const IOptionsList* GetSelectionConstraints() const = 0;

	/**
		Get selected index.
		\return	index of selected option or negative value if no option is selected.
	*/
	virtual int GetSelectedOptionIndex() const = 0;

	/**
		Set index of selected option.
		\return	true	if selection change was possible.
	*/
	virtual bool SetSelectedOptionIndex(int index) = 0;

	/**
		Get subselection for specified option.
		Please note, that returned options tree belongs to selection data model.
	*/
	virtual ISelectionParam* GetSubselection(int index) const = 0;
};


} // namespace iprm


#endif // !iprm_ISelectionParam_included


