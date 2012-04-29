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


#ifndef iocv_COcvAcquisitionComp_included
#define iocv_COcvAcquisitionComp_included


// OpenCV includes
#include "cxtypes.h"
#include "cv.h"
#include "highgui.h"

// ACF includes
#include "i2d/CRectangle.h"
#include "ibase/TLoggerCompWrap.h"
#include "icomp/CComponentBase.h"
#include "iproc/TSyncProcessorWrap.h"

// ACF-Solutions includes
#include "icam/IBitmapAcquisition.h"
#include "icam/IExposureConstraints.h"
#include "icam/IExposureParams.h"
#include "isig/ITriggerParams.h"
#include "isig/ITriggerConstraints.h"


namespace iocv
{


/**
	Open CV based camera component implementation.
*/
class COcvAcquisitionComp:
			public ibase::CLoggerComponentBase,
			virtual public isig::ITriggerConstraints,
			virtual public iproc::TSyncProcessorWrap<icam::IBitmapAcquisition>
{
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(COcvAcquisitionComp);
		I_REGISTER_INTERFACE(icam::IBitmapAcquisition);
		I_REGISTER_INTERFACE(isig::ITriggerConstraints);
	I_END_COMPONENT;

	enum MessageId
	{
	};

	COcvAcquisitionComp();

	bool IsCameraValid() const;

	// reimplemented (iproc::TSyncProcessorWrap<icam::IBitmapAcquisition>)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (icam::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;

	// reimplemented (isig::ITriggerConstraints)
	virtual bool IsTriggerModeSupported(int triggerMode) const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();
	
private:
	I_REF(icam::IExposureParams, m_defaultExposureParamsCompPtr);
	I_REF(isig::ITriggerParams, m_triggerParamsCompPtr);
	I_REF(i2d::CRectangle, m_imageRegionParamsCompPtr);

	I_ATTR(bool, m_singleShootAttrPtr);
	I_ATTR(double, m_timeoutAttrPtr);

	CvCapture* m_cameraPtr;
};


} // namespace iocv


#endif // !iocv_COcvAcquisitionComp_included


