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


#include <icmm/CSpectralColorModel.h>


// ACF includes
#include <icmm/CSpectrumInfo.h>


namespace icmm
{


// public methods

CSpectralColorModel::CSpectralColorModel(ISpectralColorSpecification::ConstSpectralColorSpecPtr spec)
	:m_spec(spec)
{
}


// reimplemented (icmm::IColorModel)

IColorModel::ModelType CSpectralColorModel::GetModelType() const
{
	return MI_SPECTRAL;
}


IColorModel::ModelClass CSpectralColorModel::GetModelClass() const
{
	return MC_DEVICE_INDEPENDENT;
}


IColorModel::ColorSpaceClass CSpectralColorModel::GetColorSpaceClass() const
{
	return CSC_PERCEPTUAL;
}


int CSpectralColorModel::GetColorSpaceDimensionality() const
{
	if (m_spec == nullptr) {
		return 0;
	}

	int componentCount = 0;

	const ISpectrumInfo* infoPtr = m_spec->GetSpectrumInfo();
	if (infoPtr != nullptr) {
		int step = infoPtr->GetStep();
		if (step > 0) {
			istd::CIntRange range = infoPtr->GetSpectralRange();

			componentCount = 1 + range.GetLength() / step;
		}
	}

	return componentCount;
}


const imath::IUnitInfo* CSpectralColorModel::GetColorSpaceComponentInfo(int /*componentIndex*/) const
{
	return nullptr;
}


QString CSpectralColorModel::GetColorSpaceComponentName(int /*componentIndex*/) const
{
	return QString();
}


const icmm::IColorTransformation* CSpectralColorModel::CreateColorTranformation(
	const IColorModel& /*otherColorModel*/,
	const QByteArray& /*transformationId*/) const
{
	return nullptr;
}


IColorSpecification::ConstColorSpecPtr CSpectralColorModel::GetSpecification() const
{
	return m_spec;
}


} // namespace icmm


