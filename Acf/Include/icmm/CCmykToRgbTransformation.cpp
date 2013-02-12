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


#include "icmm/CCmykToRgbTransformation.h"
#include "icmm/CRgb.h"
#include "icmm/CCmyk.h"


namespace icmm
{
	

// public methods

// reimplemented (icmm::IColorTransformation)

bool CCmykToRgbTransformation::GetValueAt(const ArgumentType& argument, ResultType& result) const
{
	if (argument.GetElementsCount() != icmm::CCmyk::GetElementsCount()){
		return false;
	}

	if (result.GetElementsCount() != icmm::CRgb::GetElementsCount()){
		return false;
	}

	double c = argument.GetElement(icmm::CCmyk::CI_CYAN);
	double m = argument.GetElement(icmm::CCmyk::CI_MAGENTA);
	double y = argument.GetElement(icmm::CCmyk::CI_YELLOW);
	double k = argument.GetElement(icmm::CCmyk::CI_BLACK);

	c = (c * (1.0 - k ) + k);
	m = (m * (1.0 - k ) + k);
	y = (y * (1.0 - k ) + k);

	double red = 1.0 - c;
	double green = 1.0 - m;
	double blue = 1.0 - y;

	result.SetElement(icmm::CRgb::CI_RED, red);
	result.SetElement(icmm::CRgb::CI_GREEN, green);
	result.SetElement(icmm::CRgb::CI_BLUE, blue);

	return true;
}


CCmykToRgbTransformation::ResultType CCmykToRgbTransformation::GetValueAt(const ArgumentType& argument) const
{
	CCmykToRgbTransformation::ResultType result(3);

	GetValueAt(argument, result);

	return result;
}


} // namespace iccm


