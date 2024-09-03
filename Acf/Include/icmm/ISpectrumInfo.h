/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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


#pragma once


// ACF includes
#include <istd/IChangeable.h>
#include <istd/TRange.h>


namespace icmm
{


/**
	Common interface for describing the properties or meta-informations of a measured/sampled spectrum.
*/
class ISpectrumInfo: virtual public istd::IChangeable
{
public:
	/**
		Get the spectral range of the measured values given in nm.
	*/
	virtual istd::CIntRange GetSpectralRange() const = 0;

	/**
		Get distance/step between the samples in the spectrum definition (in nm).
		We assume that we have regular sampling grid.
	*/
	virtual int GetStep() const = 0;
};


} // namespace icmm
