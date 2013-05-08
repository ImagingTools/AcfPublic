/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "i2d/CSplineSegment.h"


// ACF includes
#include "istd/TDelPtr.h"
#include "istd/TChangeNotifier.h"


namespace i2d
{


static const double minField = 0.001;


bool CSplineSegment::IsCloserThan(const i2d::CVector2d position, double distance) const
{
	i2d::CVector2d point1 = GetPointBegin();
	i2d::CVector2d point2 = GetPointEnd();
	i2d::CVector2d control1 = GetBezierPointBegin();
	i2d::CVector2d control2 = GetBezierPointEnd();

	double left = point1.GetX();
	double right = point1.GetX();
	double top = point1.GetY();
	double bottom = point1.GetY();

	if (point2.GetX() < left){
		left = point2.GetX();
	}
	else if (point2.GetX() > right){
		right = point2.GetX();
	}
	if (point2.GetY() < top){
		top = point2.GetY();
	}
	else if (point2.GetY() > bottom){
		bottom = point2.GetY();
	}

	if (control1.GetX() < left){
		left = control1.GetX();
	}
	else if (control1.GetX() > right){
		right = control1.GetX();
	}
	if (control1.GetY() < top){
		top = control1.GetY();
	}
	else if (control1.GetY() > bottom){
		bottom = control1.GetY();
	}

	if (control2.GetX() < left){
		left = control2.GetX();
	}
	else if (control2.GetX() > right){
		right = control2.GetX();
	}
	if (control2.GetY() < top){
		top = control2.GetY();
	}
	else if (control2.GetY() > bottom){
		bottom = control2.GetY();
	}

	if (			(left - distance < position.GetX()) &&
					(right + distance > position.GetX()) &&
					(top - distance < position.GetY()) &&
					(bottom + distance > position.GetY())){
		if ((right - left) * (bottom - top) < minField){
			return true;
		}
		else{
			CSplineSegment segment;

			GetHalfSegmentFirst(segment);
			if (segment.IsCloserThan(position, distance)){
				return true;
			}
			GetHalfSegmentSecond(segment);
			return segment.IsCloserThan(position, distance);
		}
	}

	return false;
}


// reimplemented (istd::IChangeable)

int CSplineSegment::GetSupportedOperations() const
{
	return SO_COPY | SO_CLONE;
}


bool CSplineSegment::CopyFrom(const IChangeable& object, CompatibilityMode /*mode*/)
{
	const CSplineSegment* splineSegmentPtr = dynamic_cast<const CSplineSegment*>(&object);

	if (splineSegmentPtr != NULL){	
		istd::CChangeNotifier notifier(this);

		A(splineSegmentPtr->A());
		B(splineSegmentPtr->B());
		C(splineSegmentPtr->C());
		D(splineSegmentPtr->D());

		return true;
	}	

	return false;
}


istd::IChangeable* CSplineSegment::CloneMe(CompatibilityMode mode) const 
{
	istd::TDelPtr<CSplineSegment> clonePtr(new CSplineSegment);

	if (clonePtr->CopyFrom(*this, mode)){
		return clonePtr.PopPtr();
	}

	return NULL;
}


} // namespace i2d


