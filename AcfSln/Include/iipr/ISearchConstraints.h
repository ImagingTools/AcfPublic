/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iipr_IISearchParamsConstraints_included
#define iipr_IISearchParamsConstraints_included


#include "istd/IChangeable.h"
#include "istd/TRange.h"


namespace iipr
{


/**	
	Interface for search algorithm limitations.
*/
class ISearchConstraints: virtual public istd::IChangeable
{
public:
	virtual const istd::CRange& GetRotationRangeConstraints() const = 0;
	virtual bool IsRotationRangeSupported() const = 0;
	virtual const istd::CRange& GetScaleRangeConstraints() const = 0;
	virtual bool IsScaleRangeSupported() const = 0;
};


} // namespace iipr


#endif // !iipr_IISearchParamsConstraints_included

