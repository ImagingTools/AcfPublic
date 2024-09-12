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


#include <icmm/CSpectralColorSpecification.h>


namespace icmm
{



CSpectralColorSpecification::CSpectralColorSpecification(const ISpectrumInfo& spectrumInfo)
{
	m_info.CopyFrom(spectrumInfo);
}

CSpectralColorSpecification::CSpectralColorSpecification(istd::CIntRange range, int step)
{
	m_info.SetRange(range);
	m_info.SetStep(step);
}

// reimplemented (ISpectrumInfoProvider)

const ISpectrumInfo* CSpectralColorSpecification::GetSpectrumInfo() const
{
	return &m_info;
}


} // namespace icmm


