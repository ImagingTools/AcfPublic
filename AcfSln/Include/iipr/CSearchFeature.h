/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_CSearchFeature_included
#define iipr_CSearchFeature_included


// ACF includes
#include "i2d/CVector2d.h"
#include "i2d/CPosition2d.h"
#include "i2d/CAffineTransformation2d.h"

// ACF-Solutions includes
#include "iipr/TWeightedFeatureWrap.h"


namespace iipr
{


/**
	Implementation of the pattern search feature.
*/
class CSearchFeature: public TWeightedFeatureWrap<i2d::CPosition2d>
{
public:
	typedef TWeightedFeatureWrap<i2d::CPosition2d> BaseClass;

	CSearchFeature(
				double weight,
				const i2d::CVector2d& position,
				double angle,
				const i2d::CVector2d& scale,
				int index = -1,
				const QString& id = "");

	double GetAngle() const;
	const i2d::CVector2d& GetScale() const;
	int GetIndex() const;
	const QString& GetId() const;
	const i2d::ITransformation2d& GetTransformation() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_angle;
	i2d::CVector2d m_scale;
	int m_index;
	QString m_id;
	mutable i2d::CAffineTransformation2d m_transformation;
};


} // namespace iipr


#endif // !iipr_CSearchFeature_included


