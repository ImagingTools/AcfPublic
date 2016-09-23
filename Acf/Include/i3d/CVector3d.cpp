/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <i3d/CVector3d.h>


// ACF includes
#include <iser/IArchive.h>
#include <iser/IVersionInfo.h>
#include <iser/CArchiveTag.h>


namespace i3d
{


// static constants
static const iser::CArchiveTag s_posXTag("X", "X coordinate", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_posYTag("Y", "Y coordinate", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_posZTag("Z", "Z coordinate", iser::CArchiveTag::TT_LEAF);


CVector3d CVector3d::GetCrossProduct(const imath::TVector<3>& vector) const
{
	return CVector3d(
				GetY() * vector[2] - GetZ() * vector[1],
				GetZ() * vector[0] - GetX() * vector[2],
				GetX() * vector[1] - GetY() * vector[0]);
}


CVector3d CVector3d::GetNormalized(double length) const
{
	CVector3d retVal;

	if (GetNormalized(retVal, length)){
		return retVal;
	}

	return CVector3d(length, 0.0, 0.0);
}


bool CVector3d::Serialize(iser::IArchive& archive)
{
	const iser::IVersionInfo& versionInfo = archive.GetVersionInfo();	// TODO: Remove it when backward compatibility to older versions will not be no more important
	quint32 frameworkVersion = 0;
	if (versionInfo.GetVersionNumber(iser::IVersionInfo::AcfVersionId, frameworkVersion) && (frameworkVersion < 3974)){
		return BaseClass::Serialize(archive);
	}

	bool retVal = true;

	retVal = retVal && archive.BeginTag(s_posXTag);
	retVal = retVal && archive.Process(operator[](0));
	retVal = retVal && archive.EndTag(s_posXTag);

	retVal = retVal && archive.BeginTag(s_posYTag);
	retVal = retVal && archive.Process(operator[](1));
	retVal = retVal && archive.EndTag(s_posYTag);

	retVal = retVal && archive.BeginTag(s_posZTag);
	retVal = retVal && archive.Process(operator[](2));
	retVal = retVal && archive.EndTag(s_posZTag);

	return retVal;
}


} // namespace i3d


