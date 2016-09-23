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


#include <icmm/CLab.h>


#include <iser/CArchiveTag.h>


namespace icmm
{


// static constants
static const iser::CArchiveTag s_lTag("L", "L component of Lab", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_aTag("A", "A component of Lab", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_bTag("B", "B component of Lab", iser::CArchiveTag::TT_LEAF);


// public methods

bool CLab::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && archive.BeginTag(s_lTag);
	retVal = retVal && archive.Process(GetElementRef(CI_L));
	retVal = retVal && archive.EndTag(s_lTag);

	retVal = retVal && archive.BeginTag(s_aTag);
	retVal = retVal && archive.Process(GetElementRef(CI_A));
	retVal = retVal && archive.EndTag(s_aTag);

	retVal = retVal && archive.BeginTag(s_bTag);
	retVal = retVal && archive.Process(GetElementRef(CI_B));
	retVal = retVal && archive.EndTag(s_bTag);

	return retVal;
}


double CLab::GetDeltaE(const CLab& lab) const
{
	return GetDistance(lab);
}


} // namespace icmm


