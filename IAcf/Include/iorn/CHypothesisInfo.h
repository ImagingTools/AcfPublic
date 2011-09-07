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


