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


#pragma once

// STL includes
#include <vector>


namespace i2d
{


/** 
	Calculates points on the given arc using Bresenham's integer algorithm.
	No antialiasing is used.
*/
class CArcPointsCalculator
{
public:
	typedef std::vector<int> Coordinates;

	/** 
		Fast implementation of the arc points calculation.

		Inputs: 
			centerX, centerY:		arc center in pixel
			radius:					arc radius in pixel
			startAngle, endAngle:	start and end angle of the arc in grad

		Outputs:
			xPoints, yPoints:		vectors of the calculated points coordinates

		Returns:
			true if arc points have been calculated, otherwise false
	*/
	static bool GetArcPoints(
				int centerX,
				int centerY,
				int radius,
				int startAngle,
				int endAngle,
				Coordinates& xPoints,
				Coordinates& yPoints);
};


} // namespace i2d


