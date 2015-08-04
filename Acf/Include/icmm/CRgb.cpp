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


#include "icmm/CRgb.h"


#include "iser/CArchiveTag.h"


namespace icmm
{


// public methods

bool CRgb::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag cyanTag("Red", "Red component", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag magentaTag("Green", "Green component", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag yellowTag("Blue", "Blue component", iser::CArchiveTag::TT_LEAF);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(cyanTag);
	retVal = retVal && archive.Process(GetElementRef(CI_RED));
	retVal = retVal && archive.EndTag(cyanTag);

	retVal = retVal && archive.BeginTag(magentaTag);
	retVal = retVal && archive.Process(GetElementRef(CI_GREEN));
	retVal = retVal && archive.EndTag(magentaTag);

	retVal = retVal && archive.BeginTag(yellowTag);
	retVal = retVal && archive.Process(GetElementRef(CI_BLUE));
	retVal = retVal && archive.EndTag(yellowTag);

	return retVal;
}


} // namespace icmm


