/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include "iipr/CCaliperDistanceFeature.h"


// ACF includes
#include "istd/CChangeNotifier.h"
#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iipr
{


CCaliperDistanceFeature::CCaliperDistanceFeature(const i2d::CLine2d& caliperLine, double weight)
	:BaseClass(weight)
{
	SetPoint1(caliperLine.GetPoint1());
	SetPoint2(caliperLine.GetPoint2());

	imath::CVarVector values;
	values.SetElementsCount(2);

	values.SetElement(0, weight);
	values.SetElement(1, GetDistance());

	SetValues(values);
}


double CCaliperDistanceFeature::GetDistance() const
{
	return GetLength();
}


// reimplemented (imeas::INumericValue)

bool CCaliperDistanceFeature::IsValueTypeSupported(ValueTypeId valueTypeId) const
{
	switch (valueTypeId){
		case VTI_AUTO:
		case VTI_WEIGHT:
		case VTI_LENGTH:
			return true;
		default:
			break;
	}

	return false;
}


imath::CVarVector CCaliperDistanceFeature::GetComponentValue(ValueTypeId valueTypeId) const
{
	imath::CVarVector retVal;

	switch (valueTypeId){
		case VTI_AUTO:
			return GetValues();

		case VTI_WEIGHT:
			retVal.SetElementsCount(1);
			retVal.SetElement(0, GetWeight());
			break;

		case VTI_LENGTH:
			retVal.SetElementsCount(1);
			retVal.SetElement(0, GetDistance());
			break;
		default:
			break;
	}

	return retVal;
}


} // namespace iipr


