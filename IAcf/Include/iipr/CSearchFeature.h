/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iipr_CSearchFeature_included
#define iipr_CSearchFeature_included


// ACF includes
#include "i2d/CVector2d.h"
#include "i2d/CPosition2d.h"

#include "iipr/TFeatureWrap.h"


namespace iipr
{


/**
	Implementation of IFeature interface for pattern search features.
*/
class CSearchFeature: public TFeatureWrap<i2d::CPosition2d>
			
{
public:
	typedef TFeatureWrap<i2d::CPosition2d> BaseClass;

	CSearchFeature(
				double weight,
				const i2d::CVector2d& position,
				double angle,
				const i2d::CVector2d& scale);

	double GetAngle() const;
	const i2d::CVector2d& GetScale() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_angle;
	i2d::CVector2d m_scale;
};


} // namespace iipr


#endif // !iipr_CSearchFeature_included

