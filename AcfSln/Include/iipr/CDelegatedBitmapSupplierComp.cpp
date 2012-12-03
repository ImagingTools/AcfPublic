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


#include "iipr/CDelegatedBitmapSupplierComp.h"


namespace iipr
{


// reimplemented (iipr::IBitmapProvider)

const iimg::IBitmap* CDelegatedBitmapSupplierComp::GetBitmap() const
{
	if (m_bitmapProviderCompPtr.IsValid()){
		return m_bitmapProviderCompPtr->GetBitmap();
	}

	if (m_bitmapCompPtr.IsValid()){
		return m_bitmapCompPtr.GetPtr();
	}

	return NULL;
}

	
// reimplemented (i2d::ICalibrationProvider)

const i2d::ICalibration2d* CDelegatedBitmapSupplierComp::GetCalibration() const
{
	if (m_calibrationProviderCompPtr.IsValid()){
		return m_calibrationProviderCompPtr->GetCalibration();
	}

	if (m_calibrationCompPtr.IsValid()){
		return m_calibrationCompPtr.GetPtr();
	}

	return NULL;
}


// reimplemented (iproc::ISupplier)

int CDelegatedBitmapSupplierComp::GetWorkStatus() const
{
	if (m_bitmapSupplierCompPtr.IsValid()){
		return m_bitmapSupplierCompPtr->GetWorkStatus();
	}

	if (m_bitmapCompPtr.IsValid()){
		return WS_OK;
	}

	return WS_CRITICAL;
}


void CDelegatedBitmapSupplierComp::InvalidateSupplier()
{
	if (m_bitmapSupplierCompPtr.IsValid()){
		m_bitmapSupplierCompPtr->InvalidateSupplier();
	}
}


void CDelegatedBitmapSupplierComp::EnsureWorkInitialized()
{
	if (m_bitmapSupplierCompPtr.IsValid()){
		m_bitmapSupplierCompPtr->EnsureWorkInitialized();
	}
}


void CDelegatedBitmapSupplierComp::EnsureWorkFinished()
{
	if (m_bitmapSupplierCompPtr.IsValid()){
		m_bitmapSupplierCompPtr->EnsureWorkFinished();
	}
}


void CDelegatedBitmapSupplierComp::ClearWorkResults()
{
	if (m_bitmapSupplierCompPtr.IsValid()){
		m_bitmapSupplierCompPtr->ClearWorkResults();
	}
}


const ibase::IMessageContainer* CDelegatedBitmapSupplierComp::GetWorkMessages() const
{
	if (m_bitmapSupplierCompPtr.IsValid()){
		return m_bitmapSupplierCompPtr->GetWorkMessages();
	}

	return NULL;
}


iprm::IParamsSet* CDelegatedBitmapSupplierComp::GetModelParametersSet() const
{
	if (m_bitmapSupplierCompPtr.IsValid()){
		return m_bitmapSupplierCompPtr->GetModelParametersSet();
	}

	return NULL;
}


// reimplemented (icomp::CComponentBase)

void CDelegatedBitmapSupplierComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_bitmapProviderCompPtr.IsValid()){
		if (m_bitmapProviderModelCompPtr.IsValid()){
			m_bitmapProviderModelCompPtr->AttachObserver(this);
		}
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
	BaseClass2::EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace iipr


