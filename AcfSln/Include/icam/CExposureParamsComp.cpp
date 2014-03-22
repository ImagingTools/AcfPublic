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


#include "icam/CExposureParamsComp.h"


#include "istd/TChangeNotifier.h"
#include "istd/TRange.h"

#include "iser/CArchiveTag.h"


namespace icam
{


CExposureParamsComp::CExposureParamsComp()
:	m_shutterTime(0.001), m_delayTime(0), m_eenDelayTime(0)
{
}


// reimplemented (icam::IExposureParams)

const IExposureConstraints* CExposureParamsComp::GetExposureConstraints() const
{
	return m_exposureConstraintsCompPtr.GetPtr();
}


double CExposureParamsComp::GetShutterTime() const
{
	return m_shutterTime;
}


bool CExposureParamsComp::SetShutterTime(double time)
{
	if (m_exposureConstraintsCompPtr.IsValid()){
		istd::CRange range = m_exposureConstraintsCompPtr->GetShutterTimeRange();

		if (!range.Contains(time)){
			return false;
		}
	}

	if (time != m_shutterTime){
		istd::CChangeNotifier notifier(this);

		m_shutterTime = time;
	}

	return true;
}


double CExposureParamsComp::GetDelayTime() const
{
	return m_delayTime;
}


bool CExposureParamsComp::SetDelayTime(double time)
{
	if (m_exposureConstraintsCompPtr.IsValid()){
		istd::CRange range = m_exposureConstraintsCompPtr->GetDelayTimeRange();

		if (!range.Contains(time)){
			return false;
		}
	}

	if (time != m_delayTime){
		istd::CChangeNotifier notifier(this);

		m_delayTime = time;
	}
	
	return true;
}


double CExposureParamsComp::GetEenDelay() const
{
	return m_eenDelayTime;
}


bool CExposureParamsComp::SetEenDelay(double time)
{
	if (m_exposureConstraintsCompPtr.IsValid()){
		istd::CRange range = m_exposureConstraintsCompPtr->GetEenDelayRange();
		if (!range.Contains(time)){
			return false;
		}
	}

	if (time != m_eenDelayTime){
		istd::CChangeNotifier notifier(this);

		m_eenDelayTime = time;
	}

	return true;
}


// reimplemented (iser::ISerializable)

bool CExposureParamsComp::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag shutterTimeTag("ShutterTime", "Shutter time in seconds");
	static iser::CArchiveTag delayTimeTag("DelayTime", "Delay of shutter in seconds");
	static iser::CArchiveTag eenDelayTimeTag("EenDelayTime", "Delay of exposure enabled signal in seconds");

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(shutterTimeTag);
	retVal = retVal && archive.Process(m_shutterTime);
	retVal = retVal && archive.EndTag(shutterTimeTag);

	retVal = retVal && archive.BeginTag(delayTimeTag);
	retVal = retVal && archive.Process(m_delayTime);
	retVal = retVal && archive.EndTag(delayTimeTag);

	retVal = retVal && archive.BeginTag(eenDelayTimeTag);
	retVal = retVal && archive.Process(m_eenDelayTime);
	retVal = retVal && archive.EndTag(eenDelayTimeTag);

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CExposureParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	Q_ASSERT(m_defaultShutterTimeAttrPtr.IsValid());	// isObligatory is set
	m_shutterTime = *m_defaultShutterTimeAttrPtr;
}


} // namespace icam


