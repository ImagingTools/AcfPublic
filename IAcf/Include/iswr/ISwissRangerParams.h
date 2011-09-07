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


#ifndef iswr_ISwissRangerParams_included
#define iswr_ISwissRangerParams_included


#include "iswr/iswr.h"


// ACF includes
#include "istd/CRange.h"

#include "iser/ISerializable.h"


namespace iswr
{


/**
	Parameters od SwissRanger sensor
*/
class ISwissRangerParams: virtual public iser::ISerializable
{
public:
	virtual void SetMedianFilterEnabled(bool isEnabled = true) = 0;
	virtual bool IsMedianFilterEnabled() const = 0;

	virtual void SetAdaptiveFilterEnabled(bool isEnabled = true) = 0;
	virtual bool IsAdaptiveFilterEnabled() const = 0;

	virtual void SetAmplitudeThreshold(double amplitudeThreshold) = 0;
	virtual double GetAmplitudeThreshold() const = 0;

	virtual void SetModulationFrequencyMode(int modulationFrequencyMode) = 0;
	virtual int GetModulationFrequencyMode() const = 0;
};


} // namespace iswr


#endif // !iswr_ISwissRangerParams_included


