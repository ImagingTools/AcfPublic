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


