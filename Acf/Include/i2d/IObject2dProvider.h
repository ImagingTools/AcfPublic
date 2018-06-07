/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef i2d_IObject2dProvider_included
#define i2d_IObject2dProvider_included


// ACF includes
#include <i2d/IObject2d.h>


namespace i2d
{


/**
	Common interface for a provider, which delivers a 2D-object.
*/
class IObject2dProvider: virtual public istd::IChangeable
{
public:
	/**
		Get access to 2D-object.
	*/
	virtual const IObject2d* GetObject2d() const = 0;
};


} // namespace i2d


#endif // !i2d_IObject2dProvider_included


