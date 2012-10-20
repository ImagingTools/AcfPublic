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


#include "iipr/CBitmapJoinerSupplierComp.h"


#include <iipr/CBitmapOperations.h>


namespace iipr
{


// reimplemented (iipr::IBitmapProvider)

const iimg::IBitmap* CBitmapJoinerSupplierComp::GetBitmap() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->second.GetPtr();
	}

	return NULL;
}


// reimplemented (i2d::ICalibrationProvider)

const i2d::ITransformation2d* CBitmapJoinerSupplierComp::GetLogTransform() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->first;
	}
	else{
		return NULL;
	}
}

// reimplemented (iproc::TSupplierCompWrap)

int CBitmapJoinerSupplierComp::ProduceObject(ProductType& result) const
{
	if (!m_bitmapsProviderCompPtr.IsValid()){
		return WS_CRITICAL;
	}

	if (!EnsureBitmapCreated(result)){
		return WS_CRITICAL;
	}
	
	I_ASSERT(result.second.IsValid());

	result.first = NULL;

	int inputBitmapsCount = m_bitmapsProviderCompPtr->GetBitmapsCount();

	if (inputBitmapsCount <= 0){
		return WS_ERROR;
	}

	QVector<const iimg::IBitmap*> inputBitmaps;

	for (int inputBitmapIndex = 0; inputBitmapIndex < inputBitmapsCount; inputBitmapIndex++){
			const iimg::IBitmap* bitmapPtr = m_bitmapsProviderCompPtr->GetBitmap(inputBitmapIndex);
		if (bitmapPtr == NULL){
			SendErrorMessage(0, "Input image could not be provided");

			return WS_ERROR;
		}
	
		inputBitmaps.push_back(bitmapPtr);
	}

	CBitmapOperations::JoinMode joinMode = *m_useHorizontalJoinAttrPtr ? CBitmapOperations::JM_HORIZONTAL : CBitmapOperations::JM_VERTICAL;

	return CBitmapOperations::JoinBitmaps(
				inputBitmaps,
				joinMode,
				*result.second.GetPtr(),
				const_cast<CBitmapJoinerSupplierComp*>(this)) ? WS_OK : WS_ERROR;
}


bool CBitmapJoinerSupplierComp::EnsureBitmapCreated(ProductType& result) const
{
	if (!m_bitmapCompFact.IsValid()){
		return false;
	}

	if (!result.second.IsValid()){
		result.second.SetPtr(m_bitmapCompFact.CreateInstance());
	}

	return result.second.IsValid();
}


// reimplemented (icomp::CComponentBase)

void CBitmapJoinerSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapsProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapsProviderModelCompPtr.GetPtr(), m_bitmapsSupplierCompPtr.GetPtr());
	}

	if (m_calibrationModelCompPtr.IsValid()){
		RegisterSupplierInput(m_calibrationModelCompPtr.GetPtr(), m_calibrationSupplierCompPtr.GetPtr());
	}
}


} // namespace iipr


