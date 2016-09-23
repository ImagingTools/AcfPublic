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


#ifndef i2d_CPolygon_included
#define i2d_CPolygon_included


// ACF includes
#include <i2d/CPolypoint.h>


namespace i2d
{


/**
	Definition of the data model for a polygon.
*/
class CPolygon: public CPolypoint
{
public:
	/**
		Get outline length of this polygon.
	*/
	virtual double GetOutlineLength() const;

	/** 
		Flip object by X-axis.
	*/
	virtual void FlipByX();
	/** 
		Flip object by Y-axis.
	*/
	virtual void FlipByY();
	/** 
		Rotate object around its center.
	*/
	virtual void Rotate(double radians);
	/** 
		Reverses nodes order.
	*/
	virtual void ReverseNodes();
};


} // namespace i2d


#endif // !i2d_CPolygon_included


