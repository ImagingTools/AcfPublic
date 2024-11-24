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


#include <icmm/CCieLabColor.h>


// ACF includes
#include <icmm/CCieLabColorModel.h>


namespace icmm
{


CCieLabColor::CCieLabColor(ColorModelPtr modelPtr)
{
	m_modelPtr = modelPtr;
}


CCieLabColor::CCieLabColor(const icmm::CLab& lab, const ITristimulusSpecification& spec)
	:m_lab(lab)
{
	m_modelPtr = std::make_shared<icmm::CCieLabColorModel>(spec);
}


// reimplemented (icmm::ICieLabColor)

const icmm::CLab& CCieLabColor::GetLab() const
{
	return m_lab;
}

IColorSpecification::ConstColorSpecPtr CCieLabColor::GetSpecification() const
{
	return m_modelPtr->GetSpecification();
}

// reimplemented (icmm::IColorObject)

icmm::CVarColor CCieLabColor::GetColor() const
{
	icmm::CVarColor varColor(3);

	varColor.SetElement(0, m_lab.GetL());
	varColor.SetElement(1, m_lab.GetA());
	varColor.SetElement(2, m_lab.GetB());

	return varColor;
}


ConstColorModelPtr CCieLabColor::GetColorModel() const
{
	return m_modelPtr;
}

std::unique_ptr<IColorObject> CCieLabColor::CloneIntoUniquePtr() const
{
	return std::make_unique<CCieLabColor>(*this);
}


// reimplemented (ISerializable)

bool CCieLabColor::Serialize(iser::IArchive& /*archive*/)
{
	return false;
}


} // namespace icmm


