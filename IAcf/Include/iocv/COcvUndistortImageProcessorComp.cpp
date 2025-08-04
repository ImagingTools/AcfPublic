/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <iocv/COcvUndistortImageProcessorComp.h>


// OpenCV includes
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

// ACF includes
#include <iprm/TParamsPtr.h>

// IACF includes
#include <iocv/COcvImage.h>
#include <iocv/COcvIntrinsicCameraCalibration.h>


namespace iocv
{


// protected methods

// reimplemented (iipr::CImageProcessorCompBase)

bool COcvUndistortImageProcessorComp::ProcessImage(
			const iprm::IParamsSet* paramsPtr,
			const iimg::IBitmap& inputImage,
			iimg::IBitmap& outputImage) const
{
	try{

		iprm::TParamsPtr<i2d::ICalibration2d> cameraCalibrationParamPtr(paramsPtr, m_cameraCalibrationParamIdAttrPtr, m_defaultCameraCalibrationCompPtr, false);
		if (!cameraCalibrationParamPtr.IsValid()){
			if (m_selectionParamIdAttrPtr.IsValid() && m_paramsManagerCompPtr.IsValid()) {
				iprm::TParamsPtr<iprm::ISelectionParam> cameraParamSelectionPtr(paramsPtr, *m_selectionParamIdAttrPtr);
				if (cameraParamSelectionPtr.IsValid()) {
					const iprm::IParamsSet* oneParamsSetPtr = m_paramsManagerCompPtr->GetParamsSet(cameraParamSelectionPtr->GetSelectedOptionIndex());
					if (oneParamsSetPtr != nullptr) {
						iprm::TParamsPtr<i2d::ICalibration2d> calibrationPtr(oneParamsSetPtr, *m_cameraCalibrationParamIdAttrPtr);
						if (calibrationPtr.IsValid())
							cameraCalibrationParamPtr.SetPtr(calibrationPtr.GetPtr());
					}
				}

			}
		}

		if (!cameraCalibrationParamPtr.IsValid()){

			outputImage.CopyFrom(inputImage);

			return true;
		}

		cv::Mat cvInput;
		COcvImage::ConvertFromBitmap(inputImage, cvInput);
		cv::Size imageSize;
		imageSize.width = inputImage.GetImageSize().GetX();
		imageSize.height = inputImage.GetImageSize().GetY();

		const iocv::COcvIntrinsicCameraCalibration* calibrationImplPtr = dynamic_cast<const iocv::COcvIntrinsicCameraCalibration*>(cameraCalibrationParamPtr.GetPtr());
		if (calibrationImplPtr != NULL){
			cv::Mat cvOutput;
			cv::undistort(cvInput, cvOutput, calibrationImplPtr->GetCameraMatrix(), calibrationImplPtr->GetDistorsion());
			bool retVal = COcvImage::ConvertToBitmap(cvOutput, outputImage);

			return retVal;
		}
	}
	catch (const cv::Exception& e){
		SendCriticalMessage(0, e.what());

		return false;
	}
	catch (...){
		SendCriticalMessage(0, QString("Unknown exception"));

		return false;
	}

	return false;
}


} // namespace iipr


