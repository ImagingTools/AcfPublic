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
#include <icmm/IColorObject.h>
#include <icmm/ISpectralColorSpecification.h>


namespace icmm
{


class CSpectralColor: virtual public IColorObject
{
public:
	CSpectralColor(ColorModelPtr modelPtr);
	CSpectralColor(const ISpectralColorSpecification& spec);

	bool SetColor(const icmm::CVarColor& values);

	// reimplemented (icmm::IColorObject)
	virtual icmm::CVarColor GetColor() const override;	
	virtual ConstColorModelPtr GetColorModel() const override;

	// reimplemented (iser::IObject)
	virtual bool Serialize(iser::IArchive& archive) override;

private:
	icmm::CVarColor m_spectrumValues;
	std::shared_ptr<IColorModel> m_modelPtr;
};


} // namespace icmm


