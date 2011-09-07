/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#include "iipr/CDelegatedBitmapSupplierComp.h"


namespace iipr
{


// reimplemented (iipr::IBitmapSupplier)

const iimg::IBitmap* CDelegatedBitmapSupplierComp::GetBitmap() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->second;
	}

	return NULL;
}


const i2d::ITransformation2d* CDelegatedBitmapSupplierComp::GetLogTransform() const
{
	const ProductType* productPtr = GetWorkProduct();
	if (productPtr != NULL){
		return productPtr->first;
	}
	else{
		return NULL;
	}
}


//protected methods

// reimplemented (iproc::TSupplierCompWrap)

int CDelegatedBitmapSupplierComp::ProduceObject(ProductType& result) const
{
	if (m_inputBitmapSupplierCompPtr.IsValid()){
		result.first = m_inputBitmapSupplierCompPtr->GetLogTransform();
		result.second = m_inputBitmapSupplierCompPtr->GetBitmap();

		return m_inputBitmapSupplierCompPtr->GetWorkStatus();
	}

	if (m_bitmapCompPtr.IsValid()){
		result.first = m_calibrationCompPtr.GetPtr();
		result.second = m_bitmapCompPtr.GetPtr();

		return ISupplier::WS_OK;
	}

	return ISupplier::WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CDelegatedBitmapSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_inputBitmapSupplierCompPtr.IsValid()){
		AddInputSupplier(m_inputBitmapSupplierCompPtr.GetPtr());
	}
	else{
		if (m_bitmapModelCompPtr.IsValid()){
			m_bitmapModelCompPtr->AttachObserver(this);
		}
		if (m_calibrationModelCompPtr.IsValid()){
			m_calibrationModelCompPtr->AttachObserver(this);
		}
	}
}


void CDelegatedBitmapSupplierComp::OnComponentDestroyed()
{
	if (m_inputBitmapSupplierCompPtr.IsValid()){
		RemoveInputSupplier(m_inputBitmapSupplierCompPtr.GetPtr());
	}
	else{
		EnsureModelsDetached();
	}

	BaseClass::OnComponentDestroyed();
}


// reimplemented (imod::CSingleModelObserverBase)

void CDelegatedBitmapSupplierComp::OnUpdate(imod::IModel* /*modelPtr*/, int /*updateFlags*/, istd::IPolymorphic* /*updateParamsPtr*/)
{
	InvalidateSupplier();
}


} // namespace iipr


