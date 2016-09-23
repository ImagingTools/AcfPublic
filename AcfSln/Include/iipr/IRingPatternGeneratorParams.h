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


#ifndef iipr_IRingPatternGeneratorParams_included
#define iipr_IRingPatternGeneratorParams_included


// ACF includes
#include <iser/ISerializable.h>


namespace iipr
{


/**
	Common interface for parameters of the ring pattern generators.
*/
class IRingPatternGeneratorParams: virtual public iser::ISerializable
{
public:
	enum PatternType
	{
		/**
			Ring pattern is generated using a fixed wave length.
		*/
		PT_FIXED_WAVELENGTH,

		/**
			Ring pattern is generated using discending wave length.
		*/
		PT_DYNAMIC_WAVELENGTH
	};

	/**
		Get used pattern generation mode.
		\sa PatternType
	*/
	virtual int GetPatternMode() const = 0;
	
	/**
		Set pattern generation mode.
		\sa PatternType
	*/
	virtual void SetPatternMode(int patternMode) = 0;
	
	/**
		Get used pattern wavelength.
	*/
	virtual double GetWaveLength() const = 0;

	/**
		Set pattern wavelength.
	*/
	virtual void SetWaveLength(double waveLength) = 0;
};


} // namespace iipr


#endif // !iipr_IRingPatternGeneratorParams_included


