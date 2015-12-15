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


#include "icmm/CHsv.h"


#include "iser/CArchiveTag.h"


namespace icmm
{


// static constants
static const iser::CArchiveTag s_hueTag("Hue", "Hue component", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_saturationTag("Saturation", "Saturation component", iser::CArchiveTag::TT_LEAF);
static const iser::CArchiveTag s_valueTag("Value", "Value component", iser::CArchiveTag::TT_LEAF);


// public methods

bool CHsv::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	retVal = retVal && archive.BeginTag(s_hueTag);
	retVal = retVal && archive.Process(GetElementRef(CI_HUE));
	retVal = retVal && archive.EndTag(s_hueTag);

	retVal = retVal && archive.BeginTag(s_saturationTag);
	retVal = retVal && archive.Process(GetElementRef(CI_SATURATION));
	retVal = retVal && archive.EndTag(s_saturationTag);

	retVal = retVal && archive.BeginTag(s_valueTag);
	retVal = retVal && archive.Process(GetElementRef(CI_VALUE));
	retVal = retVal && archive.EndTag(s_valueTag);

	return retVal;
}


} // namespace icmm


