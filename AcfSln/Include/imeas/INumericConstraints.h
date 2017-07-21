/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef imeas_INumericConstraints_included
#define imeas_INumericConstraints_included


// ACF includes
#include <iprm/IOptionsList.h>

// ACF-Solutions includes
#include <imath/IUnitInfo.h>
#include <imeas/imeas.h>


namespace imeas
{


/**
	Describe additional meta information for set of numeric values.
	\sa imeas::INumericValue
*/
class INumericConstraints: virtual public istd::IChangeable
{
public:
	/**
		Get general information about the "content" of the numeric value.
	*/
	virtual const iprm::IOptionsList& GetValueListInfo() const = 0;

	/**
		Get range of possible numeric values for specified list index.
		\param	index	index of numeric value.
	*/
	virtual const imath::IUnitInfo* GetNumericValueUnitInfo(int index) const = 0;
};


} // namespace imeas


#endif // !imeas_INumericConstraints_included


