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


#ifndef imeas_INumericConstraints_included
#define imeas_INumericConstraints_included


// ACF includes
#include "istd/IChangeable.h"

// ACF-Solutions includes
#include "imeas/IUnitInfo.h"

#include "imeas/imeas.h"


namespace imeas
{


class INumericConstraints: virtual public istd::IChangeable
{
public:
	/**
		Get number of expected numeric values.
	*/
	virtual int GetNumericValuesCount() const = 0;

	/**
		Get description of numeric value for specified list index.
	*/
	virtual istd::CString GetNumericValueDescription(int index) const = 0;

	/**
		Get range of possible numeric values for specified list index.
	*/
	virtual const imeas::IUnitInfo& GetNumericValueUnitInfo(int index) const = 0;
};


} // namespace imeas


#endif // !imeas_INumericConstraints_included


