/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iorn/CHypothesisInfo.h"


namespace iorn
{


CHypothesisInfo::CHypothesisInfo(int samplesCount, int activeChannelsCount, bool isWeightChannel)
:	m_samplesCount(samplesCount),
	m_activeChannelsCount(activeChannelsCount),
	m_isWeightChannel(isWeightChannel)
{
}


int CHypothesisInfo::GetActiveChannelsCount() const
{
	return m_activeChannelsCount;
}


int CHypothesisInfo::GetWeightChannelIndex() const
{
	return m_isWeightChannel? m_activeChannelsCount: -1;
}


int CHypothesisInfo::GetSamplesCount() const
{
	return m_samplesCount;
}


int CHypothesisInfo::GetChannelsCount() const
{
	return m_isWeightChannel? m_activeChannelsCount + 1: m_activeChannelsCount;
}


istd::CRange CHypothesisInfo::GetValueRange(int /*channelIndex*/) const
{
	return istd::CRange(0, 1);
}


bool CHypothesisInfo::HasChannelType(int channelType) const
{
	if (channelType == CT_NORMAL){
		return true;
	}
	else if (channelType == CT_WEIGHT){
		return m_isWeightChannel;
	}
	else{
		return false;
	}
}


int CHypothesisInfo::GetChannelType(int channelIndex) const
{
	if (m_isWeightChannel && (channelIndex == m_activeChannelsCount)){
		return CT_WEIGHT;
	}
	else{
		return CT_NORMAL;
	}
}


} // namespace iorn


