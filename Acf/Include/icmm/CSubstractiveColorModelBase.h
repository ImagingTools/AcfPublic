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
#include <icmm/ISubstractiveColorModel.h>
#include <icmm/CCieLabColor.h>
#include <icmm/CTristimulusSpecification.h>


namespace icmm
{


class CCieLabColor;


class CSubstractiveColorModelBase: virtual public icmm::ISubstractiveColorModel
{
public:
	CSubstractiveColorModelBase();

	void SetPreviewSpec(const ITristimulusSpecification& previewSpec);
	void SetColorantPreview(const QByteArray& colorantId, const icmm::CLab& preview);

	// reimplemented (icmm::IColorModel)
	virtual ModelType GetModelType() const override;
	virtual ModelClass GetModelClass() const override;
	virtual ColorSpaceClass GetColorSpaceClass() const override;
	virtual int GetColorSpaceDimensionality() const override;
	virtual const imath::IUnitInfo* GetColorSpaceComponentInfo(int componentIndex) const override;
	virtual QString GetColorSpaceComponentName(int componentIndex) const override;
	virtual const icmm::IColorTransformation* CreateColorTranformation(
				const IColorModel& otherColorModel,
				const QByteArray& transformationId = QByteArray()) const override;

	// reimplemented (icmm::ISubstractiveColorModel)
	virtual bool GetColorantVisualInfo(const QByteArray& colorantId, icmm::ICieLabColor& preview) const override;

private:
	/**
		Tristimulus specification used for all colorants in the color model.
	*/
	icmm::CTristimulusSpecification m_previewSpec;

	/**
		Mapping between a colorant and corresponding Lab value for its solid value.
	*/
	typedef QMap<QByteArray, icmm::CLab> ColorantPreviewMap;
	ColorantPreviewMap m_colorantPreviewMap;
};


} // namespace icmm


