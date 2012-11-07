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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef ilibav_CLibAvRtspStreamingDataSink_included
#define ilibav_CLibAvRtspStreamingDataSink_included

// Live555 includes
#include "MediaSink.hh"
#include "UsageEnvironment.hh"
#include "MediaSession.hh"

#include "ilibav/CLibAvRtspStreamingClient.h"

namespace ilibav
{

/**
	Class for receiving data from rtsp stream
*/
class CLibAvRtspStreamingDataSink: public MediaSink 
{
public:	
	static CLibAvRtspStreamingDataSink* createNew(
				CLibAvRtspStreamingClient *streamClient,
				UsageEnvironment& env,
				MediaSubsession& subsession); // identifies the kind of data that's being received

	//max buffer for incoming data
	static const int DATA_SINK_RECEIVE_BUFFER_SIZE = 500000;

private:
	// called only by "createNew()"
	CLibAvRtspStreamingDataSink(
				CLibAvRtspStreamingClient* streamClient,
				UsageEnvironment& env,
				MediaSubsession& subsession);	

	//virtual ~CLibAvRtspStreamingDataSink();
	
	static void afterGettingFrame(void* clientData, unsigned frameSize, 
		unsigned numTruncatedBytes, struct timeval presentationTime, 
		unsigned durationInMicroseconds);
	
	void afterGettingFrame(
				unsigned frameSize,
				unsigned numTruncatedBytes,
				struct timeval presentationTime,
				unsigned durationInMicroseconds);
	
	void decodeFrame(unsigned frameSize);

private:
	// redefined virtual functions:
	virtual bool continuePlaying();

private:	
	//stream and video (session) info
	MediaSubsession& m_subsession;	

	//buffer for received frame
	QVector<u_int8_t> m_receiveBuffer;

	CLibAvRtspStreamingClient* m_streamClientPtr;	
};

}

#endif //ilibav_CLibAvRtspStreamingDataSink_included


