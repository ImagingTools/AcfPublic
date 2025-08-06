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


#ifndef icalib_CSimpleLensCorrectionComp_included
#define icalib_CSimpleLensCorrectionComp_included


// ACF includes
#include <icomp/CComponentBase.h>

// ACF-Solutions includes
#include <icalib/CSimpleLensCorrection.h>


namespace icalib
{


/**
	Attributable component for simple lens correction.
*/
class CSimpleLensCorrectionComp: public icomp::CComponentBase, public CSimpleLensCorrection
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef CSimpleLensCorrection BaseClass2;

	I_BEGIN_COMPONENT(CSimpleLensCorrectionComp);
		I_REGISTER_INTERFACE(ICalibration2d);
		I_REGISTER_INTERFACE(ITransformation2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(CSimpleLensCorrection);
		I_ASSIGN(m_defaultDistortionFactorAttrPtr, "DefaultDistortionFactor", "Default value of lens distortion factor", true, 0);
		I_ASSIGN(m_defaultOpticalCenterXAttrPtr, "DefaultOpticalCenterX", "Default value of lens optical center X", true, 0);
		I_ASSIGN(m_defaultOpticalCenterYAttrPtr, "DefaultOpticalCenterY", "Default value of lens optical center Y", true, 0);
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

private:
	I_ATTR(double, m_defaultDistortionFactorAttrPtr);
	I_ATTR(double, m_defaultOpticalCenterXAttrPtr);
	I_ATTR(double, m_defaultOpticalCenterYAttrPtr);
};


} // namespace icalib


#endif // !icalib_CSimpleLensCorrectionComp_included


