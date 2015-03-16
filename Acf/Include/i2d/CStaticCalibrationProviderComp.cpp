/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "i2d/CStaticCalibrationProviderComp.h"


namespace i2d
{


CStaticCalibrationProviderComp::CStaticCalibrationProviderComp()
:	imod::CMultiModelBridgeBase(this)
{
}


// reimplemented (i2d::ICalibrationProvider)

const ICalibration2d* CStaticCalibrationProviderComp::GetCalibration() const
{
	if (m_calibrationCompPtr.IsValid()){
		return m_calibrationCompPtr.GetPtr();
	}

	return NULL;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CStaticCalibrationProviderComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_calibrationModelCompPtr.IsValid()){
		m_calibrationModelCompPtr->AttachObserver(this);
	}
}


void CStaticCalibrationProviderComp::OnComponentDestroyed()
{
	EnsureModelsDetached();

	BaseClass::OnComponentDestroyed();
}


} // namespace i2d


