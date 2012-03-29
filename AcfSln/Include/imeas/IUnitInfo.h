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


#ifndef imeas_IUnitInfo_included
#define imeas_IUnitInfo_included


// ACF includes
#include "istd/IPolymorphic.h"
#include "istd/CRange.h"
#include <QtCore/QString>

#include "imath/IDoubleManip.h"


namespace imeas
{


/**
	Common interface to get information about a measurement unit.
*/
class IUnitInfo: virtual public istd::IPolymorphic
{
public:
	/**
		General type of unit.
	*/
	enum UnitType
	{
		/**
			Unit type is unknown.
		*/
		UT_UNKNOWN,
		/**
			Physical unit like volt or amper.
		*/
		UT_PHYSICAL,
		/**
			Technical unit without physical dimension like pixel.
		*/
		UT_TECHNICAL,
		/**
			Unit relative to something others (for example %).
		*/
		UT_RELATIVE,
		/**
			Integer number counter, it represents number of occurence of something.
		*/
		UT_COUNTER
	};

	/**
		Get type of unit.
	*/
	virtual int GetUnitType() const = 0;

	/**
		Get name of unit.
	*/
	virtual QString GetUnitName() const = 0;

	/**
		Get multiplication factor used to calculate user input values.
	*/
	virtual double GetDisplayMultiplicationFactor() const = 0;

	/**
		Get range of possible filter value for specified dimension.
	*/
	virtual istd::CRange GetValueRange() const = 0;

	/**
		Return number manipulator object for filter length value.
	*/
	virtual const imath::IDoubleManip& GetValueManip() const = 0;
};


} // namespace imeas


#endif // !imeas_IUnitInfo_included


