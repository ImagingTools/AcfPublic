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


#include <icmm/CRgbColorModel.h>


// ACF includes
#include <icmm/CCmykColorModel.h>
#include <icmm/CRgbToHsvTranformation.h>
#include <icmm/CRgbToXyzTransformation.h>
#include <icmm/CRgbToCmykTransformation.h>


namespace icmm
{


// public methods

CRgbColorModel::CRgbColorModel()
	:m_unitInfo(0, "", 100.0, istd::CRange(0, 1.0)),
	m_spec(ObserverType::TwoDegree, AstmTableType::E308Table5, std::make_shared<CIlluminant>(StandardIlluminant::D50))
{
}

CRgbColorModel::CRgbColorModel(const ITristimulusSpecification& spec)
	:m_unitInfo(0, "", 100.0, istd::CRange(0, 1.0)),
	m_spec(spec)
{
}

// reimplemented (IColorModel)

IColorModel::ModelType CRgbColorModel::GetModelType() const
{
	return MT_RGB;
}


IColorModel::ModelClass CRgbColorModel::GetModelClass() const
{
	return MC_DEVICE_DEPENDENT;
}


IColorModel::ColorSpaceClass CRgbColorModel::GetColorSpaceClass() const
{
	return CSC_ADDITIVE;
}


int CRgbColorModel::GetColorSpaceDimensionality() const
{
	return 3;
}


const imath::IUnitInfo* CRgbColorModel::GetColorSpaceComponentInfo(int /*componentIndex*/) const
{
	return &m_unitInfo;
}


QString CRgbColorModel::GetColorSpaceComponentName(int componentIndex) const
{
	switch (componentIndex){
	case 0:
		return "R";
	case 1:
		return "G";
	case 2:
		return "B";
	}

	Q_ASSERT(false);

	return QString();
}


const icmm::IColorTransformation* CRgbColorModel::CreateColorTranformation(const IColorModel& otherColorModel, const QByteArray& /*transformationId*/) const
{
	switch (otherColorModel.GetModelType()){
	case MT_XYZ:
		return new icmm::CRgbToXyzTransformation();
	case MT_HSV:
		return new icmm::CRgbToHsvTranformation();
	case MT_COLORANTS:
		{
			const icmm::CCmykColorModel* cmykModelPtr = dynamic_cast<const icmm::CCmykColorModel*>(&otherColorModel);
			if (cmykModelPtr != nullptr){
				return new icmm::CRgbToCmykTransformation();
			}
		}
	}

	return nullptr;
}


IColorSpecification::ConstColorSpecPtr CRgbColorModel::GetSpecification() const
{
	return std::make_shared<CTristimulusSpecification>(m_spec);
}


} // namespace icmm


