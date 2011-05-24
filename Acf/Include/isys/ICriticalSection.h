/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef isys_ICriticalSection_included
#define isys_ICriticalSection_included


#include "isys/isys.h"


#include "istd/IPolymorphic.h"


namespace isys
{


/**
	Interface for critical section implementations.

	\ingroup System
 */
class ICriticalSection: virtual public istd::IPolymorphic
{
public:
	/**
		Enter to critical section.
		You have to call Leave() if you entered the section.
	*/
	virtual void Enter() = 0;

	/**
		Enter to critical section if it is not blocked.
		\return	true, if section was entered, false otherwise.
	*/
	virtual bool EnterIfFree() = 0;

	/**	
		Leave entered section.
	*/
	virtual void Leave() = 0;
};


} // namespace isys


#endif // !isys_ICriticalSection_included


