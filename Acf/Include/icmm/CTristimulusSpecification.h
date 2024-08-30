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
#include <icmm/THierarchicalSpecificationWrap.h>
#include <icmm/CIlluminant.h>


namespace icmm
{


class CTristimulusSpecification: public THierarchicalSpecificationWrap<ITristimulusSpecification>
{
public:
	CTristimulusSpecification(
				ObserverType observerType = ObserverType::TwoDegree,
				AstmTableType method = AstmTableType::Unknown,
				const CIlluminant& illuminant = CIlluminant());

	CTristimulusSpecification(const CTristimulusSpecification& other);

	// reimplemented (ITristimulusSpecification)
	virtual const IIluminant& GetIlluminant() const override;
	virtual ObserverType GetObserverType() const override;
	virtual AstmTableType GetMethod() const override;

private:
	ObserverType m_observerType = ObserverType::TwoDegree;
	AstmTableType m_method = AstmTableType::Unknown;
	CIlluminant m_illuminant;
};


} // namespace icmm


