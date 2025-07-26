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


#include <icmm/CCieLabColorModel.h>


// ACF includes
#include <istd/CChangeNotifier.h>
#include <imath/CGeneralUnitInfo.h>


namespace icmm
{


// public methods

CCieLabColorModel::CCieLabColorModel(const ITristimulusSpecification& spec)
	:m_spec(spec)
{
}


void CCieLabColorModel::SetTristimulusSpecification(const ITristimulusSpecification& spec)
{
	istd::CChangeNotifier changeNotifier(this);

	m_spec = spec;
}


const ITristimulusSpecification& CCieLabColorModel::GetTristimulusSpecification() const
{
	return m_spec;
}


// reimplemented (icmm::IColorModel)

IColorModel::ModelType CCieLabColorModel::GetModelType() const
{
	return MT_LAB;
}


IColorModel::ModelClass CCieLabColorModel::GetModelClass() const
{
	return MC_DEVICE_INDEPENDENT;
}


IColorModel::ColorSpaceClass CCieLabColorModel::GetColorSpaceClass() const
{
	return CSC_PERCEPTUAL;
}


int CCieLabColorModel::GetColorSpaceDimensionality() const
{
	return 3;
}


const imath::IUnitInfo* CCieLabColorModel::GetColorSpaceComponentInfo(int componentIndex) const
{
	static const std::array<imath::CGeneralUnitInfo, 3> cieLabUnitInfo = {
	imath::CGeneralUnitInfo(imath::IUnitInfo::UnitType::UT_TECHNICAL, "", 1.0, istd::CRange(0.0, 100.0)),
	imath::CGeneralUnitInfo(imath::IUnitInfo::UnitType::UT_TECHNICAL, "", 1.0, istd::CRange(-128.0, 127.0)),
	imath::CGeneralUnitInfo(imath::IUnitInfo::UnitType::UT_TECHNICAL, "", 1.0, istd::CRange(-128.0, 127.0))
	};

	return &cieLabUnitInfo.at(componentIndex);
}


QString CCieLabColorModel::GetColorSpaceComponentName(int componentIndex) const
{
	switch (componentIndex){
	case 0:
		return "L";
	case 1:
		return "a";
	case 2:
		return "b";
	}

	Q_ASSERT(false);

	return QString();
}


const icmm::IColorTransformation* CCieLabColorModel::CreateColorTranformation(
	const IColorModel& /*otherColorModel*/,
	const QByteArray& /*transformationId*/) const
{
	return nullptr;
}


IColorSpecification::ConstColorSpecPtr CCieLabColorModel::GetSpecification() const
{
	return std::make_shared<CTristimulusSpecification>(m_spec);
}


} // namespace icmm


