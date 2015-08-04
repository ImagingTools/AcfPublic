/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iipr_CImageNormalizeProcessorComp_included
#define iipr_CImageNormalizeProcessorComp_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "i2d/CRectangle.h"

// ACF-Solutions includes
#include "imeas/ILinearAdjustParams.h"

#include "iipr/CImageProcessorCompBase.h"


namespace iipr
{


/**
	Implementation of image smooth operator with homogeneous rectangle kernel.
	This implementation uses moving average alghorithm.
*/
class CImageNormalizeProcessorComp: public iipr::CImageProcessorCompBase
{
public:
	typedef iipr::CImageProcessorCompBase BaseClass;

	I_BEGIN_COMPONENT(CImageNormalizeProcessorComp);
		I_ASSIGN(m_aoiParamIdAttrPtr, "AoiParamId", "ID of rectangle AOI area in parameter set, only this area will processed", false, "AoiParamId");
		I_ASSIGN(m_adjustParamsIdAttrPtr, "AdjustParamsId", "ID of parameters for contrast and brightness in parameter set", false, "AdjustParamsId");
		I_ASSIGN(m_defaultAoiParamCompPtr, "DefaultAoiParam", "Default parameter for rectangle AOI area, if no parameters are specified", false, "DefaultAoiParam");
		I_ASSIGN(m_defaultAdjustParamsCompPtr, "DefaultAdjustParams", "Default adjust parameters, if no parameters are specified", false, "DefaultAdjustParams");
	I_END_COMPONENT;

protected:
	// reimplemented (iipr::CImageProcessorCompBase)
	virtual bool ProcessImage(
				const iprm::IParamsSet* paramsPtr,
				const iimg::IBitmap& inputImage,
				iimg::IBitmap& outputImage);

private:
	I_ATTR(QByteArray, m_aoiParamIdAttrPtr);
	I_ATTR(QByteArray, m_adjustParamsIdAttrPtr);
	I_REF(i2d::CRectangle, m_defaultAoiParamCompPtr);
	I_REF(imeas::ILinearAdjustParams, m_defaultAdjustParamsCompPtr);
};


} // namespace iipr


#endif // !iipr_CImageNormalizeProcessorComp_included


