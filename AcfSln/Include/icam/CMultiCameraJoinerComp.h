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


#pragma once


// Qt includes
#include <QtCore/QMutex>

// ACF includes
#include <ilog/TLoggerCompWrap.h>
#include <iproc/TSyncProcessorWrap.h>
#include <iprm/ISelectionParam.h>
#include <iprm/IParamsManager.h>

// ACF-Solutions includes
#include <icam/IBitmapAcquisition.h>
#include <icam/CBitmapJoinerCompBase.h>


namespace icam
{


/**
	Joiner of the several cameras.
	The output bitmap contains all sub-bitmaps ordered in the defined layout (grid)
*/
class CMultiCameraJoinerComp:
			public icam::CBitmapJoinerCompBase,
			public iproc::TSyncProcessorWrap<icam::IBitmapAcquisition>
{
public:
	typedef icam::CBitmapJoinerCompBase BaseClass;

	I_BEGIN_COMPONENT(CMultiCameraJoinerComp);
		I_REGISTER_INTERFACE(icam::IBitmapAcquisition);
		I_REGISTER_INTERFACE(iproc::IProcessor);
		I_ASSIGN(m_cameraCompPtr, "Camera", "Camera object used for image acquisition", true, "Camera");
		I_ASSIGN(m_cameraParamsManagerIdAttrPtr, "CameraParamsManagerId", "ID of the camera params manager in the processing parameter set", true, "CameraParamsManagerId");
		I_ASSIGN(m_cameraParamsManagerCompPtr, "ParamsManager", "Direct connection to the params manager (ParamSelector must be set as well)", false, "ParamsManager");
		I_ASSIGN(m_cameraSelectorCompPtr, "ParamSelector", "Index of the ParamSet in the ParamsManager (it must be set as well)", false, "ParamSelector");
	I_END_COMPONENT;

	// reimplemented (iipr::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const override;

	// reimplemented (iproc::IProcessor)
	virtual iproc::IProcessor::TaskState DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL) override;
	virtual void InitProcessor(const iprm::IParamsSet* paramsPtr) override;

private:
	const iprm::IParamsManager* GetCameraParamsManager(const iprm::IParamsSet* paramsPtr) const;

private:
	I_REF(icam::IBitmapAcquisition, m_cameraCompPtr);
	
	I_ATTR(QByteArray, m_cameraParamsManagerIdAttrPtr);

	I_REF(iprm::IParamsManager, m_cameraParamsManagerCompPtr);
	I_REF(iprm::ISelectionParam, m_cameraSelectorCompPtr);

	QMutex m_lock;
};


} // namespace icam


