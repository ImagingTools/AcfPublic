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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iview/CNoneCalibration.h"


namespace iview
{


// public methods

// reimplemented (iview::ICalibration)

CNoneCalibration::CalcStatus CNoneCalibration::GetLogLength(const i2d::CLine2d& line, double& result) const
{
	result = line.GetLength();
	
	return CS_OK;
}



CNoneCalibration::CalcStatus CNoneCalibration::GetLogDeform(const i2d::CVector2d& /*logPosition*/, i2d::CMatrix2d& result) const
{
	result = i2d::CMatrix2d::GetIdentity();
	
	return CS_OK;
}



CNoneCalibration::CalcStatus CNoneCalibration::GetViewDeform(const i2d::CVector2d& /*viewPosition*/, i2d::CMatrix2d& result) const
{
	result = i2d::CMatrix2d::GetIdentity();
	
	return CS_OK;
}



// reimplemented (iview::IIsomorphicCalibration)

CNoneCalibration::CalcStatus CNoneCalibration::GetApplyToLog(const i2d::CVector2d& viewPosition, i2d::CVector2d& result) const
{
	result = viewPosition;
	
	return CS_OK;
}



CNoneCalibration::CalcStatus CNoneCalibration::GetApplyToView(const i2d::CVector2d& logPosition, i2d::CVector2d& result) const
{
	result = logPosition;

	return CS_OK;
}



// reimplemented (iser::ISerializable)

bool CNoneCalibration::Serialize(iser::IArchive& /*archive*/)
{
	return true;
}



// static methods

const CNoneCalibration& CNoneCalibration::GetInstance()
{
	return s_defaultInstance;
}


// static attributes

CNoneCalibration CNoneCalibration::s_defaultInstance;


} // namespace iview



