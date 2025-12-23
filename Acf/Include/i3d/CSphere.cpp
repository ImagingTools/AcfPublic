/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#include <i3d/CSphere.h>


// ACF includes
#include <i3d/CLine3d.h>
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace i3d
{


// static constants
static const iser::CArchiveTag s_centerTag("Center", "Center position", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_radiusTag("Radius", "Radius", iser::CArchiveTag::TT_LEAF);


bool CSphere::Intersects(const CLine3d& line) const
{
	// Get closest point on line to sphere center
	CVector3d closest = line.GetClosestPoint(m_center);
	double distSq = (closest - m_center).GetLength2();
	
	return distSq <= m_radius * m_radius;
}


bool CSphere::Serialize(iser::IArchive& archive)
{
	bool retVal = true;
	
	retVal = retVal && archive.BeginTag(s_centerTag);
	retVal = retVal && m_center.Serialize(archive);
	retVal = retVal && archive.EndTag(s_centerTag);
	
	retVal = retVal && archive.BeginTag(s_radiusTag);
	retVal = retVal && archive.Process(m_radius);
	retVal = retVal && archive.EndTag(s_radiusTag);
	
	return retVal;
}


} // namespace i3d
