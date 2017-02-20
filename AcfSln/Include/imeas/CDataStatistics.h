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


#ifndef imeas_CDataStatistics_included
#define imeas_CDataStatistics_included


#include <imeas/IDataStatistics.h>


namespace imeas
{


/**
	General implementation of the IDataStatistics interface.
*/
class CDataStatistics: virtual public imeas::IDataStatistics
{
public:
	CDataStatistics();

	// reimplemented (imeas::IDataStatistics)
	virtual void CreateStatistics(
				double average,
				double median,
				double standardDeviation,
				const istd::CRange& dataBoundaries);
	virtual istd::CRange GetDataBoundaries() const;
	virtual double GetStandardDeviation() const;
	virtual double GetAverage() const;
	virtual double GetMedian() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_average;
	double m_median;
	double m_standardDeviation;
	istd::CRange m_dataBoundaries;
};


} // namespace imeas


#endif // !imeas_CDataStatistics_included


