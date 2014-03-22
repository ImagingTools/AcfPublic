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


#include "icmm/CRgbToXyzTransformation.h"


// Qt includes
#include <QtCore/qmath.h>

// ACF includes
#include "icmm/CRgb.h"


namespace icmm
{


// public methods

// reimplemented (icmm::IColorTransformation)

bool CRgbToXyzTransformation::GetValueAt(const icmm::CVarColor& argument, icmm::CVarColor& result) const
{
	if (argument.GetElementsCount() != icmm::CRgb::GetElementsCount()){
		return false;
	}

	if (result.GetElementsCount() != 3){
		return false;
	}

	double r = argument[icmm::CRgb::CI_RED];
	double g = argument[icmm::CRgb::CI_GREEN];
	double b = argument[icmm::CRgb::CI_BLUE];

	if (r > 0.04045){
		r = pow((r + 0.055) / 1.055, 2.4);
	}
	else{
		r /= 12.92;
	}
		
	if (g > 0.04045){
		g = pow((g + 0.055) / 1.055, 2.4);
	}
	else{
		g /= 12.92;
	}
	
	if (b > 0.04045){
		b = pow((b + 0.055) / 1.055, 2.4);
	}
	else{
		b /= 12.92;
	}

	double X = r * 0.4124 + g * 0.3576 + b * 0.1805;
	double Y = r * 0.2126 + g * 0.7152 + b * 0.0722;
	double Z = r * 0.0193 + g * 0.1192 + b * 0.9505;

	result[0] = X;
	result[1] = Y;
	result[2] = Z;

	return true;
}


icmm::CVarColor CRgbToXyzTransformation::GetValueAt(const icmm::CVarColor& argument) const
{
	icmm::CVarColor result(3);

	GetValueAt(argument, result);

	return result;
}


} // namespace iccm


