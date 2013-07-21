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


#include "icmm/CRgbToCmykTransformation.h"
#include "icmm/CRgb.h"
#include "icmm/CCmyk.h"


namespace icmm
{


// public methods

// reimplemented (icmm::IColorTransformation)

bool CRgbToCmykTransformation::GetValueAt(const ArgumentType& argument, ResultType& result) const
{
	if (argument.GetElementsCount() != icmm::CCmyk::GetElementsCount()){
		return false;
	}

	if (result.GetElementsCount() != icmm::CRgb::GetElementsCount()){
		return false;
	}

	double r = argument.GetElement(icmm::CRgb::CI_RED);
	double g = argument.GetElement(icmm::CRgb::CI_GREEN);
	double b = argument.GetElement(icmm::CRgb::CI_BLUE);

	double c = 1.0 - r;
	double m = 1.0 - g;
	double y = 1.0 - b;
	double k = 1.0;

	if (c < k){  
		k = c;
	}

	if (m < k)   
		k = m;

	if (y < k)   
		k = y;
	
	if (k == 1.0){ 
		c = 0.0;
		m = 0.0;
		y = 0.0;
	}
	else {
		c = (c - k) / (1.0 - k);
		m = (m - k) / (1.0 - k);
		y = (y - k) / (1.0 - k);
	}

	result.SetElement(icmm::CCmyk::CI_CYAN, c);
	result.SetElement(icmm::CCmyk::CI_MAGENTA, m);
	result.SetElement(icmm::CCmyk::CI_YELLOW, y);
	result.SetElement(icmm::CCmyk::CI_BLACK, k);

	return true;
}


CRgbToCmykTransformation::ResultType CRgbToCmykTransformation::GetValueAt(const ArgumentType& argument) const
{
	CRgbToCmykTransformation::ResultType result(4);

	GetValueAt(argument, result);

	return result;
}


} // namespace iccm


