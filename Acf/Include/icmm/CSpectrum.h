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
#include <imath/CSampledFunction.h>
#include <iser/ISerializable.h>
#include <icmm/ISpectrum.h>
#include <icmm/ISpectrumInfo.h>


namespace icmm
{


/**
	Standard spectrum implementation.
*/
class CSpectrum:
			public imath::CSampledFunction,
			virtual public ISpectrum,
			virtual protected ISpectrumInfo,
			virtual public iser::ISerializable
{
public:
	typedef imath::CSampledFunction BaseClass;

	CSpectrum();
	CSpectrum(const CSpectrum& other);
	CSpectrum(int startWavelength, int endWavelength, int step, const std::vector<double>& spectrumSamples);
	CSpectrum(const istd::CIntRange& wavelengthRange, int step, const std::vector<double>& spectrumSamples);

	// reimplemented (icmm::ISpectrumInfoProvider)
	virtual const ISpectrumInfo* GetSpectrumInfo() const override;

	// reimplemented (icmm::ISpectrumInfo)
	virtual istd::CIntRange GetSpectralRange() const override;
	virtual int GetStep() const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const override;
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS) override;
	virtual bool IsEqual(const IChangeable& object) const override;
	virtual IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const override;
	virtual bool ResetData(CompatibilityMode mode = CM_WITHOUT_REFS) override;

private:
	int m_step;
};


} // namespace icmm


