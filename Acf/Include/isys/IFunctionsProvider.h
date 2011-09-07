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


#ifndef isys_IFunctionsProvider_included
#define isys_IFunctionsProvider_included


#include "isys/isys.h"


#include <string>

#include "istd/IPolymorphic.h"


namespace isys
{


/**
	Interface for set of functions accessed by its ID.
	Typically it is used to access dynamic loaded libraries.
*/
class IFunctionsProvider: virtual public istd::IPolymorphic
{
public:
	/**
		Check if this object was correctly initialized and functions can be used.
	*/
	virtual bool IsValid() const = 0;
	/**
		Return function pointer using its ID.
	 *		\return	function pointer if success or NULL otherwise.
	 */
	virtual void* GetFunction(const std::string& id) const = 0;
};


} // namespace isys


#endif // !isys_IFunctionsProvider_included



