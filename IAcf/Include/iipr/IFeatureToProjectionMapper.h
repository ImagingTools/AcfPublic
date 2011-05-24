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


#ifndef iipr_IFeatureToProjectionMapper_included
#define iipr_IFeatureToProjectionMapper_included


// ACF includes
#include "i2d/CVector2d.h"
#include "iprm/IParamsSet.h"


namespace iipr
{


class IFeature;


/**
	Interface allowing mapping of extracted features to native coordinate systems.
*/
class IFeatureToProjectionMapper: virtual public istd::IPolymorphic
{
public:
	/**
		Get position on projection using position extracted from projection.
	*/
	virtual bool GetProjectionPosition(
				const IFeature& feature,
				const iprm::IParamsSet* paramsPtr,
				double& result) const = 0;
};


} // namespace iipr


#endif // !iipr_IFeatureToProjectionMapper_included


