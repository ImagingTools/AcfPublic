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


#include "ilibav/CLibAvRtspStreamingDataSink.h"


#include "ilibav/CLibAvConverter.h"


namespace ilibav
{


CLibAvRtspStreamingDataSink* CLibAvRtspStreamingDataSink::createNew(
			CLibAvRtspStreamingClient *streamClient,
			UsageEnvironment& env,
			MediaSubsession& subsession) 
{	
  return new CLibAvRtspStreamingDataSink(streamClient, env, subsession);
}


// private methods

CLibAvRtspStreamingDataSink::CLibAvRtspStreamingDataSink(
			CLibAvRtspStreamingClient *streamClient,
			UsageEnvironment& env,
			MediaSubsession& subsession)
:	MediaSink(env),
	m_receiveBuffer(DATA_SINK_RECEIVE_BUFFER_SIZE),
    m_subsession(subsession)
{
	m_streamClientPtr = streamClient;	
}

void CLibAvRtspStreamingDataSink::afterGettingFrame(
			void* clientData,
			unsigned frameSize,
			unsigned numTruncatedBytes,
			struct timeval presentationTime,
			unsigned durationInMicroseconds) 
{
	CLibAvRtspStreamingDataSink* sink = (CLibAvRtspStreamingDataSink*)clientData;
	sink->afterGettingFrame(frameSize, numTruncatedBytes, presentationTime, durationInMicroseconds);
}


void CLibAvRtspStreamingDataSink::afterGettingFrame(
			unsigned frameSize,
			unsigned /*numTruncatedBytes*/,
			struct timeval /*presentationTime*/,
			unsigned /*durationInMicroseconds*/)
{
	m_streamClientPtr->DecodeFrame(
		m_receiveBuffer.data(),
		frameSize);
	
	// Then continue, to request the next frame of data:
	continuePlaying();
}


bool CLibAvRtspStreamingDataSink::continuePlaying() 
{
	
	if (fSource == NULL){
		return false; // sanity check (should not happen)
	}
	
	// Request the next frame of data from our input source.  "afterGettingFrame()" will get called later, when it arrives:
	
	fSource->getNextFrame(
				m_receiveBuffer.data(), m_receiveBuffer.size(),
				afterGettingFrame, this, onSourceClosure, this);

	return true;
}


}


