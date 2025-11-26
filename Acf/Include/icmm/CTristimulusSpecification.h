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
#include <icmm/ITristimulusSpecification.h>
#include <icmm/ISpectralColorSpecification.h>
#include <icmm/CIlluminant.h>


namespace icmm
{


class CTristimulusSpecification: virtual public ITristimulusSpecification, virtual public iser::ISerializable
{
public:
	CTristimulusSpecification(
				ObserverType observerType = ObserverType::TwoDegree,
				AstmTableType method = AstmTableType::Unknown,
				std::shared_ptr<IIlluminant> illuminantPtr = nullptr,
				std::shared_ptr<ISpectralColorSpecification> baseSpec = nullptr);

	CTristimulusSpecification(const ITristimulusSpecification& other);

	// reimplemented (ITristimulusSpecification)
	virtual std::shared_ptr<IIlluminant> GetIlluminant() const override;
	virtual ObserverType GetObserverType() const override;
	virtual AstmTableType GetMethod() const override;
	virtual std::shared_ptr<ISpectralColorSpecification> GetBaseSpecification() const override;

	// reimplemented (istd::IChangeable)
	virtual bool IsEqual(const istd::IChangeable& other) const override;
	
	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	bool operator==(const CTristimulusSpecification& other) const;

	// Return instance of commonly used specification
	static const icmm::CTristimulusSpecification& GetD50TwoDegree();

private:
	ObserverType m_observerType;
	AstmTableType m_method;
	std::shared_ptr<IIlluminant> m_illuminantPtr;
	std::shared_ptr<ISpectralColorSpecification> m_baseSpecPtr;
};


} // namespace icmm


