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


#include <icam/CCameraSnapSupplierCompBase.h>
#include <icam/CCameraCommand.h>



namespace icam
{


// protected methods


// reimplemented (CSnapBitmapSupplierCompBase)

int CCameraSnapSupplierCompBase::DoSnap(const iprm::IParamsSet* snapParamsPtr, iimg::IBitmap& snapBitmap) const
{
	if (!m_bitmapAcquisitionCompPtr.IsValid()){
		SendCriticalMessage(0, "Bad component architecture, 'BitmapAcquisition' component reference is not set");

		return iproc::IProcessor::TS_INVALID;
	}

	icam::CCameraCommand getLastImage(icam::ICameraCommand::CI_READ_LAST_IN_BUFFER);
	return m_bitmapAcquisitionCompPtr->DoProcessing(snapParamsPtr, &getLastImage, &snapBitmap);
}


// reimplemented (iinsp::TSupplierCompWrap)

bool CCameraSnapSupplierCompBase::InitializeWork()
{
	if (m_bitmapAcquisitionCompPtr.IsValid()){
		m_bitmapAcquisitionCompPtr->InitProcessor(GetModelParametersSet());

		return true;
	}

	return false;
}


// reimplemented (icomp::CComponentBase)

void CCameraSnapSupplierCompBase::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	// initialize components
	m_bitmapAcquisitionCompPtr.EnsureInitialized();
}


} // namespace icam


