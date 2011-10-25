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


#include "iipr/CCircleFinderParams.h"


#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


#include "istd/TChangeNotifier.h"


namespace iipr
{


CCircleFinderParams::CCircleFinderParams()
:	m_isOutlierEliminationEnabled(false),
	m_minOutlierDistance(5),
	m_raysCount(-1),
	m_caliperMode(CCM_FIRST)
{
}


// reimplemented (iipr::ICircleFinderParams)

int CCircleFinderParams::GetCaliperMode() const
{
	return m_caliperMode;
}


void CCircleFinderParams::SetCaliperMode(int caliperMode)
{
	if (caliperMode != m_caliperMode){
		istd::CChangeNotifier notifier(this);

		m_caliperMode = caliperMode;
	}
}


bool CCircleFinderParams::IsOutlierEliminationEnabled() const
{
	return m_isOutlierEliminationEnabled;
}


void CCircleFinderParams::SetOutlierEliminationEnabled(bool isOutlierEliminationEnabled)
{
	if (isOutlierEliminationEnabled != m_isOutlierEliminationEnabled){
		istd::CChangeNotifier notifier(this);

		m_isOutlierEliminationEnabled = isOutlierEliminationEnabled;
	}
}


double CCircleFinderParams::GetMinOutlierDistance() const
{
	return m_minOutlierDistance;
}


void CCircleFinderParams::SetMinOutlierDistance(double minOutlierDistance)
{
	if (minOutlierDistance != m_minOutlierDistance){
		istd::CChangeNotifier notifier(this);

		m_minOutlierDistance = minOutlierDistance;
	}
}


int CCircleFinderParams::GetRaysCount() const
{
	return m_raysCount;
}


void CCircleFinderParams::SetRaysCount(int raysCount)
{
	if (raysCount != m_raysCount){
		istd::CChangeNotifier notifier(this);

		m_raysCount = raysCount;
	}
}


// reimplemented (iser::ISerializable)

bool CCircleFinderParams::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag caliperModeTag("CaliperMode", "Caliper mode");
	retVal = retVal && archive.BeginTag(caliperModeTag);
	retVal = retVal && archive.Process(m_caliperMode);
	retVal = retVal && archive.EndTag(caliperModeTag);

	static iser::CArchiveTag isOutlierEliminationEnabledTag("OutlierEliminationEnabled", "Outliers elimination is enabled");
	retVal = retVal && archive.BeginTag(isOutlierEliminationEnabledTag);
	retVal = retVal && archive.Process(m_isOutlierEliminationEnabled);
	retVal = retVal && archive.EndTag(isOutlierEliminationEnabledTag);

	static iser::CArchiveTag minOutlierDistanceTag("MinOutlierDistance", "Minimal outliers distance");
	retVal = retVal && archive.BeginTag(minOutlierDistanceTag);
	retVal = retVal && archive.Process(m_minOutlierDistance);
	retVal = retVal && archive.EndTag(minOutlierDistanceTag);

	static iser::CArchiveTag raysCountTag("RaysCount", "Number of projection rays");
	retVal = retVal && archive.BeginTag(raysCountTag);
	retVal = retVal && archive.Process(m_raysCount);
	retVal = retVal && archive.EndTag(raysCountTag);

	return retVal;
}


} // namespace iipr

