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

// ACF includes
#include "istd/TChangeNotifier.h"
#include "ilibav/CLibAvConverter.h"

#include "CLibAvRtspStreamingCameraComp.h"

namespace ilibav
{

// public methods

CLibAvRtspStreamingCameraComp::CLibAvRtspStreamingCameraComp()
{	
}

CLibAvRtspStreamingCameraComp::~CLibAvRtspStreamingCameraComp()
{	
}

void CLibAvRtspStreamingCameraComp::frameArrived(AVFrame* frame, int width, int height, int pixelformat)
{	
	frameSize = istd::CIndex2d(width, height);	

	mutex.lock();
	CLibAvConverter::ConvertBitmap(*frame, frameSize, (AVPixelFormat)pixelformat, *m_frameBitmapPtr);
	mutex.unlock();
}

// reimplemented (icam::IBitmapAcquisition)

istd::CIndex2d CLibAvRtspStreamingCameraComp::GetBitmapSize(const iprm::IParamsSet* /*paramsPtr*/) const
{	
	return frameSize;
}

// reimplemented (iproc::IProcessor)

int CLibAvRtspStreamingCameraComp::DoProcessing(
			const iprm::IParamsSet* paramsPtr,
			const istd::IPolymorphic* inputPtr,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* progressManagerPtr)
{

	if(m_frameBitmapPtr == NULL){
		return TS_OK;
	}

	readParams(paramsPtr);

	m_frameBitmapPtr = dynamic_cast<iimg::IBitmap*>(outputPtr);

	if(!m_streamingClientPtr.IsValid()){
		m_streamingClientPtr.SetPtr(new CLibAvRtspStreamingClient());

		connect(m_streamingClientPtr.GetPtr(), SIGNAL(frameReady(AVFrame*, int, int, int)),
			this, SLOT(frameArrived(AVFrame*, int , int, int)), Qt::QueuedConnection);

	}

	m_streamingClientPtr->OpenConnection(m_rtspUrl);

	return TS_OK;	
}

// reimplemented (icam::IExposureConstraints)

//istd::CRange GetShutterTimeRange()
//{
//	return istd::CRange();
//}
//
//istd::CRange GetDelayTimeRange()
//{
//	return istd::CRange();
//}
//
//istd::CRange GetEenDelayRange()
//{
//	return istd::CRange();
//}

// protected methods

void CLibAvRtspStreamingCameraComp::readParams(const iprm::IParamsSet* paramsPtr)
{
	//read stream path
	if (m_urlParamsIdAttrPtr.IsValid()){
		const iprm::IFileNameParam* urlParamPtr = dynamic_cast<const iprm::IFileNameParam*>(paramsPtr->GetParameter(*m_urlParamsIdAttrPtr));
		if (urlParamPtr != NULL){
			m_rtspUrl = urlParamPtr->GetPath();
		}
	}

	if(m_rtspUrl.isEmpty() && m_defaultUrlParamCompPtr.IsValid()){
		m_rtspUrl = m_defaultUrlParamCompPtr->GetPath();
	}

	//create http path from rtsp path
	if(!m_rtspUrl.isEmpty()){
		QString url = m_rtspUrl;

		int index_start = url.indexOf("rtsp://");

		int index_end = -1;
		if(index_start != -1){
			url = url.right(url.count() - 7);
			index_end = url.indexOf('/');
		}

		if(index_end != -1){
			url = url.left(index_end);

			int index_port = url.indexOf(':');
			if(index_port != -1)
				url = url.left(index_port);

			m_httpUrl = "http://" + url + '/';
		}		
	}

	//read exposure
	if (m_exposureParamsIdAttrPtr.IsValid()){
		const icam::IExposureParams* exposureParamPtr = dynamic_cast<const icam::IExposureParams*>(paramsPtr->GetParameter(*m_exposureParamsIdAttrPtr));
		if (exposureParamPtr != NULL){
			m_exposureTime = exposureParamPtr->GetShutterTime();
		}
	}

	if (m_defaultExposureParamsCompPtr.IsValid()){
		m_exposureTime = m_defaultExposureParamsCompPtr->GetShutterTime();
	}	
}

// reimplemented (icomp::CComponentBase)

void CLibAvRtspStreamingCameraComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();
}


void CLibAvRtspStreamingCameraComp::OnComponentDestroyed()
{
	if(m_streamingClientPtr.IsValid()){
		m_streamingClientPtr->CloseConnection();

		disconnect(m_streamingClientPtr.GetPtr(), SIGNAL(frameReady(AVFrame*, int, int, int)),
			this, SLOT(frameArrived(AVFrame*, int , int, int)));
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace ilibav


