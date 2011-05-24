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


#include "icmm/CColorTransformationProvider.h"


namespace icmm
{


// public static methods

icmm::IColorTransformation* CColorTransformationProvider::GetColorTransformation(int inputColorType, int outputColorType)
{
	if (inputColorType == HsvColor && outputColorType == RgbColor){
		return &s_hsvToRgbTransform;
	}

	if (inputColorType == RgbColor && outputColorType == CmykColor){
		return &s_rgbToCmykTransform;
	}

	if (inputColorType == CmykColor && outputColorType == RgbColor){
		return &s_cmykToRgbTransform;
	}

	return NULL;
}


// private static members

icmm::CHsvToRgbTransformation CColorTransformationProvider::s_hsvToRgbTransform;
icmm::CRgbToCmykTransformation CColorTransformationProvider::s_rgbToCmykTransform;
icmm::CCmykToRgbTransformation CColorTransformationProvider::s_cmykToRgbTransform;


} // namespace icmm
