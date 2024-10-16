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
#include <imath/TISampledFunction.h>
#include <icmm/ISpectrumInfoProvider.h>


namespace icmm
{


/**
	Common interface for a measured/sampled spectrum.
	Spectrum is described as container of samples in the regular 1D-grid.
	Sampling grid information can be retrieved via ISpectrumInfoProvider interface.
	Sample values of the spectrum are accessable via imath::ISampledFunction interface
	For getting the "real" spectral values use imath::IMathfunction interface.
	Function domain is defined by the spectral range (\sa ISpectralInfo)
	Function range is normally [0, 1],
	but can also be acquired by \c GetResultValueRange method of imath::TISampledFunction.
*/
class ISpectrum:
			virtual public imath::ISampledFunction,
			virtual public ISpectrumInfoProvider,
			virtual public iser::ISerializable
{
};


} // namespace icmm


