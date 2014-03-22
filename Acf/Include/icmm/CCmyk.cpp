/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "icmm/CCmyk.h"


#include "iser/CArchiveTag.h"


namespace icmm
{


// public methods

bool CCmyk::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag cyanTag("Cyan", "Cyan component");
	retVal = retVal && archive.BeginTag(cyanTag);
	retVal = retVal && archive.Process(GetElementRef(CI_CYAN));
	retVal = retVal && archive.EndTag(cyanTag);

	static iser::CArchiveTag magentaTag("Magenta", "Magenta component");
	retVal = retVal && archive.BeginTag(magentaTag);
	retVal = retVal && archive.Process(GetElementRef(CI_MAGENTA));
	retVal = retVal && archive.EndTag(magentaTag);

	static iser::CArchiveTag yellowTag("Yellow", "Yellow component");
	retVal = retVal && archive.BeginTag(yellowTag);
	retVal = retVal && archive.Process(GetElementRef(CI_YELLOW));
	retVal = retVal && archive.EndTag(yellowTag);

	static iser::CArchiveTag blackTag("Black", "Black component");
	retVal = retVal && archive.BeginTag(blackTag);
	retVal = retVal && archive.Process(GetElementRef(CI_BLACK));
	retVal = retVal && archive.EndTag(blackTag);

	return retVal;
}


} // namespace icmm


