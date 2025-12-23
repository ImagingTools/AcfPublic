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
#include <icmm/IColorModel.h>
#include <icmm/CTristimulusSpecification.h>


namespace icmm
{


/**
	CCieLabColorModel implements the CIE Lab color model.

	This class provides a device-independent color model based on the CIE Lab color space.
	It allows configuration of the tristimulus specification and provides information about
	the color space, its components, and related transformations.

	\ingroup ColorModel
*/
class CCieLabColorModel: virtual public icmm::IColorModel
{
public:
	/**
		Constructs a CIE Lab color model with the given tristimulus specification.

		\param spec Tristimulus specification to use for the model.
	*/
	CCieLabColorModel(const ITristimulusSpecification& spec = CTristimulusSpecification());

	/**
		Sets the tristimulus specification for this color model.

		\param spec New tristimulus specification.
	*/
	void SetTristimulusSpecification(const ITristimulusSpecification& spec);

	/**
		Returns the current tristimulus specification.

		\return Reference to the tristimulus specification.
	*/
	const ITristimulusSpecification& GetTristimulusSpecification() const;

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
	virtual IColorSpecification::ConstColorSpecPtr GetSpecification() const override;

private:
	CTristimulusSpecification m_spec;
};


} // namespace icmm


