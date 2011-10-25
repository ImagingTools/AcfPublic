/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iinsp_IIdProvider_included
#define iinsp_IIdProvider_included


// ACF includes
#include "istd/IChangeable.h"


namespace iinsp
{


/**
	Allow access to some ID.
	The meaning of the ID is depend on use case and implementation.
	Typically ID is used to unique identify inspection objects.
*/
class IIdProvider: virtual public istd::IChangeable
{
public:
	/**
		Get current ID value.
	*/
	virtual I_DWORD GetCurrentId() const = 0;

	/**
		Set current ID value.
		\return	true if ID could be set in the implementation.
	*/
	virtual bool SetCurrentId(I_DWORD id) = 0;
};


} // namespace iinsp


#endif // !iinsp_IIdProvider_included


