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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iipr/CCaliperParams.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


#include "istd/TChangeNotifier.h"


namespace iipr
{


CCaliperParams::CCaliperParams()
:	m_weightThreshold(0.1),
	m_polarityMode(PM_ALL),
	m_directionMode(DM_FORWARD)
{
}


// reimplemented (iipr::ICaliperParams)

double CCaliperParams::GetWeightThreshold() const
{
	return m_weightThreshold;
}


void CCaliperParams::SetWeightThreshold(double threshold)
{
	if (threshold != m_weightThreshold){
		istd::CChangeNotifier notifier(this);

		m_weightThreshold = threshold;
	}
}


int CCaliperParams::GetPolarityMode() const
{
	return m_polarityMode;
}


void CCaliperParams::SetPolarityMode(int mode)
{
	if (mode != m_polarityMode){
		istd::CChangeNotifier notifier(this);

		m_polarityMode = mode;
	}
}


int CCaliperParams::GetDirectionMode() const
{
	return m_directionMode;
}


void CCaliperParams::SetDirectionMode(int mode)
{
	if (mode != m_directionMode){
		istd::CChangeNotifier notifier(this);

		m_directionMode = mode;
	}
}


// reimplemented (iser::ISerializable)

bool CCaliperParams::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag weightThresholdTag("WeightThreshold", "Threshold describing of minimal weight acceptace");
	retVal = retVal && archive.BeginTag(weightThresholdTag);
	retVal = retVal && archive.Process(m_weightThreshold);
	retVal = retVal && archive.EndTag(weightThresholdTag);

	static iser::CArchiveTag polarityModeTag("PolarityMode", "Polarity mode code");
	retVal = retVal && archive.BeginTag(polarityModeTag);
	retVal = retVal && archive.Process(m_polarityMode);
	retVal = retVal && archive.EndTag(polarityModeTag);

	static iser::CArchiveTag directionModeTag("DirectionMode", "Direction mode code");
	retVal = retVal && archive.BeginTag(directionModeTag);
	retVal = retVal && archive.Process(m_directionMode);
	retVal = retVal && archive.EndTag(directionModeTag);

	return retVal;
}


} // namespace iipr

