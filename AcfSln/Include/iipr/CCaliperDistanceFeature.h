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


#ifndef iipr_CCaliperDistanceFeature_included
#define iipr_CCaliperDistanceFeature_included


// ACF includes
#include <i2d/CLine2d.h>

// ACF-Solutions includes
#include <iipr/TWeightedFeatureWrap.h>


namespace iipr
{


/**
	Implementation of INumericValue interface for caliper based distance measurement feature.
*/
class CCaliperDistanceFeature: public iipr::TWeightedFeatureWrap<i2d::CLine2d>
{
public:
	typedef iipr::TWeightedFeatureWrap<i2d::CLine2d> BaseClass;

	CCaliperDistanceFeature(const i2d::CLine2d& caliperLine, double weight);

	double GetDistance() const;

	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(ValueTypeId valueTypeId) const;
	virtual imath::CVarVector GetComponentValue(ValueTypeId valueTypeId) const;
};


} // namespace iipr


#endif // !iipr_CCaliperDistanceFeature_included


