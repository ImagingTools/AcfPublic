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


#include <i2d/CVector2d.h>


// ACF includes
#include <iser/IArchive.h>
#include <iser/IVersionInfo.h>
#include <iser/CArchiveTag.h>


namespace i2d
{


// static constants
static const iser::CArchiveTag s_posXTag("X", "X coordinate", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_posYTag("Y", "Y coordinate", iser::CArchiveTag::TT_LEAF);


void CVector2d::Init(double angle, double length)
{
	SetX(qCos(angle) * length);
	SetY(qSin(angle) * length);
}


CVector2d CVector2d::GetOrthogonal() const
{
	return CVector2d(GetY(), -GetX());
}


istd::CIndex2d CVector2d::ToIndex2d() const
{
	return istd::CIndex2d(int(GetX()), int(GetY()));
}


CVector2d CVector2d::GetNormalized(double length) const
{
	CVector2d retVal;

	if (GetNormalized(retVal, length)){
		return retVal;
	}

	return CVector2d(length, 0.0);
}


bool CVector2d::Serialize(iser::IArchive& archive)
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

	return retVal;
}


} // namespace i2d


