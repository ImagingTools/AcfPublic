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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "icmm/CHsvToRgbTransformation.h"


// Qt includes
#include <QtCore/qmath.h>

// ACF includes
#include "icmm/CHsv.h"
#include "icmm/CRgb.h"


namespace icmm
{
	

// public methods

// reimplemented (icmm::IColorTransformation)

bool CHsvToRgbTransformation::GetValueAt(const ArgumentType& argument, ResultType& result) const
{
	if (argument.GetElementsCount() != icmm::CHsv::GetElementsCount()){
		return false;
	}

	if (result.GetElementsCount() != icmm::CRgb::GetElementsCount()){
		return false;
	}

	double hue = argument.GetElement(icmm::CHsv::CI_HUE) * 360.0;
	double saturation = argument.GetElement(icmm::CHsv::CI_SATURATION);
	double value = argument.GetElement(icmm::CHsv::CI_VALUE);

	double red = 0.0;
	double green = 0.0;
	double blue = 0.0;
	
	// color is on black-and-white center line 
	if(saturation == 0.0f){
		red = value;		// achromatic: shades of gray 
		green = value;	// supposedly invalid for hue=0 but who cares 
		blue = value;
	}
	// chromatic color 
	else {
		double hTemp;
		if(hue == 360.0){		// 360 degrees same as 0 degrees 
			hTemp = 0.0;
		}
		else{ 
			hTemp = hue;
		}

		hTemp = hTemp / 60.0;		// hue is now in [0,6) 
		int intHue = qFloor(hTemp);	// largest integer <= hue 
		double f = hTemp - intHue;		// fractional part of hue 
			
		double p = value * (1.0 - saturation); 
		double q = value * (1.0 - (saturation * f)); 
		double t = value * (1.0 - (saturation * (1.0 - f))); 
		
		switch (intHue){
			case 0: 
				red = value; 
				green = t;
				blue = p; 
				break;
			
			case 1: 
				red = q; 
				green = value; 
				blue = p;
				break;
			
			case 2:
				
				red = p; 
				green = value; 
				blue = t; 
				break;
			case 3:
				
				red = p; 
				green = q; 
				blue = value; 
				break;

			case 4: 
				red = t; 
				green = p; 
				blue = value; 
				break;

			case 5: 
				red = value; 
				green = p; 
				blue = value; 
				break;
		}
	}

	result.SetElement(icmm::CRgb::Red, red);
	result.SetElement(icmm::CRgb::Green, green);
	result.SetElement(icmm::CRgb::Blue, blue);

	return true;
}


CHsvToRgbTransformation::ResultType CHsvToRgbTransformation::GetValueAt(const ArgumentType& argument) const
{
	CHsvToRgbTransformation::ResultType result(3);

	GetValueAt(argument, result);

	return result;
}


} // namespace iccm


