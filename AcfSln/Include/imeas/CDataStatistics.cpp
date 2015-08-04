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


#include "imeas/CDataStatistics.h"


// ACF includes
#include "istd/CChangeNotifier.h"
#include "istd/CChangeGroup.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace imeas
{


CDataStatistics::CDataStatistics()
	:m_average(0.0),
	m_median(0.0),
	m_standardDeviation(0.0)
{
}


// reimplemented (imeas::IDataStatistics)

void CDataStatistics::CreateStatistics(
			double average,
			double median,
			double standardDeviation,
			const istd::CRange& dataBoundaries)
{
	istd::CChangeGroup changeGroup(this);
	Q_UNUSED(changeGroup);

	if (dataBoundaries != m_dataBoundaries){
		istd::CChangeNotifier notifier(this);

		m_dataBoundaries = dataBoundaries;
	}

	if (standardDeviation != m_standardDeviation){
		istd::CChangeNotifier notifier(this);

		m_standardDeviation = standardDeviation;
	}
	
	if (average != m_average){
		istd::CChangeNotifier notifier(this);

		m_average = average;
	}
	
	if (median != m_median){
		istd::CChangeNotifier notifier(this);

		m_median = median;
	}
}


istd::CRange CDataStatistics::GetDataBoundaries() const
{
	return m_dataBoundaries;
}


double CDataStatistics::GetStandardDeviation() const
{
	return m_standardDeviation;
}


double CDataStatistics::GetAverage() const
{
	return m_average;
}


double CDataStatistics::GetMedian() const
{
	return m_median;
}



// reimplemented (iser::ISerializable)

bool CDataStatistics::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag averageTag("Average", "Data average", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag medianTag("Median", "Data median", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag standardDeviationTag("StandardDeviation", "Data's standard deviation", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag minValueTag("MinValue", "Minimal data value", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag maxValueTag("maxValue", "Maximal data value", iser::CArchiveTag::TT_LEAF);

	bool isStoring = archive.IsStoring();

	istd::CChangeNotifier notifier(isStoring? NULL: this);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(averageTag);
	retVal = retVal && archive.Process(m_average);
	retVal = retVal && archive.EndTag(averageTag);

	retVal = retVal && archive.BeginTag(medianTag);
	retVal = retVal && archive.Process(m_median);
	retVal = retVal && archive.EndTag(medianTag);

	retVal = retVal && archive.BeginTag(standardDeviationTag);
	retVal = retVal && archive.Process(m_standardDeviation);
	retVal = retVal && archive.EndTag(standardDeviationTag);

	double minValue = m_dataBoundaries.GetMinValue();
	double maxValue = m_dataBoundaries.GetMaxValue();

	retVal = retVal && archive.BeginTag(minValueTag);
	retVal = retVal && archive.Process(minValue);
	retVal = retVal && archive.EndTag(minValueTag);

	retVal = retVal && archive.BeginTag(maxValueTag);
	retVal = retVal && archive.Process(maxValue);
	retVal = retVal && archive.EndTag(maxValueTag);

	if (!isStoring){
		m_dataBoundaries = istd::CRange(minValue, maxValue);
	}

	return retVal;
}


} // namespace imeas


