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


