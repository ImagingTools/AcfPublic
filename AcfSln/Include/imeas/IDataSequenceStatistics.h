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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef imeas_IDataSequenceStatistics_included
#define imeas_IDataSequenceStatistics_included


// ACF includes
#include "iser/ISerializable.h"


namespace imeas
{


class IDataStatistics;


/**
	Common interaface for data sequence statistics.
*/
class IDataSequenceStatistics: virtual public iser::ISerializable
{
public:
	/**
		Set channel statistics for the given channel index.
	*/
	virtual bool SetChannelStatistics(const imeas::IDataStatistics& channelStatistics, int channelIndex) = 0;

	/**
		Reset all statitics data.
	*/
	virtual void ResetStatistics() = 0;

	/**
		Get number of channels.
	*/
	virtual int GetChannelsCount() const = 0;

	/**
		Get data statics of the given channel \c channelIndex.
	*/
	virtual const imeas::IDataStatistics* GetChannelStatistics(int channelIndex) const = 0;
};


} // namespace imeas


#endif // !imeas_IDataSequenceStatistics_included


