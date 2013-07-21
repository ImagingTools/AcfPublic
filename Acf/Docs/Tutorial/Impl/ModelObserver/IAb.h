/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef IAb_included
#define IAb_included


// Qt includes
#include <QtCore/QByteArray>

// ACF includes
#include "iser/ISerializable.h"


class IAConstraints;


/**
	Interface for AB-object
*/
class IAb: virtual public iser::ISerializable
{
public:
	/**
		Flags for changes indentification
	*/
	enum ChangeFlags
	{
		/**
			State of A was changed
		*/
		CF_A_CHANGED = 1 << 4,

		/**
			State of B was changed
		*/
		CF_B_CHANGED = 1 << 5
	};

	/**
		Get constraints of A.
		Constraints describes some additional information about allowed parameter ranges and related informations.
	*/
	virtual const IAConstraints& GetAConstraints() const = 0;

	/**
		Get the values of A.
	*/
	virtual int GetA() const = 0;

	/**
		Set the value of A
	*/
	virtual bool SetA(int a) = 0;

	/**
		Get the value of B
	*/
	virtual QByteArray GetB() const = 0;

	/**
		Set the value of B
	*/
	virtual void SetB(const QByteArray& b) = 0;
};


#endif // !IAb_included


