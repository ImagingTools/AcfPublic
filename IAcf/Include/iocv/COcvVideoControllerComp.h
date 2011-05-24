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


#ifndef iocv_COcvVideoControllerComp_included
#define iocv_COcvVideoControllerComp_included


// OpenCV includes
#include "cxtypes.h"
#include "cv.h"
#include "highgui.h"


// ACF includes
#include "istd/TDelPtr.h"
#include "icomp/CComponentBase.h"
#include "iproc/IBitmapAcquisition.h"
#include "iproc/TSyncProcessorCompBase.h"
#include "imm/IVideoController.h"


namespace iocv
{


/**
	Component for video controlling using OpenCV API.
*/
class COcvVideoControllerComp:
			public iproc::TSyncProcessorCompBase<iproc::IBitmapAcquisition>,
			virtual public imm::IVideoController
{
public:
	typedef iproc::TSyncProcessorCompBase<iproc::IBitmapAcquisition> BaseClass;

	I_BEGIN_COMPONENT(COcvVideoControllerComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(imm::IMediaController);
		I_REGISTER_INTERFACE(imm::IVideoInfo);
		I_REGISTER_INTERFACE(imm::IVideoController);
		I_ASSIGN(m_frameDataCompPtr, "FrameData", "Frame instance will be loaded with loader", true, "FrameData");
	I_END_COMPONENT();

	COcvVideoControllerComp();

	// reimplemented (iproc::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);

	// reimplemented (imm::IMediaController)
	virtual istd::CString GetOpenedMediumUrl() const;
	virtual bool OpenMediumUrl(const istd::CString& url, bool autoPlay = true);
	virtual void CloseMedium();
	virtual bool IsPlaying() const;
	virtual bool SetPlaying(bool state = true);
	virtual double GetMediumLength() const;
	virtual double GetCurrentPosition() const;
	virtual bool SetCurrentPosition(double position);
	virtual int GetSupportedFeatures() const;

	// reimplemented (imm::IVideoInfo)
	virtual int GetFramesCount() const;
	virtual double GetFrameIntervall() const;
	virtual istd::CIndex2d GetFrameSize() const;
	virtual double GetPixelAspectRatio() const;

	// reimplemented (imm::IVideoController)
	virtual int GetCurrentFrame() const;
	virtual bool SetCurrentFrame(int frameIndex);

protected:
	virtual bool GrabCurrentFrame(iimg::IBitmap& result) const;
	virtual bool SeekToPosition(int frameIndex) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentDestroyed();

private:
	void EnsureMediumClosed();
	int GetStreamPosition() const;
	bool MoveToNextFrame() const;

private:
	I_REF(istd::IChangeable, m_frameDataCompPtr);

	istd::CString m_mediumUrl;
	bool m_isPlaying;

	istd::TDelPtr<CvCapture> m_capturePtr;
	mutable int m_currentFrameIndex;
	int m_framesCount;
};


} // namespace iocv


#endif // !iocv_COcvVideoControllerComp_included

