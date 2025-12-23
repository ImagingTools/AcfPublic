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


#include <i3d/CBox3d.h>


// ACF includes
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace i3d
{


// static constants
static const iser::CArchiveTag s_minTag("Min", "Minimum corner", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_maxTag("Max", "Maximum corner", iser::CArchiveTag::TT_LEAF);


CVector3d CBox3d::GetClosestPoint(const CVector3d& point) const
{
	if (IsEmpty()){
		return point;
	}
	
	// Clamp point to box bounds
	CVector3d result;
	result.SetX(qMax(m_min.GetX(), qMin(point.GetX(), m_max.GetX())));
	result.SetY(qMax(m_min.GetY(), qMin(point.GetY(), m_max.GetY())));
	result.SetZ(qMax(m_min.GetZ(), qMin(point.GetZ(), m_max.GetZ())));
	
	return result;
}


bool CBox3d::Serialize(iser::IArchive& archive)
{
	bool retVal = true;
	
	retVal = retVal && archive.BeginTag(s_minTag);
	retVal = retVal && m_min.Serialize(archive);
	retVal = retVal && archive.EndTag(s_minTag);
	
	retVal = retVal && archive.BeginTag(s_maxTag);
	retVal = retVal && m_max.Serialize(archive);
	retVal = retVal && archive.EndTag(s_maxTag);
	
	return retVal;
}


} // namespace i3d
