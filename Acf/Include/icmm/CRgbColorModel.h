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
#include "icmm/CTristimulusSpecification.h"
#include <icmm/IColorModel.h>
#include <imath/CGeneralUnitInfo.h>

namespace icmm
{


class CRgbColorModel: virtual public IColorModel
{
public:

	CRgbColorModel();
    /**
        Sets a particular TristimulusSpecification,
        for example, if the RGB color is originating from Lab
    */
    CRgbColorModel(const ITristimulusSpecification& spec);

	// reimplemented (IColorModel)
	virtual ModelType GetModelType() const override;
	virtual ModelClass GetModelClass() const override;
	virtual ColorSpaceClass GetColorSpaceClass() const override;
	virtual int GetColorSpaceDimensionality() const override;
	virtual const imath::IUnitInfo* GetColorSpaceComponentInfo(int componentIndex) const override;
	virtual QString GetColorSpaceComponentName(int componentIndex) const override;
	virtual const icmm::IColorTransformation* CreateColorTranformation(const IColorModel& otherColorModel, const QByteArray& transformationId) const override;
    virtual IColorSpecification::ConstColorSpecPtr GetSpecification() const override;

protected:
	imath::CGeneralUnitInfo m_unitInfo;
    CTristimulusSpecification m_spec;
};


} // namespace icmm


