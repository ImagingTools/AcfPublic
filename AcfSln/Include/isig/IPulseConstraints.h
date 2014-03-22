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


#ifndef isig_IPulseConstraints_included
#define isig_IPulseConstraints_included


// ACF includes
#include "istd/IChangeable.h"
#include "istd/TRange.h"


namespace isig
{


/**
	Constraits of signal pulse paramters (isig::IPulseParams).
*/
class IPulseConstraints: virtual public istd::IChangeable
{
public:
	/**
		List of flags for supported options.
	*/
	enum PulseSupportedFlags
	{
		PSF_NONE = 0,
		PSF_DELAY_TIME = 1 << 0,
		PSF_PULSE_DURATION = 1 << 1,
		PSF_RELAXING_TIME = 1 << 2
	};

	/**
		Gets information about supported features.
	*/
	virtual int GetPulseSupportedFlags() const = 0;

	/**
		Get information about delay time range.
		\return	information about possible delay time in seconds
	*/
	virtual istd::CRange GetDelayTimeRange() const = 0;
	/**
		Get information about on time range.
		\return	information about possible on time in seconds
	*/
	virtual istd::CRange GetPulseDurationRange() const = 0;
	/**
		Get information about off time range.
		\return	information about possible off time in seconds
	*/
	virtual istd::CRange GetRelaxingTimeRange() const = 0;
};


} // namespace isig


#endif // !isig_IPulseConstraints_included


