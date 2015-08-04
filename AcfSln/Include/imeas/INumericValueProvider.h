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


#ifndef imeas_INumericValueProvider_included
#define imeas_INumericValueProvider_included


// ACF includes
#include "istd/IChangeable.h"
#include "imath/CVarVector.h"

// ACF-Solutions includes
#include "imeas/INumericValue.h"


namespace imeas
{


/**
	Provide access to the list of the numeric values.
*/
class INumericValueProvider: virtual public istd::IChangeable
{
public:
	/**
		Get number of numeric values in the list.
	*/
	virtual int GetValuesCount() const = 0;

	/**
		Returns a single numeric value from the list.
	*/
	virtual const imeas::INumericValue& GetNumericValue(int index) const = 0;
};


} // namespace imeas


#endif // !imeas_INumericValueProvider_included


