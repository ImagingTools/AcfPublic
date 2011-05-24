/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icmm/CHsv.h"


#include "iser/CArchiveTag.h"


namespace icmm
{


// public methods

bool CHsv::Serialize(iser::IArchive& archive)
{
	bool retVal = true;

	static iser::CArchiveTag hueTag("Hue", "Hue component");
	retVal = retVal && archive.BeginTag(hueTag);
	retVal = retVal && archive.Process(GetElementRef(CI_HUE));
	retVal = retVal && archive.EndTag(hueTag);

	static iser::CArchiveTag saturationTag("Saturation", "Saturation component");
	retVal = retVal && archive.BeginTag(saturationTag);
	retVal = retVal && archive.Process(GetElementRef(CI_SATURATION));
	retVal = retVal && archive.EndTag(saturationTag);

	static iser::CArchiveTag valueTag("Value", "Value component");
	retVal = retVal && archive.BeginTag(valueTag);
	retVal = retVal && archive.Process(GetElementRef(CI_VALUE));
	retVal = retVal && archive.EndTag(valueTag);

	return retVal;
}


} // namespace icmm


