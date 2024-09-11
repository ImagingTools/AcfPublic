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
#include "icmm/CRgb.h"
#include "icmm/IColorModel.h"
#include <icmm/IRgbColor.h>
#include <icmm/ITristimulusSpecification.h>


namespace icmm
{


class CRgbColor: virtual public IRgbColor
{
public:
    /**
        Takes a ColorModel (if you want to get particular about the color specification)
    */

    CRgbColor(const icmm::CRgb& rgb, ColorModelPtr modelPtr);

    /**
        Just pass Rgb values; defaults the ColorModel to D50/2
     */
    CRgbColor(const icmm::CRgb& rgb);

    void SetSpecification(const ITristimulusSpecification& spec);

    // reimplemented (icmm::IRgbColor)
    virtual const icmm::CRgb& GetRgb() const override;
	virtual IColorSpecification::ConstColorSpecPtr GetSpecification() const override;

	// reimplemented (icmm::IColorObject)
	virtual icmm::CVarColor GetColor() const override;
	virtual ConstColorModelPtr GetColorModel() const override;
	virtual std::unique_ptr<IColorObject> CloneIntoUniquePtr() const override;

	// reimplemented (iser::IObject)
	virtual bool Serialize(iser::IArchive& archive) override;

private:
    icmm::CRgb m_rgb;
	std::shared_ptr<IColorModel> m_modelPtr;
};


} // namespace icmm


