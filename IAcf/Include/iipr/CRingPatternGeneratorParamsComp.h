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


#ifndef iipr_CRingPatternGeneratorParamsComp_included
#define iipr_CRingPatternGeneratorParamsComp_included


// ACF includes
#include "icomp/CComponentBase.h"


// IACF includes
#include "iipr/IRingPatternGeneratorParams.h"


namespace iipr
{


class CRingPatternGeneratorParamsComp:
			public icomp::CComponentBase,
			virtual public iipr::IRingPatternGeneratorParams
{
public:
	typedef icomp::CComponentBase BaseClass;
	
	I_BEGIN_COMPONENT(CRingPatternGeneratorParamsComp);
		I_REGISTER_INTERFACE(iipr::IRingPatternGeneratorParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_defaultPatternModeAttrPtr, "DefaultPatternMode", "Default mode for ring pattern generation.\n0 - Fixed wavelength ist used\n1 - Dynamic wavelength is used", false, 0);
		I_ASSIGN(m_defaultWaveLengthAttrPtr, "DefaultWaveLength", "Default wavelength used for generated ring pattern in pixel", false, 4);
	I_END_COMPONENT;

	CRingPatternGeneratorParamsComp();

	// reimplemented (iipr::IRingPatternGeneratorParams)
	virtual int GetPatternMode() const;
	virtual void SetPatternMode(int patternMode);
	virtual double GetWaveLength() const;
	virtual void SetWaveLength(double waveLength);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(int, m_defaultPatternModeAttrPtr);
	I_ATTR(double, m_defaultWaveLengthAttrPtr);

	int m_patternMode;
	double m_waveLength;
};


} // namespace iipr


#endif // !iipr_CRingPatternGeneratorParamsComp_included

