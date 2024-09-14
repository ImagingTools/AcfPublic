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


#include <icmm/CRgbColor.h>


// ACF includes
#include <icmm/CRgb.h>
#include <icmm/CRgbColorModel.h>


namespace icmm
{


CRgbColor::CRgbColor(const icmm::CRgb& rgb, ColorModelPtr modelPtr)
	: m_rgb(rgb),
	m_modelPtr(modelPtr)
{
}


CRgbColor::CRgbColor(const icmm::CRgb& Rgb)
	:m_rgb(Rgb)
{
	m_modelPtr = std::make_shared<icmm::CRgbColorModel>();  // D50 Color Spec
}


void CRgbColor::SetSpecification(const ITristimulusSpecification& spec)
{
	m_modelPtr = std::make_shared<CRgbColorModel>(spec);
}


// reimplemented (icmm::IRgbColor)

const icmm::CRgb& CRgbColor::GetRgb() const
{
	return m_rgb;
}


IColorSpecification::ConstColorSpecPtr CRgbColor::GetSpecification() const
{
	return m_modelPtr->GetSpecification();
}


// reimplemented (icmm::IColorObject)

icmm::CVarColor CRgbColor::GetColor() const
{
	icmm::CVarColor varColor(3);

	varColor.SetElement(0, m_rgb.GetRed());
	varColor.SetElement(1, m_rgb.GetGreen());
	varColor.SetElement(2, m_rgb.GetBlue());

	return varColor;
}


ConstColorModelPtr CRgbColor::GetColorModel() const
{
	return m_modelPtr;
}


std::unique_ptr<IColorObject> CRgbColor::CloneIntoUniquePtr() const
{
	return std::make_unique<CRgbColor>(*this);
}


// reimplemented (iser::ISerializable)

bool CRgbColor::Serialize(iser::IArchive& /*archive*/)
{
	return false;
}


} // namespace icmm


