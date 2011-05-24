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


#ifndef iswr_CSwissRangerParamsComp_included
#define iswr_CSwissRangerParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"

// IACF includes
#include "iswr/CSwissRangerParams.h"


namespace iswr
{


/**
	SwissRanger based camera component implementing interfaces 
	\c iproc::IBitmapAcquisition and \c icam::IExposureConstraints for exposure control support.
*/
class CSwissRangerParamsComp: public icomp::CComponentBase, public iswr::CSwissRangerParams

{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSwissRangerParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(iswr::ISwissRangerParams);	
		I_ASSIGN(m_isMedianFilterEnabledAttrPtr, "MedianEnabled", "Internal 3x3 median filter is enabled", false, true);
		I_ASSIGN(m_amplitudeThresholdAttrPtr, "AmplitudeThreshold", "Threshold for signal amplitude.\nAll values below this value are ignored", false, 0);
		I_ASSIGN(m_modulationFrequencyModeAttrPtr, "ModulationFrequency", "Modulation frequency.\n0 - 40MHz(3.75m SRR3)\n1 - 30MHz(5m SR3, SR4)\n2 - 21MHz(7.14m, SR3)\n3 - 20MHz(7.5m, SR3)\n4 - 19MHz(7.89m, SR3)", false, 1);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(bool, m_isMedianFilterEnabledAttrPtr);
	I_ATTR(double, m_amplitudeThresholdAttrPtr);
	I_ATTR(int, m_modulationFrequencyModeAttrPtr);
};


} // namespace iswr


#endif // !iswr_CSwissRangerParamsComp_included


