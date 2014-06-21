/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iipr/CArcProjectionSupplierComp.h"


namespace iipr
{


// reimplemented (iinsp::TSupplierCompWrap)

int CArcProjectionSupplierComp::ProduceObject(ProductType& result) const
{
	if (		m_bitmapProviderCompPtr.IsValid() &&
				m_arcCompPtr.IsValid()){
		const iimg::IBitmap* bitmapPtr = m_bitmapProviderCompPtr->GetBitmap();

		bool isOk = m_projectionProcessorCompPtr->DoProjection(*bitmapPtr, *m_arcCompPtr, NULL, result);
		if (!isOk){
			return WS_ERROR;
		}

		return WS_OK;
	}

	SendCriticalMessage(0, "Bad component archtecture. Bitmap provider or arc were not set");
	
	return WS_CRITICAL;
}


// reimplemented (icomp::CComponentBase)

void CArcProjectionSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderModelCompPtr.IsValid()){
		RegisterSupplierInput(m_bitmapProviderModelCompPtr.GetPtr(), m_bitmapSupplierCompPtr.GetPtr());
	}

	if (m_arcModelCompPtr.IsValid()){
		RegisterSupplierInput(m_arcModelCompPtr.GetPtr());
	}
}


// reimplemented (imeas::IDataSequenceProvider)

const imeas::IDataSequence* CArcProjectionSupplierComp::GetDataSequence() const
{
	return GetWorkProduct();
}


} // namespace iipr


