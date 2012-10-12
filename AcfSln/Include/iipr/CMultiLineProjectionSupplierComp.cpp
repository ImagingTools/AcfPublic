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


#include "iipr/CMultiLineProjectionSupplierComp.h"


namespace iipr
{


// reimplemented (iproc::TSupplierCompWrap)

int CMultiLineProjectionSupplierComp::ProduceObject(ProductType& result) const
{
	if (		m_bitmapProviderCompPtr.IsValid() &&
				m_linesProviderCompPtr.IsValid()){
		const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();
		int projectionCount = m_linesProviderCompPtr->GetValuesCount();

		if (bitmapPtr != NULL && projectionCount > 0){
			result.resize(projectionCount);

			for (int i = 0; i < projectionCount; i++){
				imeas::CGeneralDataSequence& lineResult = result[i];

				imath::CVarVector varVector = m_linesProviderCompPtr->GetNumericValue(i).GetComponentValue(imeas::INumericValue::VTI_2D_LINE);
				if (varVector.GetElementsCount() < 4){
					return WS_ERROR;
				}

				i2d::CLine2d line(
					varVector.GetElement(0), 
					varVector.GetElement(1), 
					varVector.GetElement(2), 
					varVector.GetElement(3));

				bool isOk = m_projectionProcessorCompPtr->DoProjection(*bitmapPtr, line, NULL, lineResult);
				if (!isOk){
					return WS_ERROR;
				}
			}

			return WS_OK;
		}

		return WS_ERROR;
	}

	SendCriticalMessage(0, "Bad component archtecture. Bitmap provider or lines provider were not set");
	
	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CMultiLineProjectionSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr());
	}

	if (m_linesProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_linesProviderModelCompPtr.GetPtr());
	}
}


// reimplemented (imeas::IMultiDataSequenceProvider)

int CMultiLineProjectionSupplierComp::GetSequencesCount() const
{
	const ProductType* resultPtr = GetWorkProduct();
	if (resultPtr != NULL){
		return resultPtr->count();
	}

	return 0;
}


const imeas::IDataSequence* CMultiLineProjectionSupplierComp::GetDataSequence(int index) const
{
	const ProductType* resultPtr = GetWorkProduct();
	if (resultPtr != NULL){
		if (index >= 0 && index < resultPtr->count()){
			return &resultPtr->at(index);
		}
	}

	return NULL;
}


} // namespace iipr


