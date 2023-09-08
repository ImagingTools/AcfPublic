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


#include <iblob/CBlobFilterParamsComp.h>


namespace iblob
{


// public methods

// reimplemented (i2d::ICalibrationProvider)

const i2d::ICalibration2d* CBlobFilterParamsComp::GetCalibration() const
{
	return m_calibrationCompPtr.GetPtr();
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CBlobFilterParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	SetSupportedProperties(m_supportedPropertiesCompPtr.GetPtr());
}


} // namespace iblob


