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


#ifndef iipr_CFeatureBase_included
#define iipr_CFeatureBase_included


#include "iipr/IFeature.h"


namespace iipr
{


/**
	Base implementation of IFeature interface to reduce overhead by interface changes.
*/
class CFeatureBase: virtual public iipr::IFeature
{
public:
	CFeatureBase(double weight = 1.0);

	void SetWeight(double weight);

	// reimplemented (iipr::IFeature)
	virtual double GetWeight() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_weight;
};


} // namespace iipr


#endif // !iipr_CFeatureBase_included


