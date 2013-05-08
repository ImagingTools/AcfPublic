/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icmm/CLab.h"


#include "iser/CArchiveTag.h"


namespace icmm
{


// public methods

bool CLab::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag lTag("L", "L component of Lab");
	retVal = retVal && archive.BeginTag(lTag);
	retVal = retVal && archive.Process(GetElementRef(CI_L));
	retVal = retVal && archive.EndTag(lTag);

	static iser::CArchiveTag aTag("A", "A component of Lab");
	retVal = retVal && archive.BeginTag(aTag);
	retVal = retVal && archive.Process(GetElementRef(CI_A));
	retVal = retVal && archive.EndTag(aTag);

	static iser::CArchiveTag bTag("B", "B component of Lab");
	retVal = retVal && archive.BeginTag(bTag);
	retVal = retVal && archive.Process(GetElementRef(CI_B));
	retVal = retVal && archive.EndTag(bTag);

	return retVal;
}


} // namespace icmm


