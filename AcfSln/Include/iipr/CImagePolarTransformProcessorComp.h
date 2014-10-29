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


#ifndef iipr_CImagePolarTransformProcessorComp_included
#define iipr_CImagePolarTransformProcessorComp_included


// ACF-Solutions includes
#include "iipr/CImageRegionProcessorCompBase.h"


namespace iipr
{


/**	
	Implementation of a processor for the polar tranformation of an image region.
*/
class CImagePolarTransformProcessorComp: public CImageRegionProcessorCompBase
{
public:
	typedef CImageRegionProcessorCompBase BaseClass;
	
	I_BEGIN_COMPONENT(CImagePolarTransformProcessorComp);
		I_ASSIGN(m_angleResolutionParamIdAttrPtr, "AngleResolutionParamId", "ID of the angle resolution parameter in the parameter set", true, "AngleResolution");
		I_ASSIGN(m_interpolationParamIdAttrPtr, "InterpolationParamId", "ID of the interpolation parameter in the parameter set", true, "Interpolation");
		I_ASSIGN(m_extraUnrollingAttrPtr, "ExtraUnrollingParamId", "ID of the extra unrolling value parameter in the parameter set", true, "ExtraUnrolling");
	I_END_COMPONENT;

protected:
	// reimplemented (CImageRegionProcessorCompBase)
	virtual bool ProcessImageRegion(
				const iimg::IBitmap& inputBitmap,
				const iprm::IParamsSet* paramsPtr,
				const i2d::IObject2d* aoiPtr,
				istd::IChangeable* outputPtr) const;

private:
	I_ATTR(QByteArray, m_angleResolutionParamIdAttrPtr);
	I_ATTR(QByteArray, m_interpolationParamIdAttrPtr);
	I_ATTR(QByteArray, m_extraUnrollingAttrPtr);
};


} // namespace iipr


#endif // !iipr_CImagePolarTransformProcessorComp_included

