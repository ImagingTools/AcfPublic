/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "imeas/CDataSequenceStatistics.h"


#include "istd/TChangeNotifier.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace imeas
{


// reimplemented (imeas::IDataSequenceStatistics)

bool CDataSequenceStatistics::SetChannelStatistics(const imeas::IDataStatistics& channelStatistics, int channelIndex)
{
	int channelsCount = GetChannelsCount();

	I_ASSERT(channelIndex >= 0);
	I_ASSERT(channelIndex <= channelsCount);
	if (channelIndex < 0 || channelIndex > channelsCount){
		return false;
	}

	istd::CChangeNotifier changePtr(this);

	ChannelStatistics* dataStatisticsPtr = NULL;
	
	if (channelIndex == channelsCount){
		dataStatisticsPtr = new ChannelStatistics;

		m_channelStatisticsList.PushBack(dataStatisticsPtr);
	}
	else{
		dataStatisticsPtr = m_channelStatisticsList.GetAt(channelIndex);
	}

	dataStatisticsPtr->CreateStatistics(
				channelStatistics.GetAverage(),
				channelStatistics.GetMedian(),
				channelStatistics.GetStandardDeviation(),
				channelStatistics.GetDataBoundaries());

	return true;
}


void CDataSequenceStatistics::ResetStatistics()
{
	if (!m_channelStatisticsList.IsEmpty()){
		istd::CChangeNotifier changePtr(this);

		m_channelStatisticsList.Reset();
	}
}


int CDataSequenceStatistics::GetChannelsCount() const
{
	return m_channelStatisticsList.GetCount();
}


const imeas::IDataStatistics* CDataSequenceStatistics::GetChannelStatistics(int channelIndex) const
{
	I_ASSERT(channelIndex >= 0);
	I_ASSERT(channelIndex < GetChannelsCount());

	return m_channelStatisticsList.GetAt(channelIndex);
}


// reimplemented (iser::ISerializable)

bool CDataSequenceStatistics::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag statisticsTag("DataStatistics", "Data sequence statistics");
	static iser::CArchiveTag statisticsChannelTag("StatisticsChannel", "Single statistics channel");

	int channelsCount = m_channelStatisticsList.GetCount();

	if (!archive.IsStoring()){
		m_channelStatisticsList.SetCount(channelsCount);
		for (int channelIndex = 0; channelIndex < channelsCount; channelIndex++){
			m_channelStatisticsList.SetElementAt(channelIndex, new ChannelStatistics);
		}
	}

	retVal = retVal && archive.BeginMultiTag(statisticsTag, statisticsChannelTag, channelsCount);

	for (int channelIndex = 0; channelIndex < channelsCount; channelIndex++){
		retVal = retVal && archive.BeginTag(statisticsChannelTag);
		retVal = retVal && m_channelStatisticsList.GetAt(channelIndex)->Serialize(archive);
		retVal = retVal && archive.EndTag(statisticsChannelTag);		
	}

	retVal = retVal && archive.EndTag(statisticsTag);

	return retVal;
}


} // namespace imeas


