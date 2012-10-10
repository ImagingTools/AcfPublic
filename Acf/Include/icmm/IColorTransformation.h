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


#ifndef icmm_IColorTransformation_included
#define icmm_IColorTransformation_included


#include "imath/TIMathFunction.h"

#include "icmm/CVarColor.h"


namespace icmm
{


/**
	Basic interface for a color transformation.
*/
class IColorTransformation: virtual public imath::TIMathFunction<icmm::CVarColor, icmm::CVarColor>
{
};


} // namespace icmm


#endif // !icmm_IColorTransformation_included


