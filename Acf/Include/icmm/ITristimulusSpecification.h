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
#include <icmm/IIlluminant.h>


namespace icmm
{


class ITristimulusSpecification: virtual public IColorSpecification
{
public:
	virtual std::shared_ptr<IIlluminant> GetIlluminant() const = 0;
	virtual ObserverType GetObserverType() const = 0;
	virtual AstmTableType GetMethod() const = 0;

	/**
		Get the base spectral specification, if exists.
	*/
	virtual std::shared_ptr<ISpectralColorSpecification> GetBaseSpecification() const = 0;

protected:
	// reimplemented (IColorSpecification)
	virtual SpecType GetSpecificationType() const override;
};


inline IColorSpecification::SpecType ITristimulusSpecification::GetSpecificationType() const
{
	return SpecType::Tristimulus;
}

typedef std::shared_ptr<ITristimulusSpecification> TristimulusPtr;
typedef std::shared_ptr<const ITristimulusSpecification> ConstTristimulusPtr;

} // namespace icmm


