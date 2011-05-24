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


#ifndef iswr_CSwissRangerParams_included
#define iswr_CSwissRangerParams_included


#include "iswr/ISwissRangerParams.h"


namespace iswr
{


/**
	Parameters od SwissRanger sensor
*/
class CSwissRangerParams: virtual public iswr::ISwissRangerParams
{
public:
	CSwissRangerParams();

	// reimplemented (iswr::ISwissRangerParams)
	virtual void SetMedianFilterEnabled(bool isMedianFilterEnabled = true);
	virtual bool IsMedianFilterEnabled() const;
	virtual void SetAdaptiveFilterEnabled(bool isAdaptiveFilterEnabled = true);
	virtual bool IsAdaptiveFilterEnabled() const;
	virtual void SetAmplitudeThreshold(double amplitudeThreshold);
	virtual double GetAmplitudeThreshold() const;
	virtual void SetModulationFrequencyMode(int modulationFrequencyMode);
	virtual int GetModulationFrequencyMode() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	bool m_isMedianFilterEnabled;
	bool m_isAdaptiveFilterEnabled;	
	double m_amplitudeThreshold;
	int m_modulationFrequencyMode;
	istd::CRange m_distanceClipRange;
};


} // namespace iswr


#endif // !iswr_CSwissRangerParams_included


