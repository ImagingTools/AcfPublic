/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iipr_IProjectionParams_included
#define iipr_IProjectionParams_included


#include "iser/ISerializable.h"


namespace iipr
{


class IProjectionConstraints;


/**
	Describe parameter for projection 2D image to 1D structure.
*/
class IProjectionParams: virtual public iser::ISerializable
{
public:
	/**
		Get access to constraints information about possible value ranges.
	*/
	virtual const IProjectionConstraints* GetConstraints() const = 0;

	/**
		Get width of projection line.
		Depending on interpretation this value can be in pixel or logical units.
		If this value is negative, smallest width is mean.
	*/
	virtual double GetLineWidth() const = 0;
	/**
		Set width of projection line.
		Depending on interpretation this \c width value can be in pixel or logical units.
		If \c width value is negative, smallest width is mean.
	*/
	virtual void SetLineWidth(double width) = 0;

	/**
		Get number of projection elements should be calculated by this projection.
		If returned value is negative, automatic size is mean.
	*/
	virtual int GetProjectionSize() const = 0;
	/**
		Set number of projection elements should be calculated by this projection.
		If \c size value is negative, automatic projction size is mean.
	*/
	virtual void SetProjectionSize(int size) = 0;
};


} // namespace iipr


#endif // !iipr_IProjectionParams_included


