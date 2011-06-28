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


#ifndef iipr_IRingPatternGeneratorParams_included
#define iipr_IRingPatternGeneratorParams_included


// ACF includes
#include "iser/ISerializable.h"


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


