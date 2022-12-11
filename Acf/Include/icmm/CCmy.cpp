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


#include <icmm/CCmy.h>


// ACF includes
#include <iser/CArchiveTag.h>


namespace icmm
{


// static constants
static const iser::CArchiveTag s_cyanTag("Cyan", "Cyan component", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_magentaTag("Magenta", "Magenta component", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_yellowTag("Yellow", "Yellow component", iser::CArchiveTag::TT_LEAF);


// public methods

bool CCmy::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && archive.BeginTag(s_cyanTag);
	retVal = retVal && archive.Process(GetElementRef(CI_CYAN));
	retVal = retVal && archive.EndTag(s_cyanTag);

	retVal = retVal && archive.BeginTag(s_magentaTag);
	retVal = retVal && archive.Process(GetElementRef(CI_MAGENTA));
	retVal = retVal && archive.EndTag(s_magentaTag);

	retVal = retVal && archive.BeginTag(s_yellowTag);
	retVal = retVal && archive.Process(GetElementRef(CI_YELLOW));
	retVal = retVal && archive.EndTag(s_yellowTag);

	return retVal;
}


} // namespace icmm


