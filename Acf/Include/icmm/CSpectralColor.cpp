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


#include <icmm/CSpectralColor.h>


// ACF includes
#include <icmm/CSpectralColorModel.h>


namespace icmm
{


CSpectralColor::CSpectralColor(ColorModelPtr modelPtr)
{
	m_modelPtr = modelPtr;
}


CSpectralColor::CSpectralColor(std::shared_ptr<ISpectralColorSpecification> spec)
{
	m_modelPtr = std::make_shared<icmm::CSpectralColorModel>(spec);
}


bool CSpectralColor::SetColor(const CVarColor& otherSpectrals)
{
	if(m_modelPtr->GetColorSpaceDimensionality() != otherSpectrals.GetElementsCount()){
		return false;
	}

	m_spectrumValues = otherSpectrals;

	return true;
}

ISpectralColorSpecification::ConstSpectralColorSpecPtr CSpectralColor::GetSpecification() const
{
	auto spectralColorDef = std::dynamic_pointer_cast<const ISpectralColorSpecification>(m_modelPtr->GetSpecification());
	return spectralColorDef;
}

// reimplemented (icmm::IColorObject)

icmm::CVarColor CSpectralColor::GetColor() const
{
	return m_spectrumValues;
}

ConstColorModelPtr CSpectralColor::GetColorModel() const
{
	return m_modelPtr;
}

std::unique_ptr<IColorObject> CSpectralColor::CloneIntoUniquePtr() const
{
	return std::make_unique<CSpectralColor>(*this);
}

bool CSpectralColor::Serialize(iser::IArchive& /*archive*/)
{
	return false;
}


} // namespace icmm


