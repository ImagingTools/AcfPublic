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


#ifndef imeas_CDataSequenceStatistics_included
#define imeas_CDataSequenceStatistics_included


// ACF includes
#include <istd/TPointerVector.h>
#include <imod/TModelWrap.h>

// ACF-Solutions includes
#include <imeas/IDataSequenceStatistics.h>
#include <imeas/CDataStatistics.h>


namespace imeas
{


class CDataSequenceStatistics: virtual public imeas::IDataSequenceStatistics
{
public:
	// reimplemented (imeas::IDataSequenceStatistics)
	virtual bool SetChannelStatistics(const imeas::IDataStatistics& channelStatistics, int channelIndex);
	virtual void ResetStatistics();
	virtual int GetChannelsCount() const;
	virtual const imeas::IDataStatistics* GetChannelStatistics(int channelIndex) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	typedef imod::TModelWrap<imeas::CDataStatistics> ChannelStatistics;
	typedef istd::TPointerVector<ChannelStatistics> ChannelStatisticsList;

	ChannelStatisticsList m_channelStatisticsList;
};


} // namespace imeas


#endif // !imeas_CDataSequenceStatistics_included


