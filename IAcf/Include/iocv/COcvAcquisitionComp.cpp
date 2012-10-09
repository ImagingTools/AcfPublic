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


#include "iocv/COcvAcquisitionComp.h"


// ACF includes 
#include "istd/TChangeNotifier.h"

#include "iprm/IParamsSet.h"


// IACF includes
#include "iocv/COcvImage.h"


namespace iocv
{


COcvAcquisitionComp::COcvAcquisitionComp()
:	m_cameraPtr(NULL)
{
}


bool COcvAcquisitionComp::IsCameraValid() const
{
	return (m_cameraPtr != NULL);
}


// reimplemented (iproc::TSyncProcessorWrap<icam::IBitmapAcquisition>)

int COcvAcquisitionComp::DoProcessing(
			const iprm::IParamsSet* /* paramsPtr*/,
			const istd::IPolymorphic* /*inputPtr*/,
			istd::IChangeable* outputPtr,
			ibase::IProgressManager* /*progressManagerPtr*/)
{
	if (m_cameraPtr == NULL){
		return TS_INVALID;
	}

	istd::TChangeNotifier<iimg::IBitmap> bitmapPtr(dynamic_cast<iimg::IBitmap*>(outputPtr));
	if (!bitmapPtr.IsValid()){
		return TS_INVALID;
	}

	IplImage* iplImagePtr = cvQueryFrame(m_cameraPtr);
	if (iplImagePtr == NULL){
		return TS_INVALID;
	}

	if (iocv::COcvImage::ConvertToBitmap(*iplImagePtr, *bitmapPtr.GetPtr())){
		return TS_OK;
	}

	return TS_INVALID;
}


// reimplemented (icam::IBitmapAcquisition)

istd::CIndex2d COcvAcquisitionComp::GetBitmapSize(const iprm::IParamsSet* /*paramsPtr*/) const
{
	int imageWidth = (int)cvGetCaptureProperty(m_cameraPtr, CV_CAP_PROP_FRAME_WIDTH);
	int imageHeight = (int)cvGetCaptureProperty(m_cameraPtr, CV_CAP_PROP_FRAME_HEIGHT);

	return istd::CIndex2d(imageWidth, imageHeight);
}


// reimplemented (isig::ITriggerConstraints)

bool COcvAcquisitionComp::IsTriggerModeSupported(int triggerMode) const
{
	return (triggerMode == isig::ITriggerParams::TM_CONTINUOUS);
}


// protected methods

// reimplemented (icomp::CComponentBase)

void COcvAcquisitionComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	m_cameraPtr = cvCreateCameraCapture(CV_CAP_ANY);
	if (m_cameraPtr != NULL){
		cvSetCaptureProperty(m_cameraPtr, CV_CAP_PROP_FRAME_WIDTH, 640);
		cvSetCaptureProperty(m_cameraPtr, CV_CAP_PROP_FRAME_HEIGHT, 480);
	}
}


void COcvAcquisitionComp::OnComponentDestroyed()
{
	if (m_cameraPtr != NULL){
		cvReleaseCapture(&m_cameraPtr);
	}

	BaseClass::OnComponentDestroyed();
}


} // namespace iocv


