/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
#include <i2d/CPosition2d.h>
#include <i2d/CAffineTransformation2d.h>

// ACF-Solutions includes
#include <iipr/TWeightedFeatureWrap.h>


namespace iipr
{


/**
	Implementation of a general image object feature.
*/
class CObjectFeature: public TWeightedFeatureWrap<i2d::CPosition2d>
{
public:
	typedef TWeightedFeatureWrap<i2d::CPosition2d> BaseClass;

	CObjectFeature();
	CObjectFeature(
				double weight,
				const i2d::CVector2d& position,
				double angle = 0.0,
				const i2d::CVector2d& scale = i2d::CVector2d(1.0, 1.0));

	double GetAngle() const;
	i2d::CVector2d GetScale() const;
	void SetScale(const i2d::CVector2d& scale);

	QByteArray GetObjectId() const;
	void SetObjectId(const QByteArray& objectId);

	const i2d::ITransformation2d& GetTransformation() const;

	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(ValueTypeId valueTypeId) const override;
	virtual imath::CVarVector GetComponentValue(ValueTypeId valueTypeId) const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS) override;
	virtual istd::IChangeableUniquePtr CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const override;

private:
	double m_angle;
	i2d::CVector2d m_scale;
	QByteArray m_objectId;
	mutable i2d::CAffineTransformation2d m_transformation;
};


} // namespace iipr


