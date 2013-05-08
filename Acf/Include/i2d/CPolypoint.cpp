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


#include "i2d/CPolypoint.h"


// ACF includes
#include "istd/TChangeNotifier.h"
#include "i2d/CRectangle.h"


namespace i2d
{


// reimplemented (i2d::IObject2d)

CVector2d CPolypoint::GetCenter() const
{
	CVector2d sumVector(0, 0);
	for (		Points::ConstIterator iter = m_points.begin();
				iter != m_points.end();
				++iter){
		sumVector += *iter;
	}

	return sumVector / m_points.size();
}


void CPolypoint::MoveCenterTo(const CVector2d& position)
{
	CVector2d diffVector = position - CPolypoint::GetCenter();

	istd::CChangeNotifier notifier(this, CF_OBJECT_POSITION | CF_MODEL);

	for (		Points::Iterator iter = m_points.begin();
				iter != m_points.end();
				++iter){
		*iter += diffVector;
	}
}


CRectangle CPolypoint::GetBoundingBox() const
{	
	if (!m_points.isEmpty()){
		Points::ConstIterator iter = m_points.constBegin();
		Q_ASSERT(iter != m_points.constEnd());

		const i2d::CVector2d& firstPoint = *iter;
		i2d::CRectangle boundingBox(firstPoint, firstPoint);

		for (		++iter;
					iter != m_points.end();
					++iter){
			const i2d::CVector2d& point = *iter;

			boundingBox.Unite(point);
		}

		return boundingBox;
	}

	return i2d::CRectangle::GetEmpty();
}


bool CPolypoint::Transform(
		const ITransformation2d& transformation,
		ITransformation2d::ExactnessMode mode,
		double* /*errorFactorPtr*/)
{
	for (		Points::Iterator iter = m_points.begin();
				iter != m_points.end();
				++iter){
		CVector2d transformedPos;
		if (!transformation.GetPositionAt(*iter, transformedPos, mode)){
			return false;
		}

		*iter = transformedPos;
	}

	return true;
}


bool CPolypoint::InvTransform(
		const ITransformation2d& transformation,
		ITransformation2d::ExactnessMode mode,
		double* /*errorFactorPtr*/)
{
	for (		Points::Iterator iter = m_points.begin();
				iter != m_points.end();
				++iter){
		CVector2d transformedPos;
		if (!transformation.GetInvPositionAt(*iter, transformedPos, mode)){
			return false;
		}

		*iter = transformedPos;
	}

	return true;
}


bool CPolypoint::GetTransformed(
		const ITransformation2d& /*transformation*/,
		IObject2d& /*result*/,
		ITransformation2d::ExactnessMode /*mode*/,
		double* /*errorFactorPtr*/) const
{
	return false;
}


bool CPolypoint::GetInvTransformed(
		const ITransformation2d& /*transformation*/,
		IObject2d& /*result*/,
		ITransformation2d::ExactnessMode /*mode*/,
		double* /*errorFactorPtr*/) const
{
	return false;
}


// reimplemented (istd::IChangeable)

int CPolypoint::GetSupportedOperations() const
{
	return SO_COPY | SO_CLONE;
}


bool CPolypoint::CopyFrom(const IChangeable& object, CompatibilityMode mode)
{
	const CPolypoint* polypointPtr = dynamic_cast<const CPolypoint*>(&object);

	if (polypointPtr != NULL){

		istd::CChangeNotifier notifier(this);

		int sourcePolypointCount = polypointPtr->GetPointsCount();
		for (int pointIndex = 0; pointIndex < sourcePolypointCount; pointIndex++){		
			Insert(polypointPtr->GetPoint(pointIndex));
		}

		CObject2dBase::CopyFrom(object, mode);

		return true;
	}	

	return false;
}


istd::IChangeable* CPolypoint::CloneMe(CompatibilityMode mode) const 
{
	istd::TDelPtr<CPolypoint> clonePtr(new CPolypoint);

	if (clonePtr->CopyFrom(*this, mode)){
		return clonePtr.PopPtr();
	}

	return NULL;
}


// reimplemented (iser::ISerializable)

bool CPolypoint::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag polypointTag("Polypoint", "Polypoint");
	static iser::CArchiveTag vectorTag("V", "Vector");

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this, CF_OBJECT_POSITION | CF_MODEL);

	int pointsCount = m_points.size();
	bool retVal = true;

	retVal = retVal && archive.BeginMultiTag(polypointTag, vectorTag, pointsCount);

	if (!archive.IsStoring() && retVal){
		m_points.resize(pointsCount);
	}

	for (int nodeIndex = 0; nodeIndex < pointsCount; ++nodeIndex){
		retVal = retVal && archive.BeginTag(vectorTag);
		retVal = retVal && m_points[nodeIndex].Serialize(archive);
		retVal = retVal && archive.EndTag(vectorTag);
	}

	retVal = retVal && archive.EndTag(polypointTag);

	return retVal;
}


} // namespace i2d

