/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#include "icmm/CRgbToHsvTranformation.h"


// Qt includes
#include <QtCore/qmath.h>

// ACF includes
#include "icmm/CHsv.h"
#include "icmm/CRgb.h"


namespace icmm
{


// public methods

// reimplemented (icmm::IColorTransformation)

bool CRgbToHsvTranformation::GetValueAt(const icmm::CVarColor& argument, icmm::CVarColor& result) const
{
	if (argument.GetElementsCount() != icmm::CRgb::GetElementsCount()){
		return false;
	}

	if (result.GetElementsCount() != icmm::CHsv::GetElementsCount()){
		return false;
	}

	double red = argument.GetElement(icmm::CRgb::CI_RED);
	double green = argument.GetElement(icmm::CRgb::CI_GREEN);
	double blue = argument.GetElement(icmm::CRgb::CI_BLUE);

	double hue = 0;
	double saturation = 0;
	double value = 0;

	double maxRgb = qMax(qMax(red, green), blue);
	double minRgb = qMin(qMin(red, green), blue);
	double delta = maxRgb - minRgb;

	if (fabs(delta) <= I_EPSILON){
		hue = 0;
		saturation = 0.0;
	}
	else{
		saturation = (delta) / maxRgb;

		if (qFuzzyCompare(maxRgb, red)){
			hue = (green - blue) / delta;
		}
		else if (qFuzzyCompare(maxRgb,green)){
			hue = (2 + (blue - red) / delta);
		}
		else if (qFuzzyCompare(maxRgb, blue)){
			hue = (4 + (red - green) / delta);
		}

		hue *= 60;
	}

	if (hue < 0){
		hue += 360.0;
	}

	value = maxRgb;

	result.SetElement(icmm::CHsv::CI_HUE, hue);
	result.SetElement(icmm::CHsv::CI_SATURATION, saturation);
	result.SetElement(icmm::CHsv::CI_VALUE, value);

	return true;
}


icmm::CVarColor CRgbToHsvTranformation::GetValueAt(const icmm::CVarColor& argument) const
{
	icmm::CVarColor result(3);

	GetValueAt(argument, result);

	return result;
}


} // namespace iccm


