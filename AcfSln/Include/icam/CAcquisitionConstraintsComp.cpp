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


#include "icam/CAcquisitionConstraintsComp.h"


// IACF includes
#include "isig/ITriggerParams.h"


namespace icam
{


// public methods

// reimplemented (icam::IExposureConstraints)
	
bool CAcquisitionConstraintsComp::IsTriggerModeSupported(int triggerMode) const
{
	if (triggerMode == isig::ITriggerParams::TM_NONE && *m_isNoAcquisitionSupportedAttrPtr){
		return true;
	}

	if (triggerMode == isig::ITriggerParams::TM_CONTINUOUS && *m_isContinuousAcqSupportedAttrPtr){
		return true;
	}

	if (triggerMode == isig::ITriggerParams::TM_RISING_EDGE && *m_isRisingEdgeTriggerSupportedAttrPtr){
		return true;
	}

	if (triggerMode == isig::ITriggerParams::TM_FALLING_EDGE && *m_isFallingEdgeTriggerSupportedAttrPtr){
		return true;
	}

	if (triggerMode == isig::ITriggerParams::TM_NEGATIVE_LEVEL && *m_isNegativeLevelTriggerSupportedAttrPtr){
		return true;
	}

	if (triggerMode == isig::ITriggerParams::TM_POSITIVE_LEVEL && *m_isPositiveLevelTriggerSupportedAttrPtr){
		return true;
	}

	return false;
}


// reimplemented (icam::IExposureConstraints)

istd::CRange CAcquisitionConstraintsComp::GetShutterTimeRange() const
{
	I_ASSERT(m_minShutterTimeAttrPtr.IsValid());
	I_ASSERT(m_maxShutterTimeAttrPtr.IsValid());

	return istd::CRange(*m_minShutterTimeAttrPtr, *m_maxShutterTimeAttrPtr);
}


istd::CRange CAcquisitionConstraintsComp::GetDelayTimeRange() const
{
	I_ASSERT(m_minDelayTimeAttrPtr.IsValid());
	I_ASSERT(m_maxDelayTimeAttrPtr.IsValid());

	return istd::CRange(*m_minDelayTimeAttrPtr, *m_maxDelayTimeAttrPtr);
}


istd::CRange CAcquisitionConstraintsComp::GetEenDelayRange() const
{
	I_ASSERT(m_minEenDelayAttrPtr.IsValid());
	I_ASSERT(m_maxEenDelayAttrPtr.IsValid());

	return istd::CRange(*m_minEenDelayAttrPtr, *m_maxEenDelayAttrPtr);
}


} // namespace icam


