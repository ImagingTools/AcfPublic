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


#ifndef imeas_IDataStatistics_included
#define imeas_IDataStatistics_included


#include <istd/TRange.h>

#include <iser/ISerializable.h>


namespace imeas
{


/**
	Common interace for simple data statistics.
	\TODO: think about moving it to imath.
*/
class IDataStatistics: virtual public iser::ISerializable
{
public:

	/**
		Create statistics object from the input data.
	*/
	virtual void CreateStatistics(
				double average,
				double median,
				double standardDeviation,
				const istd::CRange& dataBoundaries) = 0;

	/**
		Get the range of values in the data sequence.
	*/
	virtual istd::CRange GetDataBoundaries() const = 0;

	/**
		Get data variance.
	*/
	virtual double GetStandardDeviation() const = 0;

	/**
		Get data average.
	*/
	virtual double GetAverage() const = 0;

	/**
		Get data median.
	*/
	virtual double GetMedian() const = 0;
};


} // namespace imeas


#endif // !imeas_IDataStatistics_included


