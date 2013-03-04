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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iedge/CEdgeLineContainer.h"


namespace iedge
{


// reimplemented (i2d::IObject2d)

i2d::CVector2d CEdgeLineContainer::GetCenter() const
{
	return GetBoundingBox().GetCenter();
}


void CEdgeLineContainer::MoveCenterTo(const i2d::CVector2d& position)
{
	i2d::CVector2d diffVector = position - GetCenter();

	int contoursCount = BaseClass2::GetItemsCount();
	for (int i = 0; i < contoursCount; ++i){
		CEdgeLine& edgeLine = GetAt(i);

		edgeLine.MoveCenterTo(edgeLine.GetCenter() + diffVector);
	}
}


i2d::CRectangle CEdgeLineContainer::GetBoundingBox() const
{
	i2d::CRectangle retVal = i2d::CRectangle::GetEmpty();

	int contoursCount = BaseClass2::GetItemsCount();
	for (int i = 0; i < contoursCount; ++i){
		const CEdgeLine& edgeLine = GetAt(i);

		retVal.Unite(edgeLine.GetBoundingBox());
	}

	return retVal;
}


bool CEdgeLineContainer::Transform(
			const i2d::ITransformation2d& transformation,
			i2d::ITransformation2d::ExactnessMode mode,
			double* errorFactorPtr)
{
	bool retVal = true;

	double errorFactorSum = 0;

	int linesCount = BaseClass2::GetItemsCount();
	for (int lineIndex = 0; lineIndex < linesCount; ++lineIndex){
		CEdgeLine& edgeLine = BaseClass2::GetAt(lineIndex);

		if (errorFactorPtr != NULL){
			double factor;

			retVal = edgeLine.Transform(transformation, mode, &factor) && retVal;

			errorFactorSum += factor;
		}
		else{
			retVal = edgeLine.Transform(transformation, mode) && retVal;
		}
	}

	if (errorFactorPtr != NULL){
		*errorFactorPtr = errorFactorSum / linesCount;
	}

	return retVal;
}


bool CEdgeLineContainer::InvTransform(
			const i2d::ITransformation2d& transformation,
			i2d::ITransformation2d::ExactnessMode mode,
			double* errorFactorPtr)
{
	bool retVal = true;

	double errorFactorSum = 0;

	int linesCount = BaseClass2::GetItemsCount();
	for (int lineIndex = 0; lineIndex < linesCount; ++lineIndex){
		CEdgeLine& edgeLine = BaseClass2::GetAt(lineIndex);

		if (errorFactorPtr != NULL){
			double factor;

			retVal = edgeLine.InvTransform(transformation, mode, &factor) && retVal;

			errorFactorSum += factor;
		}
		else{
			retVal = edgeLine.InvTransform(transformation, mode) && retVal;
		}
	}

	if (errorFactorPtr != NULL){
		*errorFactorPtr = errorFactorSum / linesCount;
	}

	return retVal;
}


bool CEdgeLineContainer::GetTransformed(
			const i2d::ITransformation2d& transformation,
			i2d::IObject2d& result,
			i2d::ITransformation2d::ExactnessMode mode,
			double* errorFactorPtr) const
{
	CEdgeLineContainer* resultContainerPtr = dynamic_cast<CEdgeLineContainer*>(&result);
	if (resultContainerPtr != NULL){
		*resultContainerPtr = *this;

		return result.Transform(transformation, mode, errorFactorPtr);
	}
	else{
		return false;
	}
}


bool CEdgeLineContainer::GetInvTransformed(
			const i2d::ITransformation2d& transformation,
			i2d::IObject2d& result,
			i2d::ITransformation2d::ExactnessMode mode,
			double* errorFactorPtr) const
{
	CEdgeLineContainer* resultContainerPtr = dynamic_cast<CEdgeLineContainer*>(&result);
	if (resultContainerPtr != NULL){
		*resultContainerPtr = *this;

		return result.InvTransform(transformation, mode, errorFactorPtr);
	}
	else{
		return false;
	}
}


// protected methods

// reimplemented (ibase::TSerializableContainer)

bool CEdgeLineContainer::SerializeItem(CEdgeLine& item, iser::IArchive& archive)
{
	return item.Serialize(archive);
}


} // namespace iedge


