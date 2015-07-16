/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#pragma once


// ACF includes
#include "iimg/IBitmap.h"
#include "icam/CCameraDelegatorComp.h"


namespace icam
{


/**
	Camera provided bitmaps with integrated calibration information.
*/
class CCalibratedCameraComp: public icam::CCameraDelegatorComp
{
public:
	enum{
		RESOLUTION_PATTERN = 0xff00ff00
	};

	typedef icam::CCameraDelegatorComp BaseClass;

	I_BEGIN_COMPONENT(CCalibratedCameraComp);
		I_ASSIGN(m_scaleParamIdAttrPtr, "ScaleParamId", "ID of the scale parameter in the parameter set", true, "Scale");
	I_END_COMPONENT;

	static bool ReadImageResolution(const iimg::IBitmap& bitmap, double& resolution);
	static bool WriteImageResolution(iimg::IBitmap& bitmap, double resolution);

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);

private:
	I_ATTR(QByteArray, m_scaleParamIdAttrPtr);
};


} // namespace icam


