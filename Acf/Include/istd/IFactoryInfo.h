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


#ifndef istd_IFactoryInfo_included
#define istd_IFactoryInfo_included


// STL includes
#include <string>
#include <vector>

#include "istd/IPolymorphic.h"


namespace istd
{


/**
	Base interface providing info about factorisable objects.
*/
class IFactoryInfo: virtual public istd::IPolymorphic  
{
public:
	typedef std::vector<std::string> KeyList;

	/**
		Returns all posible keys for this factory.
	*/
	virtual KeyList GetFactoryKeys() const = 0;
};


} // namespace istd


#endif // !istd_IFactoryInfo_included

