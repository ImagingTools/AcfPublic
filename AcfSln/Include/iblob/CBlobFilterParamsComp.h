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


#pragma once


// ACF includes
#include <icomp/CComponentBase.h>

// ACF-Solutions includes
#include <iblob/CBlobFilterParams.h>


namespace iblob
{


class CBlobFilterParamsComp:
			public icomp::CComponentBase,
			public CBlobFilterParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CBlobFilterParamsComp);
		I_REGISTER_INTERFACE(iblob::IBlobFilterParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN(m_supportedPropertiesCompPtr, "SupportedProperties", "Provides list of features supported for filtering", true, "SupportedProperties");
		I_ASSIGN(m_calibrationCompPtr, "Calibration", "Calibration associated with this object", false, "Calibration");
		I_ASSIGN_MULTI_0(m_defaultAvailablePropertiesAttrPtr, "DefaultProperties", "Default available properties", false);
	I_END_COMPONENT;

	// reimplemented (i2d::ICalibrationProvider)
	virtual const i2d::ICalibration2d* GetCalibration() const;

protected:
	// reimplemented (icomp::CComponentBase)
	void OnComponentCreated();

private:
	I_REF(iprm::IOptionsList, m_supportedPropertiesCompPtr);
	I_REF(i2d::ICalibration2d, m_calibrationCompPtr);
	I_MULTIATTR(QByteArray, m_defaultAvailablePropertiesAttrPtr);
};


} // namespace iblob


