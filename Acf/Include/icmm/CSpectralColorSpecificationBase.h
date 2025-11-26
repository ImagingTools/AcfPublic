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
#include <icmm/ISpectralColorSpecification.h>
#include <icmm/CSpectrumInfo.h>


namespace icmm
{


class CSpectralColorSpecificationBase: virtual public ISpectralColorSpecification
{
public:
	virtual ~CSpectralColorSpecificationBase();

	CSpectralColorSpecificationBase(const CSpectralColorSpecificationBase& spec);

	// reimplemented (ISpectrumInfoProvider)
	virtual const ISpectrumInfo* GetSpectrumInfo() const override;
	virtual SpectrumType GetSpectrumType() const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	// reimplemented (istd::IChangeable)
	virtual bool IsEqual(const istd::IChangeable& other) const override;

protected:
	CSpectralColorSpecificationBase(const ISpectrumInfo& spectrumInfo);
	CSpectralColorSpecificationBase(istd::CIntRange range, int step);

	SpectrumType m_spectrumType;

private:
	CSpectrumInfo m_info;
};


} // namespace icmm


