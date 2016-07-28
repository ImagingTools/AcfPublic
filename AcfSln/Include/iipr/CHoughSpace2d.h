/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef iipr_CHoughSpace2d_included
#define iipr_CHoughSpace2d_included


// Qt includes
#include <QtCore/QMultiMap>

// ACF includes
#include "i2d/CVector2d.h"
#include "iimg/CGeneralBitmap.h"


namespace iipr
{


/**
	Hough space used for 2d Hough transformations.
*/
class CHoughSpace2d: public iimg::CGeneralBitmap
{
public:
	typedef iimg::CGeneralBitmap BaseClass;

	typedef QMultiMap<double, i2d::CVector2d> WeightToHoughPosMap;

	/**
		Create Hough space with specified size.
	*/
	bool CreateHoughSpace(const istd::CIndex2d& size);

	/**
		Smooth this space with specified stronness.
	*/
	void SmoothHoughSpace(int iterations);
	/**
		Analyse this Hough space to find set of local maximums.
		\param	maxPoints	maximal number of points to find.
		\param	minWeight	minimal weight of point.
		\param	minMaxRatio	maximal proportion between best and worse.
		\param	minDistance	minimal distance between two found points.
		\param	result		will be filled with list of found points.
	*/
	void AnalyseHoughSpace(int maxPoints, int minWeight, double minMaxRatio, double minDistance, WeightToHoughPosMap& result);

	/**
		Extract this Hough space to some gray scale bitmap.
	*/
	bool ExtractToBitmap(iimg::IBitmap& bitmap);

	/**
		Calculate minimum of all pixels in this space.
	*/
	void CalcMin(const CHoughSpace2d& space);
	/**
		Calculate maximum of all pixels in this space.
	*/
	void CalcMax(const CHoughSpace2d& space);
};


} // namespace iipr


#endif // !iipr_CHoughSpace2d_included


