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


#include <i3d/CPlane3d.h>


// ACF includes
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


namespace i3d
{


// static constants
static const iser::CArchiveTag s_pointTag("Point", "Point on plane", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_normalTag("Normal", "Normal vector", iser::CArchiveTag::TT_LEAF);


CPlane3d::CPlane3d(const CVector3d& p1, const CVector3d& p2, const CVector3d& p3)
:	m_point(p1)
{
	// Calculate normal from cross product of two edge vectors
	CVector3d edge1 = p2 - p1;
	CVector3d edge2 = p3 - p1;
	m_normal = edge1.GetCrossProduct(edge2).GetNormalized();
}


bool CPlane3d::Serialize(iser::IArchive& archive)
{
	bool retVal = true;
	
	retVal = retVal && archive.BeginTag(s_pointTag);
	retVal = retVal && m_point.Serialize(archive);
	retVal = retVal && archive.EndTag(s_pointTag);
	
	retVal = retVal && archive.BeginTag(s_normalTag);
	retVal = retVal && m_normal.Serialize(archive);
	retVal = retVal && archive.EndTag(s_normalTag);
	
	return retVal;
}


} // namespace i3d
