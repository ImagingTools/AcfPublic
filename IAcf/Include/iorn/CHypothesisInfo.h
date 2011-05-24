/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iorn_CHypothesisInfo_included
#define iorn_CHypothesisInfo_included


// ACF includes
#include "istd/IChangeable.h"
#include "istd/CRange.h"


namespace iorn
{


/**
	Data sequence information for single processing hypothesis.
	Data sequence for hypothesis contains on active channels and optional single weight channel.
*/
class CHypothesisInfo: virtual public istd::IChangeable
{
public:
	enum ChannelType
	{
		CT_NORMAL,
		CT_WEIGHT
	};

	CHypothesisInfo(int samplesCount, int activeChannelsCount, bool isWeightChannel);

	int GetActiveChannelsCount() const;
	int GetWeightChannelIndex() const;

	virtual int GetSamplesCount() const;
	virtual int GetChannelsCount() const;
	virtual istd::CRange GetValueRange(int channelIndex = -1) const;
	virtual bool HasChannelType(int channelType) const;
	virtual int GetChannelType(int channelIndex) const;

private:
	int m_samplesCount;
	int m_activeChannelsCount;
	bool m_isWeightChannel;
};


} // namespace iorn


#endif // !iorn_CHypothesisInfo_included


