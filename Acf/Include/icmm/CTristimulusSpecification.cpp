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


#include <icmm/CTristimulusSpecification.h>


namespace icmm
{


CTristimulusSpecification::CTristimulusSpecification(
			ObserverType observerType,
			AstmTableType method,
			std::shared_ptr<IIlluminant> illuminantPtr,
			std::shared_ptr<ISpectralColorSpecification> baseSpec)
:	m_observerType(observerType),
	m_method(method),
	m_illuminant(illuminantPtr),
	m_baseSpec(baseSpec)
{
}


CTristimulusSpecification::CTristimulusSpecification(const ITristimulusSpecification& other)
:	m_observerType(other.GetObserverType()),
	m_method(other.GetMethod()),
	m_illuminant(other.GetIlluminant()),
	m_baseSpec(other.GetBaseSpecification())
{
}


// reimplemented (ITristimulusSpecification)

std::shared_ptr<IIlluminant> icmm::CTristimulusSpecification::GetIlluminant() const
{
	return m_illuminant;
}


ObserverType CTristimulusSpecification::GetObserverType() const
{
	return m_observerType;
}


AstmTableType CTristimulusSpecification::GetMethod() const
{
	return m_method;
}


std::shared_ptr<ISpectralColorSpecification> CTristimulusSpecification::GetBaseSpecification() const
{
	return m_baseSpec;
}

bool CTristimulusSpecification::IsEqual(const IChangeable& other) const
{
	const CTristimulusSpecification* objectPtr = dynamic_cast<const CTristimulusSpecification*>(&other);

	if (objectPtr == nullptr){
		return false;
	}

	auto otherBaseSpec = objectPtr->GetBaseSpecification();
	bool isBaseSpecSame = this->m_baseSpec == nullptr && otherBaseSpec == nullptr;
	if (!isBaseSpecSame && this->m_baseSpec && otherBaseSpec) {
		isBaseSpecSame = this->m_baseSpec->IsEqual(*otherBaseSpec);
	}

	return m_observerType == objectPtr->GetObserverType() &&
		   m_method == objectPtr->GetMethod() &&
		   m_illuminant->IsEqual(*objectPtr->GetIlluminant()) &&
		   isBaseSpecSame;
}

} // namespace icmm


